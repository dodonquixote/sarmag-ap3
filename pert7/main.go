package main

import (
	"encoding/json"
	"fmt"
	"html/template"
	"net/http"
	"path/filepath"
)

// Fungsi untuk render HTML
func renderHTML(w http.ResponseWriter, filename string) {
	path := filepath.Join("templates", filename)
	tmpl, err := template.ParseFiles(path)
	if err != nil {
		http.Error(w, "File HTML tidak ditemukan", http.StatusInternalServerError)
		return
	}
	tmpl.Execute(w, nil)
}

func main() {

	// Route 1: Halaman utama
	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		renderHTML(w, "index.html")
	})

	http.HandleFunc("/about", func(w http.ResponseWriter, r *http.Request) {
		renderHTML(w, "about.html")
	})

	// Route 2: Menampilkan pesan sederhana
	http.HandleFunc("/halo", func(w http.ResponseWriter, r *http.Request) {
		fmt.Fprintf(w, "Halo Dunia!")
	})

	// Route 3: Menampilkan data JSON
	http.HandleFunc("/json", func(w http.ResponseWriter, r *http.Request) {
		w.Header().Set("Content-Type", "application/json")

		data := map[string]string{
			"pesan": "Ini response JSON dari Go",
			"versi": "1.0",
		}

		json.NewEncoder(w).Encode(data)
	})

	fmt.Println("Server berjalan di http://localhost:8080")
	http.ListenAndServe(":8080", nil)
}
