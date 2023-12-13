#include<stdio.h>
#include<string.h>

int main(){
    int tugas, quiz, uts, uas;
    float akhir;
    char huruf_mutu[50];

    for (int i = 0; i < 3; i++) {
        printf("Mahasiswa %d\n", i + 1);

        printf("Masukkan Nilai Tugas: ");
        scanf("%d", &tugas);
        printf("Masukkan Nilai Quiz: ");
        scanf("%d", &quiz);
        printf("Masukkan Nilai UTS: ");
        scanf("%d", &uts);
        printf("Masukkan Nilai UAS: ");
        scanf("%d", &uas);

        akhir = 0.1*tugas + 0.2*quiz + 0.3*uts + 0.4*uas;

        if (akhir >= 90) {
            strcpy(huruf_mutu, "A");
        } else if (akhir >= 86 && akhir <= 90) {
            strcpy(huruf_mutu, "A-");
        } else if (akhir >= 81 && akhir <= 85) {
            strcpy(huruf_mutu, "B+");
        } else if (akhir >= 76 && akhir <= 80) {
            strcpy(huruf_mutu, "B");
        } else if (akhir >= 71 && akhir <= 75) {
            strcpy(huruf_mutu, "B-");
        } else if (akhir >= 66 && akhir <= 70) {
            strcpy(huruf_mutu, "C+");
        } else if (akhir >= 61 && akhir <= 65) {
            strcpy(huruf_mutu, "C");
        } else if (akhir >= 56 && akhir <= 60) {
            strcpy(huruf_mutu, "C-");
        } else if (akhir >= 46 && akhir <= 55) {
            strcpy(huruf_mutu, "D"); 
        } else {
            strcpy(huruf_mutu, "E");
        }

        printf("Nilai Akhir: %.f, Huruf Mutu: %s\n\n", akhir, huruf_mutu);
    }

    return 0;
}