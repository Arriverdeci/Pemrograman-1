typedef struct {
    int idPromo;
    char namaPromo[50];
    int diskon;
    char ketentuan[100];
    char statusKetersediaanPromo[15];
} DataPromo;
DataPromo Promo;

void menuPromo();
void createPromo();
void readPromo();

void MasterPromo() {

    garismenu();
    menuPromo();

}

void menuPromo() {

    int choose;

    do {
        SetColorBlock(0, 14);
        HapusTengah();
        HapusKanan();
        SpecialkeyloginVertical(MenuMaster, 147, 15, 19, 3, 5, 5, &choose);
        HapusTengah();
        switch (choose) {
            case 1:
                createPromo();
                break;
            case 2:
                readPromo();
                gotoxy(60, 42); printf("========== ketik apapun untuk melanjutkan ==========");
                getch();
                HapusTengah();
                break;
            case 3:
//                updatePromo();
                break;
            case 4:
//                deletePromo();
                break;
            case 5:
                HapusKanan();
                switch (ROLES) {
                    case 1:
                        MenuAdmin();
                        break;
                    case 2:
                        MenuEO();
                        break;
                    case 3:
                        MenuManajer();
                        break;
                    case 4:
                        MenuPemasaran();
                        break;
                }
                break;
        }
    } while (choose != 5);

}

char STATUSPRM[5][20] = {"Tersedia", "Tidak Tersedia"};

void createPromo() {

    int id;
    int loop = 0;
    int tambah;
    FILE *buat;

    buat = fopen("../Dat/Master Promo.dat", "ab+");
    while (fread(&Promo, sizeof(Promo), 1, buat) == 1) {
        id = Promo.idPromo;
        loop++;
    }

    if (loop == 0) {
        Promo.idPromo = 1;
    } else {
        Promo.idPromo = id + 1;
    }
    fclose(buat);

    gotoxy(32, 15); printf("Masukkan Data Promo!");
    gotoxy(32, 18); printf("ID Promo    : PRM%03d", Promo.idPromo);
    gotoxy(32, 20); printf("Nama Promo  :");
    gotoxy(32, 22); printf("Diskon      :");
    gotoxy(32, 24); printf("Ketentuan   :");
    gotoxy(32, 26); printf("Status      :");
    gotoxy(60, 42); printf("========== klik 0 dan ENTER untuk kembali ==========");

    // input data
    gotoxy(46, 20); getletter(Promo.namaPromo, 25);
    int diskon;
    gotoxy(46, 22); getnum(&Promo.diskon, 10);
    if(Promo.diskon == 0) {
        MasterPromo();
    }
    gotoxy(46, 24); getteks(Promo.ketentuan, 100);
    if(strcmp(Promo.ketentuan, "0") == 0) {
        MasterPromo();
    }
    Pilihan(46, 26, 15, Promo.statusKetersediaanPromo, 1, STATUSPRM);

    buat = fopen("../Dat/Master Promo.dat", "ab");
    fwrite(&Promo, sizeof(Promo), 1, buat);
    fclose(buat);

    MessageBox(NULL, "Data Promo Berhasil Ditambahkan", "Information", MB_OK | MB_ICONASTERISK | MB_DEFAULT_DESKTOP_ONLY);

    do {
        HapusTengah();
        SetColorBlock(0, 14);
        gotoxy(73, 25); printf("Ingin menambah data lagi ?");
        SpecialkeyloginHorizontal(yntengah, 74, 27, 9, 1, 13, 2, &tambah);
        HapusTengah();

        switch (tambah) {
            case 1:
                HapusTengah();
                createPromo();
                break;
            case 2:
                HapusTengah();
                MasterPromo();
                break;
        }

    } while (tambah == 1);

}

void readPromo() {

    FILE * baca = fopen("../Dat/Master Promo.dat", "rb");

    if (baca == NULL) {
        MessageBox(NULL, "Data Promo Tidak Ditemukan", "Information", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
    } else {
        gotoxy(92, 13); printf("D A T A  P R O M O");

        // border
        for (j = 29; j < 143; j++) {
            gotoprintchar(j, 15, 205);
            gotoprintchar(j, 17, 205);
        }

        gotoxy(32, 16);     printf("ID");
        gotoxy(50, 16);     printf("NAMA");
        gotoxy(75, 16);     printf("DISKON");
        gotoxy(90, 16);     printf("KETENTUAN");
        gotoxy(127, 16);    printf("STATUS");

        i = 18;
        while (fread(&Promo, sizeof(Promo), 1, baca) == 1) {
            gotoxy(32, i);  printf("PRM%03d", Promo.idPromo);
            fflush(stdin);
            gotoxy(50, i);  printf("%s", Promo.namaPromo);
            fflush(stdin);
            gotoxy(75, i); printf("%d%%", Promo.diskon);
            gotoxy(90, i); printf("%s", Promo.ketentuan);
            gotoxy(127, i); printf("%s", Promo.statusKetersediaanPromo);
            i++;
        }

    }
    fclose(baca);
}

int updatePromo(FILE *Temp, FILE *ArsPromo, FILE *Asal, int dicari) {
    DataPromo DataBaru;
    int ditemukan;
    int pilihan;
    ArsPromo = fopen("Promo.dat", "rb");
    printf("\n");

    printf("Data Promo:\n");
    printf("Id\t|Nama Promo\t|Diskon\t|Ketentuan\t|Status Ketersediaan\n");
    while (fread(&Promo, sizeof(Promo), 1, ArsPromo) == 1) {
        printf("PRM%d", Promo.idPromo);
        printf("\t|%s", Promo.namaPromo);
        printf("\t\t|%.2f%%", Promo.diskon);
        printf("\t|%s", Promo.ketentuan);
        printf("\t|%s\n", Promo.statusKetersediaanPromo ? "Tersedia" : "Tidak Tersedia");
    }
    fclose(ArsPromo);

    printf("Masukkan Id yang ingin diubah:\tPRM");
    scanf("%d", &dicari);

    Asal = fopen("Promo.dat", "rb");
    Temp = fopen("Temp.dat", "wb");

    ditemukan = 0;
    while (fread(&Promo, sizeof(Promo), 1, Asal) == 1) {
        if (Promo.idPromo == dicari) {
            ditemukan = 1;
        } else {
            fwrite(&Promo, sizeof(Promo), 1, Temp);
        }
    }

    if (ditemukan == 1) {
        do {
            printf("\n[1]. Ubah Semua Data\n");
            printf("[2]. Ubah Nama Promo\n");
            printf("[3]. Ubah Diskon\n");
            printf("[4]. Ubah Ketentuan\n");
            printf("[5]. Ubah Status Ketersediaan\n");
            printf("[6]. Kembali\n");
            printf("Pilih menu:");
            scanf("%d", &pilihan);

            if (pilihan == 1) {
                printf("Masukkan Nama Promo Baru:");
                scanf(" %[^\n]", DataBaru.namaPromo);
                strcpy(Promo.namaPromo, DataBaru.namaPromo);

                printf("Masukkan Diskon Baru:");
                scanf("%f", &Promo.diskon);

                printf("Masukkan Ketentuan Baru:");
                scanf(" %[^\n]", Promo.ketentuan);

                printf("Masukkan Status Ketersediaan Baru (1: Tersedia, 0: Tidak Tersedia):");
                scanf("%d", &Promo.statusKetersediaanPromo);

                MessageBox(NULL, "Data Promo Berhasil Diubah", "Information", MB_OK | MB_ICONASTERISK);
            } else if (pilihan == 2) {
                printf("Masukkan Nama Promo baru:");
                scanf(" %[^\n]", DataBaru.namaPromo);
                strcpy(Promo.namaPromo, DataBaru.namaPromo);
                MessageBox(NULL, "Data Promo Berhasil Diubah", "Information", MB_OK | MB_ICONASTERISK);
            } else if (pilihan == 3) {
                printf("Masukkan Diskon Baru:");
                scanf("%f", &Promo.diskon);
                MessageBox(NULL, "Data Promo Berhasil Diubah", "Information", MB_OK | MB_ICONASTERISK);
            } else if (pilihan == 4) {
                printf("Masukkan Ketentuan Baru:");
                scanf(" %[^\n]", Promo.ketentuan);
                MessageBox(NULL, "Data Promo Berhasil Diubah", "Information", MB_OK | MB_ICONASTERISK);
            } else if (pilihan == 5) {
                printf("Masukkan Status Ketersediaan Baru (1: Tersedia, 0: Tidak Tersedia):");
                scanf("%d", &Promo.statusKetersediaanPromo);
                MessageBox(NULL, "Data Promo Berhasil Diubah", "Information", MB_OK | MB_ICONASTERISK);
            } else if (pilihan == 6) {
                break;
            } else {
                MessageBox(NULL, "Pilihan Tidak Sesuai", "Error", MB_OK | MB_ICONERROR);
            }
        } while (pilihan != 6);
        fwrite(&Promo, sizeof(Promo), 1, Temp);
        while (fread(&Promo, sizeof(Promo), 1, Asal) == 1) {
            fwrite(&Promo, sizeof(Promo), 1, Temp);
        }
    } else {
        MessageBox(NULL, "Id Promo tidak ditemukan di dalam arsip asal", "Error", MB_OK | MB_ICONERROR);
    }
    fclose(Asal);
    fclose(Temp);

    Asal = fopen("Promo.dat", "wb");
    Temp = fopen("Temp.dat", "rb");

    while (fread(&Promo, sizeof(Promo), 1, Temp) == 1) {
        fwrite(&Promo, sizeof(Promo), 1, Asal);
    }
    fclose(Temp);
    fclose(Asal);
}

int deletePromo(FILE *Asal, FILE *Temp, int dicari) {
    int ditemukan;
    Asal = fopen("Promo.dat", "rb");
    printf("\n");

    printf("Data Promo:\n");
    printf("Id\t|Nama Promo\t|Diskon\t|Ketentuan\t|Status Ketersediaan\n");
    while (fread(&Promo, sizeof(Promo), 1, Asal) == 1) {
        printf("PRM%d", Promo.idPromo);
        printf("\t|%s", Promo.namaPromo);
        printf("\t\t|%.2f%%", Promo.diskon);
        printf("\t|%s", Promo.ketentuan);
        printf("\t|%s\n", Promo.statusKetersediaanPromo ? "Tersedia" : "Tidak Tersedia");
    }
    fclose(Asal);
    printf("\nMasukkan Id yang ingin dihapus:\tPRM");
    scanf("%d", &dicari);

    Asal = fopen("Promo.dat", "rb");
    Temp = fopen("Temp.dat", "wb");

    ditemukan = 0;
    while (ditemukan == 0 && fread(&Promo, sizeof(Promo), 1, Asal) == 1) {
        if (Promo.idPromo == dicari) {
            ditemukan = 1;
        } else {
            fwrite(&Promo, sizeof(Promo), 1, Temp);
        }
    }

    if (ditemukan == 1) {
        printf("\n");
        printf("Data Promo berikut berhasil dihapus\n");
        printf("Id\t|Nama Promo\t|Diskon\t|Ketentuan\t|Status Ketersediaan\n");
        printf("PRM%d", Promo.idPromo);
        printf("\t|%s", Promo.namaPromo);
        printf("\t\t|%.2f%%", Promo.diskon);
        printf("\t|%s", Promo.ketentuan);
        printf("\t|%s\n", Promo.statusKetersediaanPromo ? "Tersedia" : "Tidak Tersedia");
        printf("\n");

        while (fread(&Promo, sizeof(Promo), 1, Asal) == 1) {
            fwrite(&Promo, sizeof(Promo), 1, Temp);
        }

        fclose(Asal);
        fclose(Temp);

        Asal = fopen("Promo.dat", "wb");
        Temp = fopen("Temp.dat", "rb");

        while (fread(&Promo, sizeof(Promo), 1, Temp) == 1) {
            fwrite(&Promo, sizeof(Promo), 1, Asal);
        }
        fclose(Asal);
        fclose(Temp);
    } else {
        MessageBox(NULL, "Id Promo tidak ditemukan di dalam arsip asal", "Error", MB_OK | MB_ICONERROR);
    }
}

//int menupromo() {
//    int pilihan;
//    FILE *Temp;
//    FILE *Asal;
//    FILE *ArsPromo;
//
//    do {
//        printf("\n========Data Promo========\n");
//        printf("[1]. Menambahkan Data\n");
//        printf("[2]. Menampilkan Data\n");
//        printf("[3]. Mengubah Data\n");
//        printf("[4]. Menghapus Data\n");
//        printf("[5]. Keluar\n");
//        printf("Pilih menu:");
//        scanf("%d", &pilihan);
//
//        switch (pilihan) {
//            case 1:
//                createPromo(ArsPromo);
//                break;
//            case 2:
//                readPromo(ArsPromo);
//                break;
//            case 3:
//                updatePromo(Temp, ArsPromo, Asal, 0);
//                break;
//            case 4:
//                deletePromo(Asal, Temp, 0);
//                break;
//            case 5:
//                MessageBox(NULL, "Terimakasih", "Information", MB_OK | MB_ICONASTERISK);
//                break;
//            default:
//                MessageBox(NULL, "Pilihan Tidak Sesuai", "Error", MB_OK | MB_ICONERROR);
//        }
//    } while (pilihan != 5);
//
//    return 0;
//}
