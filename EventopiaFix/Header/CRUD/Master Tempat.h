void menuTempat ();
void createTempat ();
void readTempat ();
void menuUpdate ();
void updateTempat ();
void deleteTempat ();
void SalinArsipTempkeAsal (FILE *Temp, FILE *Asal);

void Terimakasih ();
void Keluar ();

//int ROLES;
void MenuAdmin();
void MenuEO();
void MenuManajer();
void MenuPemasaran();

void MasterTempat () {

    garismenu();
    menuTempat();

}

void menuTempat () {

    int pilih;

    SetColorBlock(0, 14);
    while(1){
        HapusKanan();
        SpecialkeyloginVertical(MenuMaster, 147, 15, 19, 3, 5, 5, &pilih);
        switch (pilih) {
            case 1:
                createTempat();
                break;
            case 2:
                readTempat();
                gotoxy(60, 42); printf("========== ketik apapun untuk melanjutkan ==========");
                getch();
                HapusTengah();
                break;
            case 3:
                updateTempat();
                break;
            case 4:
                deleteTempat();
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
    }

}

char STATUSVEN [5][20] = {"Tersedia", "Tidak Tersedia"};

void createTempat () {

    int id;
    int loop = 0;
    char ans;
    FILE *tmpt;

//    HapusKiri();

    // auto increment
    tmpt = fopen("../Dat/Master Tempat.dat","ab+"); /* buka file user untuk dibaca */
    while (fread(&tempat, sizeof(tempat),1,tmpt) == 1){
        id = tempat.id;
        loop++;
    }
    if (loop == 0) {
        tempat.id = 1;
    } else {
        tempat.id = id + 1; /* id otomatis */
    }
    fclose(tmpt);

    gotoxy(37, 15); printf("Masukkan Data Tempat!");
    gotoxy(37, 18); printf("ID Tempat           : VEN%03d", tempat.id);
    gotoxy(37, 20); printf("Nama Tempat         :");
    gotoxy(37, 22); printf("Alamat Tempat       :");
    gotoxy(37, 24); printf("Kapasitas Tempat    :");
    gotoxy(37, 26); printf("Harga Tempat        : Rp");
    gotoxy(37, 28); printf("Status Ketersediaan : (gunakan Key Up/Down untuk memilih)");

    // input data
    gotoxy(59, 20); getletter(tempat.nama, 25);
    gotoxy(59, 22); getteks(tempat.alamat, 50);
    if(strcmp(tempat.alamat, "0") == 0) {
        HapusTengah();
        MasterTempat();
    }
    gotoxy(59, 24); getnum(&tempat.kapasitas, 15);
    if(tempat.kapasitas == 0) {
        HapusTengah();
        MasterTempat();
    }
    gotoxy(62, 26); getRp(&tempat.harga, 1, 15, 62, 26);
    if (tempat.harga == 0) {
        HapusTengah();
        MasterTempat();
    }
    clearArea(59, 28, 40, 1);
    Pilihan(59, 28, 15, tempat.status, 1, STATUSVEN);

    // input ke file
    tmpt = fopen("../Dat/Master Tempat.dat", "ab");
    fwrite(&tempat, sizeof(tempat), 1, tmpt);
    fclose(tmpt);

    MessageBox(NULL, "Data Berhasil Ditambahkan!", "NOTIFICATION", MB_OK | MB_DEFAULT_DESKTOP_ONLY);

    while(1) {
        HapusTengah();
        SetColorBlock(0, 14);
        gotoxy(73, 25); printf("Ingin menambah data lagi ?");
        SpecialkeyloginHorizontal(yntengah, 74, 27, 9, 1, 13, 2, &ans);
        HapusTengah();

        switch (ans) {
            case 1:
                HapusTengah();
                createTempat();
                break;
            case 2:
                HapusTengah();
                MasterTempat();
                break;
        }
    }

}

void readTempat () {

    FILE *tmpt;

    tmpt = fopen("../Dat/Master Tempat.dat", "rb");

    if (tmpt == NULL) {
        MessageBox(NULL, "Data Transaksi tidak ditemukan", "Attention", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
    } else {
        gotoxy(76, 13);
        printf("D A T A  T E M P A T");

        // border
        for(j = 29; j < 143; j++) {
            gotoprintchar(j, 15, 205);
            gotoprintchar(j, 17, 205);
        }

        gotoxy(31, 16);     printf("ID");
        gotoxy(41, 16);     printf("NAMA");
        gotoxy(66, 16);     printf("ALAMAT");
        gotoxy(91, 16);    printf("KAPASITAS");
        gotoxy(106, 16);    printf("HARGA");
        gotoxy(127, 16);    printf("STATUS");

        i = 18;
        while (fread(&tempat, sizeof(tempat), 1, tmpt) == 1) {
            gotoxy(31, i);  printf("VEN%03d", tempat.id);
            gotoxy(41, i);  printf("%s", tempat.nama);
            gotoxy(66, i);  printf("%s", tempat.alamat);
            gotoxy(91, i); printf("%d", tempat.kapasitas);
            strcpy(rp, "0");
            rupiah(tempat.harga, rp);
            gotoxy(106, i); printf("Rp %s", rp);
            gotoxy(127, i); printf("%s", tempat.status);
            i++;
        }
    }

    fclose(tmpt);

}

void menuupdatetempat () {

    gotoxy(148, 15);    printf("S E M U A   D A T A");
    gotoxy(148, 18);    printf("      N A M A      ");
    gotoxy(148, 20);    printf("    T E M P A T    ");
    gotoxy(148, 22);    printf("    A L A M A T    ");
    gotoxy(148, 24);    printf("    T E M P A T    ");
    gotoxy(148, 26);    printf(" K A P A S I T A S ");
    gotoxy(148, 28);    printf("    T E M P A T    ");
    gotoxy(148, 30);    printf("     H A R G A     ");
    gotoxy(148, 32);    printf("    T E M P A T    ");
    gotoxy(148, 34);    printf("    S T A T U S    ");
    gotoxy(148, 36);    printf("    T E M P A T    ");
    gotoxy(148, 39);    printf("   K E M B A L I   ");

}

void updateTempat () {

    FILE *Asal;
    FILE *Temp;
    int KodeCari;
    int ans;
    Tempat NewTmpt;

    readTempat();

    gotoxy(60, 42);
    printf("========== klik 0 dan ENTER untuk kembali ==========");
    Tunggu(5);
    gotoxy(32, i + 3);  printf("Masukkan ID : VEN");
    gotoxy(49, i + 3);  getnum(&KodeCari, 3);
    if(KodeCari == 0) {
        HapusTengah();
        MasterTempat();
    }

    Asal = fopen("../Dat/Master Tempat.dat", "rb");
    Temp = fopen("../Dat/Temp.dat", "wb");

    found = 0;
    while (found == 0 && fread(&tempat, sizeof(tempat), 1, Asal) == 1) {

        if (tempat.id == KodeCari) {
            found = 1;
            break;
        } else {
            fwrite(&tempat, sizeof(tempat), 1, Temp);
        }
    }

    if (found == 1) {
        HapusTengah();
        gotoxy(36, 15); printf("Data tempat yang ingin di update");
        gotoxy(36, 18); printf("ID Tempat           : VEN%03d", tempat.id);
        gotoxy(36, 20); printf("Nama Tempat         : %s", tempat.nama);
        gotoxy(36, 22); printf("Alamat Tempat       : %s", tempat.alamat);
        gotoxy(36, 24); printf("Kapasitas Tempat    : %d", tempat.kapasitas);
        strcpy(rp, "0");
        rupiah(tempat.harga, rp);
        gotoxy(36, 26); printf("Harga Tempat        : Rp %s", rp);
        gotoxy(36, 28); printf("Status Tempat       : %s", tempat.status);

        gotoxy(72, 39); printf("Ingin mengubah data tempat?");
        ans = 0;
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

                gotoxy(31, 16);     printf("ID");
                gotoxy(41, 16);     printf("NAMA");
                gotoxy(66, 16);     printf("ALAMAT");
                gotoxy(91, 16);    printf("KAPASITAS");
                gotoxy(106, 16);    printf("HARGA");
                gotoxy(127, 16);    printf("STATUS");

                gotoxy(31, 18);  printf("VEN%03d", tempat.id);
                gotoxy(41, 18);  printf("%s", tempat.nama);
                gotoxy(66, 18);  printf("%s", tempat.alamat);
                gotoxy(91, 18); printf("%d", tempat.kapasitas);
                strcpy(rp, "0");
                rupiah(tempat.harga, rp);
                gotoxy(106, 18); printf("Rp %s", rp);
                gotoxy(127, 18); printf("%s", tempat.status);

                updt = 0;
                HapusKanan();
                SpecialkeyloginVertical(menuupdatetempat, 147, 13, 19, 3, 4, 7, &updt);
                i = 25;
                switch (updt) {
                    case 1:
                        gotoxy(36, i);      printf("ID Tempat           : VEN%03d", tempat.id);
                        gotoxy(36, i + 2);  printf("Nama Tempat         :");
                        gotoxy(36, i + 4);  printf("Alamat Tempat       :");
                        gotoxy(36, i + 6);  printf("Kapasitas Tempat    :");
                        gotoxy(36, i + 8);  printf("Harga Tempat        : Rp");
                        gotoxy(36, i + 10); printf("Status Tempat       :");

                        gotoxy(58, i + 2);  getletter(NewTmpt.nama, 25);
                        strcpy(tempat.nama, NewTmpt.nama);
                        gotoxy(58, i + 4);  getteks(NewTmpt.alamat, 50);
                        if(strcmp(NewTmpt.alamat, "0") == 0) {
                            MasterTempat();
                        }
                        strcpy(tempat.alamat, NewTmpt.alamat);
                        gotoxy(58, i + 6);  getnum(&NewTmpt.kapasitas, 10);
                        if(NewTmpt.kapasitas == 0) {
                            MasterTempat();
                        }
                        tempat.kapasitas = NewTmpt.kapasitas;
                        gotoxy(61, i + 8);  getRp(&NewTmpt.harga, 1, 25, 61, i + 8);
                        if(NewTmpt.harga == 0) {
                            MasterTempat();
                        }
                        tempat.harga = NewTmpt.harga;
                        clearArea(58, i + 10, 25, 1);
                        Pilihan(58, i + 10, 15, NewTmpt.status, 1, STATUSVEN);
                        strcpy(tempat.status, NewTmpt.status);
                        break;
                    case 2:
//                        i = 25;
                        gotoxy(36, i);      printf("ID Tempat   : VEN%03d", tempat.id);
                        gotoxy(36, i + 2);  printf("Nama Tempat :");

                        gotoxy(50, i + 2);  getletter(NewTmpt.nama, 25);
                        strcpy(tempat.nama, NewTmpt.nama);
                        break;
                    case 3:
//                        i = 25;
                        gotoxy(36, i);      printf("ID Tempat       : VEN%03d", tempat.id);
                        gotoxy(36, i + 2);  printf("Alamat Tempat   :");

                        gotoxy(54, i + 2);  getteks(NewTmpt.alamat, 50);
                        if(strcmp(NewTmpt.alamat, "0") == 0) {
                            MasterTempat();
                        }
                        strcpy(tempat.alamat, NewTmpt.alamat);
                        break;
                    case 4:
//                        i = 25;
                        gotoxy(36, i);      printf("ID Tempat           : VEN%03d", tempat.id);
                        gotoxy(36, i + 2);  printf("Kapasitas Tempat    :");

                        gotoxy(58, i + 2);  getnum(&NewTmpt.kapasitas, 10);
                        if (NewTmpt.kapasitas == 0) {
                            MasterTempat();
                        }
                        tempat.kapasitas = NewTmpt.kapasitas;
                        break;
                    case 5:
//                        i = 25;
                        gotoxy(36, i);      printf("ID Tempat       : VEN%03d", tempat.id);
                        gotoxy(36, i + 2);  printf("Harga Tempat    : Rp");

                        gotoxy(57, i + 2);  getRp(&NewTmpt.harga, 0, 15, 57, i + 2);
                        if (NewTmpt.harga == 0) {
                            MasterTempat();
                        }
                        tempat.harga = NewTmpt.harga;
                        break;
                    case 6:
//                        i = 25;
                        gotoxy(36, i);      printf("ID Tempat       : VEN%03d", tempat.id);
                        gotoxy(36, i + 2);  printf("Status Tempat   : (gunakan Key Up/DOwn untuk memilih)");

                        clearArea(54, i + 2, 40, 1);
                        Pilihan(54, i + 2, 15, NewTmpt.status, 1, STATUSVEN);
                        strcpy(tempat.status, NewTmpt.status);
                        break;
                    case 7:
                        HapusKanan();
                        MasterTempat();
                        break;
                }

                fwrite(&tempat, sizeof(tempat), 1, Temp);
                while(fread(&tempat, sizeof(tempat), 1, Asal) == 1) {
                    fwrite(&tempat, sizeof(tempat), 1, Temp);
                }

                MessageBox(NULL, "Data Berhasil Diupdate!", "NOTIFICATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                break;
            case 2:
                HapusTengah();
                fwrite(&tempat, sizeof(tempat), 1, Temp);

                while (fread(&tempat, sizeof(tempat), 1, Asal) == 1) {
                    fwrite(&tempat, sizeof(tempat), 1, Temp);
                }
                break;

        }

        fclose(Asal);
        fclose(Temp);

        remove("../Dat/Master Tempat.dat");
        rename("../Dat/Temp.dat", "../Dat/Master Tempat.dat");

        int answ;
        do {
            HapusTengah();
            gotoxy(73, 25);  printf("Ingin mengubah data lain?");
            SpecialkeyloginHorizontal(yntengah, 74, 27, 9, 1, 13, 2, &answ);
            HapusTengah();
            HapusKanan();
            switch (answ) {
                case 1:
                    updateTempat();
                    break;
                case 2:
                    MasterTempat();
                    break;
            }
        } while (answ == 1);


    } else {
        MessageBox(NULL, "ID Jasa tidak ditemukan!", "NOTIFICATION", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        HapusTengah();
        updateTempat();
    }
}

void deleteTempat () {

    FILE *Asal;
    FILE *Temp;
    int KodeCari;
    int ketemu;
    int ans = 0;

    readTempat();

    gotoxy(60, 42); printf("========== klik 0 dan ENTER untuk kembali ==========");
    Tunggu(5);
    gotoxy(32, i + 3);  printf("Masukkan ID : VEN");
    gotoxy(49, i + 3);  getnummin(&KodeCari, 1, 3);
    if (KodeCari == 0) {
        HapusTengah();
        MasterTempat();
    }

    Asal = fopen("../Dat/Master Tempat.dat", "rb");
    Temp = fopen("../Dat/Temp.dat", "wb");

    ketemu = 0;
    while (!ketemu && fread(&tempat, sizeof(tempat), 1, Asal) == 1) {
        if (tempat.id == KodeCari){
            ketemu = 1;
        } else {
            fwrite(&tempat, sizeof(tempat), 1, Temp);
        }
    }

    if (ketemu == 1) {
        HapusTengah();
        gotoxy(36, 15); printf("Data tempat yang ingin dihapus");
        gotoxy(36, 18); printf("ID Tempat           : VEN%03d", tempat.id);
        gotoxy(36, 20); printf("Nama Tempat         : %s", tempat.nama);
        gotoxy(36, 22); printf("Alamat Tempat       : %s", tempat.alamat);
        gotoxy(36, 24); printf("Kapasitas Tempat    : %d", tempat.kapasitas);
        strcpy(rp, "0");
        rupiah(tempat.harga, rp);
        gotoxy(36, 26); printf("Harga Tempat        : Rp %s", rp);
        gotoxy(36, 28); printf("Status Tempat       : %s", tempat.status);

        gotoxy(72, 39); printf("Ingin menghapus data tempat ?");
        SpecialkeyloginHorizontal(YN, 74, 40, 9, 1, 13, 2, &ans);
        switch (ans) {
            case 1:
                while (fread(&tempat, sizeof(tempat), 1, Asal) == 1) {
                    fwrite(&tempat, sizeof(tempat), 1, Temp);
                }

                MessageBox(NULL, "Data Berhasil Dihapus", "NOTIFICATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                break;
            case 2:
                fwrite(&tempat, sizeof(tempat), 1, Temp);

                while (fread(&tempat, sizeof(tempat), 1, Asal) == 1) {
                    fwrite(&tempat, sizeof(tempat), 1, Temp);
                }
                break;
        }

        fclose(Asal);
        fclose(Temp);

        remove("../Dat/Master Tempat.dat");
        rename("../Dat/Temp.dat", "../Dat/Master Tempat.dat");

        int answ;
        do {
            HapusTengah();
            gotoxy(73, 25);  printf("Ingin menghapus data lain ?");
            SpecialkeyloginHorizontal(yntengah, 74, 27, 9, 1, 13, 2, &answ);
            HapusTengah();
            switch (answ) {
                case 1:
                    deleteTempat();
                    break;
                case 2:
                    MasterTempat();
                    break;
            }
        } while (answ == 1);

    } else {
        MessageBox(NULL, "ID Tempat tidak ditemukan!", "NOTIFICATION", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        HapusTengah();
        deleteTempat();
    }
}

void Terimakasih () {

    HapusAll();
    PrintFile("Terimakasih.txt", 30, 14);
    fflush(stdout);
    usleep(10 * 100000);

}

void Keluar () {

    gotoxy(70, 20);
    printf("Keluar Program");

    int x = 85;
    for (i = 0; i < 1; i++) {
        for (j = 0; j < 3; j++) {
            gotoxy(x, 20);
            printf(".");
            x++;
            fflush(stdout);
            usleep(5 * 100000);
        }
    }

}