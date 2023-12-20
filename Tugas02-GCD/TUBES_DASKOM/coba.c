#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char username[20];
    char password[20];
    int saldo;
    int laundryCount;
    struct Laundry {
        char jenis[50];
        int beratKg;
        int harga;
        char status[20];
    } laundry[50];
} Customer;

typedef struct {
    char name[50];
    char username[20];
    char password[20];
} Admin;

void checkLaundryPricing() {
    printf("================== CUCI KILOAN ==================\n");
    printf("Reguler => 2 Hari Kerja => Rp.6.000 / Kg\n");
    printf("Express => 1 Hari Kerja => Rp.8.000 / Kg\n");
    printf("================== HOUSEHOLD ==================\n");
    printf("[1]. Baju Biasa");
    printf("[2]. Baju Putih");
    printf("[3]. Sprei/Selimut/Sarung Bantal & Guling => Rp.15.000\n");
    printf("[4]. Bed Cover Kecil => Rp.10.000\n");
    printf("[5]. Bed Cover Sedang => Rp.13.000\n");
    printf("[6]. Bed Cover Besar => Rp.16.000\n");
    printf("*Untuk fitur cek harga, cukup digunakan pada jenis laundry cuci kiloan saja.\n");
}

void registerCust(Customer *customerList, int *customerCount) {
    Customer newCustomer;
    printf("Masukan nama customer: ");
    scanf("%s", newCustomer.name);
    printf("Masukan username customer: ");
    scanf("%s", newCustomer.username);
    printf("Masukan password customer: ");
    scanf("%s", newCustomer.password);
    newCustomer.saldo = 0;
    newCustomer.laundryCount = 0;
    customerList[*customerCount] = newCustomer;
    (*customerCount)++;
    printf("Registrasi Berhasil\n");
    // Registration process
}

void laundryDeposit(Customer *customer) {
     printf("Jenis laundry yang ingin disetorkan: \n");
    printf("1. Pakaian Biasa\n");
    printf("2. Pakaian Putih\n");
    printf("3. Sepatu\n");
    printf("4. Sprei\n");
    printf("5. Bed Cover Kecil\n");
    printf("6. Bed Cover Sedang\n");
    printf("7. Bed Cover Besar\n");
    printf("8. Kembali ke menu utama \n");

    int totalItems = 0;
    int totalCost = 0;

    while (1) {
        int selectedOption;
        printf("Pilih jenis laundry: ");
        scanf("%d", &selectedOption);

        if (selectedOption == 8) {
            printf("Total items: %d\n", totalItems);
            printf("Total cost: %d\n", totalCost);
            return; // Return to the main menu
        }

        char jenisLaundry[50];
        int beratKg, harga;
        printf("Masukkan berat laundry (Kg): ");
        scanf("%d", &beratKg);

        switch (selectedOption) {
            case 1:
                strcpy(jenisLaundry, "Pakaian Biasa");
                harga = 6000 * beratKg;
                break;
            case 2:
                strcpy(jenisLaundry, "Pakaian Putih");
                harga = 6000 * beratKg;
                break;
            case 3: {
            int sepatuOption;
            printf("Pilih jenis sepatu (1. Biasa / 2. Kulit): ");
            scanf("%d", &sepatuOption);
            if (sepatuOption == 1) {
                strcpy(jenisLaundry, "Sepatu Biasa");
                harga = 12000;
            } else if (sepatuOption == 2) {
                strcpy(jenisLaundry, "Sepatu Kulit");
                harga = 20000;
            } else {
                printf("Pilihan sepatu tidak valid\n");
                return;
            }
            break;
        }
            case 4:
                strcpy(jenisLaundry, "Sprei");
                harga = 15000;
                break;
            case 5:
                strcpy(jenisLaundry, "Bed Cover Kecil");
                harga = 10000;
                break;
            case 6:
                strcpy(jenisLaundry, "Bed Cover Sedang");
                harga = 13000;
                break;
            case 7:
                strcpy(jenisLaundry, "Bed Cover Besar");
                harga = 16000;
                break;
            default:
                printf("Pilihan tidak valid\n");
                continue; // Go back to the start of the loop
        }

        printf("Jenis paket kecepatan laundrynya: \n");
        printf("1. Reguler => 2 Hari Kerja => Rp.6.000 / Kg\n");
        printf("2. Express => 1 Hari Kerja => Rp.8.000 / Kg\n");

        int speedOption;
        printf("Pilih paket kecepatan: ");
        scanf("%d", &speedOption);

        if (speedOption == 1) {
            strcpy(jenisLaundry, strcat(jenisLaundry, " - Reguler"));
            harga = 6000 * beratKg;
        } else if (speedOption == 2) {
            strcpy(jenisLaundry, strcat(jenisLaundry, " - Express"));
            harga = 8000 * beratKg;
        } else {
            printf("Pilihan kecepatan tidak valid\n");
            continue; // Go back to the start of the loop
        }

        // Update total items and cost
        totalItems++;
        totalCost += harga;

        // Store laundry in customer data
        if (customer->saldo >= harga) {
            strcpy(customer->laundry[customer->laundryCount].jenis, jenisLaundry);
            customer->laundry[customer->laundryCount].beratKg = beratKg;
            customer->laundry[customer->laundryCount].harga = harga;
            strcpy(customer->laundry[customer->laundryCount].status, "Belum Dikerjakan");
            customer->saldo -= harga;
            customer->laundryCount++;
            printf("Laundry berhasil disetorkan\n");
        } else {
            printf("Saldo tidak mencukupi\n");
        }
    }
}

void checkLaundryStatus(Customer *customer) {
    printf("=== Status Laundry ===\n");
    if (customer->laundryCount == 0) {
        printf("Tidak ada laundry yang disetorkan.\n");
        return;
    }

    printf("Jumlah Laundry: %d\n", customer->laundryCount);
    printf("================================\n");
    printf("No. | Jenis Laundry     | Status\n");
    printf("================================\n");
    for (int i = 0; i < customer->laundryCount; i++) {
        printf("%-4d| %-18s| %s\n", i + 1, customer->laundry[i].jenis, customer->laundry[i].status);
    }
    printf("================================\n");
}

void topUpSaldo(Customer *customer) {
    int amount;
    printf("Masukkan jumlah saldo yang ingin ditambahkan: ");
    scanf("%d", &amount);
    customer->saldo += amount;
    printf("Saldo berhasil ditambahkan. Saldo sekarang: %d\n", customer->saldo);
}

void deleteCustomerAccount(Customer *customerList, int *customerCount) {
    char username[20];
    printf("Masukkan username customer yang akan dihapus: ");
    scanf("%s", username);

    int found = 0;
    for (int i = 0; i < *customerCount; i++) {
        if (strcmp(customerList[i].username, username) == 0) {
            found = 1;
            // Remove the customer by shifting all elements after it
            for (int j = i; j < *customerCount - 1; j++) {
                customerList[j] = customerList[j + 1];
            }
            (*customerCount)--;
            printf("Akun customer '%s' berhasil dihapus.\n", username);
            break;
        }
    }

    if (!found) {
        printf("Username customer tidak ditemukan.\n");
    }
}

void viewLaundryEarnings(Customer *customerList, int customerCount) {
    int totalEarnings = 0;
    for (int i = 0; i < customerCount; i++) {
        for (int j = 0; j < customerList[i].laundryCount; j++) {
            totalEarnings += customerList[i].laundry[j].harga;
        }
    }
    printf("Total penghasilan dari laundry: Rp%d\n", totalEarnings);
}

void updateLaundryStatus(Customer *customerList, int customerCount) {
    char username[20];
    printf("Masukkan username customer: ");
    scanf("%s", username);

    int found = 0;
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customerList[i].username, username) == 0) {
            found = 1;
            printf("Jumlah laundry untuk customer '%s': %d\n", username, customerList[i].laundryCount);
            printf("Pilih nomor laundry yang ingin diupdate statusnya: ");
            int selectedLaundry;
            scanf("%d", &selectedLaundry);

            if (selectedLaundry > 0 && selectedLaundry <= customerList[i].laundryCount) {
                printf("Masukkan status baru (Misal: 'Sedang Dikerjakan', 'Selesai'): ");
                char newStatus[20];
                scanf("%s", newStatus);
                strcpy(customerList[i].laundry[selectedLaundry - 1].status, newStatus);
                printf("Status laundry berhasil diupdate.\n");
            } else {
                printf("Nomor laundry tidak valid.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Username customer tidak ditemukan.\n");
    }
}

void viewCustomerHistory(Customer *customerList, int customerCount) {
    // Sort customer by laundryCount to display frequent customers first
    for (int i = 0; i < customerCount - 1; i++) {
        for (int j = i + 1; j < customerCount; j++) {
            if (customerList[i].laundryCount < customerList[j].laundryCount) {
                Customer temp = customerList[i];
                customerList[i] = customerList[j];
                customerList[j] = temp;
            }
        }
    }

    printf("\n=== Customer History ===\n");
    for (int i = 0; i < customerCount; i++) {
        printf("Username: %s | Jumlah Laundry: %d\n", customerList[i].username, customerList[i].laundryCount);
    }
}

void adminOptions(Customer *customerList, int *customerCount, Admin *admin) {
    int choice;
    printf("\n=== Admin Options ===\n");
    printf("1. Hapus Akun Customer\n");
    printf("2. Lihat Penghasilan dari Laundry\n");
    printf("3. Update Status Laundry Customer\n");
    printf("4. Lihat History Customer\n");
    printf("5. Logout\n");
    printf("Pilih opsi: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            deleteCustomerAccount(customerList, customerCount);
            break;
        case 2:
            viewLaundryEarnings(customerList, *customerCount);
            break;
        case 3:
            updateLaundryStatus(customerList, *customerCount);
            break;
        case 4:
            viewCustomerHistory(customerList, *customerCount);
            break;
        case 5:
            printf("Logout berhasil.\n");
            return;
        default:
            printf("Opsi tidak valid.\n");
            break;
    }

    adminOptions(customerList, customerCount, admin);
}

void adminLogin(Admin *admin, Customer *customerList, int *customerCount) {
    char username[20], password[20];
    printf("Masukan username admin: ");
    scanf("%s", username);
    printf("Masukan password admin: ");
    scanf("%s", password);
    if (strcmp(admin->username, username) == 0 && strcmp(admin->password, password) == 0) {
        printf("Login Berhasil\n");
        adminOptions(customerList, customerCount, admin);
    } else {
        printf("Username atau password salah\n");
        adminLogin(admin, customerList, customerCount);
    }
}


void customerLogin(Customer *customerList, int customerCount) {
    char username[20], password[20];
    printf("Masukan username customer: ");
    scanf("%s", username);
    printf("Masukan password customer: ");
    scanf("%s", password);
    int i, flag = 0;
    for (i = 0; i < customerCount; i++) {
        if (strcmp(customerList[i].username, username) == 0 && strcmp(customerList[i].password, password) == 0) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        printf("Login Berhasil\n");
        // Tambahkan opsi customer setelah login berhasil
    } else {
        printf("Username atau password salah\n");
        customerLogin(customerList, customerCount);
    }
}

int main() {
    int opsi, customerCount = 0;
    Customer customerList[100];
    Admin admin;
    strcpy(admin.username, "admin");
    strcpy(admin.password, "admin");

    while (1) {
        printf("\n\n\tMenu Utama\n");
        printf("1. register dulu yuk\n");
        printf("2. login \n");
        printf("3. hanya admin yang bisa buka \n");
        printf("4. top up saldo \n");
        printf("5. deposit \n");
        printf("6. status pakian\n");
        printf("7. cek harga\n");
        printf("8. Exit\n");
        printf("\nMasukkan pilihan Anda: ");
        printf("\n\tMasukan opsi: ");
        scanf("%d", &opsi);

        switch (opsi) {
            case 1:
                registerCust(customerList, &customerCount);
                break;
            case 2:
                customerLogin(customerList, customerCount);
                break;
            case 3:
                adminLogin(&admin, customerList, &customerCount);
                break;
            case 4:
                topUpSaldo(customerList);
                break;
            case 5:
                laundryDeposit(customerList);
                break;
            case 6:
                checkLaundryStatus(customerList);
                break;
            case 7:
                checkLaundryPricing();
                break;
            case 8:
                exit(0);
            default:
                printf("\n\tOpsi tidak valid\n");
        }
    }
    return 0;
}
