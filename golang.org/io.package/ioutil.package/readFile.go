package main

import (
	"io/ioutil"
	"log"
)

func main() {
	bytes, err := ioutil.ReadFile("./README")
	if err != nil {
		log.Fatal(err)
	}

	log.Printf("%s", bytes)
}
