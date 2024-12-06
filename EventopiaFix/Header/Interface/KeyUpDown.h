typedef void (*Procedur)(int);

void BorderSwitchRole(int x, int y, int lebar, int tinggi){
    //untuk kiri atas/
    gotoxy(x,y);printf("%c", 201);

    int a;
    a = x + 1;
    for(i = 0; i < lebar; i++){
        gotoxy(a,y);printf("%c",205); //untuk asci tepi atas =/
        a++;
    }

    //untuk kanan atas/
    gotoxy(a,y);printf("%c", 187);

    int b;
    b = y + 1;
    for (j = 0; j < tinggi; j++) {
        gotoxy(x,b);printf("%c",186);//untuk ascii tepi sama dengan miring kiri tengah/
        gotoxy(a,b);printf("%c",186);//untuk ascii tepi sama dengan miring kiri tengah/
        b++;
    }

    gotoxy(x,b);printf("%c",200);//untuk sudut kiri bawah/
    a = x + 1;
    for(i = 0; i < lebar; i++){
        gotoxy(a,b);printf("%c",205);//untuk tepi bawah =/
        a++;
    }
    gotoxy(a,b);printf("%c",188);//untuk sudut kanan bawah/
}

void SpecialkeyloginVertical(Procedur procedur, int x, int y, int lebar, int tinggi, int hapus, int countmax, int *output) {
    //Declaration
    int count = 1;
    char ch;

    //Algorithm
    procedur(0);
    BorderSwitchRole(x, y, lebar, tinggi);

    while (1) {
        ch = getch();
        if (ch == ENTER || ch == TAB) {
            switch (count) {
                case 1 :
                    Beep(3000, 100);
                    *output = count;
                    break;

                case 2 :
                    Beep(3000, 100);
                    *output = count;
                    break;

                case 3 :
                    Beep(3000, 100);
                    *output = count;
                    break;
                case 4 :
                    Beep(3000, 100);
                    *output = count;
                    break;
                case 5 :
                    Beep(3000, 100);
                    *output = count;
                    break;
                case 6 :
                    Beep(3000, 100);
                    *output = count;
                    break;
                case 7 :
                    Beep(3000, 100);
                    *output = count;
                    break;
                case 8 :
                    Beep(3000, 100);
                    *output = count;
                    break;
                case 9 :
                    Beep(3000, 100);
                    *output = count;
                    break;
            }
            break;
        } else if (ch == UP_KEY) {
            if (count > 1) {
                Beep(1000, 100);
                clearArea(x, y, lebar + 2, tinggi + hapus);
                y -= hapus;  // Geser ke atas sebanyak 4 unit
                BorderSwitchRole(x, y, lebar, tinggi);
                procedur(0);
                count--;
            }
        } else if (ch == DWN_KEY) {
            if (count < countmax) {
                Beep(1000, 100);
                clearArea(x, y, lebar + 2, tinggi + hapus);
                y += hapus;  // Geser ke bawah sebanyak 4 unit
                BorderSwitchRole(x, y, lebar, tinggi);
                procedur(0);
                count++;
            }
        }
    }
}

void menuHorizontal () {

    gotoxy(15, 10);
    printf("L O G I N");
    gotoxy(40, 10);
    printf("K E L U A R");
}

void SpecialkeyloginHorizontal(Procedur procedur, int x, int y, int lebar, int tinggi, int hapus, int countmax, int *output) {
    //Declaration
    int count = 1;
    char ch;

    //Algorithm
    procedur(0);
    BorderSwitchRole(x, y, lebar, tinggi);

    while (1) {
        ch = getch();
        if (ch == ENTER || ch == TAB) {
            switch (count) {
                case 1 :
                    Beep(3000, 100);
                    *output = count;
                    break;

                case 2 :
                    Beep(3000, 100);
                    *output = count;
                    break;

                case 3 :
                    Beep(3000, 100);
                    *output = count;
                    break;

                case 4 :
                    Beep(3000, 100);
                    *output = count;
                    break;
            }
            break;
        } else if (ch == LEFT_KEY) {
            if (count > 1) {
                Beep(1000, 100);
                clearArea(x, y, lebar + hapus, tinggi + 2);
                x -= hapus;  // Geser ke atas sebanyak 4 unit
                BorderSwitchRole(x, y, lebar, tinggi);
                procedur(0);
                count--;
            }
        } else if (ch == RIGHT_KEY) {
            if (count < countmax) {
                Beep(1000, 100);
                clearArea(x, y, lebar + hapus, tinggi + 2);
                x += hapus;  // Geser ke bawah sebanyak 4 unit
                BorderSwitchRole(x, y, lebar, tinggi);
                procedur(0);
                count++;
            }
        }
    }
}