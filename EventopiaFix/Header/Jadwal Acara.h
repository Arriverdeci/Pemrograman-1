void menuKegiatan ();
void createKegiatan ();
void readKegiatan ();
void menuUpdateKegiatan ();
void updateKegiatan ();
void deleteKegiatan ();

//int ROLES;
void MenuAdmin();
void MenuEO();
void MenuManajer();
void MenuPemasaran();

void MasterKegiatan () {

    HapusAll();
    garismenu();
    menuKegiatan();

}


void menuKegiatan () {

    int pilih;

    SetColorBlock(0, 14);

    gotoxy(13, 16);
    printf("M A S T E R");
    gotoxy(11, 18);
    printf("K E G I A T A N");
//    gotoxy(14, 19);
//    printf("A C A R A");

    gotoxy(10, 21);
    printf("1. Create Data");
    gotoxy(10, 22);
    printf("2. Read Data");
    gotoxy(10, 23);
    printf("3. Update Data");
    gotoxy(10, 24);
    printf("4. Delete Data");
    gotoxy(10, 25);
    printf("5. Keluar");
    gotoxy(10, 27);
    printf("Pilih : [ ]");
    gotoxy(19, 27);
    scanf("%d", &pilih);

    switch (pilih) {
        case 1:
            createKegiatan();
            break;
        case 2:
            readKegiatan();
            gotoxy(80, 41);
            printf("========== klik apapun untuk melanjutkan ==========");
            getch();
            HapusAll();
            MasterKegiatan();
            break;
        case 3:
            updateKegiatan();
            break;
        case 4:
            deleteKegiatan();
            break;
        case 5:
            HapusKiri();
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
        default:
//            HapusKiri();
            MessageBoxA(NULL,"Incorrect input","ATTENTION",MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
            MasterKegiatan();
            break;
    }

}

void createKegiatan () {

    int id;
    int loop = 0;
    char ans;
    FILE *keg;

    HapusKiri();

    keg = fopen("Kegiatan.dat","rb"); /* buka file user untuk dibaca */
    fread(&act, sizeof(act),1,keg);
    while (!feof(keg)){
        fread(&act,sizeof(act),1,keg);
        id = act.id;
        loop++;
    }

    if (loop == 0) {
        act.id = 1;
    } else {
        act.id = id + 1; /* id otomatis */
    }
    fclose(keg);

    gotoxy(36, 15); printf("Masukkan data!");
    gotoxy(36, 17); printf("ID Kegiatan         : ACT%d", act.id);
//    gotoxy(36, 18); printf("ID Acara            : EVT");
    gotoxy(36, 18); printf("Nama Kegiatan       :");
    gotoxy(36, 19); printf("Deskripsi Kegiatan  :");
    gotoxy(36, 20); printf("Waktu Mulai         : HH:MM");
    gotoxy(36, 21); printf("Waktu Selesai       : HH:MM");

//    gotoxy(61, 18); scanf("%d", &act.idacara);

    gotoxy(58, 18); scanf(" %[^\n]", act.nama);
    getchar() != '\n';
    gotoxy(58, 19); scanf(" %[^\n]", act.desk);
    getchar() != '\n';
    gotoxy(58, 20); scanf("%02d", &act.jm);
    if (act.jm > 23) {
        MessageBox(NULL, "Tidak boleh lebih dari 23!", "NOTIFICATION", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);

    } else if (act.jm < 0) {
        MessageBox(NULL, "Tidak boleh kurang dari 0!", "NOTIFICATION", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);

    }
    gotoxy(61, 20); scanf("%02d", &act.mm);
    gotoxy(58, 21); scanf("%02d", &act.js);
    gotoxy(61, 21); scanf("%02d", &act.ms);

    // input ke file
    keg = fopen("Kegiatan.dat", "ab");
    fwrite(&act, sizeof(act), 1, keg);
    fclose(keg);

    MessageBox(NULL, "Data Berhasil Ditambahkan", "NOTIFICATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);

    do {

        gotoxy(36, 23);
        printf("Ingin menambah data tempat lagi [Y/N]?");
        gotoxy(75, 23);
        scanf("%s", &ans);
        HapusTengah();

        switch (toupper(ans)) {
            case 'Y':
                HapusTengah();
                createKegiatan();
                break;
            case 'N':
                HapusKiri();
                menuKegiatan();
        }

    } while (toupper(ans) != 'Y' && toupper(ans) != 'N');

//    fclose(keg);
}

void readKegiatan () {

    FILE *lihat = fopen("Kegiatan.dat", "rb");

    HapusKiri();
    if (lihat == NULL) {
        gotoxy(56, 13);
        printf("DATA TIDAK DITEMUKAN");
    } else {
        gotoxy(80, 13);
        printf("D A T A  K E G I A T A N");

        // border
        for(j = 35; j < 167; j++) {
            gotoprintchar(j, 15, 205);
            gotoprintchar(j, 17, 205);
        }

        gotoxy(36, 16);     printf("ID");
        gotoxy(46, 16);     printf("NAMA");
        gotoxy(96, 16);     printf("DESKRIPSI");
        gotoxy(146, 16);    printf("MULAI");
        gotoxy(156, 16);    printf("SELESAI");

        i = 18;
        while (fread(&act, sizeof(act), 1, lihat) == 1) {
            gotoxy(36, i);
            printf("ACT%d", act.id);
            gotoxy(46, i);
            printf("%s", act.nama);
            gotoxy(96, i);
            printf("%s", act.desk);
            gotoxy(146, i);
            printf("%02d:%02d", act.jm, act.mm);
            gotoxy(156, i);
            printf("%02d:%02d", act.js, act.ms);
            i++;
        }
    }

    fclose(lihat);


}

void updateKegiatan () {

    FILE *Asal;
    int KodeKeg;
    int found;
    int pilUpdate;
    char ans [2];
    FILE *Temp;
    Kegiatan actNew;

    readKegiatan();

    Tunggu(5);
    gotoxy(6, 15);
    printf("Masukkan ID : ACT");
//    gotoxy(20, 15);
    scanf("%d", &KodeKeg);

    Asal = fopen("Kegiatan.dat", "rb");
    Temp = fopen("Temp.dat", "wb");

    found = 0;
    while (found == 0 && fread(&act, sizeof(act), 1, Asal) == 1) {
        if (tempat.id == KodeKeg) {
            found = 1;
        } else {
            fwrite(&act, sizeof(act), 1, Temp);
        }
    }

    if (found == 1) {
        HapusTengah();
        gotoxy(35, 15); printf("Data kegiatan yang ingin di update");

        gotoxy(35, 17); printf("ID Kegiatan         = ACT%d", act.id);
        gotoxy(35, 18); printf("Nama Kegiatan       = %s", act.nama);
        gotoxy(35, 19); printf("Deskripsi Kegiatan  = %s", act.desk);
        gotoxy(35, 20); printf("Waktu Mulai         = %02d:%02d", act.jm, act.mm);
        gotoxy(35, 21); printf("Waktu Selesai       = %02d:%02d", act.js, act.ms);

        i = 23;
        gotoxy(35, i); printf("Ingin mengupdate data [Y/N]?");
        gotoxy(64, i); scanf("%s", ans);
        HapusKiri();

        if (strcmp(ans, "Y") == 0 || strcmp(ans, "y") == 0) {

            HapusTengah();
            gotoxy(57, 13);     printf("========== Data kegiatan yang ingin diupdate =========");

            // border
            for(j = 35; j < 167; j++) {
                gotoprintchar(j, 15, 205);
                gotoprintchar(j, 17, 205);
            }

            gotoxy(36, 16);     printf("ID");
            gotoxy(46, 16);     printf("NAMA");
            gotoxy(96, 16);     printf("DESKRIPSI");
            gotoxy(146, 16);    printf("MULAI");
            gotoxy(156, 16);    printf("SELESAI");

            gotoxy(36, 18);     printf("TMPT%d", act.id);
            gotoxy(46, 18);     printf("%s", act.nama);
            gotoxy(96, 18);     printf("%s", act.desk);
            gotoxy(146, 18);    printf("%02d:%02d", act.jm, act.mm);
            gotoxy(156, 18);    printf("%02d:%02d", act.js, act.ms);

            menuUpdateKegiatan();
            gotoxy(36, 26); printf("Pilih data yang ingin diupdate :");
//                   gotoxy(80, 41); printf("ketik 0 dan ENTER untuk kembali");

            gotoxy(69, 26);
            scanf("%d", &pilUpdate);
//
            i = 29;
            switch (pilUpdate) {
                case 1:
                    gotoxy(36, i);  printf("ID Kegiatan         = ACT%d", act.id);
                    i++;
                    gotoxy(36, i);  printf("Nama Kegiatan       =");
                    i++;
                    gotoxy(36, i);  printf("Deskripsi Kegiatan  =");
                    i++;
                    gotoxy(36, i);  printf("Waktu Mulai         = HH:MM");
                    i++;
                    gotoxy(36, i);  printf("Waktu Selesai       = HH:MM");

                    // input data baru
                    i = 30;
                    gotoxy(58, i);  scanf(" %[^\n]", actNew.nama);
                    getchar() != '\n';
                    strcpy(act.nama, actNew.nama);
                    i++;
                    gotoxy(50, i);  scanf(" %[^\n]", actNew.desk);
                    getchar() != '\n';
                    strcpy(act.desk, actNew.desk);
                    i++;
                    gotoxy(58, i);  scanf("%02d", &actNew.jm);
                    act.jm = actNew.jm;
                    gotoxy(63, i);  scanf("%02d", &actNew.mm);
                    act.mm = actNew.mm;
                    i++;
                    gotoxy(58, i);  scanf("%02d", &actNew.js);
                    act.js = actNew.js;
                    gotoxy(63, i);  scanf("%02d", &actNew.ms);
                    act.ms = actNew.ms;
                    break;
                case 2:
                    gotoxy(36, i);  printf("Nama Kegiatan :");
                    gotoxy(52, i);  scanf(" %[^\n]", actNew.nama);
                    getchar() != '\n';
                    strcpy(act.nama, actNew.nama);
                    break;
                case 3:
                    gotoxy(36, i);  printf("Deskripsi Kegiatan :");
                    gotoxy(57, i);  scanf(" %[^\n]", actNew.desk);
                    getchar() != '\n';
                    strcpy(act.desk, actNew.desk);
                    break;
                case 4:
                    gotoxy(36, i);  printf("Waktu Mulai = HH:MM");
                    gotoxy(50, i);  scanf("%02d", &actNew.jm);
                    act.jm = actNew.jm;
                    gotoxy(53, i);  scanf("%02d", &actNew.mm);
                    act.mm = actNew.mm;
                    break;
                case 5:
                    gotoxy(36, i);  printf("Waktu Selesai = HH:MM");
                    gotoxy(52, i);  scanf("%02d", &actNew.ms);
                    act.js = actNew.js;
                    gotoxy(55, i);  scanf("%02d", &actNew.ms);
                    act.ms = actNew.ms;
                    break;
                default:
                    i = 26;
                    break;
            }

            fwrite(&act, sizeof(act), 1, Temp);

            while (fread(&act, sizeof(tempat), 1, Asal) == 1) {
                fwrite(&act, sizeof(act), 1, Temp);
            }

        } else if (strcmp(ans, "N") == 0 || strcmp(ans, "n") == 0) {

            fwrite(&act, sizeof(act), 1, Temp);

            while (fread(&act, sizeof(act), 1, Asal) == 1) {
                fwrite(&act, sizeof(act), 1, Temp);
            }

        } else {

            HapusTengah();
            updateKegiatan();

        }

        fclose(Asal);
        fclose(Temp);

        Temp = fopen("Temp.dat", "rb");
        Asal = fopen("Kegiatan.dat", "wb");

        while (fread(&act, sizeof(act), 1, Temp) == 1) {
            fwrite(&act, sizeof(act), 1, Asal);
        }

        fclose(Temp);
        fclose(Asal);

//        SalinArsipTempkeAsal (Temp, Asal);

        do {
            gotoxy(36, i + 3);
            printf("Ingin mengupdate data lain (Y/N)?");
            gotoxy(70, i + 3);
            scanf("%s", ans);
            HapusTengah();

            if (strcmp(ans, "Y") == 0 && strcmp(ans, "y") == 0) {
                HapusTengah();
                updateKegiatan();
            } else if (strcmp(ans, "N") == 0 && strcmp(ans, "n") == 0) {
                break;
            } else {
                HapusTengah();
                menuKegiatan();
            }

        } while (strcmp(ans, "N") != 0 || strcmp(ans, "n") != 0);

    } else {
        MessageBox(NULL, "ID Kegiatan tidak ditemukan!", "NOTIFICATION", MB_OK | MB_DEFAULT_DESKTOP_ONLY);
//        gotoxy(6, 16);
//        printf("%s tidak ditemukan", KodeTmpt);
//        getch();
    }

    HapusKiri();
    HapusTengah();

}

void menuUpdateKegiatan () {

    gotoxy(36, 20); printf("[1] Semua Data");
    gotoxy(36, 21); printf("[2] Nama Kegiatan");
    gotoxy(36, 22); printf("[3] Deskripsi Kegiatan");
    gotoxy(36, 23); printf("[4] Waktu Mulai");
    gotoxy(36, 24); printf("[5] Waktu Selesai");

}

void deleteKegiatan () {

    FILE *Asal;
    int KodeCari;
    int ketemu;
    char ans [2];
    FILE *Temp;

    readKegiatan();

    Tunggu(5);
    gotoxy(6, 15);
    printf("Masukkan ID : ACT");
//    gotoxy(20, 15);
    scanf("%d", &KodeCari);

    Asal = fopen("Kegiatan.dat", "rb");
    Temp = fopen("Temp.dat", "wb");

    ketemu = 0;
    while (ketemu == 0 && fread(&act, sizeof(act), 1, Asal) == 1) {
        if (act.id == KodeCari) {
            ketemu = 1;
        } else {
            fwrite(&act, sizeof(act), 1, Temp);
        }
    }

    if (ketemu == 1) {
        HapusTengah();
        gotoxy(35, 15); printf("Data kegiatan yang ingin dihapus");
        gotoxy(35, 17); printf("ID Kegiatan         = ACT%d", act.id);
        gotoxy(35, 18); printf("Nama Kegiatan       = %s", act.nama);
        gotoxy(35, 19); printf("Dskripsi Kegiatan   = %s", act.desk);
        gotoxy(35, 20); printf("Waktu Mulai         = %02d:%02d", act.jm, act.mm);
        gotoxy(35, 21); printf("Waktu Selesai       = %02d:%02d", act.js, act.ms);
        gotoxy(35, 23); printf("Ingin menghapus data [Y/N]?");
        gotoxy(63, 23); scanf("%s", ans);

        HapusKiri();
        HapusTengah();

        if (strcmp(ans, "Y") == 0 || strcmp(ans, "y") == 0) {
            while (fread(&act, sizeof(act), 1, Asal) == 1) {
                fwrite(&act, sizeof(act), 1, Temp);
            }
            gotoxy(37, 25);
            printf("Data berhasil dihapus");
            getch();
            HapusTengah();
        } else {

            fwrite(&act, sizeof(act), 1, Temp);

            while (fread(&act, sizeof(act), 1, Asal) == 1) {
                fwrite(&act, sizeof(act), 1, Temp);
            }

        }



    } else {
//        gotoxy(6, 16);
//        printf("%s tidak ditemukan", KodeTmpt);
//        getch();
        HapusTengah();
        HapusKiri();
    }

    fclose(Asal);
    fclose(Temp);

    Temp = fopen("Temp.dat", "rb");
    Asal = fopen("Kegiatan.dat", "wb");

    while (fread(&act, sizeof(act), 1, Temp) == 1) {
        fwrite(&act, sizeof(act), 1, Asal);
    }

    fclose(Temp);
    fclose(Asal);

    MessageBox(NULL,"Data Berhasil di Hapus","ATTENTION",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);

    do {
        gotoxy(36, i + 4);
        printf("Ingin menghapus data lagi (Y/N)?");
        gotoxy(70, i + 4);
        scanf("%s", ans);
        HapusTengah();

        if (strcmp(ans, "Y") == 0 || strcmp(ans, "y") == 0) {
//            HapusKiri();
//            HapusTengah();
            deleteKegiatan();
        } else if (strcmp(ans, "N") == 0 || strcmp(ans, "n") == 0) {
            MasterKegiatan();
            break;
        } else {
            HapusAll();
            MasterKegiatan();
        }

    } while (strcmp(ans, "N") != 0 && strcmp(ans, "n") != 0);

}