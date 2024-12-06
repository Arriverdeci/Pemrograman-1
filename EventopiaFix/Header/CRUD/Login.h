FILE *usr;
void MenuAdmin ();
void MenuEO ();
void MenuManajer ();
void MenuPemasaran ();

void tampilanawal () {

    Background();

}

void Login () {

    Background();
    TampilanDepan();
    borderlogin();

    int trylogin = 0;
    char usn [50];
    char pw [50];

    do {
        trylogin++;
        clearArea(81, 28, 15, 1);
        clearArea(81, 32, 15, 1);
        fflush(stdin);
        gotoxy(81, 28);  getteks(usn,15);
        if (strcmp(usn, "0") == 0) {
            exit(0);
        }

        fflush(stdin);
        gotoxy(81, 32); getpass(pw, 15);
        if (strcmp(pw, "0") == 0) {
            exit(0);
        }

        usr = fopen("../Dat/Karyawan.dat", "rb");
        while (fread(&U, sizeof(U), 1, usr) == 1) {
            if (strcmp(U.username, usn) == 0 && strcmp(U.password, pw) == 0) {
                int roleint;
                rltoint(U.role, &roleint);
                switch (roleint) {
                    case 1:
                        MessageBoxA(NULL,"Welcome To Admin!","NOTIFICATION",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                        HapusAll();
                        ROLES = 1;
                        strcpy(emp, U.nama);
//                        gotoxy(10, 5);  printf(" M E N U ");
//                        gotoxy(10, 7);  printf("A D M I N");
                        fclose(usr);
                        MenuAdmin ();
                        break;
                    case 2:
                        MessageBoxA(NULL,"Welcome To EO!","NOTIFICATION",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                        HapusAll();
                        ROLES = 2;
                        strcpy(emp, U.nama);
//                        gotoxy(10, 5);  printf("M E N U");
//                        gotoxy(10, 7);  printf("  E O  ");
                        fclose(usr);
                        MenuEO();
                        break;
                    case 3:
                        MessageBoxA(NULL,"Welcome To Manajer!","NOTIFICATION",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                        HapusAll();
                        ROLES = 3;
                        strcpy(emp, U.nama);
//                        gotoxy(10, 5);  printf("   M E N U   ");
//                        gotoxy(10, 7);  printf("M A N A J E R");
                        fclose(usr);
                        MenuManajer();
                        break;
                    case 4:
                        MessageBoxA(NULL,"Welcome To Pemasaran!","NOTIFICATION",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                        HapusAll();
                        ROLES = 4;
                        strcpy(emp, U.nama);
//                        gotoxy(10, 5);  printf("     M E N U     ");
//                        gotoxy(10, 7);  printf("P E M A S A R A N");
                        fclose(usr);
                        MenuPemasaran();
                        break;
                }
            }
        }

        if (trylogin < 3 && ROLES != 1 && ROLES != 2 && ROLES != 3 && ROLES != 4) {
            MessageBoxA(NULL,"Username Atau Password Tidak Sesuai!","ERROR",MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
        } else if (trylogin == 3 && ROLES != 1 && ROLES != 2 && ROLES != 3 && ROLES != 4) {
            out = MessageBoxA(NULL, "Login mencapai batas maksimum. Ingin keluar?", "Notofication", MB_OKCANCEL | MB_ICONQUESTION | MB_DEFAULT_DESKTOP_ONLY);
            if (out == IDOK) {
                Beep(3000, 100);
                break;
            } else if (out == IDCANCEL) {
                Beep(3000, 100);
                fclose(usr);
                Login();
                break;
            }
        }

        fclose(usr);
    } while (trylogin < 3 || ROLES != 1 && ROLES != 2 && ROLES != 3 && ROLES != 4);

}

void Admin () {
    gotoxy(7,15);printf("D E K O R A S I");
    gotoxy(7,18);printf("    J A S A    ");
    gotoxy(7,21);printf("K A R Y A W A N");
    gotoxy(7,24);printf("   K L I E N   ");
    gotoxy(7,27);printf("      M C      ");
    gotoxy(7,30);printf(" S P O N S O R ");
    gotoxy(7,33);printf("  T E M P A T  ");
    gotoxy(7,36);printf("   A C A R A   ");
    gotoxy(7,39);printf("  K E L U A R  ");
}

void MenuAdmin () {

    HapusKiri();
    garismenu();
    int choose;

    SpecialkeyloginVertical(Admin, 4, 14, 19, 1, 3, 9,&choose);
    switch (choose) {
        case 1:
            MasterDCR();
            break;
        case 2:
            MasterJasa();
            break;
        case 3:
            MasterUser();
            break;
        case 4:
//            MasterKlien();
            break;
        case 5:
//            MasterMC();
            break;
        case 6:
            MasterSponsor();
            break;
        case 7:
            MasterTempat();
            break;
        case 8:
            TransaksiPengajuanAcara();
            break;
        case 9:
            MessageBoxA(NULL,"Thank You","NOTIFICATION",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            Login();
            break;
    }

}

void EO () {

    gotoxy(7, 22);printf("K A R Y A W A N");
    gotoxy(7, 27);printf(" L A P O R A N ");
    gotoxy(7, 32);printf("  K E L U A R  ");

}

void LaporEO () {

    SetColorBlock(0, 0);
    for ( i = 12; i < 44; i++) {
        for ( j = 145; j < 147; j++) {
            gotoprintchar(j, i, 32);
        }
    }

    SetColorBlock(0, 14);
    gotoxy(149,20);printf("  L A P O R A N  ");
    gotoxy(149,22);printf("    A C A R A    ");
    gotoxy(149,26);printf("  L A P O R A N  ");
    gotoxy(149,28);printf("P E N J U A L A N");
    gotoxy(149,33);printf("   K E L U A R   ");

}

void Laporan () {

    int laporan;
    garismenu();

    SpecialkeyloginVertical(LaporEO, 147, 18, 19, 5, 6, 3, &laporan);
    switch (laporan) {
        case 1:
            HapusKanan();
            LaporanAcara();
            break;
        case 2:
            HapusKanan();
            LaporanSV();
            break;
        case 3:
//            SetColorBlock(0, 14);
//            for ( i = 12; i < 43; i++) {
//                for ( j = 145; j < 147; j++) {
//                    gotoprintchar(j, i, 32);
//                }
//            }
            HapusKanan();
            MenuEO();
            break;
    }

}

void MenuEO () {

    int choose;
    HapusKiri();
    garismenu();

    SpecialkeyloginVertical(EO, 4, 20, 19, 3, 5, 3, &choose);
    switch (choose) {
        case 1:
            HapusKiri();
            MasterUser();
            break;
        case 2:
            Laporan();
            break;
        case 3:
            MessageBoxA(NULL,"Thank You","NOTIFICATION",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            Login();
            break;
//        default:
//            MenuEO();
//            break;
    }


}

void Manajer () {

    gotoxy(7, 25);printf("   A C A R A   ");
    gotoxy(7, 29);printf("  K E L U A R  ");

}

void MenuManajer () {

    int choose;
    HapusKiri();
    garismenu();

//    gotoxy(14, 16);
//    printf("M E N U");
//    gotoxy(11, 18);
//    printf("M A N A J E R");

    SpecialkeyloginVertical(Manajer, 4, 23, 19, 3, 4, 2, &choose);
    switch (choose) {
        case 1:
            HapusKiri();
            TransaksiPengajuanAcara();
            break;
        case 2:
//            MessageBoxA(NULL,"Thank You","NOTIFICATION",MB_OK | MB_DEFAULT_DESKTOP_ONLY);
            MessageBoxA(NULL,"Thank You","NOTIFICATION",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);

            Login();
            break;
    }

}

void Pemasaran () {

    gotoxy(6, 19);printf("  P E M A S O K  ");
    gotoxy(6, 23);printf("    P R O M O    ");
    gotoxy(6, 27);printf("  S U V E N I R  ");
    gotoxy(6, 31);printf("J U A L   S V N R");
    gotoxy(6, 35);printf("   K E L U A R   ");

}

void MenuPemasaran () {

    int choose;
    HapusKiri();
    garismenu();

    SpecialkeyloginVertical(Pemasaran, 4, 18, 19, 1, 4, 5, &choose);
    switch (choose) {
        case 1:
            MasterPemasok();
            break;
        case 2:
            MasterPromo();
            break;
        case 3:
            MasterSuvenir();
            break;
        case 4:
            TransaksiPenjualanSUvenir();
            break;
        case 5:
            Login();
            break;
    }

}