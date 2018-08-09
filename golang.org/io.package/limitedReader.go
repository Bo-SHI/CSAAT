package main

import (
	"io"
	"log"
	"strings"
)

func main() {
	r := strings.NewReader("some io.Reader stream to be read\n")

	lr := &io.LimitedReader{R: r, N: r.Size()}

	// for lr.N > 0 {
	// 	buf := make([]byte, 8)
	// 	lr.Read(buf)
	// 	log.Printf("%s\n", buf)
	// }

	buf := make([]byte, 8)
	for _, err := lr.Read(buf); err == nil; {
		log.Printf("%s\n", buf)

		_, err = lr.Read(buf)
	}
}
