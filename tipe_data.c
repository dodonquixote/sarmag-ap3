#include <stdio.h>

int main() {
    int umur = 20;              // bilangan bulat
    float tinggi = 1.72;        // bilangan desimal
    double berat = 65.8;        // bilangan desimal presisi tinggi
    char huruf = 'A';           // satu karakter
    char nama[20] = "Doni";     // string (kumpulan karakter)

    printf("Nama   : %s\n", nama);
    printf("Huruf  : %c\n", huruf);
    printf("Umur   : %d tahun\n", umur);
    printf("Tinggi : %.2f meter\n", tinggi);
    printf("Berat  : %.2lf kg\n", berat);

    return 0;
}
