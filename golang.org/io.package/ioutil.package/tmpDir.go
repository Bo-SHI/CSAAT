package main

import (
	"io/ioutil"
	"log"
	"os"
	"path/filepath"
)

func main() {
	content := []byte("temporary file's content")
	dir, err := ioutil.TempDir("./", "example")
	if err != nil {
		log.Fatal(err)
	}
	defer os.RemoveAll(dir)

	log.Printf("%s", dir)

	tmpfn := filepath.Join(dir, "tmpfile")
	if err := ioutil.WriteFile(tmpfn, content, 066); err != nil {
		log.Fatal(err)
	}
}
