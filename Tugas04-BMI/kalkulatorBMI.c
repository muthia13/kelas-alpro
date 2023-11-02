#include <stdio.h>
int main (){
int TB, BB, BMI, pilihan;

printf ("1. Laki-laki \n2. Perempuan \n");
printf ("Pilih Jenis kelamin: ");
scanf ("%d", pilihan);
switch (pilihan)
{
    case 1:
    printf ("Masukkan tinggi badan: ");
    scanf ("%d", &TB);
    printf ("Masukkan berat badan: ");
    scanf ("%d", &BB);
    BMI = BB/(TB*TB);
    if (17<=BMI<=23) {
        printf ("Berat badan ideal\n");
    } else {
        printf ("Berat badan tidak ideal\n");
    }
    case 2:
    printf ("Masukkan tinggi badan: ");
    scanf ("%d", &TB);
    printf ("Masukkan berat badan: ");
    scanf ("%d", &BB);
    BMI = BB/(TB*TB);
    if (18<=BMI<=25) {
        printf ("Berat badan ideal\n");
    } else {
        printf ("Berat badan tidak ideal\n");
    }
}
}