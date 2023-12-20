#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

double fungsiAcak();

void main()
{
    int I, hitungKeluar, num;
    float luas, total, hitung;
    FILE *fptr;
    time_t t;

    double x, y, xKeluar[3500], yKeluar[3500], xPusatMassa, yPusatMassa;
    fptr = fopen("cofmc.dat", "w");

    srand((unsigned)time(&t));

    for (I = 0; I < 3500; I++)
    {
        xKeluar[I] = 0.0;
        yKeluar[I] = 0.0;
    }

    xPusatMassa = 0.0;
    yPusatMassa = 0.0;

    total = 0.0;
    hitung = 0.0;
    hitungKeluar = 0;

    printf("Masukkan jumlah iterasi yang diinginkan: ");
    scanf("%d", &num);

    for (I = 1; I <= num; I++)
    {

        x = fungsiAcak() * 4.0 - 2.0;
        y = fungsiAcak() * 4.0 - 2.0;

        if (y > -sqrt(4 - pow(x, 2)) && y < sqrt(4 - pow(x, 2)))
        {
            xPusatMassa = xPusatMassa + x;
            yPusatMassa = yPusatMassa + y;
            total = total + 1;
            hitungKeluar = hitungKeluar + 1;
            xKeluar[hitungKeluar] = x;
            yKeluar[hitungKeluar] = y;
        }
        hitung = hitung + 1;
    }
    luas = (total / hitung) * 16;
    printf("total is %f count is %f\n", total, hitung);
    xPusatMassa = xPusatMassa / total;
    yPusatMassa = yPusatMassa / total;
    printf("luas is %lf\n", luas);
    printf("pusat massa is %lf,%lf", xPusatMassa, yPusatMassa);

    if (hitungKeluar >= 2700)
        hitungKeluar = 2700;
    for (I = 1; I <= hitungKeluar - 1; I++)
        fprintf(fptr, "%lf %lf\n", xKeluar[I], yKeluar[I]);
    fclose(fptr);
}
double fungsiAcak()
{

    double ans;
    ans = rand() % 1000;
    ans = ans / 1000;
    return ans;
}