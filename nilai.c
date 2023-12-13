#include <stdio.h>

float calcNilai(float tugas, float quiz, float UTS, float UAS)
{
    return (tugas * 10 / 100) + (quiz * 20 / 100) + (UTS * 30 / 100) + (UAS * 40 / 100);
}

void displayNilaiAkhir(char *nama, char *NIM, float nilai_akhir)
{
    char *predikat;
    char *keterangan;

    if (nilai_akhir > 90)
    {
        predikat = "A";
        keterangan = "Lulus";
    }
    else if (nilai_akhir > 81)
    {
        predikat = "AB";
        keterangan = "Lulus";
    }
    else if (nilai_akhir > 71)
    {
        predikat = "B";
        keterangan = "Lulus";
    }
    else if (nilai_akhir > 61)
    {
        predikat = "BC";
        keterangan = "Lulus";
    }
    else if (nilai_akhir > 51)
    {
        predikat = "C";
        keterangan = "Lulus";
    }
    else if (nilai_akhir > 45)
    {
        predikat = "D";
        keterangan = "Tidak Lulus";
    }
    else
    {
        predikat = "E";
        keterangan = "Tidak Lulus";
    }

    printf("Nama Mahasiswa: %s\n", nama);
    printf("NIM: %s\n", NIM);
    printf("Nilai Akhir: %.f\n", nilai_akhir);
    printf("Predikat: %s\n", predikat);
    printf("Keterangan: %s\n", keterangan);
}

int main()
{
    char nama[50];
    char NIM[20];
    float tugas, quiz, UTS, UAS;

    printf("Masukkan Nama: ");
    scanf("%s", nama);
    printf("Masukkan NIM: ");
    scanf("%s", NIM);
    printf("Masukkan Nilai Tugas: ");
    scanf("%f", &tugas);
    printf("Masukkan Nilai Quiz: ");
    scanf("%f", &quiz);
    printf("Masukkan Nilai UTS: ");
    scanf("%f", &UTS);
    printf("Masukkan Nilai UAS: ");
    scanf("%f", &UAS);

    float nilai_akhir = calcNilai(tugas, quiz, UTS, UAS);
    displayNilaiAkhir(nama, NIM, nilai_akhir);

    return 0;
}