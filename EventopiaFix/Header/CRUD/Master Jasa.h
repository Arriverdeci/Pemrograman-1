void menuJasa ();
void createJasa ();
void readJasa ();
void updateJasa ();
void deleteJasa ();

void MasterJasa () {

    garismenu();
    menuJasa();

}

void menuJasa () {

    int choose;

    do {
        SetColorBlock(0, 14);
        HapusTengah();
        HapusKanan();
        SpecialkeyloginVertical(MenuMaster, 147, 15, 19, 3, 5, 5, &choose);
        HapusTengah();
        switch (choose) {
            case 1:
                createJasa();
                break;
            case 2:
                readJasa();
                gotoxy(60, 42); printf("========== ketik apapun untuk melanjutkan ==========");
                getch();
                HapusTengah();
                break;
            case 3:
                updateJasa();
                break;
            case 4:
                deleteJasa();
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

void createJasa () {

    int id;
    int loop = 0;
    int tambah;
    FILE *js;

//    HapusKiri();

    SetColorBlock(0, 14);
    js = fopen("../Dat/Jasa.dat","ab+"); /* buka file user untuk dibaca */
    fread(&jasa, sizeof(jasa),1, js);
    while (!feof(js)){
        fread(&jasa,sizeof(jasa),1,js);
        id = jasa.id;
        loop++;
    }

    if (loop == 0) {
        jasa.id = 1;
    } else {
        jasa.id = id + 1; /* id otomatis */
    }
    fclose(js);

    gotoxy(37, 15); printf("Masukkan Data Jasa!!");
    gotoxy(37, 18); printf("ID Jasa     : JS%03d", jasa.id);
    gotoxy(37, 20); printf("Jenis Jasa  :");
    gotoxy(37, 22); printf("Biaya Jasa  : Rp ");
    gotoxy(60, 42); printf("========== klik 0 dan ENTER untuk kembali ==========");
    gotoxy(51, 20); getteks(jasa.jenis, 30);
    if(strcmp(jasa.jenis, "0")== 0) {
        MasterJasa();
    }
    gotoxy(54, 22);
    getRp(&jasa.biaya, 5, 10, 54, 22);
    if(jasa.biaya == 0) {
        MasterJasa();
    }

    js = fopen("../Dat/Jasa.dat", "ab");
    fwrite(&jasa, sizeof(jasa), 1, js);   // input ke file
    fclose(js);

    MessageBox(NULL,"Data Berhasil Ditambahkan!","NOTIFICATION",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);

    do {
        HapusTengah();
        SetColorBlock(0, 14);
        gotoxy(73, 25); printf("Ingin menambah data lagi ?");
        SpecialkeyloginHorizontal(yntengah, 74, 27, 9, 1, 13, 2, &tambah);
//        SpecialkeyloginHorizontal(YN, 74, 40, 9, 1, 13, 2, &tambah);
        HapusTengah();

        switch (tambah) {
            case 1:
                HapusTengah();
                createJasa();
                break;
            case 2:
                HapusTengah();
                menuJasa();
                break;
        }

    } while (tambah == 1);

}

void readTrJasa () {

    FILE *js;
    char biaya [30];

    js = fopen("../Dat/Jasa.dat", "rb");

    if (js == NULL) {
        gotoxy(56, 13);
        printf("DATA TIDAK DITEMUKAN");
    } else {
        gotoxy(78, 13);
        printf("D A T A  J A S A");

        // border
        for (j = 29; j < 143; j++) {
            gotoprintchar(j, 15, 205);
            gotoprintchar(j, 17, 205);
        }

        gotoxy(39, 16);
        printf("ID");
        gotoxy(54, 16);
        printf("JENIS");
        gotoxy(84, 16);
        printf("BIAYA");

        i = 18;
        while (fread(&jasa, sizeof(jasa), 1, js) == 1) {
            gotoxy(39, i);  printf("JS%03d", jasa.id);  fflush(stdin);
            gotoxy(54, i);  printf("%s", jasa.jenis);   fflush(stdin);
            rupiah(jasa.biaya, biaya);
            gotoxy(84, i);  printf("Rp %s", biaya);     fflush(stdin);
            i++;
        }

    }

    fclose(js);

}

void readJasa () {

    FILE *js;
    char biaya [30];

    js = fopen("../Dat/Jasa.dat", "rb");

    if (js == NULL) {
        gotoxy(56, 13);
        printf("DATA TIDAK DITEMUKAN");
    } else {
        gotoxy(78, 13);
        printf("D A T A  J A S A");

        // border
        for (j = 29; j < 143; j++) {
            gotoprintchar(j, 15, 205);
            gotoprintchar(j, 17, 205);
        }

        gotoxy(39, 16);
        printf("ID");
        gotoxy(54, 16);
        printf("JENIS");
        gotoxy(84, 16);
        printf("BIAYA");

        i = 18;
        while (fread(&jasa, sizeof(jasa), 1, js) == 1) {
            gotoxy(39, i);  printf("JS%03d", jasa.id);  fflush(stdin);
            gotoxy(54, i);  printf("%s", jasa.jenis);   fflush(stdin);
            rupiah(jasa.biaya, biaya);
            gotoxy(84, i);  printf("Rp %s", biaya);     fflush(stdin);
            i++;
        }

    }

    fclose(js);

}

void menuupdatejasa () {

    gotoxy(149, 21);  printf("    S E M U A    ");
    gotoxy(149, 23);  printf("     D A T A     ");
    gotoxy(149, 25);  printf("    J E N I S    ");
    gotoxy(149, 27);  printf("     J A S A     ");
    gotoxy(149, 29);  printf("    B I A Y A    ");
    gotoxy(149, 31);  printf("     J A S A     ");
    gotoxy(149, 34);  printf("  K E M B A L I  ");

}

void updateJasa () {

    FILE *Asal;
    int KodeCari;
    int found;
    char rp[25];
    int ans;
    FILE *Temp;
    Jasa NewJasa;

    readJasa();

    gotoxy(60, 42); printf("========== klik 0 dan ENTER untuk kembali ==========");
    Tunggu(5);
    gotoxy(30, i + 3);  printf("Masukkan ID : JS");
    gotoxy(46, i + 3);  getnummin(&KodeCari, 1, 2);
    if (KodeCari == 0) {
        MasterJasa();
    }

    Asal = fopen("../Dat/Jasa.dat", "rb");
    Temp = fopen("../Dat/Temp.dat", "wb");

    found = 0;
    while (found == 0 && fread(&jasa, sizeof(jasa), 1, Asal)) {

        if (jasa.id == KodeCari) {
            found = 1;

        } else {
            fwrite(&jasa, sizeof(jasa), 1, Temp);
        }

    }

    if (found == 1) {
        HapusTengah();
        gotoxy(36, 15); printf("Data jasa yang ingin di update");
        gotoxy(36, 18); printf("ID Jasa    : JS%d", jasa.id);
        gotoxy(36, 20); printf("Jenis Jasa : %s", jasa.jenis);
        rupiah(jasa.biaya, rp);
        gotoxy(36, 22); printf("Biaya Jasa : Rp %s", rp);

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
                gotoxy(54, 16);     printf("JENIS");
                gotoxy(84, 16);     printf("BIAYA");

                gotoxy(39, 18); printf("JS%03d", jasa.id);
                gotoxy(54, 18); printf("%s", jasa.jenis);
                rupiah(jasa.biaya, rp);
                gotoxy(84, 18); printf("Rp %s", rp);

                int updt;
                HapusKanan();
                SpecialkeyloginVertical(menuupdatejasa, 147, 20, 19, 3, 4, 4, &updt);
                switch (updt) {
                    case 1:
                        i = 25;
                        gotoxy(36, i);      printf("ID Jasa     : JS%03d", jasa.id);
                        gotoxy(36, i + 2);  printf("Jenis Jasa  : ");
                        gotoxy(36, i + 4);  printf("Biaya Jasa  : Rp ");

                        gotoxy(49, i + 2);  getletter(NewJasa.jenis, 30);
                        strcpy(jasa.jenis, NewJasa.jenis);
                        getRp(&NewJasa.biaya, 6, 10, 53, 29);
                        jasa.biaya = NewJasa.biaya;
                        break;
                    case 2:
                        i = 25;
                        gotoxy(36, i);      printf("ID Jasa     : JS%03d", jasa.id);
                        gotoxy(36, i + 2);  printf("Jenis Jasa  : ");
                        gotoxy(49, i + 2);  getletter(NewJasa.jenis, 30);
                        strcpy(jasa.jenis, NewJasa.jenis);
                        break;
                    case 3:
                        gotoxy(36, i + 2);  printf("Biaya Jasa : Rp ");
                        getRp(&NewJasa.biaya, 6, 10, 53, i + 2);
                        jasa.biaya = NewJasa.biaya;
                        break;
                    case 4:
                        HapusKanan();
                        menuJasa();
                        break;
                }

                fwrite(&jasa, sizeof(jasa), 1, Temp);
                while (fread(&jasa, sizeof(jasa), 1, Asal) == 1) {
                    fwrite(&jasa, sizeof(jasa), 1, Temp);
                }

                MessageBox(NULL, "Data Berhasil Diupdate!", "NOTIFICATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                break;
            case 2:
                HapusTengah();
                fwrite(&jasa, sizeof(jasa), 1, Temp);

                while (fread(&jasa, sizeof(jasa), 1, Asal) == 1) {
                    fwrite(&jasa, sizeof(jasa), 1, Temp);
                }
                break;
        }

        fclose(Asal);
        fclose(Temp);

        remove("../Dat/Jasa.dat");
        rename("../Dat/Temp.dat", "../Dat/Jasa.dat");

        int answ;
        do {
            HapusTengah();
            gotoxy(73, 25);  printf("Ingin mengubah data lain?");
            SpecialkeyloginHorizontal(yntengah, 74, 27, 9, 1, 13, 2, &answ);
            HapusTengah();
            HapusKanan();
            switch (answ) {
                case 1:
                    updateJasa();
                    break;
                case 2:
                    MasterJasa();
                    break;
            }
        } while (answ == 1);


    } else {
        MessageBox(NULL, "ID Jasa tidak ditemukan!", "NOTIFICATION", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        HapusTengah();
        updateJasa();
    }

}

void deleteJasa () {

    FILE *Asal;
    int KodeCari;
    int ketemu;
    FILE *Temp;
    char rp[25];
    int ans = 0;

    readJasa();

    gotoxy(60, 42); printf("========== klik 0 dan ENTER untuk kembali ==========");
    Tunggu(5);
    gotoxy(30, i + 3);
    printf("Masukkan ID : JS");
    gotoxy(46, i + 3);
    getnummin(&KodeCari, 1, 3);
    if (KodeCari == 0) {
        MasterJasa();
    }

    Asal = fopen("../Dat/Jasa.dat", "rb");
    Temp = fopen("../Dat/Temp.dat", "wb");

    ketemu = 0;
    while (!ketemu && fread(&jasa, sizeof(jasa), 1, Asal) == 1) {
        if (jasa.id == KodeCari){
            ketemu = 1;
        } else {
            fwrite(&jasa, sizeof(jasa), 1, Temp);
        }
    }

    if (ketemu == 1) {
        HapusTengah();
        gotoxy(36, 15); printf("Data jasa yang ingin dihapus");
        gotoxy(36, 18); printf("ID Jasa    : JS%03d", jasa.id);
        gotoxy(36, 20); printf("Jenis Jasa : %s", jasa.jenis);
        rupiah(jasa.biaya, rp);
        gotoxy(36, 22); printf("Biaya Jasa : Rp %s", rp);

        gotoxy(73, 39); printf("Ingin menghapus data jasa ?");
        SpecialkeyloginHorizontal(YN, 74, 40, 9, 1, 13, 2, &ans);
        switch (ans) {
            case 1:
                while (fread(&jasa, sizeof(jasa), 1, Asal) == 1) {
                    fwrite(&jasa, sizeof(jasa), 1, Temp);
                }

                MessageBox(NULL, "Data Berhasil Dihapus", "NOTIFICATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                break;
            case 2:
                fwrite(&jasa, sizeof(jasa), 1, Temp);

                while (fread(&jasa, sizeof(jasa), 1, Asal) == 1) {
                    fwrite(&jasa, sizeof(jasa), 1, Temp);
                }
                break;
        }

        fclose(Asal);
        fclose(Temp);

        remove("../Dat/Jasa.dat");
        rename("../Dat/Temp.dat", "../Dat/Jasa.dat");

        int answ;
        do {
            HapusTengah();
            gotoxy(73, 25);  printf("Ingin menghapus data lain ?");
            SpecialkeyloginHorizontal(yntengah, 74, 27, 9, 1, 13, 2, &answ);
            HapusTengah();
            switch (answ) {
                case 1:
                    deleteJasa();
                    break;
                case 2:
                    MasterJasa();
                    break;
            }
        } while (answ == 1);

    } else {
        MessageBox(NULL, "ID Jasa tidak ditemukan!", "NOTIFICATION", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        HapusTengah();
        deleteJasa();
    }

}