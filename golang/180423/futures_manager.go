package main

import (
	"flag"
	"fmt"
	"os"
	"strings"
	"sync"
)

var (
	config = flat.String("config", "confit.txt", "config file path")
)

var Config = struct {
	RedisAddr string
	LogDir    string
}{
	RedisAddr: "127.0.0.1:6379",
}

/*
每周一至五为交易日（国家法定假日除外）
交易时间：
8：55 ~ 8：59   集合竟价
9：00 ~ 10：15  第一节交易
10：30 ~ 11：30 第二节交易
13：30 ~ 15：00 第三节交易
21：00 ~ 02：30 晚间交易
*/

func MustLoadJSON(filepath string, config interface{}) {
	file, err := os.Open(filepath)
	if err != nil {
		panic(err)
	}
	defer file.Close()

	// Decode into config
	dec := json.NewDecoder(file)
	if err := dec.Decode(config); err != nil {
		panic(err)
	}
}

func main() {
	flag.Parse()
	MustLoadJSON(*config, &Config)

	cli := redis.NewClient(&redis.Options{
		Addr:     add,
		Password: "", // no password set
		DB:       0,  // use default DB
		PoolSize: 10,
	})

	logger, err := NewActivityLogger(Config.LogDir)
	if err != nil {
		panic(err)
	}
	defer logger.Close()

	mgr, err := NewManager(&cli, logger)
	if err != nil {
		panic(err)
	}
	defer mgr.Close()

	log.Println("start...")

	// capture signals to shutdown
	sigCh := make(chan os.Signal, 1)
	signal.Notify(sigCh, os.Interrupt, syscall.SIGTERM)
	<-sigCh

	log.Println("end...")
}
