#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Deklarasi struct data kendaraan
typedef struct {
    char merk[100];
    char tipe[100];
    int tahun;
    int harga;
    int stok;
} Kendaraan;

// Deklarasi struct data user
typedef struct {
    char nama[100];
    char alamat[100];
    char no_hp[100];
    char username[100];
    char password[100];
    int role; // 0 = user, 1 = admin
} User;
// Fungsi login admin
int login_admin(User* user) {
    // Input username dan password
    printf("Username: ");
    scanf("%s", user->username);
    printf("Password: ");
    scanf("%s", user->password);

    // Cek apakah username dan password valid
    if (strcmp(user->username, "admin") == 0 && strcmp(user->password, "admin") == 0) {
        return 1;
    } else {
        return 0;
    }
}
// Fungsi menu admin
void menu_admin(User* user) {
    int pilihan;

    // Tampilkan menu
    printf("=== Menu Admin ===\n");
    printf("1. Edit, lihat, dan hapus akun user\n");
    printf("2. Menambah kendaraan\n");
    printf("3. Melihat request jual dari user\n");
    printf("4. Keluar\n");
    printf("Pilihan: ");
    scanf("%d", &pilihan);

    // Lakukan aksi berdasarkan pilihan
    switch (pilihan) {
        case 1:
            edit_lihat_hapus_akun_user(user);
            break;
        case 2:
            tambah_kendaraan(user);
            break;
        case 3:
            lihat_request_jual_user(user);
            break;
        case 4:
            printf("Keluar dari menu admin...\n");
            break;
        default:
            printf("Pilihan tidak valid!\n");
            break;
    }
}
// Fungsi edit, lihat, dan hapus akun user
void edit_lihat_hapus_akun_user(User* user) {
    int pilihan;

    // Tampilkan menu
    printf("=== Edit, Lihat, dan Hapus Akun User ===\n");
    printf("1. Edit akun user\n");
    printf("2. Lihat akun user\n");
    printf("3. Hapus akun user\n");
    printf("4. Kembali ke menu admin\n");
    printf("Pilihan: ");
    scanf("%d", &pilihan);

    // Lakukan aksi berdasarkan pilihan
    switch (pilihan) {
        case 1:
            edit_akun_user(user);
            break;
        case 2:
            lihat_akun_user(user);
            break;
        case 3:
            hapus_akun_user(user);
            break;
        case 4:
            printf("Kembali ke menu admin...\n");
            break;
        default:
            printf("Pilihan tidak valid!\n");
            break;
    }
}
// Fungsi edit akun user
void edit_akun_user(User* user) {
    // Input data user
    printf("Masukan data user yang ingin diedit:\n");
    printf("Nama: ");
    scanf("%s", user->nama);
    printf("Alamat: ");
    scanf("%s", user->alamat);
    printf("No. HP: ");
    scanf("%s", user->no_hp);
    printf("Username: ");
    scanf("%s", user->username);
    printf("Password: ");
    scanf("%s", user->password);

    // Update data user
    update_akun_user(user);

    // Tampilkan pesan berhasil
    printf("Akun berhasil diubah!!");