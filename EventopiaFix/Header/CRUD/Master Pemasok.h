void menuPemasok ();
void createPemasok ();
void readPemasok ();
void updatePemasok ();
void deletePemasok();

void MasterPemasok () {

    garismenu();
    menuPemasok();

}

void menuPemasok () {

    int choose;

    do {
        SetColorBlock(0, 14);
        HapusTengah();
        HapusKanan();
        SpecialkeyloginVertical(MenuMaster, 147, 15, 19, 3, 5, 5, &choose);
        HapusTengah();
        switch (choose) {
            case 1:
                createPemasok();
                break;
            case 2:
                readPemasok();
                gotoxy(60, 42); printf("========== ketik apapun untuk melanjutkan ==========");
                getch();
                HapusTengah();
                break;
            case 3:
                updatePemasok();
                break;
            case 4:
                deletePemasok();
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

void createPemasok() {

    int id;
    int loop = 0;
    int tambah;
    FILE *SUP;

    SetColorBlock(0, 14);
    SUP = fopen("../Dat/Pemasok.dat", "ab+");
    while (fread(&sp, sizeof(sp), 1, SUP) == 1) {
        id = sp.id;
        loop++;
    }

    if (loop == 0) {
        sp.id = 1;
    } else {
        sp.id = id + 1;
    }
    fclose(SUP);

    gotoxy(37, 15); printf("Masukkan Data Pemasok!");
    gotoxy(37, 18); printf("ID Pemasok      : SUP%03d", sp.id);
    gotoxy(37, 20); printf("Nama Pemasok    :");
    gotoxy(37, 22); printf("Kategori        :");
    gotoxy(37, 24); printf("No Telp Pemasok :");
    gotoxy(60, 42); printf("========== klik 0 dan ENTER untuk kembali ==========");

    // input data
    gotoxy(55, 20); getletter(sp.nama, 25);
    gotoxy(55, 22); getletter(sp.kategori, 30);
    gotoxy(55, 24); getteksnum(sp.notelp, 15);
    if (strcmp(sp.notelp, "0") == 0) {
        MasterPemasok();
    }

    SUP = fopen("../Dat/Pemasok.dat", "ab");
    fwrite(&sp, sizeof(sp), 1, SUP);
    fclose(SUP);

    MessageBox(NULL, "Data Pemasok Berhasil Ditambahkan", "Information", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);

    do {
        HapusTengah();
        SetColorBlock(0, 14);
        gotoxy(73, 25); printf("Ingin menambah data lagi ?");
        SpecialkeyloginHorizontal(yntengah, 74, 27, 9, 1, 13, 2, &tambah);
        HapusTengah();

        switch (tambah) {
            case 1:
                HapusTengah();
                createPemasok();
                break;
            case 2:
                HapusTengah();
                MasterPemasok();
                break;
        }

    } while (tambah == 1);
}

void readFKPemasok () {

    SetColorBlock(0, 0);
    // garis berdiri kanan
    for ( i = 12; i < 40; i++) {
        for ( j = 75; j < 77; j++) {
            gotoprintchar(j, i, 32);
        }
    }

    FILE *SUP;
    SUP = fopen("../Dat/Pemasok.dat", "rb");
    SetColorBlock(0, 14);

    if (SUP == NULL) {
//        printf("Data Pemasok tidak ditemukan\n");
    } else {
        gotoxy(90, 13);
        printf("D A T A  P E M A S O K");


        // border
        for (j = 79; j < 143; j++) {
            gotoprintchar(j, 15, 205);
            gotoprintchar(j, 17, 205);
        }

        gotoxy(81, 16);
        printf("ID");
        gotoxy(91, 16);
        printf("NAMA");
        gotoxy(114, 16);
        printf("KATEGORI");

        i = 18;
        while (fread(&sp, sizeof(sp), 1, SUP) == 1) {
            gotoxy(81, i);
            printf("SUP%03d", sp.id);
            fflush(stdin);
            gotoxy(91, i);
            printf("%s", sp.nama);
            fflush(stdin);
            gotoxy(114, i);
            printf("%s", sp.kategori);
            i++;
        }
    }

    fclose(SUP);

}

void deleteFKPemasok() {

    SetColorBlock(0, 14);
    for ( i = 12; i < 40; i++) {
        for ( j = 75; j < 77; j++) {
            gotoprintchar(j, i, 32);
        }
    }

    clearArea(77, 12, 68, 27);

}

void readPemasok () {

    FILE *SUP;

    SUP = fopen("../Dat/Pemasok.dat", "rb");

    if (SUP == NULL) {
//        printf("Data Pemasok tidak ditemukan\n");
    } else {
        gotoxy(75, 13);
        printf("D A T A  P E M A S O K");

        // border
        for (j = 29; j < 143; j++) {
            gotoprintchar(j, 15, 205);
            gotoprintchar(j, 17, 205);
        }

        gotoxy(34, 16);
        printf("ID");
        gotoxy(54, 16);
        printf("NAMA");
        gotoxy(88, 16);
        printf("KATEGORI");
        gotoxy(123, 16);
        printf("NO TELP");

        i = 18;
        while (fread(&sp, sizeof(sp), 1, SUP) == 1) {
            gotoxy(34, i);
            printf("SUP%03d", sp.id);
            fflush(stdin);
            gotoxy(54, i);
            printf("%s", sp.nama);
            fflush(stdin);
            gotoxy(88, i);
            printf("%s", sp.kategori);
            gotoxy(123, i);
            printf("%s", sp.notelp);
            fflush(stdin);
            i++;
        }
    }

    fclose(SUP);
}

void menuupdatepemasok () {

    gotoxy(149, 16);  printf("    S E M U A    ");
    gotoxy(149, 18);  printf("     D A T A     ");
    gotoxy(149, 21);  printf("     N A M A     ");
    gotoxy(149, 23);  printf("  P E M A S O K  ");
    gotoxy(149, 26);  printf(" K A T E G O R I ");
    gotoxy(149, 28);  printf("  P E M A S O K  ");
    gotoxy(149, 31);  printf("  N O   T E L P  ");
    gotoxy(149, 33);  printf("  P E M A S O K  ");
    gotoxy(149, 37);  printf("  K E M B A L I  ");

}

void updatePemasok() {

    FILE *Asal;
    FILE *Temp;
    int KodeCari;
    int ans;
    int found;
    Pemasok NewSp;

    readPemasok();

    gotoxy(60, 42); printf("========== klik 0 dan ENTER untuk kembali ==========");
    Tunggu(5);
    gotoxy(30, i + 3);  printf("Masukkan ID : SUP");
    gotoxy(47, i + 3);  getnummin(&KodeCari, 1, 2);
    if (KodeCari == 0) {
        MasterPemasok();
    }

    Asal = fopen("../Dat/Pemasok.dat", "rb");
    Temp = fopen("../Dat/Temp.dat", "wb");

    found = 0;
    while (found == 0 && fread(&sp, sizeof(sp), 1, Asal)) {

        if (sp.id == KodeCari) {
            found = 1;
        } else {
            fwrite(&sp, sizeof(sp), 1, Temp);
        }

    }

    if (found == 1) {
        HapusTengah();
        gotoxy(36, 15); printf("Data pemasok yang ingin di update");
        gotoxy(36, 18); printf("ID Pemasok          : SUP%03d", sp.id);
        gotoxy(36, 20); printf("Nama Pemasok        : %s", sp.nama);
        gotoxy(36, 22); printf("Kategori Pemasok    : %s", sp.kategori);
        gotoxy(36, 24); printf("No Telp Pemasok     : %s", sp.notelp);

        gotoxy(73, 39); printf("Ingin mengubah data jasa?");
        SpecialkeyloginHorizontal(YN, 74, 40, 9, 1, 13, 2, &ans);

        switch (ans) {
            case 1:
                HapusTengah();
                gotoxy(65, 13);
                printf("========== Data yang ingin diupdate =========");

                // border
                for(j = 29; j < 143; j++) {
                    gotoprintchar(j, 15, 205);
                    gotoprintchar(j, 17, 205);
                }

                gotoxy(39, 16);     printf("ID");
                gotoxy(54, 16);     printf("NAMA");
                gotoxy(84, 16);     printf("KATEGORI");
                gotoxy(114, 16);    printf("NO TELP");

                gotoxy(39, 18); printf("SUP%03d", sp.id);
                gotoxy(54, 18); printf("%s", sp.nama);
                gotoxy(84, 18); printf("%s", sp.kategori);
                gotoxy(114, 18);    printf("%s", sp.notelp);

                int updt;
                HapusKanan();
                SpecialkeyloginVertical(menuupdatepemasok, 147, 15, 19, 3, 5, 5, &updt);
                switch (updt) {
                    case 1:
                        i = 25;
                        gotoxy(36, i);      printf("ID Pemasok          : SUP%03d", jasa.id);
                        gotoxy(36, i + 2);  printf("Nama Pemasok        :");
                        gotoxy(36, i + 4);  printf("Kategori Pemasok    :");
                        gotoxy(36, i + 6);  printf("No Telp Pemasok     :");

                        gotoxy(58, i + 2);  getletter(NewSp.nama, 30);
                        strcpy(sp.nama, NewSp.nama);
                        gotoxy(58, i + 4);  getletter(NewSp.kategori, 30);
                        strcpy(sp.kategori, NewSp.kategori);
                        gotoxy(58, i + 6);  getteksnum(NewSp.notelp, 15);
                        strcpy(sp.notelp, NewSp.notelp);
                        break;
                    case 2:
                        i = 25;
                        gotoxy(36, i);      printf("ID Pemasok      : SUP%03d", sp.id);
                        gotoxy(36, i + 2);  printf("Nama Pemasok    : ");
                        gotoxy(54, i + 2);  getletter(NewSp.nama, 30);
                        strcpy(sp.nama, NewSp.nama);
                        break;
                    case 3:
                        i = 25;
                        gotoxy(36, i);      printf("ID Pemasok          : SUP%03d", sp.id);
                        gotoxy(36, i + 2);  printf("Kategori Pemasok    :");
                        gotoxy(58, i + 2);  getletter(NewSp.kategori, 30);
                        strcpy(sp.kategori, NewSp.kategori);
                        break;
                    case 4:
                        i = 25;
                        gotoxy(36, i);      printf("ID Pemasok      : SUP%03d", sp.id);
                        gotoxy(36, i + 2);  printf("No Telp Pemasok :");
                        gotoxy(54, i + 2);  getteksnum(NewSp.notelp, 15);
                        strcpy(sp.notelp, NewSp.notelp);
                    case 5:
                        HapusKanan();
                        menuJasa();
                        break;
                }

                fwrite(&sp, sizeof(sp), 1, Temp);
                while (fread(&sp, sizeof(sp), 1, Asal) == 1) {
                    fwrite(&sp, sizeof(sp), 1, Temp);
                }

                MessageBox(NULL, "Data Berhasil Diupdate!", "NOTIFICATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                break;
            case 2:
                HapusTengah();
                fwrite(&sp, sizeof(sp), 1, Temp);

                while (fread(&sp, sizeof(sp), 1, Asal) == 1) {
                    fwrite(&sp, sizeof(sp), 1, Temp);
                }
                break;
        }

        fclose(Asal);
        fclose(Temp);

        remove("../Dat/Pemasok.dat");
        rename("../Dat/Temp.dat", "../Dat/Pemasok.dat");

        int answ;
        do {
            HapusTengah();
            gotoxy(73, 25);  printf("Ingin mengubah data lain?");
            SpecialkeyloginHorizontal(yntengah, 74, 27, 9, 1, 13, 2, &answ);
            HapusTengah();
            HapusKanan();
            switch (answ) {
                case 1:
                    updatePemasok();
                    break;
                case 2:
                    MasterPemasok();
                    break;
            }
        } while (answ == 1);


    } else {
        MessageBox(NULL, "ID Pemasok tidak ditemukan!", "NOTIFICATION", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        HapusTengah();
        updatePemasok();
    }
}

void deletePemasok () {

    FILE *Asal;
    FILE *Temp;
    int KodeCari;
    int ketemu;
    int ans = 0;

    readPemasok();

    gotoxy(60, 42); printf("========== klik 0 dan ENTER untuk kembali ==========");
    Tunggu(5);
    gotoxy(30, i + 3);
    printf("Masukkan ID : SUP");
    gotoxy(47, i + 3);
    getnummin(&KodeCari, 1, 3);
    if (KodeCari == 0) {
        MasterPemasok();
    }

    Asal = fopen("../Dat/Pemasok.dat", "rb");
    Temp = fopen("../Dat/Temp.dat", "wb");

    ketemu = 0;
    while (!ketemu && fread(&sp, sizeof(sp), 1, Asal) == 1) {
        if (sp.id == KodeCari){
            ketemu = 1;
        } else {
            fwrite(&sp, sizeof(sp), 1, Temp);
        }
    }

    if (ketemu == 1) {
        HapusTengah();
        gotoxy(36, 15); printf("Data pemasok yang ingin dihapus");
        gotoxy(36, 18); printf("ID Pemasok          : SUP%03d", sp.id);
        gotoxy(36, 20); printf("Nama Pemasok        : %s", sp.nama);
        gotoxy(36, 22); printf("Kategori Pemasok    : %s", sp.kategori);
        gotoxy(36, 24); printf("No Telp Pemasok     : %s", sp.notelp);

        gotoxy(72, 39); printf("Ingin menghapus data pemasok?");
        SpecialkeyloginHorizontal(YN, 74, 40, 9, 1, 13, 2, &ans);
        switch (ans) {
            case 1:
                while (fread(&sp, sizeof(sp), 1, Asal) == 1) {
                    fwrite(&sp, sizeof(sp), 1, Temp);
                }

                MessageBox(NULL, "Data Berhasil Dihapus", "Notification", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                break;
            case 2:
                fwrite(&sp, sizeof(sp), 1, Temp);

                while (fread(&sp, sizeof(sp), 1, Asal) == 1) {
                    fwrite(&sp, sizeof(sp), 1, Temp);
                }
                break;
        }

        fclose(Asal);
        fclose(Temp);

        remove("../Dat/Pemasok.dat");
        rename("../Dat/Temp.dat", "../Dat/Pemasok.dat");

        int answ;
        do {
            HapusTengah();
            gotoxy(73, 25);  printf("Ingin menghapus data lain ?");
            SpecialkeyloginHorizontal(yntengah, 74, 27, 9, 1, 13, 2, &answ);
            HapusTengah();
            switch (answ) {
                case 1:
                    deletePemasok();
                    break;
                case 2:
                    MasterPemasok();
                    break;
            }
        } while (answ == 1);

    } else {
        MessageBox(NULL, "ID Pemasok tidak ditemukan!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        HapusTengah();
        deletePemasok();
    }
}