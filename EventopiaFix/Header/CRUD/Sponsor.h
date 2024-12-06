void menuSponsor ();
void createSponsor ();
void readSponsor ();
void updateSponsor ();
void deleteSponsor ();

void MasterSponsor() {
    garismenu();
    menuSponsor();
}

char stsKetersediaan[5][20] = {"Tersedia", "Tidak Tersedia"};
void menuSponsor() {
    int choose;

    do {
        SetColorBlock(0, 14);
        HapusTengah();
        HapusKanan();
        SpecialkeyloginVertical(MenuMaster, 147, 15, 19, 3, 5, 5, &choose);
        HapusTengah();
        switch (choose) {
            case 1:
                createSponsor();
                break;
            case 2:
                readSponsor();
                gotoxy(60, 42); printf("========== ketik apapun untuk melanjutkan ==========");
                getch();
                HapusTengah();
                break;
            case 3:
                updateSponsor();
                break;
            case 4:
                deleteSponsor();
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

void createSponsor() {
    FILE *SPNSR;
    int id;
    int loop = 0;
    int tambah;

    SetColorBlock(0, 14);
    SPNSR = fopen("../Dat/Sponsor.dat","ab+"); /* buka file user untuk dibaca */
    fread(&spnsr, sizeof(spnsr),1, SPNSR);
    while (!feof(SPNSR)){
        fread(&spnsr,sizeof(spnsr),1,SPNSR);
        id = spnsr.idPerusahaanSponsor;
        loop++;
    }

    if (loop == 0) {
        spnsr.idPerusahaanSponsor = 1;
    } else {
        spnsr.idPerusahaanSponsor = id + 1; /* id otomatis */
    }
    fclose(SPNSR);

    gotoxy(37, 15);printf("Masukkan Data Sponsor!!!");
    gotoxy(37, 18);printf("Id Perusahaan Sponsor    :SPNSR%03d", spnsr.idPerusahaanSponsor);
    gotoxy(37, 20);printf("Nama Perusahaan Sponsor  :");
    gotoxy(37, 22);printf("Alamat Perusahaan Sponsor:");
    gotoxy(37, 24);printf("Nomor Telepon Sponsor    :");
    gotoxy(37, 26);printf("Email Perusahaan Sponsor :");
    gotoxy(37, 28);printf("Benefit Sponsor          :");
    gotoxy(37, 30);printf("Status Ketersediaan      :");
    gotoxy(60, 42);printf("========== klik 0 dan ENTER untuk kembali ==========");

    gotoxy(64, 20);getletter(spnsr.namaPerusahaanSponsor, 50);
    if (strcmp(spnsr.namaPerusahaanSponsor, "0") == 0) {
        MasterSponsor();
    }
    gotoxy(64, 22);getletter(spnsr.alamatPerusahaanSponsor, 50);
    if (strcmp(spnsr.alamatPerusahaanSponsor, "0") == 0) {
        MasterSponsor();
    }
    gotoxy(64, 24);getteksnummin(spnsr.noTelpPerusahaanSponsor, 11, 13);
    if (strcmp(spnsr.noTelpPerusahaanSponsor, "0") == 0) {
        MasterSponsor();
    }
    gotoxy(64, 26);getteks(spnsr.emailPerusahaanSponsor, 50);
    strlwr(spnsr.emailPerusahaanSponsor);
    if (strcmp(spnsr.emailPerusahaanSponsor, "0") == 0) {
        MasterSponsor();
    }

    gotoxy(64, 28);getteks(spnsr.benefit, 100);
    if (strcmp(spnsr.benefit, "0") == 0) {
        MasterSponsor();
    }

    Pilihan(64, 30, 20, spnsr.statusKetersediaanSponsor, 2, stsKetersediaan);

    SPNSR = fopen("../Dat/Sponsor.dat", "ab");
    fwrite(&spnsr, sizeof(spnsr), 1, SPNSR);
    fclose(SPNSR);

    MessageBox(0, "Data Sponsor Berhasil Ditambahkan", "Information", MB_OK | MB_ICONASTERISK);

    do {
        HapusTengah();
        SetColorBlock(0, 14);
        gotoxy(73, 25); printf("Ingin menambah data lagi ?");
        SpecialkeyloginHorizontal(yntengah, 74, 27, 9, 1, 13, 2, &tambah);
        HapusTengah();

        switch (tambah) {
            case 1:
                HapusTengah();
                createSponsor();
                break;
            case 2:
                HapusTengah();
                menuSponsor();
                break;
        }

    } while (tambah == 1);
}

int readSponsor() {
    FILE *SPNSR
    SPNSR = fopen("../Dat/Sponsor.dat", "rb");

    if (SPNSR == NULL) {
        gotoxy(56, 13);
        printf("DATA TIDAK DITEMUKAN");
    } else {
        gotoxy(78, 13);
        printf("D A T A  S P O N S O R");

        //border
        for (j = 29; j < 143; j++) {
            gotoprintchar(j, 15, 205);
            gotoprintchar(j, 17, 205);
        }

        gotoxy(39, 16);
        printf("ID");
        gotoxy(54, 16);
        printf("NAMA");
        gotoxy(84, 16);
        printf("ALAMAT");
        gotoxy(114, 16);
        printf("NO TELP");
        gotoxy(144, 16);
        printf("EMAIL");
        gotoxy(174, 16);
        printf("BENEFIT");
        gotoxy(214, 16);
        printf("STATUS");

        i = 18;

        while (fread(&spnsr, sizeof(spnsr), 1, SPNSR) == 1) {
            gotoxy(39, i);  printf("SPNSR%03d", spnsr.idPerusahaanSponsor); fflush(stdin);
            gotoxy(54, i);  printf("%s", spnsr.namaPerusahaanSponsor);      fflush(stdin);
            gotoxy(84, i);  printf("%s", spnsr.alamatPerusahaanSponsor);    fflush(stdin);
            gotoxy(114, i); printf("%s", spnsr.noTelpPerusahaanSponsor);    fflush(stdin);
            gotoxy(144, i); printf("%s", spnsr.emailPerusahaanSponsor);     fflush(stdin);
            gotoxy(174, i); printf("%s", spnsr.benefit);                    fflush(stdin);
            gotoxy(214, i); printf("%s", spnsr.statusKetersediaanSponsor);  fflush(stdin);
            i++;
        }
    }
    fclose(SPNSR);
}

void menuupdateSponsor () {
    gotoxy(149, 21);  printf("    S E M U A    ");
    gotoxy(149, 23);  printf("     D A T A     ");
    gotoxy(149, 25);  printf("     N A M A     ");
    gotoxy(149, 27);  printf("  S P O N S O R  ");
    gotoxy(149, 29);  printf("   A L A M A T   ");
    gotoxy(149, 31);  printf("  S P O N A S A     ");
    gotoxy(149, 34);  printf("  K E M B A L I  ");
}
void updateSponsor() {
    FILE *Temp;
    FILE *SPNSR;
    FILE *Asal;
    int dicari;
    DataSponsor DataBaru;
    int ditemukan;
    int pilihan;

    ArsSponsor = fopen("Sponsor.dat", "rb");
    printf("\n");

    printf("Data Sponsor:\n");
    printf("Id\t|Nama Perusahaan\t|Alamat\t\t|No. Telepon\t|Email\t\t|Benefit\t|Status Ketersediaan\n");
    while (fread(&Sponsor, sizeof(Sponsor), 1, ArsSponsor) == 1) {
        printf("SPN%d", Sponsor.idPerusahaanSponsor);
        printf("\t|%s", Sponsor.namaPerusahaanSponsor);
        printf("\t\t\t|%s", Sponsor.alamatPerusahaanSponsor);
        printf("\t|%s", Sponsor.noTelpPerusahaanSponsor);
        printf("\t|%s", Sponsor.emailPerusahaanSponsor);
        printf("\t|%s", Sponsor.benefit);
        printf("\t\t|%c\n", Sponsor.statusKetersediaanSponsor);
    }
    fclose(ArsSponsor);

    printf("Masukkan Id yang ingin diubah:\tSPN");
    scanf("%d", &dicari);

    Asal = fopen("Sponsor.dat", "rb");
    Temp = fopen("Temp.dat", "wb");

    ditemukan = 0;
    while (fread(&Sponsor, sizeof(Sponsor), 1, Asal) == 1) {
        if (Sponsor.idPerusahaanSponsor == dicari) {
            ditemukan = 1;
        } else {
            fwrite(&Sponsor, sizeof(Sponsor), 1, Temp);
        }
    }

    if (ditemukan == 1) {
        do {
            printf("\n[1]. Ubah Semua Data\n");
            printf("[2]. Ubah Nama Perusahaan Sponsor\n");
            printf("[3]. Ubah Alamat Perusahaan Sponsor\n");
            printf("[4]. Ubah Nomor Telepon Sponsor\n");
            printf("[5]. Ubah Email Perusahaan Sponsor\n");
            printf("[6]. Ubah Benefit\n");
            printf("[7]. Ubah Status Ketersediaan Sponsor\n");
            printf("[8]. Kembali\n");
            printf("Pilih menu:");
            scanf("%d", &pilihan);

            if (pilihan == 1) {
                printf("Masukkan Nama Perusahaan Sponsor baru:");
                scanf(" %[^\n]", DataBaru.namaPerusahaanSponsor);
                strcpy(Sponsor.namaPerusahaanSponsor, DataBaru.namaPerusahaanSponsor);

                printf("Masukkan Alamat Perusahaan Sponsor baru:");
                scanf(" %[^\n]", DataBaru.alamatPerusahaanSponsor);
                strcpy(Sponsor.alamatPerusahaanSponsor, DataBaru.alamatPerusahaanSponsor);

                printf("Masukkan Nomor Telepon Sponsor baru:");
                scanf(" %[^\n]", DataBaru.noTelpPerusahaanSponsor);
                strcpy(Sponsor.noTelpPerusahaanSponsor, DataBaru.noTelpPerusahaanSponsor);

                printf("Masukkan Email Perusahaan Sponsor baru:");
                scanf(" %[^\n]", DataBaru.emailPerusahaanSponsor);
                strcpy(Sponsor.emailPerusahaanSponsor, DataBaru.emailPerusahaanSponsor);

                printf("Masukkan Benefit baru:");
                scanf(" %[^\n]", DataBaru.benefit);
                strcpy(Sponsor.benefit, DataBaru.benefit);

                printf("Masukkan Status Ketersediaan Sponsor baru (Y: Tersedia, N: Tidak Tersedia):");
                scanf(" %c", &DataBaru.statusKetersediaanSponsor);
                Sponsor.statusKetersediaanSponsor = DataBaru.statusKetersediaanSponsor;

                MessageBox(NULL, "Data Sponsor Berhasil Diubah", "Information", MB_OK | MB_ICONASTERISK);
            } else if (pilihan == 2) {
                printf("Masukkan Nama Perusahaan Sponsor baru:");
                scanf(" %[^\n]", DataBaru.namaPerusahaanSponsor);
                strcpy(Sponsor.namaPerusahaanSponsor, DataBaru.namaPerusahaanSponsor);
                MessageBox(NULL, "Data Sponsor Berhasil Diubah", "Information", MB_OK | MB_ICONASTERISK);
            } else if (pilihan == 3) {
                printf("Masukkan Alamat Perusahaan Sponsor baru:");
                scanf(" %[^\n]", DataBaru.alamatPerusahaanSponsor);
                strcpy(Sponsor.alamatPerusahaanSponsor, DataBaru.alamatPerusahaanSponsor);
                MessageBox(NULL, "Data Sponsor Berhasil Diubah", "Information", MB_OK | MB_ICONASTERISK);
            } else if (pilihan == 4) {
                printf("Masukkan Nomor Telepon Sponsor baru:");
                scanf(" %[^\n]", DataBaru.noTelpPerusahaanSponsor);
                strcpy(Sponsor.noTelpPerusahaanSponsor, DataBaru.noTelpPerusahaanSponsor);
                MessageBox(NULL, "Data Sponsor Berhasil Diubah", "Information", MB_OK | MB_ICONASTERISK);
            } else if (pilihan == 5) {
                printf("Masukkan Email Perusahaan Sponsor baru:");
                scanf(" %[^\n]", DataBaru.emailPerusahaanSponsor);
                strcpy(Sponsor.emailPerusahaanSponsor, DataBaru.emailPerusahaanSponsor);
                MessageBox(NULL, "Data Sponsor Berhasil Diubah", "Information", MB_OK | MB_ICONASTERISK);
            } else if (pilihan == 6) {
                printf("Masukkan Benefit baru:");
                scanf(" %[^\n]", DataBaru.benefit);
                strcpy(Sponsor.benefit, DataBaru.benefit);
                MessageBox(NULL, "Data Sponsor Berhasil Diubah", "Information", MB_OK | MB_ICONASTERISK);
            } else if (pilihan == 7) {
                printf("Masukkan Status Ketersediaan Sponsor baru (Y: Tersedia, N: Tidak Tersedia):");
                scanf(" %c", &DataBaru.statusKetersediaanSponsor);
                Sponsor.statusKetersediaanSponsor = DataBaru.statusKetersediaanSponsor;
                MessageBox(NULL, "Data Sponsor Berhasil Diubah", "Information", MB_OK | MB_ICONASTERISK);
            } else if (pilihan == 8) {
                break;
            } else {
                MessageBox(NULL, "Pilihan Tidak Sesuai", "Error", MB_OK | MB_ICONERROR);
            }
        } while (pilihan != 8);

        fwrite(&Sponsor, sizeof(Sponsor), 1, Temp);
        while (fread(&Sponsor, sizeof(Sponsor), 1, Asal) == 1) {
            fwrite(&Sponsor, sizeof(Sponsor), 1, Temp);
        }

        fclose(Asal);
        fclose(Temp);

        Asal = fopen("Sponsor.dat", "wb");
        Temp = fopen("Temp.dat", "rb");

        while (fread(&Sponsor, sizeof(Sponsor), 1, Temp) == 1) {
            fwrite(&Sponsor, sizeof(Sponsor), 1, Asal);
        }
        fclose(Asal);
        fclose(Temp);
    } else {
        MessageBox(NULL, "Id Sponsor tidak ditemukan di dalam arsip asal", "Error", MB_OK | MB_ICONERROR);
    }
}

void MenghapusData(FILE *Asal, FILE *Temp, int dicari) {
    int ditemukan;
    Asal = fopen("Sponsor.dat", "rb");
    printf("\n");

    printf("Data Sponsor:\n");
    printf("Id\t|Nama Perusahaan\t|Alamat\t\t|No. Telepon\t|Email\t\t|Benefit\t|Status Ketersediaan\n");
    while (fread(&Sponsor, sizeof(Sponsor), 1, Asal) == 1) {
        printf("SPN%d", Sponsor.idPerusahaanSponsor);
        printf("\t|%s", Sponsor.namaPerusahaanSponsor);
        printf("\t\t\t|%s", Sponsor.alamatPerusahaanSponsor);
        printf("\t|%s", Sponsor.noTelpPerusahaanSponsor);
        printf("\t|%s", Sponsor.emailPerusahaanSponsor);
        printf("\t|%s", Sponsor.benefit);
        printf("\t\t|%c\n", Sponsor.statusKetersediaanSponsor);
    }

    fclose(Asal);
    printf("\nMasukkan Id yang ingin dihapus:\tSPN");
    scanf("%d", &dicari);

    Asal = fopen("Sponsor.dat", "rb");
    Temp = fopen("Temp.dat", "wb");

    ditemukan = 0;
    while (ditemukan == 0 && fread(&Sponsor, sizeof(Sponsor), 1, Asal) == 1) {
        if (Sponsor.idPerusahaanSponsor == dicari) {
            ditemukan = 1;
        } else {
            fwrite(&Sponsor, sizeof(Sponsor), 1, Temp);
        }
    }

    if (ditemukan == 1) {
        printf("Data yang dihapus:\n");
        printf("Id\t|Nama Perusahaan\t|Alamat\t\t|No. Telepon\t|Email\t\t|Benefit\t|Status Ketersediaan\n");
        printf("SPN%d", Sponsor.idPerusahaanSponsor);
        printf("\t|%s", Sponsor.namaPerusahaanSponsor);
        printf("\t\t\t|%s", Sponsor.alamatPerusahaanSponsor);
        printf("\t|%s", Sponsor.noTelpPerusahaanSponsor);
        printf("\t|%s", Sponsor.emailPerusahaanSponsor);
        printf("\t|%s", Sponsor.benefit);
        printf("\t\t|%c\n", Sponsor.statusKetersediaanSponsor);

        fclose(Asal);
        fclose(Temp);

        Asal = fopen("Sponsor.dat", "wb");
        Temp = fopen("Temp.dat", "rb");

        while (fread(&Sponsor, sizeof(Sponsor), 1, Temp) == 1) {
            fwrite(&Sponsor, sizeof(Sponsor), 1, Asal);
        }

        fclose(Asal);
        fclose(Temp);
    } else {
        MessageBox(NULL, "Id Sponsor tidak ditemukan di dalam arsip asal", "Error", MB_OK | MB_ICONERROR);
    }
}