#include <stdio.h>

int main() {
    // ====== PENGENALAN TIPE DATA ======
    int umur;
    float tinggi;
    char nama[50];

    // ====== INPUT ======
    printf("Masukkan nama Anda: ");
    scanf("%s", nama); // Input string tanpa spasi

    printf("Masukkan umur Anda: ");
    scanf("%d", &umur);

    printf("Masukkan tinggi badan Anda (meter): ");
    scanf("%f", &tinggi);

    // ====== OUTPUT ======
    printf("\n=== DATA DIRI ANDA ===\n");
    printf("Nama   : %s\n", nama);
    printf("Umur   : %d tahun\n", umur);
    printf("Tinggi : %.2f meter\n", tinggi);

    // ====== ARRAY ======
    int nilai[5]; // array untuk menyimpan 5 nilai
    printf("\nMasukkan 5 nilai ujian:\n");
    for(int i = 0; i < 5; i++) {
        printf("Nilai ke-%d: ", i+1);
        scanf("%d", &nilai[i]);
    }

    // Hitung rata-rata
    int total = 0;
    for(int i = 0; i < 5; i++) {
        total += nilai[i];
    }
    float rata = total / 5.0;

    printf("\nRata-rata nilai Anda: %.2f\n", rata);

    return 0;
}
