package main

import (
	"fmt"
	"net/http"
)

func f(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "hello world")
}

func main() {
	handler := http.HandlerFunc(f)
	http.Handle("/", handler)
	http.ListenAndServe(":111111", nil)
}
