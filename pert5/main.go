package main

import (
	"fmt"  // untuk output ke layar
	"sort" // untuk pengurutan slice
)

// === Struct ===
// Struct Mahasiswa untuk menyimpan data tiap mahasiswa
type Mahasiswa struct {
	Nama    string // nama mahasiswa
	Jurusan string // jurusan mahasiswa
	Nilai   []int  // daftar nilai (bisa lebih dari satu)
}

// === Fungsi menghitung rata-rata (Pointer + for klasik) ===
func HitungRata(m *Mahasiswa) float64 {
	total := 0 // variabel untuk menjumlahkan semua nilai

	// loop klasik untuk menjumlahkan semua elemen dalam slice Nilai
	for i := 0; i < len(m.Nilai); i++ {
		total += m.Nilai[i]
	}

	// hasil rata-rata dikembalikan dalam tipe float64
	return float64(total) / float64(len(m.Nilai))
}

// === Fungsi menentukan grade (Array) ===
func TentukanGrade(rata float64) string {
	// array berisi daftar grade dari A sampai E
	gr := [5]string{"A", "B", "C", "D", "E"}

	// logika if-else menentukan grade berdasarkan nilai rata-rata
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
	// tambahkan data mahasiswa ke slice (pakai pointer agar bisa diubah langsung)
	*list = append(*list, m)

	// simpan alamat mahasiswa terakhir ke dalam map dengan key = nama mahasiswa
	data[m.Nama] = &(*list)[len(*list)-1]
}

// === Fungsi menampilkan daftar mahasiswa ===
func TampilMahasiswa(list []Mahasiswa) {
	fmt.Println("=== Daftar Mahasiswa ===")

	// loop klasik untuk menampilkan semua mahasiswa
	for i := 0; i < len(list); i++ {
		rata := HitungRata(&list[i]) // hitung rata-rata tiap mahasiswa

		// tampilkan data secara terformat (Nama, Jurusan, Rata-rata, Grade)
		fmt.Printf("Nama: %-8s | Jurusan: %-17s | Rata: %.2f | Grade: %s\n",
			list[i].Nama, list[i].Jurusan, rata, TentukanGrade(rata))
	}
}

// === Fungsi mencari mahasiswa berdasarkan nama (pakai Map) ===
func CariMahasiswa(data map[string]*Mahasiswa, nama string) {
	// cek apakah nama mahasiswa ada di dalam map
	if m, ok := data[nama]; ok {
		fmt.Printf("\nData %s ditemukan:\n", nama)
		// tampilkan detail mahasiswa jika ditemukan
		fmt.Printf("Jurusan: %s, Nilai: %v, Rata: %.2f\n", m.Jurusan, m.Nilai, HitungRata(m))
	} else {
		// jika tidak ditemukan
		fmt.Println("\nMahasiswa tidak ditemukan.")
	}
}

// === Fungsi menghitung jumlah mahasiswa per jurusan (Map + for klasik) ===
func HitungJurusan(list []Mahasiswa) {
	// map untuk menyimpan jumlah mahasiswa per jurusan
	jumlah := make(map[string]int)

	// loop klasik untuk menghitung jumlah tiap jurusan
	for i := 0; i < len(list); i++ {
		jumlah[list[i].Jurusan]++
	}

	fmt.Println("\n=== Jumlah Mahasiswa per Jurusan ===")

	// tampilkan hasil perhitungan
	for jur, jml := range jumlah {
		fmt.Printf("%-15s : %d\n", jur, jml)
	}
}

func main() {
	// === Deklarasi Slice dan Map ===
	var daftar []Mahasiswa              // slice untuk menyimpan semua data mahasiswa
	data := make(map[string]*Mahasiswa) // map untuk akses cepat berdasarkan nama

	// === Tambahkan beberapa data mahasiswa ke slice dan map ===
	TambahMahasiswa(&daftar, data, Mahasiswa{"Alya", "Informatika", []int{90, 85, 88}})
	TambahMahasiswa(&daftar, data, Mahasiswa{"Bima", "Sistem Informasi", []int{70, 65, 75}})
	TambahMahasiswa(&daftar, data, Mahasiswa{"Citra", "Informatika", []int{95, 92, 93}})
	TambahMahasiswa(&daftar, data, Mahasiswa{"Deni", "Teknik Komputer", []int{60, 55, 58}})

	// === Urutkan berdasarkan nilai rata-rata (Slice + fungsi sort) ===
	sort.Slice(daftar, func(i, j int) bool {
		// urut descending (dari terbesar ke terkecil)
		return HitungRata(&daftar[i]) > HitungRata(&daftar[j])
	})

	// === Tampilkan semua data mahasiswa ===
	TampilMahasiswa(daftar)

	// === Cari mahasiswa berdasarkan nama ===
	CariMahasiswa(data, "Bima")

	// === Hitung dan tampilkan jumlah mahasiswa per jurusan ===
	HitungJurusan(daftar)
}
