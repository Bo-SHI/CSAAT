package main

import (
	"encoding/json"
	"io/ioutil"
	"log"
	"net/http"
	"net/url"
	"os"
	"os/exec"
	"sync"
	"sync/atomic"
	"time"

	"github.com/go-redis/redis"
	"github.com/robfig/cron"
)

type Manager struct {
	mutex sync.Mutex

	cmd           *exec.Cmd
	lastStatus    int64 //0-正常；1-异常
	retryCount    int64
	restartStatus int64
	closedStatus  int64

	StartCron *cron.Cron
	EndCron   *cron.Cron

	stopCh chan struct{}
	wg     sync.WaitGroup
}

func startProcess() (p *exec.Cmd) {
	cmd := exec.Command("./FuturesProcess.exe")
	cmd.Start()
	return cmd
}

func NewManager(redisCli *redis.Client, logger *ActivityLogger) (*Manager, error) {
	mgr := &Manager{
		lastStatus:    0,
		retryCount:    0,
		restartStatus: 0,
		closedStatus:  0,

		stopCh: make(chan struct{}, 0),
	}

	mgr.cmd = startProcess()

	mgr.wg.Add(1)
	go mgr.goroute_1(redisCli, logger)

	mgr.wg.Add(1)
	go mgr.goroute_2(logger)

	mgr.StartCron = cron.New()
	mgr.StartCron.AddFunc("0 30 07 * * 1-5", func() {
		if atomic.LoadInt64(&mgr.closedStatus) == 1 {
			// cmd = startProcess() ?
			atomic.StoreInt64(&mgr.closedStatus, 0)
			logStr := "Auto Start Successed!!!"
			log.Println(logStr)
			logger.Log(logStr)
			//time.Sleep(1 * time.Second) ?
			atomic.StoreInt64(&mgr.restartStatus, 0)
		}
	})
	mgr.StartCron.Start()

	mgr.EndCron = cron.New()
	mgr.EndCron.AddFunc("0 00 03 * * 1-6", func() {
		if atomic.LoadInt64(&mgr.closedStatus) == 0 {
			atomic.StoreInt64(&mgr.closedStatus, 1)
			cmd := mgr.GetCMD()
			if cmd.ProcessState.Exited() {
				cmd.Process.Kill()
				logStr := "Auto Close Successed!!!"
				log.Println(logStr)
				logger.Log(logStr)
			}
			atomic.StoreInt64(&mgr.restartStatus, 1)
		}
	})
	mgr.EndCron.Start()

	return mgr, nil
}

func (mgr *Manager) GetCMD() *exec.Cmd {
	mgr.mutex.Lock()
	defer mgr.mutex.Unlock()

	return mgr.Cmd
}

func (mgr *Manager) ResetCMD() *exec.Cmd {
	mgr.mutex.Lock()
	defer mgr.mutex.Unlock()

	mgr.Cmd = startProcess()
	return mgr.Cmd
}

func (mgr *Manager) Close() {
	close(mgr.stopCh)
	mgr.cmd.Wait()
	mgr.wg.Wait()
}

func (mgr *Manager) goroute_1(redisCli *redis.Client, logger *ActivityLogger) {
	defer mgr.wg.Done()

	timer := time.NewTimer(5 * time.Second)
	defer timer.Stop()

loop:
	for {
		select {
		case <-mgr.stopCh:
			break loop
		case <-timer.C:
		}

		if atomic.LoadInt64(&mgr.restartStatus) != 0 || atomic.LoadInt64(&mgr.closedStatus) != 0 {
			timer.Reset(1 * time.Second)
		} else {
			_, err := redisCli.Ping().Result()
			if err != nil {
				fmt.Println(err)
				logger.Log(err.Error())
			} else {
				today := fmt.Sprintf("%04d%02d%02d", time.Now().Year(), time.Now().Month(), time.Now().Day())
				if !isHoliDay(today) {
					sub := redisCli.Subscribe("shang_hai_qh_channel")
					for i := 0; i < 2; i++ {
						reply, err := sub.ReceiveTimeout(2 * time.Second)
						if err != nil {
							fmt.Println(err)
							logger.Log(err.Error())
							atomic.StoreInt64(&mgr.lastStatus, 1)
							break
						} else {
							if i == 1 {
								if atomic.LoadInt64(&mgr.lastStatus) == 1 {
									atomic.StoreInt64(&mgr.lastStatus, 0)
								}
								atomic.StoreInt64(&mgr.retryCount, 0)
							}
						}
						fmt.Println(reply)
					}
					sub.Close()
				} else {
					fmt.Println("Holiday!!!")
				}
			}
		}
	}
}

func (mgr *Manager) goroute_2(logger *ActivityLogger) {
	defer mgr.wg.Done()

	timer := time.NewTimer(10 * time.Millisecond)
	defer timer.Stop()

loop:
	for {
		select {
		case <-mgr.stopCh:
			break loop
		case <-timer.C:
		}

		if atomic.LoadInt64(&mgr.lastStatus) == 1 {
			atomic.AddInt64(&mgr.retryCount, 1)
			if atomic.LoadInt64(&mgr.retryCount) > 2 {
				atomic.StoreInt64(&mgr.restartStatus, 1)
				mgr.GetCMD().Process.Kill()
				logStr := "Somthing Wrong! Restart FuturesProcess.exe!!!!"
				log.Println(logStr)
				logger.Log(logStr)
				//time.Sleep(5 * time.Second) 为什么要休眠5秒钟
				if atomic.LoadInt64(&mgr.retryCount) > 5 {
					log.Println("Remove temp file!!!!")
					logStr = "删除文件重新启动！"
					sendMessageJZ("18635464131", logStr)
					logger.Log(logStr)
					os.Remove("00000bb9.con")
					os.Remove("00000bb9.id")
					atomic.StoreInt64(&mgr.retryCount, 0)
				}
				mgr.ResetCMD()
				atomic.StoreInt64(&mgr.lastStatus, 0)
				//time.Sleep(1 * time.Second) ?
				atomic.StoreInt64(&mgr.restartStatus, 0)
			} else {
				logStr := "No Data,Retry!"
				log.Println(logStr)
				logger.Log(logStr)
				atomic.StoreInt64(&mgr.lastStatus, 0)
			}
		}
	}
}

func sendMessageJZ(mobile string, content string) error {
	var temp string
	temp = fmt.Sprintf("上期所行情接收-%s【朝阳永续】", content)
	resp, err := http.PostForm("http://www.jianzhou.sh.cn/JianzhouSMSWSServer/http/sendBatchMessage",
		url.Values{"account": {"sdk_shzyyx2"}, "password": {"gogoal2014"}, "msgText": {temp}, "destmobile": {mobile}})

	if err != nil {
		// handle error
		log.Println(err)
		writeLog(err.Error())
	}
	defer resp.Body.Close()
	body, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		// handle error
		log.Println(err)
		writeLog(err.Error())
	}
	fmt.Println(string(body))
	return err
}

func isHoliDay(date string) bool {
	holidayMap := map[string]int{
		"20180101": 0,
		"20180215": 0,
		"20180216": 0,
		"20180217": 0,
		"20180218": 0,
		"20180219": 0,
		"20180220": 0,
		"20180221": 0,
		"20180405": 0,
		"20180406": 0,
		"20180407": 0,
		"20180429": 0,
		"20180430": 0,
		"20180501": 0,
		"20180616": 0,
		"20180617": 0,
		"20180618": 0,
		"20180922": 0,
		"20180923": 0,
		"20180924": 0,
		"20181001": 0,
		"20181002": 0,
		"20181003": 0,
		"20181004": 0,
		"20181005": 0,
		"20181006": 0,
		"20181007": 0,
	}
	if _, ok := holidayMap[date]; ok {
		return true
	}
	return false
}
