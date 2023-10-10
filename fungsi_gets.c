#include <stdio.h>

int main () {
   char nama[20], asal[20];

   printf("Nama: ");
   gets(nama);
   
   printf("Asal: ");
   gets(asal);

   printf("You entered: %s\n", nama);
   printf("Asal: %s\n", asal);
   
   return(0);
}
