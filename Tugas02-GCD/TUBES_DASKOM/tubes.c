#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct loginadmin
{
    char username[50];
    char password[50];
};
struct user
{
    char namalengkap[100];
    char alamat[100];
    char nomortelpon[100];
    char username[100];
    char password[50];
}user;

struct Transaksi
{
    char username[20];
    char jenis[10]; // Rent, Sell, Buy
};
// Function Prototypes
void adminLogin();
void userRegistrasi();
void userLogin();
void adminMenu();
void userMenu();
void addVehicle();
void sewakendaraan();
void menjualkendaraan();
void membelikendaran();
void Statusjual();
void Historypenjualan();
char sewamobil[50];
char sewamotor[50];
 int waktu;
int main()
{
    int pilihan;

    do
    {
        printf("\nD'ShowRoom\n");
        printf("1. Admin Login\n");
        printf("2. User Registration\n");
        printf("3. User Login\n");
        printf("4. Exit\n");
        printf("masukkan pilihan: ");
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan)
        {
        case 1:
            adminLogin();
            break;
        case 2:
            userRegistrasi();
            break;
        case 3:
            userLogin();
            break;
        case 4:
            printf("program keluar. Goodbye!\n");
            break;
        default:
            printf("pilihan salah. silahkan masukkan pilihan yangbenar.\n");
        }

    } while (pilihan != 4);

    return 0;
}
void adminLogin()
{

    char username[20];
    char password[20];
    int percobaan = 3;

    do
    {
        printf("\nAdmin Login\n");
        printf("Enter username: ");
        gets(username);
        printf("Enter password: ");
        gets(password);

        if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0)
        {
            printf("Login berhasil!\n");
            adminMenu();
            return;
        }
        else
        {
            percobaan--;

            if (percobaan > 0)
            {
                printf("username dan password salah. Sisa percobaan: %d\n", percobaan);
            }
            else
            {
                printf("Terlalu banyak percobaan. keluar dari program.\n");
                exit(0);
            }
        }

    } while (percobaan > 0);
}

void userRegistrasi()
{
    FILE *dataUser;

    dataUser = fopen("Data user.dat", "ab");

    printf("\n");
    printf("REGISTER\n");
    printf("Silahkan registrasi username dan password yang anda ingin.\n");
    printf("Username\t: ");
    gets(user.username);
    printf("Password\t: ");
    gets(user.password);

    fwrite(&user, sizeof(user), 1, dataUser);
    fclose(dataUser);

    printf("Username dan password tersimpan!!!\n");
    printf("\n");

    int c;
    printf("1. Login\n2. Kembali ke Menu Utama\n");
    printf("Masukkan pilihan Anda: ");
    scanf("%d", &c);

    switch (c)
    {
    case 1:
        userLogin();
        system("pause");
        system("cls");
        break;
    case 2:
        main();
        system("pause");
        system("cls");
        break;
    default:
        printf("Silakan pilih menu yang valid.\n");
        userRegistrasi();
    }
}

struct tes
{
    char nama[100], usn[50], jk[50], sj[50], jk1[50], sj1[50];
    int lama;
} data;

void adminMenu()
{
    system("cls");
    char dicari[50], jawab;
    int i, n, b, xb, yb;
    FILE *dataUser;
    FILE *dataUser1;
    FILE *listKendaraan;
    FILE *listKendaraan1;
    FILE *reqKendaraan;

    printf("1. Mengedit, melihat dan menghapus akun user\n2. Menambah kendaraan (motor/mobil)\n3. Melihat request jual dari user dan meng-acc nya atau tidak\n4.Keluar\n");
    printf("Pilih menu: ");
    scanf("%d", &b);
    switch (b)
    {
    case 1:
        printf("1. Mengedit akun user\n2. Melihat akun user\n3. Menghapus akun user\n");
        printf("Pilih menu: ");
        scanf("%d", &xb);

        switch (xb)
        {
        case 1:
            system("cls");
            dataUser = fopen("Data user.dat", "ab");
            for (i = 0; i < n; i++)
            {
                printf("%d. Masukkan nama lengkap\t: ", i + 1);fflush(stdin);
                gets(data.nama); 
                printf("   Masukkan username\t: ");
                gets(data.usn);
                fwrite(&data, sizeof(data), 1, dataUser);
            }
            fclose(dataUser);
            system("pause");

        case 2:
            system("cls");
            dataUser = fopen("Data user.dat", "rb");
            while (fread(&data, sizeof(data), 1, dataUser) == 1)
            {
                printf("%d. Masukkan nama lengkap\t: %s\n", i + 1, data.nama);
                printf("   Masukkan username\t\t\t: %s\n", data.usn);
                printf("\n");
                i++;
            }
            fclose(dataUser);
            system("pause");

        case 3:
            system("cls");
            dataUser = fopen("Data user.dat", "rb");
            dataUser1 = fopen("Data user1.dat", "wb");
            printf("Silahkan masukkan nama user yang akan dihapus: ");
            gets(dicari);
            getchar();
            while (fread(&data, sizeof(data), 1, dataUser) == 1)
            {
                if (strcmp(data.nama, dicari) != 0)
                {
                    fwrite(&data, sizeof(data), 1, dataUser1);
                }
            }
            fclose(dataUser);
            fclose(dataUser1);

            remove("Data user.dat");
            rename("Data user1.dat", "Data user.dat");
            printf("Berhasil dihapus");
            system("pause");
            main();
            break;

        default:
            printf("Pilihan anda tidak ada\n");
            break;
        }
    case 2:
        printf("1. Motor\n2. Mobil\n");
        printf("Pilih menu\t: ");
        scanf("%d", &yb);
        getchar();

        switch (yb)
        {
        case 1:
            system("cls");
            listKendaraan = fopen("List kendaraan motor.dat", "ab");
            while (fread(&data, sizeof(data), 1, listKendaraan) == 1)
            {
            printf("%d. Masukkan jenis kendaraan\t: ", i + 1);
            gets(data.jk);
            printf("   Masukkan harga kendaraan\t: ");
            gets(data.sj);
            fwrite(&data, sizeof(data), 1, listKendaraan);
        }
        fclose(listKendaraan);
        system("pause");
        break;
    case 2:
        system("cls");
        listKendaraan1 = fopen("List kendaraan mobil.dat", "ab");
        while (fread(&data, sizeof(data), 1, listKendaraan1) == 1)
        {
            printf("%d. Masukkan jenis kendaraan\t: ", i + 1);
            gets(data.jk1);
            printf("   Masukkan harga kendaraan\t: ");
            gets(data.sj1);
            fwrite(&data, sizeof(data), 1, listKendaraan1);
        }
        fclose(listKendaraan1);
        system("pause");
        break;
    default:
        break;
        }
    case 3:
        system("cls");
        reqKendaraan = fopen("Request kendaraan.dat", "rb");
        while (fread(&data, sizeof(data), 1, reqKendaraan) == 1)
        {
            printf("%d. Masukkan jenis kendaraan\t: ", i + 1);
            gets(data.jk);
            printf("\n");
            i++;
        }
        printf("Apakah Anda ingin menyetujui kendaraan tersebut? y/n: ,");
        scanf("&c", jawab);
        fclose(reqKendaraan);
        system("pause");
        main();
        break;

    case 4:
        printf("Keluar\n");
        exit(0);
        break;

    default:
        printf("Pilihan anda tidak ada\n");
        break;
    }
}
void userLogin()
{
    FILE *dataUser;
    char username[20], inputPass[20], usne[20], paso[20];

    dataUser = fopen("Data user.dat", "rb");

    if (dataUser == NULL)
    {
        printf("Error membaca file\n");
        exit(1);
    }

    printf("\n");
    printf("LOGIN USER\n");
    printf("Masukkan Username\t: "); fflush(stdin);
    gets(username); 
    printf("Masukkan Password\t: ");
    gets(inputPass);
    int found = 1;

    while (fread(&data, sizeof(data), 1, dataUser) == 1)
    {
        if (strcmp(username, usne) == 0 && strcmp(inputPass, paso) == 0)
        {
            printf("Login Berhasil!!\n");
            found = 1;
            break;
        }
    }

    fclose(dataUser);

    if (found)
    {
        userMenu();
    }
    else
    {
        printf("Username atau password salah!!\n");
        printf("Silahkan Ulang\n");
        adminLogin();
    }
}

void userMenu()
{
    system("cls");
    int n, i, j, temp, d, spek, merk, jumlahKendaraan1;
    struct
    {
        char jenis[10], merek[20]; // Motor atau Mobil
        float hargaPerjam;
    } kendaraan;
    FILE *listKendaraan1;
            FILE *sm, *sm1, *sm2;
        struct sewa
        {
            char nama[100], usn[50], jk[50], sj[50], jk1[50], sj1[50];
            int lama;
        }sewa;
    printf("1. Menyewa kendaraan\n2. Menjual kendaraan\n3. Membeli kendaraan\n4. Melihat status jual\n5. Melihat history user\n6. Keluar\n ");
    printf("Pilih menu: ");
    scanf("%d", &d);

    switch (d)
    {
    case 1:
        system("cls");
        printf("Pilih jenis kendaraan yang ingin disewa (mobil/motor): \n");
        printf("Pilih menu 1-2: "); 
        scanf("%d", &spek);
        getchar();
        switch (spek)
        {
        case 1:
            sm = fopen("List kendaraan mobil.dat", "rb");
            sm1 = fopen("List kendaraan mobil2.dat", "wb");
            sm2 = fopen("sewa mobil.dat", "ab");
            printf("Masukkan nama mobil yang ingin disewa: ");
            gets(sewamobil);
            printf("Pinjam berapa lama? (jam)\n");
            printf("1. 3 jam\n2. 6 jam\n3. 12 jam\n");
            printf("Pilih waktu (1-3): ");
            scanf("%d", &waktu); getchar();
            switch (waktu)
            {
            case 1:
                while (fread(&data, sizeof(data),1 , sm) == 1){
                if (strcmp(data.jk1, sewamobil) != 0)
                {
                    fwrite(&data, sizeof(data), 1, sm1);
                }
                if (strcmp(data.jk1, sewamobil) == 0)
                {
                    strcpy(sewa.jk1, data.jk1);
                    sewa.lama = 3;
                    fwrite(&sewa, sizeof(sewa), 1, sm2);
                }
            }
                break;
            case 2:
            while (fread(&data, sizeof(data),1 , sm) == 1){
                if (strcmp(data.jk1, sewamobil) != 0)
                {
                    fwrite(&data, sizeof(data), 1, sm1);
                }
                if (strcmp(data.jk1, sewamobil) == 0)
                {
                    strcpy(sewa.jk1, data.jk1);
                    sewa.lama = 6;
                    fwrite(&sewa, sizeof(sewa), 1, sm2);
                }
            }
            case 3:
            while (fread(&data, sizeof(data),1 , sm) == 1){
                if (strcmp(data.jk1, sewamobil) != 0)
                {
                    fwrite(&data, sizeof(data), 1, sm1);
                }
                if (strcmp(data.jk1, sewamobil) == 0)
                {
                    strcpy(sewa.jk1, data.jk1);
                    sewa.lama = 12;
                    fwrite(&sewa, sizeof(sewa), 1, sm2);
                }
            }
            fclose(sm);
            fclose(sm1);
            fclose(sm2);
            default:
                break;
            }
        case 2:
            sm = fopen("List kendaraan motor.dat", "rb");
            sm1 = fopen("List kendaraan motor2.dat", "wb");
            sm2 = fopen("sewa motor.dat", "ab");
            printf("Masukkan nama motor yang ingin disewa: ");
            gets(sewamotor);
            printf("Pinjam berapa lama? (jam)\n");
            printf("1. 3 jam\n2. 6 jam\n3. 12 jam\n");
            printf("Pilih waktu (1-3): ");
            scanf("%d", &waktu); getchar();
            switch (waktu)
            {
            case 1:
                while (fread(&data, sizeof(data),1 , sm) == 1){
                if (strcmp(data.jk, sewamotor) != 0)
                {
                    fwrite(&data, sizeof(data), 1, sm1);
                }
                if (strcmp(data.jk, sewamotor) == 0)
                {
                    strcpy(sewa.jk, data.jk);
                    sewa.lama = 3;
                    fwrite(&sewa, sizeof(sewa), 1, sm2);
                }
            }
                break;
            case 2:
            while (fread(&data, sizeof(data),1 , sm) == 1){
                if (strcmp(data.jk, sewamotor) != 0)
                {
                    fwrite(&data, sizeof(data), 1, sm1);
                }
                if (strcmp(data.jk, sewamotor) == 0)
                {
                    strcpy(sewa.jk, data.jk);
                    sewa.lama = 6;
                    fwrite(&sewa, sizeof(sewa), 1, sm2);
                }
            }
            case 3:
            while (fread(&data, sizeof(data),1 , sm) == 1){
                if (strcmp(data.jk, sewamotor) != 0)
                {
                    fwrite(&data, sizeof(data), 1, sm1);
                }
                if (strcmp(data.jk, sewamotor) == 0)
                {
                    strcpy(sewa.jk, data.jk);
                    sewa.lama = 12;
                    fwrite(&sewa, sizeof(sewa), 1, sm2);
                }
            }
            fclose(sm);
            fclose(sm1);
            fclose(sm2);
            default:
                break;

            break;
            }
        default:
            break;
        }
    }
}