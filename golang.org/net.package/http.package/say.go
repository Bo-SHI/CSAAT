package main

import (
	"fmt"
	"log"
	"net/http"
)

func say(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "hello http package\n")
}

func main() {
	http.HandleFunc("/", say)
	err := http.ListenAndServe(":19999", nil)
	if err != nil {
		log.Fatal(err)
	}
}
