package main

import (
	"io"
	"log"
	"strings"
)

func main() {
	r := strings.NewReader("some io.Reader stream to be read\n")
	// buf := make([]byte, 33)
	// if _, err := io.ReadAtLeast(r, buf, 33); err != nil {
	// 	log.Fatal(err)
	// }
	// log.Printf("%s\n", buf)

	// // shortBuf, buf size is small than min(the min is the third param in func ReadAtLeast)
	// shortBuf := make([]byte, 8)
	// if _, err := io.ReadAtLeast(r, shortBuf, 33); err != nil {
	// 	log.Println("error:", err)
	// }

	// // minimal read size bigger than io.Reader stream
	// longBuf := make([]byte, 64)
	// if _, err := io.ReadAtLeast(r, longBuf, 64); err != nil {
	// 	log.Println("error:", err)
	// }

	// buf := make([]byte, 128)
	// if _, err := io.ReadAtLeast(r, buf, 64); err != nil {
	// 	log.Println("error:", err)
	// }

	buf := make([]byte, 33)
	if _, err := io.ReadAtLeast(r, buf, 33); err != nil {
		log.Fatal(err)
	}
}
