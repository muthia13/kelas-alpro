#include <stdio.h>

int main () {
    char nama[20], asal[30];

    printf("Nama: ");
    scanf("%s", &nama);

    printf("Asal: ");
    scanf("%s", &asal);

    printf("\n--------------------\n");
    printf("Nama: %s\n", nama);
    printf("Asal: %s\n", asal);
   
    return 0;
}
