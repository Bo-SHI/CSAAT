package main

import (
	"fmt"
	"log"
	"net"
)

func main() {
	addrs, err := net.InterfaceAddrs()
	if err != nil {
		log.Fatal(err)
	}
	for _, addr := range addrs {
		fmt.Println(addr)
	}
}
