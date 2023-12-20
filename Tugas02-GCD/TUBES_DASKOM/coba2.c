#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nama[100];
    char alamat[50];
    char no_hp [100];
    char username[100];
    char password[50];

    struct showroom{
        char merk[50];
        char tipe[50];
        int harga[50];
        int tahun[100];
        int stok[100];
    }showroom[50];
}User;

typedef struct{
    char namalengkap[50];
    char username[50];
    char password[50];
}Admin;

void registerUser(User *userList, int *userCount){
    User newUser;
    printf("Masukkan nama lengkap: "); scanf("%s", newUser.nama);
    printf("Masukkan username: "); scanf("%s", newUser.username);
    printf("Masukkan password:"); scanf("%s", newUser.password);

    newUser.
}