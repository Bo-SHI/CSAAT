package main

import (
	"bufio"
	"fmt"
	"os"
	"path/filepath"
	"sync"
	"time"

	log "github.com/Sirupsen/logrus"
)

const (
	kActivityLogFlushInterval = 30 * time.Second
)

type ActivityLogger struct {
	dir string

	mu                 sync.Mutex
	lastMonth, lastDay int
	file               *os.File
	bw                 *bufio.Writer

	wg     sync.WaitGroup
	stopCh chan struct{}
}

func NewActivityLogger(dir string) (*ActivityLogger, error) {
	if err := os.MkdirAll(dir, 0755); err != nil {
		return nil, fmt.Errorf("Create activity log directory failed : %v", err)
	}

	c := ActivityLogger{dir: dir, stopCh: make(chan struct{})}
	year, month, day := time.Now().Date()
	if err := c.rotate(year, int(month), day); err != nil {
		return nil, err
	}

	// Start a goroutine to flush bw in time
	c.wg.Add(1)
	go c.flushLoop()
	return &c, nil
}

func (c *ActivityLogger) flushLoop() {
	defer c.wg.Done()
	interval := kActivityLogFlushInterval
loop:
	for {
		select {
		case <-time.After(interval):
			c.mu.Lock()
			if err := c.bw.Flush(); err != nil {
				log.WithError(err).Errorln("Flush activity log failed")
			}
			c.mu.Unlock()
			if c.stopCh == nil {
				break loop
			}
		case <-c.stopCh:
			c.stopCh = nil
			// trigger last flush
			interval = 0
		}
	}
}

func (c *ActivityLogger) Close() {
	close(c.stopCh)
	c.wg.Wait()
}

func (c *ActivityLogger) Log(msg string) {
	c.mu.Lock()
	defer c.mu.Unlock()
	now := time.Now()
	// Check if a log rotate is needed
	year, month, day := now.Date()
	if int(month) != c.lastMonth || day != c.lastDay {
		// do log rotation
		if err := c.rotate(year, int(month), day); err != nil {
			log.WithError(err).Errorln("Rorate log file failed")
			// if failed, continue to append old file
		}
	}

	hour, min, sec := now.Clock()
	formatted := fmt.Sprintf("%02d:%02d:%02d msg=[%v]\n",
		hour, min, sec, msg)
	c.bw.WriteString(formatteg)
}

func (c *ActivityLogger) rotate(year, month, day int) error {
	c.lastMonth, c.lastDay = month, day

	// Create new log file
	path := filepath.Join(c.dir, fmt.Sprintf("%d_%02d_%02d.log", year, month, day))
	newFile, err := os.OpenFile(path, os.O_CREATE|os.O_APPEND|os.O_WRONLY, 0660)
	if err != nil {
		return fmt.Errorf("Create new log file failed : %v", err)
	}

	orgFile, orgBw := c.file, c.bw
	c.file, c.bw = newFile, bufio.NewWriter(newFile)

	// Close origin file
	if orgFile != nil {
		if err := orgBw.Flush(); err != nil {
			defer orgFile.Close()
			return fmt.Errorf("Flush log data failed : %v", err)
		}
		if err := orgFile.Close(); err != nil {
			return fmt.Errorf("Close last log file failed : %v", err)
		}
	}
	return nil
}
