void MenuMaster () {

    SetColorBlock(0, 14);
    gotoxy(149, 16);   printf("   T A M B A H   ");
    gotoxy(149, 18);   printf("     D A T A     ");
    gotoxy(149, 21);   printf("     B A C A     ");
    gotoxy(149, 23);   printf("     D A T A     ");
    gotoxy(149, 26);   printf("     U B A H     ");
    gotoxy(149, 28);   printf("     D A T A     ");
    gotoxy(149, 31);   printf("    H A P U S    ");
    gotoxy(149, 33);   printf("     D A T A     ");
    gotoxy(149, 37);   printf("  K E M B A L I  ");

}

char ROLE[5][20] = {"Admin", "EO", "Manajer", "Pemasaran"};
void rltoint (char charrole [15], int *introle) {

    if (strcmp(charrole, "Admin") == 0) {
        *introle = 1;
    } else if (strcmp(charrole, "EO") == 0) {
        *introle = 2;
    } else if (strcmp(charrole, "Manajer") == 0) {
        *introle = 3;
    } else if (strcmp(charrole, "Pemasaran") == 0) {
        *introle = 4;
    }

}

void YN () {

    gotoxy(78, 41); printf("Y A");
    gotoxy(90,41);  printf("TIDAK");

}

void yntengah () {
    gotoxy(78, 28); printf("Y A");
    gotoxy(90, 28); printf("TIDAK");
}