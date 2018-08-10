package main

import (
	"io"
	"io/ioutil"
	"log"
	"os"
)

func main() {
	content := []byte("tmp file's content")
	file, err := ioutil.TempFile("", "example")
	if err != nil {
		log.Fatal(err)
	}
	defer os.Remove(file.Name())

	if _, err := file.Write(content); err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	if b, err := ioutil.ReadFile(file.Name()); err != nil {
		log.Fatal(err)
	} else {
		log.Printf("%s", b)
	}

	if _, ok := interface{}(file).(io.Reader); ok {
		log.Println("*os.File is a io.Reader")
	}

	if _, ok := interface{}(file).(io.WriterTo); ok {
		log.Println("*os.File is a io.WriterTo")
	}

	if _, ok := interface{}(os.Stdout).(io.ReaderFrom); ok {
		log.Println("os.Stdout is a io.ReaderFrom")
	}

	if _, err := io.Copy(os.Stdout, file); err != nil {
		log.Fatal(err)
	}

	if size, err := io.CopyBuffer(os.Stdout, file, nil); err != nil {
		log.Fatal(err)
	} else {
		log.Println(size)
	}
}
