void menuUser ();
void createUser ();
void readUser ();
void menuUpdateUser ();
void updateUser ();
void deleteUser ();

//int ROLES;
void MenuAdmin();
void MenuEO();
void MenuManajer();
void MenuPemasaran();

void MasterUser () {

    garismenu();
    menuUser();

}

void menuUser () {

    int pilih;

    HapusTengah();
    SetColorBlock(0, 14);

    do {
        HapusKanan();
        SpecialkeyloginVertical(MenuMaster, 147, 15, 19, 3, 5, 5, &pilih);
        switch (pilih) {
            case 1:
                createUser();
                break;
            case 2:
                readUser();
                gotoxy(60, 42);
                printf("========== ketik apapun untuk melanjutkan ==========");
                getch();
                HapusTengah();
                break;
            case 3:
                HapusTengah();
                updateUser();
                break;
            case 4:
                HapusTengah();
                deleteUser();
                break;
            case 5:
                SetColorBlock(0, 14);
                for ( i = 12; i < 43; i++) {
                    for ( j = 145; j < 147; j++) {
                        gotoprintchar(j, i, 32);
                    }
                }
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
    } while (pilih != 5);

}

void createUser () {

    int id;
    int loop = 0;
    char ans;
    FILE *user;

//    HapusKanan();

    user = fopen("../Dat/Karyawan.dat","ab+"); /* buka file user untuk dibaca */
    fread(&U, sizeof(U),1,user);
    while (!feof(user)){
        fread(&U,sizeof(U),1,user);
        id = U.id;
        loop++;
    }

    if (loop == 0) {
        U.id = 1;
    } else {
        U.id = id + 1; /* id otomatis */
    }
    fclose(user);

    gotoxy(37, 15); printf("Masukkan data!");
    gotoxy(37, 18); printf("ID Karyawan    : EMP%03d", U.id);
    gotoxy(37, 20); printf("Nama           :");
    gotoxy(37, 22); printf("Username       :");
    gotoxy(37, 24); printf("Password       :");
    gotoxy(37, 26); printf("Password ulang :");
    gotoxy(37, 28); printf("No Telp        :");
    gotoxy(37, 30); printf("Tanggal Lahir  : YYYY/MM/DD");
    gotoxy(37, 32); printf("Jabatan        : (gunakan Key/Up Down untuk memilih)");
    gotoxy(60, 42); printf("========== klik 0 dan ENTER untuk kembali ==========");

    // input nama
    gotoxy(54, 20); getletter(U.nama, 30);
    int found;
    do {
        // input usn
        found = 0;
        gotoxy(54, 22); getteks(U.username, 15);
        if (strcmp(U.username, "0") == 0) {
            HapusTengah();
            MasterUser();
        }

        user = fopen("../Dat/Karyawan.dat", "rb");

        while (found == 0 && fread(&uNew, sizeof(uNew), 1, user) == 1) {
            if (strcmp(uNew.username, U.username) == 0) {
                found = 1;
            }
        }
        fclose(user);

        if (found) {
            MessageBox(NULL, "Username sudah digunakan!", "Notification", MB_OK | MB_ICONERROR |MB_DEFAULT_DESKTOP_ONLY);
            clearArea(54, 22, 25, 1);
        }

    } while (found);

    // input pw
    gotoxy(54, 24); getpass(U.password, 15);
    if (!strcmp(U.password, "0")) {
        HapusTengah();
        MasterUser();
    }

    // tambah ketik ulang pw
    do {
        // input usn
        char pass [15];
        gotoxy(54, 26); getpass(pass, 15);
        if (strcmp(pass, "0") == 0) {
            HapusTengah();
            MasterUser();
        } else if (strcmp(U.password, pass) == 0) {
            found = 1;
        }

        if (found != 1) {
            MessageBox(NULL, "Password tidak sesuai, ulangi!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(54, 26, 15, 1);
        }

    } while (!found);

    // input notelp
    gotoxy(54, 28); getteksnum(U.notelp, 15);
    if (!strcmp(U.notelp, "0")) {
        HapusTengah();
        MasterUser();
    }

    // tanggal
    int a = 54;
    int b = 30;
    int condi;
    DateTime dateNow;
    DateTimeNow(&dateNow);
    // tahun
    do {
        condi = 0;
        gotoxy(a, b); getnummin(&U.tahun, 3, 4);
        if (U.tahun == 0) {
            MasterUser();
            break;
        } else if (U.tahun < 0) {
            condi = 1;
            MessageBox (NULL, "Jangka tahun tidak boleh kurang dari 0!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(a, b, 4, 1);
            gotoxy(a, b);   printf("YYYY");
        } else if (U.tahun > dateNow.tahun) {
            condi = 2;
            MessageBox (NULL, "Jangka tahun tidak boleh lebih dari tahun ini!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(a, b, 4, 1);
            gotoxy(a, b);   printf("YYYY");
        } else {
            break;
        }
    } while (condi == 1 || condi == 2);

    // bulan
    do {
        condi = 0;
        gotoxy(a + 5, b); getnum(&U.bulan, 2);
        if(U.bulan == 0) {
            MasterUser();
            break;
        } else if (U.bulan < 0) {
            condi = 1;
            MessageBox(NULL, "Jangka bulan tidak boleh kurang dari dari 0!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(a + 5, b, 2, 1);
            gotoxy(a + 5, b); printf("MM");
        } else if (U.bulan > 12) {
            condi = 2;
            MessageBox(NULL, "Jangka bulan tidak boleh lebih dari dari 12!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(a + 5, b, 2, 1);
            gotoxy(a + 5, b); printf("MM");
        } else {
            break;
        }
    } while (condi == 1 || condi == 2);

    // tanggal
    do {
        condi = 0;
        gotoxy(a + 8,b);  getnummin(&U.tgl, 1, 2);
        if (U.tgl == 0) {
            MasterUser();
            break;
        } else if (U.tgl < 0) {
            condi = 1;
            MessageBox(NULL, "Jangka tanggal tidak boleh kurang dari 0!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(a + 8, b, 2, 1);
            gotoxy(a + 8, b); printf("DD");
        } else if (U.tahun % 400 == 0 && U.bulan == 2 && U.tgl > 29) {
            condi = 2;
            MessageBox(NULL, "Jangka tanggal tidak boleh lebih dari 29!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(a + 8, b, 2, 1);
            gotoxy(a + 8, b); printf("DD");
        } else if (U.tahun % 400 != 0 && U.bulan == 2 && U.tgl > 28) {
            condi = 3;
            MessageBox(NULL, "Jangka tanggal tidak boleh lebih dari 28!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(a + 8, b, 2, 1);
            gotoxy(a + 8, b); printf("DD");
        } else if (U.bulan % 2 == 0 && U.tgl > 30) {
            condi = 4;
            MessageBox(NULL, "Jangka tanggal tidak boleh lebih dari 30!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(a + 8, b, 2, 1);
            gotoxy(a + 8, b); printf("DD");
        } else if (U.bulan % 2 != 0 && U.tgl > 31) {
            condi = 5;
            MessageBox(NULL, "Jangka tanggal tidak boleh dari 31!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(a + 8, b, 2, 1);
            gotoxy(a + 8, b); printf("DD");
        } else {
            break;
        }
    } while (condi == 1 || condi == 2 || condi == 3 || condi == 4 || condi == 5);

    clearArea(54, 32, 50, 1);
    Pilihan(54, 32, 15, U.role, 3, ROLE);

    // input ke file
    user = fopen("../Dat/Karyawan.dat", "ab");
    fwrite(&U, sizeof(U), 1, user);
    fclose(user);

    MessageBox(NULL, "Data Berhasil Ditambahkan", "NOTIFICATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);

    do {
        HapusTengah();
        gotoxy(73, 26); printf("Ingin menambah data karyawan lagi?");
        SpecialkeyloginHorizontal(yntengah, 74, 27, 9, 1, 13, 2, &ans);
        HapusTengah();

        switch (ans) {
            case 1:
                HapusTengah();
                createUser();
                break;
            case 2:
                HapusTengah();
                MasterUser();
                break;
        }

    } while (ans == 1);

}

void readUser () {

    FILE *lihat = fopen("../Dat/Karyawan.dat", "rb");

    if (lihat == NULL) {
        gotoxy(56, 13);
        printf("DATA TIDAK DITEMUKAN");
    } else {
        gotoxy(74, 13);
        printf("D A T A  K A R Y A W A N");

        // border
        for(j = 28; j < 144; j++) {
            gotoprintchar(j, 15, 205);
            gotoprintchar(j, 17, 205);
        }

        gotoxy(31, 16);     printf("ID");
        gotoxy(46, 16);     printf("NAMA");
        gotoxy(76, 16);    printf("JABATAN");
        gotoxy(96, 16);    printf("NO TELP");
        gotoxy(116, 16);    printf("TANGGAL LAHIR");

        i = 18;
        while (fread(&U, sizeof(U), 1, lihat) == 1) {
            gotoxy(31, i);  printf("EMP%03d", U.id);
            gotoxy(46, i);  printf("%s", U.nama);
            gotoxy(76, i);  printf("%s", U.role);
            gotoxy(96, i);  printf("%s", U.notelp);
            gotoxy(116, i); printf("%02d/%02d/%04d", U.tgl, U.bulan, U.tahun);
            i++;
        }
    }

    fclose(lihat);

}

void menuUpdateUser () {

    gotoxy(148, 18);    printf("S E M U A   D A T A");
    gotoxy(148, 21);    printf("      N A M A      ");
    gotoxy(148, 24);    printf("  P A S S W O R D ");
    gotoxy(148, 27);    printf("   J A B A T A N  ");
    gotoxy(148, 30);    printf("   N O   T E L P  ");
    gotoxy(148, 33);    printf(" T G L   L A H I R");
    gotoxy(148, 36);    printf("   K E M B A L I  ");

}

void updateUser () {

    FILE *Asal;
    int KodeUser;
    int found;
    int ans;
    FILE *Temp;

    readUser();

    gotoxy(60, 42); printf("========== klik 0 dan ENTER untuk kembali ==========");
    Tunggu(5);
    gotoxy(30, i + 3);
    printf("Masukkan ID : EMP");
    gotoxy(47, i + 3);  getnummin(&KodeUser, 1, 3);
    if (KodeUser == 0) {
        HapusTengah();
        MasterUser();
    }

    Asal = fopen("../Dat/Karyawan.dat", "rb");
    Temp = fopen("../Dat/Temp.dat", "wb");

    found = 0;
    while (!found && fread(&U, sizeof(U), 1, Asal) == 1) {
        if (U.id == KodeUser) {
            found = 1;
        } else {
            fwrite(&U, sizeof(U), 1, Temp);
        }
    }

    if (found == 1) {
        HapusTengah();
        gotoxy(36, 15); printf("Data karyawan yang ingin di update");
        gotoxy(36, 18); printf("ID Karyawan     : EMP%03d", U.id);
        gotoxy(36, 20); printf("Nama Lengkap    : %s", U.nama);
        gotoxy(36, 22); printf("Username        : %s", U.username);
        gotoxy(36, 24); printf("Password        : %s", U.password);
        gotoxy(36, 26); printf("Jabatan         : %s", U.role);
        gotoxy(36, 28); printf("No Telp         : %s", U.notelp);
        gotoxy(36, 30); printf("Tanggal Lahir   : %02d/%02d/%d", U.tgl, U.bulan, U.tahun);

//        i = 24;
        gotoxy(71, 39); printf("Ingin mengubah data karyawan?");
        SpecialkeyloginHorizontal(YN, 74, 40, 9, 1, 13, 2, &ans);
        switch (ans) {
            case 1:
                HapusTengah();
                gotoxy(65, 13);
                printf("========== Data yang ingin diubah =========");

                // border
                for(j = 28; j < 144; j++) {
                    gotoprintchar(j, 15, 205);
                    gotoprintchar(j, 17, 205);
                }

                gotoxy(29, 16);     printf("NO.");
                gotoxy(39, 16);     printf("NAMA");
                gotoxy(69, 16);     printf("USERNAME");
                gotoxy(84, 16);     printf("PASSWORD");
                gotoxy(99, 16);     printf("JABATAN");
                gotoxy(114, 16);    printf("NO TELP");
                gotoxy(129, 16);    printf("TANGGAL LAHIR");

                gotoxy(29, 18);     printf("EMP%03d", U.id);
                gotoxy(39, 18);     printf("%s", U.nama);
                gotoxy(69, 18);     printf("%s", U.username);
                gotoxy(84, 18);     printf("%s", U.password);
                gotoxy(99, 18);     printf("%s", U.role);
                gotoxy(114, 18);    printf("%s", U.notelp);
                gotoxy(129, 18);    printf("%02d/%02d/%04d", U.tgl, U.bulan, U.tahun);
                gotoxy(60, 42); printf("========== klik 0 dan ENTER untuk kembali ==========");

                int updt;
                HapusKanan();
                SpecialkeyloginVertical(menuUpdateUser, 147, 17, 19, 1, 3, 7, &updt);
                switch (updt) {
                    case 1:
//                        uNew.id = 0;    uNew.tgl = 0;   uNew.bulan = 0; uNew.tahun = 0;
//                        strcpy(uNew.nama, "0"); strcpy(uNew.notelp, "0");   strcpy(uNew.password, "0"); strcpy(uNew.role, "0");
                        i = 23;
                        gotoxy(36, i);      printf("ID Karyawan     : EMP%03d", U.id);
                        gotoxy(36, i + 2);  printf("Nama Lengkap    :");
                        gotoxy(36, i + 4);  printf("Password        :");
                        gotoxy(36, i + 6);  printf("Password ulang  :");
                        gotoxy(36, i + 8);  printf("No Telp         :");
                        gotoxy(36, i + 10); printf("Tanggal Lahir   : YYYY/MM/DD");
                        gotoxy(36, i + 12); printf("Jabatan         :");

                        // input data baru
                        gotoxy(54, i + 2);  getletter(uNew.nama, 30);
                        strcpy(U.nama, uNew.nama);

                        gotoxy(54, i + 4);  getpass(uNew.password, 15);
                        if(strcmp(uNew.password, "0") == 0) {
                            HapusTengah();
                            MasterUser();
                        }

                        found = 0;
                        do {
                            // input usn
                            char pass [15];
                            gotoxy(54, i + 6); getpass(pass, 15);
                            if (strcmp(pass, "0") == 0) {
                                HapusTengah();
                                MasterUser();
                            } else if (strcmp(uNew.password, pass) == 0) {
                                found = 1;
                            }

                            if (!found) {
                                MessageBox(NULL, "Password tidak sesuai, ulangi!", "Notification", MB_OK | MB_DEFAULT_DESKTOP_ONLY);
                                clearArea(54, i + 6, 15, 1);
                            }

                        } while (!found);
                        strcpy(U.password, uNew.password);

                        gotoxy(54, i + 8);  getteksnum(uNew.notelp, 13);
                        if (strcmp(uNew.notelp, "0") == 0) {
                            HapusTengah();
                            MasterUser();
                        }
                        strcpy(U.notelp, uNew.notelp);

                        // tanggal
                        int a = 54;
                        int b = i + 10;
                        DateTime dateNow;
                        DateTimeNow(&dateNow);
                        do {
                            gotoxy(a, b); getnum(&uNew.tahun, 4);
                            if (uNew.tahun == 0) {
                                MasterUser();
                            } else if (uNew.tahun > dateNow.tahun) {
                                MessageBox (NULL, "Jangka tahun tidak boleh lebih dari tahun ini!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
                                clearArea(a, b, 4, 1);
                                gotoxy(a, b);   printf("YYYY");
                            }
                        } while (uNew.tahun > dateNow.tahun);

                        do {
                            gotoxy(a + 5, b); getnum(&uNew.bulan, 2);
                            if(uNew.bulan == 0) {
                                MasterUser();
                            } else if (uNew.bulan < 0 || uNew.bulan > 12) {
                                MessageBox(NULL, "Jangka bulan tidak boleh lebih dari dari 12!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
                                clearArea(a + 5, b, 2, 1);
                                gotoxy(a + 5, b); printf("MM");
                            }
                        } while (uNew.bulan < 0 || uNew.bulan > 12);

                        int condi;
                        do {
                            gotoxy(a + 8,b);  getnum(&uNew.tgl, 2);
                            if (uNew.tgl == 0) {
                                HapusKanan();
                                MasterUser();
                            } else if (uNew.tahun % 400 == 0 && uNew.bulan == 2 && uNew.tgl > 29) {
                                condi = 1;
                                MessageBox(NULL, "Tidak boleh dari 29!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
                                clearArea(a + 8, b, 2, 1);
                                gotoxy(a + 8, b); printf("DD");
                            } else if (uNew.tahun % 400 != 0 && uNew.bulan == 2 && uNew.tgl > 28) {
                                condi = 2;
                                MessageBox(NULL, "Tidak boleh dari 28!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
                                clearArea(a + 8, b, 2, 1);
                                gotoxy(a + 8, b); printf("DD");
                            } else if (uNew.bulan % 2 == 0 && uNew.tgl > 30) {
                                condi = 3;
                                MessageBox(NULL, "Tidak boleh dari 30!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
                                clearArea(a + 8, b, 2, 1);
                                gotoxy(a + 8, b); printf("DD");
                            } else if (uNew.bulan % 2 != 0 && uNew.tgl > 31) {
                                condi = 4;
                                MessageBox(NULL, "Tidak boleh dari 31!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
                                clearArea(a + 8, b, 2, 1);
                                gotoxy(a + 8, b); printf("DD");
                            } else {
                                break;
                            }
                        } while (uNew.tgl < 0 || condi == 1 || condi == 2 || condi == 3 || condi == 4);

                        U.tgl = uNew.tgl;   U.bulan = uNew.bulan;   U.tahun = uNew.tahun;

                        // update role
                        Pilihan(54, i + 12, 15, uNew.role, 3, ROLE);
                        strcpy(U.role, uNew.role);
                        break;
                    case 2:
                        i = 23;
                        gotoxy(36, i);      printf("ID Karyawan     : EMP%03d", U.id);
                        gotoxy(36, i + 2);  printf("Nama Karyawan   :");
                        gotoxy(54, i + 2);  getletter(uNew.nama, 25);
                        strcpy(U.nama, uNew.nama);
                        break;
                    case 3:
                        i = 23;
                        gotoxy(36, i);      printf("ID Karyawan     : EMP%03d", U.id);
                        gotoxy(36, i + 2);  printf("Password        :");
                        gotoxy(36, i + 4);  printf("Password ulang  :");

                        gotoxy(54, i + 2);  getpass(uNew.password, 15);
                        found = 0;
                        do {
                            // input usn
                            char pass [15];
                            gotoxy(54, i + 4); getpass(pass, 15);
                            if (strcmp(pass, "0") == 0) {
                                HapusTengah();
                                MasterUser();
                            } else if (strcmp(uNew.password, pass) == 0) {
                                found = 1;
                            }

                            if (found == 0) {
                                MessageBox(NULL, "Password tidak sesuai, ulangi!", "Notification", MB_OK | MB_ICONERROR |MB_DEFAULT_DESKTOP_ONLY);
                                clearArea(54, i + 4, 15, 1);
                            }

                        } while (!found);

                        strcpy(U.password, uNew.password);
                        break;
                    case 4:
                        i = 23;
                        gotoxy(36, i);      printf("ID Karyawan : EMP%03d", U.id);
                        gotoxy(36, i + 2);  printf("Jabatan     :");
                        Pilihan(50, i + 2, 15, uNew.role, 3, ROLE);
                        strcpy(U.role, uNew.role);
                        break;
                    case 5:
                        i = 23;
                        gotoxy(36, i);      printf("ID Karyawan : EMP%03d", U.id);
                        gotoxy(36, i + 2);  printf("No Telp     :");
                        gotoxy(50, i + 2);  getteksnum(uNew.notelp, 15);
                        strcpy(U.notelp, uNew.notelp);
                        break;
                    case 6:
                        i = 23;
                        gotoxy(36, i);      printf("ID Karyawan     : EMP%03d", U.id);
                        gotoxy(36, i + 2);  printf("Tanggal Lahir   : YYYY/MM/DD");

                        DateTimeNow(&dateNow);
                        // tanggal
                        a = 54;
                        b = i + 2;
                        do {
                            fflush(stdin);
                            gotoxy(a, b); getnum(&uNew.tahun, 4);
                            if (uNew.tahun == 0) {
                                MasterUser();
                            } else if (uNew.tahun > dateNow.tahun) {
                                MessageBox (NULL, "Jangka tahun tidak boleh lebih dari tahun ini!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
                                clearArea(a, b, 4, 1);
                                gotoxy(a, b);   printf("YYYY");
                            }
                        } while (uNew.tahun > dateNow.tahun);

                        do {
                            gotoxy(a + 5, b); getnum(&uNew.bulan, 2);
                            if(uNew.bulan == 0) {
                                MasterUser();
                            } else if (uNew.bulan < 0 || uNew.bulan > 12) {
                                MessageBox(NULL, "Jangka bulan tidak boleh lebih dari dari 12!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
                                clearArea(a + 5, b, 2, 1);
                                gotoxy(a + 5, b); printf("MM");
                            }
                        } while (uNew.bulan < 0 || uNew.bulan > 12);

                        condi = 0;
                        do {
                            gotoxy(a + 8,b);  getnummin(&uNew.tgl, 1, 2);
                            if (uNew.tgl == 0) {
                                MasterUser();
                            } else if (uNew.tahun % 400 == 0 && uNew.bulan == 2 && uNew.tgl > 29) {
                                condi = 1;
                                MessageBox(NULL, "Tidak boleh dari 29!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
                                clearArea(a + 8, b, 2, 1);
                                gotoxy(a + 8, b); printf("DD");
                            } else if (uNew.tahun % 400 != 0 && uNew.bulan == 2 && uNew.tgl > 28) {
                                condi = 2;
                                MessageBox(NULL, "Tidak boleh dari 28!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
                                clearArea(a + 8, b, 2, 1);
                                gotoxy(a + 8, b); printf("DD");
                            } else if (uNew.bulan % 2 == 0 && uNew.tgl > 30) {
                                condi = 3;
                                MessageBox(NULL, "Tidak boleh dari 30!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
                                clearArea(a + 8, b, 2, 1);
                                gotoxy(a + 8, b); printf("DD");
                            } else if (uNew.bulan % 2 != 0 && uNew.tgl > 31) {
                                condi = 4;
                                MessageBox(NULL, "Tidak boleh dari 31!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
                                clearArea(a + 8, b, 2, 1);
                                gotoxy(a + 8, b); printf("DD");
                            } else {
                                break;
                            }
                        } while (uNew.tgl < 0 || condi == 1 || condi == 2 || condi == 3 || condi == 4);

                        U.tgl = uNew.tgl;   U.bulan = uNew.bulan;   U.tahun = uNew.tahun;
                        break;
                    case 7:
                        HapusTengah();
                        MasterUser();
                        break;
                }

                fwrite(&U, sizeof(U), 1, Temp);

                while (fread(&U, sizeof(U), 1, Asal) == 1) {
                    fwrite(&U, sizeof(U), 1, Temp);
                }

                MessageBox(NULL, "Data Berhasil Diupdate!", "NOTIFICATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                break;
            case 2:
                HapusTengah();

                fwrite(&U, sizeof(U), 1, Temp);
                while (fread(&U, sizeof(U), 1, Asal) == 1) {
                    fwrite(&U, sizeof(U), 1, Temp);
                }

                break;
        }

        fclose(Asal);
        fclose(Temp);

        remove("../Dat/Karyawan.dat");
        rename("../Dat/Temp.dat", "../Dat/Karyawan.dat");

        int answ;
        do {
            HapusTengah();
            gotoxy(73, 25);  printf("Ingin mengubah data lain?");
            SpecialkeyloginHorizontal(yntengah, 74, 27, 9, 1, 13, 2, &answ);
            HapusTengah();
            HapusKanan();
            switch (answ) {
                case 1:
                    updateUser();
                    break;
                case 2:
                    MasterUser();
                    break;
            }
        } while (answ == 1);


    } else {
        MessageBox(NULL, "ID Karyawan tidak ditemukan!", "NOTIFICATION", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        HapusTengah();
        updateUser();
    }
}

void deleteUser () {

    FILE *Asal;
    int KodeUser;
    int found;
    int ans = 0;
    FILE *Temp;

    readUser();

    gotoxy(60, 42); printf("========== klik 0 dan ENTER untuk kembali ==========");
    Tunggu(5);
    gotoxy(30, i + 3);
    printf("Masukkan ID : EMP");
    gotoxy(47, i + 3);  getnum(&KodeUser, 3);
    if(KodeUser == 0) {
        HapusTengah();
        MasterUser();
    }

    Asal = fopen("../Dat/Karyawan.dat", "rb");
    Temp = fopen("../Dat/Temp.dat", "wb");

    found = 0;
    while (found == 0 && fread(&U, sizeof(U), 1, Asal) == 1) {
        if (U.id == KodeUser) {
            found = 1;
        } else {
            fwrite(&U, sizeof(U), 1, Temp);
        }
    }

    if (found == 1) {
        HapusTengah();
        gotoxy(36, 15); printf("Data karyawan yang ingin dihapus");
        gotoxy(36, 18); printf("ID Karyawan     : EMP%03d", U.id);
        gotoxy(36, 20); printf("Nama Lengkap    : %s", U.nama);
        gotoxy(36, 22); printf("Username        : %s", U.username);
        gotoxy(36, 24); printf("Password        : %s", U.password);
        gotoxy(36, 26); printf("Jabatan         : %s", U.role);
        gotoxy(36, 28); printf("No Telp         : %s", U.notelp);
        gotoxy(36, 30); printf("Tanggal Lahir   : %02d/%02d/%04d", U.tgl, U.bulan, U.tahun);

        gotoxy(71, 39); printf("Ingin menghapus data karyawan ?");
        SpecialkeyloginHorizontal(YN, 74, 40, 9, 1, 13, 2, &ans);
        switch (ans) {
            case 1:
                while (fread(&U, sizeof(U), 1, Asal) == 1) {
                    fwrite(&U, sizeof(U), 1, Temp);
                }

                MessageBox(NULL, "Data Berhasil Dihapus", "NOTIFICATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                break;
            case 2:
                fwrite(&U, sizeof(U), 1, Temp);

                while (fread(&U, sizeof(U), 1, Asal) == 1) {
                    fwrite(&U, sizeof(U), 1, Temp);
                }
                break;
        }

        fclose(Asal);
        fclose(Temp);

        remove("../Dat/Karyawan.dat");
        rename("../Dat/Temp.dat", "../Dat/Karyawan.dat");

        int answ;
        do {
            HapusTengah();
            gotoxy(73, 25);  printf("Ingin menghapus data lain ?");
            SpecialkeyloginHorizontal(yntengah, 74, 27, 9, 1, 13, 2, &answ);
            HapusTengah();
            switch (answ) {
                case 1:
                    deleteUser();
                    break;
                case 2:
                    MasterUser();
                    break;
            }
        } while (answ == 1);

    } else {
        MessageBox(NULL, "ID Karyawan tidak ditemukan!", "NOTIFICATION", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        HapusTengah();
        deleteUser();
    }

}