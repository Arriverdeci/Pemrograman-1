void Background ();

void Background () {

    // background full
    SetColorBlock(14, 14);  // fore ground : tulisan
    for ( i = 0; i < 45; i++) {
        for ( j = 0; j < 172; j++) {
            gotoprintchar(j, i, 32);
        }
    }

    // garis atas
    SetColorBlock(0, 0);  // fore ground : tulisan
    for ( i = 1; i < 2; i++) {
        for ( j = 2; j < 170; j++) {
            gotoprintchar(j, i, 32);
        }
    }

    // garis kiri
    for ( i = 1; i < 44; i++) {
        for ( j = 2; j < 4; j++) {
            gotoprintchar(j, i, 32);
        }
    }

    // garis kanan
    for ( i = 1; i < 44; i++) {
        for ( j = 168; j < 170; j++) {
            gotoprintchar(j, i, 32);
        }
    }

    // garis bawah
    for ( i = 43; i < 44; i++) {
        for ( j = 2; j < 170; j++) {
            gotoprintchar(j, i, 32);
        }
    }
}

void TampilanDepan () {

    SetColorBlock(0, 14);
    PrintFile("../Text/Welcome to Eventopia.txt", 46, 6);
}

void borderlogin () {

    SetColorBlock(0, 14);

    // border usn
    gotoprintchar(65, 28, 186);
    gotoprintchar(65, 27, 201);
    gotoprintchar(65, 29, 200);
    for (j = 66; j < 100; j++) {
        gotoprintchar(j, 27, 205);
        gotoprintchar(j, 29, 205);
    }
    gotoprintchar(100, 27, 187);
    gotoprintchar(100, 29, 188);
    gotoprintchar(100, 28, 186);

    // border pw
    gotoprintchar(65, 32, 186);
    gotoprintchar(65, 31, 201);
    gotoprintchar(65, 33, 200);
    for (j = 66; j < 100; j++) {
        gotoprintchar(j, 31, 205);
        gotoprintchar(j, 33, 205);
    }
    gotoprintchar(100, 31, 187);
    gotoprintchar(100, 33, 188);
    gotoprintchar(100, 32, 186);

    gotoxy(70, 28);
    printf("USERNAME :");
    gotoxy(70, 32);
    printf("PASSWORD :");

    gotoxy(69, 26); printf("--- ketik 0 untuk keluar ---");

}

void garismenu () {

    // garis berdiri
    SetColorBlock(0, 0);
    for ( i = 12; i < 44; i++) {
        for ( j = 25; j < 27; j++) {
            gotoprintchar(j, i, 32);
        }
    }

    // garis miring
    for ( i = 11; i < 12; i++) {
        for ( j = 2; j < 170; j++) {
            gotoprintchar(j, i, 32);
        }
    }

    // border tanggal
//    for ( i = 5; i < 6; i++) {
//        for ( j = 2; j < 33; j++) {
//            gotoprintchar(j, i, 32);
//        }
//    }

    // garis berdiri kanan
    for ( i = 12; i < 44; i++) {
        for ( j = 145; j < 147; j++) {
            gotoprintchar(j, i, 32);
        }
    }

    SetColorBlock(0, 14);
    PrintFile("../Text/Eventopia.txt", 49, 3);

    TanggalJam (152, 5);

    switch (ROLES) {
        case 1:
            gotoxy(10, 5);  printf(" M E N U ");
            gotoxy(10, 7);  printf("A D M I N");
            break;
        case 2:
            gotoxy(10, 5);  printf("M E N U");
            gotoxy(10, 7);  printf("  E O  ");
            break;
        case 3:
            gotoxy(10, 5);  printf("   M E N U   ");
            gotoxy(10, 7);  printf("M A N A J E R");
            break;
        case 4:
            gotoxy(10, 5);  printf("     M E N U     ");
            gotoxy(10, 7);  printf("P E M A S A R A N");
            break;
    }

}

void TeksTempat () {

    SetColorBlock(0, 7);
    PrintFile("Master Tempat.txt", 4, 14);

}

void garisTrnsksi () {

    SetColorBlock(0, 0);

    // garis berdiri
    for ( i = 12; i < 44; i++) {
        for ( j = 25; j < 27; j++) {
            gotoprintchar(j, i, 32);
        }
    }

    // garis miring
    for ( i = 11; i < 12; i++) {
        for ( j = 2; j < 170; j++) {
            gotoprintchar(j, i, 32);
        }
    }

    // garis tengah
    for (i = 12; i < 44; i++) {
        for ( j = 97; j < 98; j++) {
            gotoprintchar(j, i, 32);

        }
    }

    SetColorBlock(0, 14);
    PrintFile("../Text/Eventopia.txt", 49, 3);

    TanggalJam (152, 5);

//    switch (ROLES) {
//        case 1:
//            gotoxy(10, 5);  printf(" M E N U ");
//            gotoxy(10, 7);  printf("A D M I N");
//            break;
//        case 2:
//            gotoxy(10, 5);  printf("M E N U");
//            gotoxy(10, 7);  printf("  E O  ");
//            break;
//        case 3:
//            gotoxy(10, 5);  printf("   M E N U   ");
//            gotoxy(10, 7);  printf("M A N A J E R");
//            break;
//        case 4:
//            gotoxy(10, 5);  printf("     M E N U     ");
//            gotoxy(10, 7);  printf("P E M A S A R A N");
//            break;
//    }

}