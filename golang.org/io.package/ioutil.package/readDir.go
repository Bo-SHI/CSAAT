package main

import (
	"io/ioutil"
	"log"
)

func main() {
	files, err := ioutil.ReadDir("../")
	if err != nil {
		log.Fatal(err)
	}

	for _, file := range files {
		log.Println(file.Name())
	}
}
