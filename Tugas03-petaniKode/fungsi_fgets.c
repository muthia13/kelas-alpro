#include <stdio.h>

int main(){
    char nama[20], asal[20];
    
    printf("Nama: ");
    fgets(nama, sizeof(nama), stdin);
    
    printf("Asal: ");
    fgets(asal, sizeof(asal), stdin);
   
    printf("\n-------------------------\n");
    printf("Nama anda: %s", nama);
    printf("Asal dari: %s", asal);
    
    return 0;
}
