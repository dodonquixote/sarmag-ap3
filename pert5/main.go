package main

import (
	"fmt"
	"sort"
)

// === Struct ===
type Mahasiswa struct {
	Nama    string
	Jurusan string
	Nilai   []int
}

// === Fungsi menghitung rata-rata (Pointer + for klasik) ===
func HitungRata(m *Mahasiswa) float64 {
	total := 0
	for i := 0; i < len(m.Nilai); i++ {
		total += m.Nilai[i]
	}
	return float64(total) / float64(len(m.Nilai))
}

// === Fungsi menentukan grade (Array) ===
func TentukanGrade(rata float64) string {
	gr := [5]string{"A", "B", "C", "D", "E"}
	if rata >= 85 {
		return gr[0]
	} else if rata >= 70 {
		return gr[1]
	} else if rata >= 55 {
		return gr[2]
	} else if rata >= 40 {
		return gr[3]
	}
	return gr[4]
}

// === Fungsi menambah mahasiswa ke Map dan Slice ===
func TambahMahasiswa(list *[]Mahasiswa, data map[string]*Mahasiswa, m Mahasiswa) {
	*list = append(*list, m)
	data[m.Nama] = &(*list)[len(*list)-1]
}

// === Fungsi menampilkan daftar mahasiswa ===
func TampilMahasiswa(list []Mahasiswa) {
	fmt.Println("=== Daftar Mahasiswa ===")
	for i := 0; i < len(list); i++ {
		rata := HitungRata(&list[i])
		fmt.Printf("Nama: %-8s | Jurusan: %-17s | Rata: %.2f | Grade: %s\n",
			list[i].Nama, list[i].Jurusan, rata, TentukanGrade(rata))
	}
}

// === Fungsi mencari mahasiswa berdasarkan nama (pakai Map) ===
func CariMahasiswa(data map[string]*Mahasiswa, nama string) {
	if m, ok := data[nama]; ok {
		fmt.Printf("\nData %s ditemukan:\n", nama)
		fmt.Printf("Jurusan: %s, Nilai: %v, Rata: %.2f\n", m.Jurusan, m.Nilai, HitungRata(m))
	} else {
		fmt.Println("\nMahasiswa tidak ditemukan.")
	}
}

// === Fungsi menghitung jumlah mahasiswa per jurusan (Map + for klasik) ===
func HitungJurusan(list []Mahasiswa) {
	jumlah := make(map[string]int)
	for i := 0; i < len(list); i++ {
		jumlah[list[i].Jurusan]++
	}
	fmt.Println("\n=== Jumlah Mahasiswa per Jurusan ===")
	for jur, jml := range jumlah {
		fmt.Printf("%-15s : %d\n", jur, jml)
	}
}

func main() {
	// === Deklarasi Slice dan Map ===
	var daftar []Mahasiswa
	data := make(map[string]*Mahasiswa)

	// Tambahkan beberapa mahasiswa
	TambahMahasiswa(&daftar, data, Mahasiswa{"Alya", "Informatika", []int{90, 85, 88}})
	TambahMahasiswa(&daftar, data, Mahasiswa{"Bima", "Sistem Informasi", []int{70, 65, 75}})
	TambahMahasiswa(&daftar, data, Mahasiswa{"Citra", "Informatika", []int{95, 92, 93}})
	TambahMahasiswa(&daftar, data, Mahasiswa{"Deni", "Teknik Komputer", []int{60, 55, 58}})

	// Urutkan berdasarkan rata-rata (Slice + Pointer)
	sort.Slice(daftar, func(i, j int) bool {
		return HitungRata(&daftar[i]) > HitungRata(&daftar[j])
	})

	// Tampilkan semua data
	TampilMahasiswa(daftar)

	// Cari mahasiswa
	CariMahasiswa(data, "Bima")

	// Hitung jumlah per jurusan
	HitungJurusan(daftar)
}
