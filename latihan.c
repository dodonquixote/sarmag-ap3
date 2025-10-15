#include <stdio.h>

int main() {
    char nama[30];
    int umur;
    int nilai1, nilai2, nilai3;
    float rata;

    printf("Masukkan nama siswa: ");
    scanf("%s", nama);

    printf("Masukkan umur siswa: ");
    scanf("%d", &umur);

    printf("Masukkan nilai ujian 1: ");
    scanf("%d", &nilai1);

    printf("Masukkan nilai ujian 2: ");
    scanf("%d", &nilai2);

    printf("Masukkan nilai ujian 3: ");
    scanf("%d", &nilai3);

    // Simpan nilai ke dalam array
    int nilai[3] = {nilai1, nilai2, nilai3};

    // Hitung rata-rata tanpa loop
    rata = (nilai[0] + nilai[1] + nilai[2]) / 3.0;

    printf("\n=== DATA SISWA ===\n");
    printf("Nama   : %s\n", nama);
    printf("Umur   : %d tahun\n", umur);
    printf("Nilai 1  : %d\n", nilai[0]);
    printf("Nilai 2  : %d\n", nilai[1]);
    printf("Nilai 3  : %d\n", nilai[2]);

    printf("Rata-rata: %.2f\n", rata);

    return 0;
}

