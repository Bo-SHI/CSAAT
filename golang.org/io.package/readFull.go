package main

import (
	"io"
	"log"
	"strings"
)

func main() {
	r := strings.NewReader("some io.Reader stream to be read\n")
	buf := make([]byte, 64)
	if _, err := io.ReadFull(r, buf); err != nil {
		log.Printf("error:%s", err)
	}
	if _, err := io.ReadFull(r, buf); err != nil {
		log.Printf("error:%s", err)
	}
}
