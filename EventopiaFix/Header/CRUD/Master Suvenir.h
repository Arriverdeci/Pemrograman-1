void menuSuvenir();
void createSuvenir();
void readSuvenir();
void updateSuvenir();
void deleteSuvenir();

int stoktemp;

void MasterSuvenir () {

    garismenu();
    menuSuvenir();

}

void menuSuvenir() {

    int choose;

    do {
        SetColorBlock(0, 14);
        HapusTengah();
        HapusKanan();
        SpecialkeyloginVertical(MenuMaster, 147, 15, 19, 3, 5, 5, &choose);
        HapusTengah();
        switch (choose) {
            case 1:
                createSuvenir();
                break;
            case 2:
                readSuvenir();
                gotoxy(60, 42); printf("========== ketik apapun untuk melanjutkan ==========");
                getch();
                HapusTengah();
                break;
            case 3:
                updateSuvenir();
                break;
            case 4:
                deleteSuvenir();
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

void createSuvenir() {

    int id;
    int ans;
    int loop = 0;
    int found;
    FILE *SV;
    FILE *SUP;

    SV = fopen("../Dat/Suvenir.dat", "ab+");

    while (fread(&sv, sizeof(sv), 1, SV) == 1) {
        id = sv.id;
        loop++;
    }

    if (loop == 0) {
        sv.id = 1;
    } else {
        sv.id = id + 1;
    }
    fclose(SV);

    gotoxy(32, 15); printf("Masukkan Data Suvenir!");
    gotoxy(32, 18); printf("ID Suvenir      : MERCH%03d", sv.id);
    gotoxy(32, 20); printf("Nama Suvenir    :");
    gotoxy(32, 22); printf("ID Pemasok      : SUP");
    gotoxy(32, 24); printf("Nama Pemasok    :");
    gotoxy(32, 26); printf("Stok Suvenir    :");
    gotoxy(32, 28); printf("Harga Suvenir   : Rp");
    gotoxy(60, 42); printf("========== klik 0 dan ENTER untuk kembali ==========");

    gotoxy(50, 20); getteks(sv.nama, 25);
    if (strcmp(sv.nama, "0") == 0) {
        HapusTengah();
        MasterSuvenir();
    }

    readFKPemasok();

    //input data
    // ID PEMASOK
    found = 0;
    do {
        gotoxy(53, 22); getnum(&sv.idSup, 3);
        if (sv.idSup == 0) {
            MasterSuvenir();
        }

        SUP = fopen("../Dat/Pemasok.dat", "rb");
        while(fread(&sp, sizeof(sp), 1, SUP) == 1) {
            if (sv.idSup == sp.id) {
                strcpy(sv.namaSup, sp.nama);
                found = 1;
            }
        }
        fclose(SUP);

        if (!found) {
            MessageBoxA(NULL,"ID Pemasok tidak tersedia!","ATTENTION",MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(53, 22, 3, 1);
        }
    } while (!found);
    gotoxy(50, 24); printf("%s", sv.namaSup);

    deleteFKPemasok();

    gotoxy(50, 26); getnum(&sv.stok, 1000);
    if (sv.stok == 0) {
        MasterSuvenir();
    }

    gotoxy(53, 28); getRp(&sv.harga, 3, 10, 53, 28);
    if (sv.harga == 0) {
        MasterSuvenir();
    }

    SV = fopen("../Dat/Suvenir.dat", "ab");
    fwrite(&sv, sizeof(sv), 1, SV);
    fclose(SV);

    MessageBox(NULL,"Data Berhasil Ditambahkan!","NOTIFICATION",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);

    do {
        HapusTengah();
        SetColorBlock(0, 14);
        gotoxy(73, 25); printf("Ingin menambah data lagi ?");
        SpecialkeyloginHorizontal(yntengah, 74, 27, 9, 1, 13, 2, &ans);
        HapusTengah();

        switch (ans) {
            case 1:
                HapusTengah();
                createSuvenir();
                break;
            case 2:
                HapusTengah();
                MasterSuvenir();
                break;
        }

    } while (ans == 1);
}

void readMerchTrnsksi () {

    FILE *SV;
    char rp[25];

    SV = fopen("../Dat/Suvenir.dat", "rb");

    if (SV == NULL) {
        MessageBox(NULL, "Data Transaksi tidak ditemukan", "Attention", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
    } else {

        gotoxy(122, 13);
        printf("D A T A  S U V E N I R");

        // border
        for (j = 100; j < 166; j++) {
            gotoprintchar(j, 15, 205);
            gotoprintchar(j, 17, 205);
        }

        gotoxy(102, 16); printf("ID");
        gotoxy(112, 16); printf("NAMA");
        gotoxy(135, 16); printf("ID PEMASOK");
        gotoxy(148, 16);   printf("STOK");
        gotoxy(155, 16);   printf("HARGA");

        i = 18;
        while (fread(&sv, sizeof(sv), 1, SV) == 1) {
            gotoxy(102, i);  printf("MERCH%03d", sv.id);  fflush(stdin);
            gotoxy(112, i);  printf("%s", sv.nama);   fflush(stdin);
            gotoxy(135, i);  printf("SUP%03d", sv.idSup);
            gotoxy(148, i); printf("%d", sv.stok);
            rupiah(sv.harga, rp);
            gotoxy(155, i); printf("Rp %s", rp);
            i++;
        }
    }
    fclose(SV);

}

void readSuvenir() {

    FILE *SV;
    char rp[25];

    SV = fopen("../Dat/Suvenir.dat", "rb");

    if (SV == NULL) {
//        printf("Data tidak ditemukan\n");
    } else {

        gotoxy(75, 13);
        printf("D A T A  S U V E N I R");

        // border
        for (j = 29; j < 143; j++) {
            gotoprintchar(j, 15, 205);
            gotoprintchar(j, 17, 205);
        }

        gotoxy(31, 16); printf("ID SUVENIR");
        gotoxy(43, 16); printf("NAMA SUVENIR");
        gotoxy(73, 16); printf("ID PEMASOK");
        gotoxy(85, 16); printf("NAMA PEMASOK");
        gotoxy(116, 16);   printf("STOK");
        gotoxy(126, 16);   printf("HARGA");

        i = 18;
        while (fread(&sv, sizeof(sv), 1, SV) == 1) {
            gotoxy(31, i);  printf("MERCH%03d", sv.id);  fflush(stdin);
            gotoxy(43, i);  printf("%s", sv.nama);   fflush(stdin);
            gotoxy(73, i);  printf("SUP%03d", sv.idSup);
            gotoxy(85, i);  printf("%s", sv.namaSup);
            gotoxy(116, i); printf("%d", sv.stok);
            rupiah(sv.harga, rp);
            gotoxy(126, i); printf("Rp %s", rp);
            i++;
        }
    }
    fclose(SV);
}

void menuupdatesuvenir () {

    gotoxy(148, 17);  printf("S E M U A   D A T A");
    gotoxy(148, 20);  printf("      N A M A      ");
    gotoxy(148, 22);  printf("   S U V E N I R   ");
    gotoxy(148, 25);  printf("   P E M A S O K   ");
    gotoxy(148, 28);  printf("      S T O K      ");
    gotoxy(148, 30);  printf("   S U V E N I R   ");
    gotoxy(148, 32);  printf("     H A R G A     ");
    gotoxy(148, 34);  printf("   S U V E N I R   ");
    gotoxy(148, 37);  printf("   K E M B A L I   ");

}

void updateSuvenir() {

    FILE *Asal;
    FILE *Temp;
    FILE *SUP;
    int KodeCari;
    int found;
    char rp[25];
    int ans;
    Suvenir NewSv;

    readSuvenir();

    gotoxy(60, 42);
    printf("========== klik 0 dan ENTER untuk kembali ==========");
    Tunggu(5);
    gotoxy(30, i + 3);
    printf("Masukkan ID : MERCH");
    gotoxy(49, i + 3);
    getnummin(&KodeCari, 1, 2);
    if (KodeCari == 0) {
        MasterSuvenir();
    }

    Asal = fopen("../Dat/Suvenir.dat", "rb");
    Temp = fopen("../Dat/Temp.dat", "wb");

    found = 0;
    while (found == 0 && fread(&sv, sizeof(sv), 1, Asal)) {

        if (sv.id == KodeCari) {
            found = 1;
            break;
        } else {
            fwrite(&sv, sizeof(sv), 1, Temp);
        }

    }

    if (found == 1) {
        HapusTengah();
        gotoxy(36, 15); printf("Data suvenir yang ingin di update");
        gotoxy(36, 18); printf("ID Suvenir      : MERCH%03d", sv.id);
        gotoxy(36, 20); printf("Nama Suvenir    : %s", sv.nama);
        gotoxy(36, 22); printf("ID Pemasok      : SUP%03d", sv.idSup);
        gotoxy(36, 24); printf("Nama Pemasok    : %s", sv.namaSup);
        gotoxy(36, 26); printf("Stok Suvenir    : %d", sv.stok);
        rupiah(sv.harga, rp);
        gotoxy(36, 28); printf("Harga Suvenir   : Rp %s", rp);

        gotoxy(71, 39);
        printf("Ingin mengubah data suvenir ?");
        SpecialkeyloginHorizontal(YN, 74, 40, 9, 1, 13, 2, &ans);

        switch (ans) {
            case 1:
                HapusTengah();
                gotoxy(65, 13);
                printf("========== Data yang ingin diupdate =========");

                // border
                for (j = 29; j < 143; j++) {
                    gotoprintchar(j, 15, 205);
                    gotoprintchar(j, 17, 205);
                }

                gotoxy(31, 16); printf("ID");
                gotoxy(46, 16); printf("NAMA");
                gotoxy(76, 16); printf("ID PEMASOK");
                gotoxy(91, 16); printf("NAMA PEMASOK");
                gotoxy(121, 16);    printf("STOK");
                gotoxy(131, 16);    printf("HARGA");

                gotoxy(31, 18); printf("MERCH%03d", sv.id);
                gotoxy(46, 18); printf("%s", sv.nama);
                gotoxy(76, 18); printf("SUP%03d", sv.idSup);
                gotoxy(91, 18); printf("%s", sv.namaSup);
                gotoxy(121, 18);    printf("%d", sv.stok);
                rupiah(sv.harga, rp);
                gotoxy(131, 18);    printf("Rp %s", rp);

                int updt;
                HapusKanan();
                SpecialkeyloginVertical(menuupdatesuvenir, 147, 15, 19, 3, 4, 6, &updt);
                switch (updt) {
                    case 1:
                        i = 25;
                        gotoxy(36, i);
                        printf("ID Suvenir      : MERCH%03d", sv.id);
                        gotoxy(36, i + 2);
                        printf("Nama Suvenir    :");
                        gotoxy(36, i + 4);
                        printf("ID Pemasok      : SUP");
                        gotoxy(36, i + 6);
                        printf("Nama Pemasok    :");
                        gotoxy(36, i + 8);
                        printf("Stok Suvenir    :");
                        rupiah(sv.harga, rp);
                        gotoxy(36, i + 10);
                        printf("Harga Suvenir   : Rp");

                        gotoxy(54, i + 2);
                        getteks(NewSv.nama, 30);
                        if (strcmp(NewSv.nama, "0") == 0) {
                            HapusTengah();
                            MasterSuvenir();
                        }
                        strcpy(sv.nama, NewSv.nama);

                        // ID PEMASOK
                        found = 0;
                        do {
                            gotoxy(57, i + 4);
                            getnum(&NewSv.idSup, 3);
                            if (NewSv.idSup == 0) {
                                HapusTengah();
                                MasterSuvenir();
                            }

                            SUP = fopen("../Dat/Pemasok.dat", "rb");
                            while (fread(&sp, sizeof(sp), 1, SUP) == 1) {
                                if (NewSv.idSup == sp.id) {
                                    strcpy(NewSv.namaSup, sp.nama);
                                    found = 1;
                                }
                            }
                            fclose(SUP);

                            if (!found) {
                                MessageBoxA(NULL, "ID Pemasok tidak tersedia!", "ATTENTION",MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
                                clearArea(57, 33, 3, 1);
                            }
                        } while (!found);

                        gotoxy(54, i + 6);
                        printf("%s", NewSv.namaSup);
                        sv.idSup = NewSv.idSup;
                        strcpy(sv.namaSup, NewSv.namaSup);

                        gotoxy(54, i + 8);
                        getnum(&NewSv.stok, 1000);
                        if (NewSv.stok == 0) {
                            HapusTengah();
                            MasterSuvenir();
                        }
                        sv.stok = NewSv.stok;

                        gotoxy(57, i + 10);
                        getRp(&NewSv.harga, 6, 10, 57, i + 10);
                        sv.harga = NewSv.harga;
                        break;
                    case 2:
                        i = 25;
                        gotoxy(36, i);      printf("ID Suvenir      : MERCH%03d", sv.id);
                        gotoxy(36, i + 2);  printf("Nama Suvenir    :");
                        gotoxy(54, i + 2);  getteks(NewSv.nama, 30);
                        if (strcmp(NewSv.nama, "0") == 0) {
                            HapusTengah();
                            MasterSuvenir();
                        }
                        strcpy(sv.nama, NewSv.nama);
                        break;
                    case 3:
                        i = 25;
                        gotoxy(36, i);  printf("ID Suvenir      : MERCH%03d", sv.id);
                        gotoxy(36, i + 2);
                        printf("ID Pemasok      : SUP");
                        gotoxy(36, i + 4);
                        printf("Nama Pemasok    :");
                        // ID PEMASOK
                        found = 0;
                        do {
                            gotoxy(57, i + 2);
                            getnum(&NewSv.idSup, 3);
                            if (NewSv.idSup == 0) {
                                HapusTengah();
                                MasterSuvenir();
                            }

                            SUP = fopen("../Dat/Pemasok.dat", "rb");
                            while (fread(&sp, sizeof(sp), 1, SUP) == 1) {
                                if (NewSv.idSup == sp.id) {
                                    strcpy(NewSv.namaSup, sp.nama);
                                    found = 1;
                                }
                            }
                            fclose(SUP);

                            if (!found) {
                                MessageBoxA(NULL, "ID Pemasok tidak tersedia!", "ATTENTION",
                                            MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
                                clearArea(57, i + 4, 3, 1);
                            }
                        } while (!found);

                        gotoxy(54, i + 4);
                        printf("%s", NewSv.namaSup);
                        sv.idSup = NewSv.idSup;
                        strcpy(sv.namaSup, NewSv.namaSup);
                        break;
                    case 4:
                        i = 25;
                        gotoxy(36, i);      printf("ID Suvenir      : MERCH%03d", sv.id);
                        gotoxy(36, i + 2);  printf("Stok Suvenir    :");
                        gotoxy(54, i + 2);  getnum(&NewSv.stok, 3);
                        if (NewSv.stok == 0) {
                            HapusTengah();
                            MasterSuvenir();
                        }
                        sv.stok = NewSv.stok;
                        break;
                    case 5:
                        i = 25;
                        gotoxy(36, i);      printf("ID Suvenir      : MERCH%03d", sv.id);
                        gotoxy(36, i + 2);  printf("Harga Suvenir   : Rp");
                        gotoxy(57, i + 2);  getRp(&NewSv.harga, 1, 10, 57, i + 2);
                        if (NewSv.harga == 0) {
                            HapusTengah();
                            MasterSuvenir();
                        }
                        sv.harga = NewSv.harga;
                        break;
                    case 6:
                        HapusKanan();
                        menuJasa();
                        break;
                }

                fwrite(&sv, sizeof(sv), 1, Temp);
                while (fread(&sv, sizeof(sv), 1, Asal) == 1) {
                    fwrite(&sv, sizeof(sv), 1, Temp);
                }

                MessageBox(NULL, "Data Berhasil Diupdate!", "NOTIFICATION",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                break;
            case 2:
                HapusTengah();
                fwrite(&sv, sizeof(sv), 1, Temp);

                while (fread(&sv, sizeof(sv), 1, Asal) == 1) {
                    fwrite(&sv, sizeof(sv), 1, Temp);
                }
                break;
        }

        fclose(Asal);
        fclose(Temp);

        remove("../Dat/Suvenir.dat");
        rename("../Dat/Temp.dat", "../Dat/Suvenir.dat");

        int answ;
        do {
            HapusTengah();
            gotoxy(73, 25);
            printf("Ingin mengubah data lain?");
            SpecialkeyloginHorizontal(yntengah, 74, 27, 9, 1, 13, 2, &answ);
            HapusTengah();
            HapusKanan();
            switch (answ) {
                case 1:
                    updateSuvenir();
                    break;
                case 2:
                    MasterSuvenir();
                    break;
            }
        } while (answ == 1);


    } else {
        MessageBox(NULL, "ID Suvenir tidak ditemukan!", "NOTIFICATION", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        HapusTengah();
        updateSuvenir();
    }
}

void deleteSuvenir () {

    FILE *Asal;
    int KodeCari;
    int ketemu;
    FILE *Temp;
    char rp[25];
    int ans = 0;

    readSuvenir();

    gotoxy(60, 42); printf("========== klik 0 dan ENTER untuk kembali ==========");
    Tunggu(5);
    gotoxy(30, i + 3);
    printf("Masukkan ID : MERCH");
    gotoxy(49, i + 3);
    getnummin(&KodeCari, 1, 3);
    if (KodeCari == 0) {
        HapusTengah();
        MasterSuvenir();
    }

    Asal = fopen("../Dat/Suvenir.dat", "rb");
    Temp = fopen("../Dat/Temp.dat", "wb");

    ketemu = 0;
    while (!ketemu && fread(&sv, sizeof(sv), 1, Asal) == 1) {
        if (sv.id == KodeCari){
            ketemu = 1;
        } else {
            fwrite(&sv, sizeof(sv), 1, Temp);
        }
    }

    if (ketemu == 1) {
        HapusTengah();
        gotoxy(36, 15); printf("Data jasa yang ingin dihapus");

        gotoxy(36, 18); printf("ID Suvenir      : MERCH%03d", sv.id);
        gotoxy(36, 20); printf("Nama Suvenir    : %s", sv.nama);
        gotoxy(36, 22); printf("ID Pemasok      : SUP%03d", sv.idSup);
        gotoxy(36, 24); printf("Nama Pemasok    : %s", sv.namaSup);
        gotoxy(36, 26); printf("Stok Suvenir    : %d", sv.stok);
        rupiah(sv.harga, rp);
        gotoxy(36, 28); printf("Harga Suvenir   : Rp %s", rp);

        gotoxy(72, 39); printf("Ingin menghapus data suvenir?");
        SpecialkeyloginHorizontal(YN, 74, 40, 9, 1, 13, 2, &ans);
        switch (ans) {
            case 1:
                while (fread(&sv, sizeof(sv), 1, Asal) == 1) {
                    fwrite(&sv, sizeof(sv), 1, Temp);
                }

                MessageBox(NULL, "Data Berhasil Dihapus", "NOTIFICATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                break;
            case 2:
                fwrite(&sv, sizeof(sv), 1, Temp);

                while (fread(&sv, sizeof(sv), 1, Asal) == 1) {
                    fwrite(&sv, sizeof(sv), 1, Temp);
                }
                break;
        }

        fclose(Asal);
        fclose(Temp);

        remove("../Dat/Suvenir.dat");
        rename("../Dat/Temp.dat", "../Dat/Suvenir.dat");

        int answ;
        do {
            HapusTengah();
            gotoxy(73, 25);  printf("Ingin menghapus data lain ?");
            SpecialkeyloginHorizontal(yntengah, 74, 27, 9, 1, 13, 2, &answ);
            HapusTengah();
            switch (answ) {
                case 1:
                    deleteSuvenir();
                    break;
                case 2:
                    MasterSuvenir();
                    break;
            }
        } while (answ == 1);

    } else {
        MessageBox(NULL, "ID Suvenir tidak ditemukan!", "NOTIFICATION", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        HapusTengah();
        deleteSuvenir();
    }

}