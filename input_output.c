#include <stdio.h>

int main() {
    char nama[30];
    int umur;
    float tinggi;

    printf("Masukkan nama Anda: ");
    scanf("%s", nama); // tidak bisa membaca spasi

    printf("Masukkan umur Anda: ");
    scanf("%d", &umur);

    printf("Masukkan tinggi badan Anda (meter): ");
    scanf("%f", &tinggi);

    printf("\n=== DATA ANDA ===\n");
    printf("Nama   : %s\n", nama);
    printf("Umur   : %d tahun\n", umur);
    printf("Tinggi : %.2f meter\n", tinggi);

    return 0;
}

