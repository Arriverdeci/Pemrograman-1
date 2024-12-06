void fullscreen();
void SetBackGroundColor (int color);
void gotoxy(int x,int y);
void gotoprintchar (int x, int y, int dec);
void SetColorBlock (int foreground, int background);
void clearArea(int x, int y, int width, int height);
void Loading (int duration);
void PrintFile(char file[], int x, int y);

void fullscreen() {
    keybd_event(VK_MENU,0x38,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

void SetBackGroundColor (int color) {

    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);
    WORD originalAttrs = bufferInfo.wAttributes;

    // Mengatur latar belakang
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color | (originalAttrs & 0xFFF));

    // Menampilkan teks dengan latar belakang berwarna
    printf("Ini adalah teks dengan latar belakang berwrna!\n");

    // Mengembalikan warna ke default
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), originalAttrs);
}

//void gotoxy (int x, int y) {
//
//    COORD coord = {0, 0};
//    coord.X = x;
//    coord.Y = y;
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//
//}

void gotoprintchar (int x, int y, int dec) {

    gotoxy(x, y);
    printf("%c", dec);

}

void SetColorBlock (int foreground, int background) {

    int color = foreground + (background << 4);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);

}

void clearArea(int x, int y, int width, int height) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD topLeft = {(SHORT) x, (SHORT) y};
    DWORD written;

    for (int row = 0; row < height; ++row) {
        FillConsoleOutputCharacterA(console, ' ', width, topLeft, &written);
        topLeft.Y++;
    }
}

void Loading (int duration) {

    gotoprintchar(56,16,201);
    for( i = 0; i < 21; i++){
        gotoprintchar(57+i,16,205);
    }
    gotoprintchar(77,16,187);

    gotoprintchar(56,17,186);
    gotoprintchar(77,17,186);

    gotoprintchar(56,18,200);
    for( i = 0; i < 21; i++){
        gotoprintchar(57+i,18,205);
    }
    gotoprintchar(77, 18, 188);

    int x;
    int persen = 0;
    gotoxy(57, 17);
    printf("Loading ");

    x = 40;
    for ( i = 0; i < 1; i++) {
        for( j = 0; j < 51; j++){
            gotoprintchar(x,18,178);
            x++;
            gotoxy(73, 17);
            printf("%d%%",persen);
            persen += 2;
            fflush(stdout);
            usleep(1 * 100000); // Waktu jeda dalam mikrodetik
        }
    }

    fflush(stdout);
    usleep(5 * 100000);

    clearArea(37,16,55,4);
    gotoxy(63,17);
    printf("Complete!\n");
    fflush(stdout);
    usleep(duration * 100000);

}

void PrintFile(char file[], int x, int y) {

    FILE *Text;
    char Data[500];
    if((Text=fopen(file, "r")) == NULL) {
        system("cls");
    }

    while(fgets(Data, 500, Text)) {
        gotoxy(x, y);
        printf("%s", Data);
        y++;
    }
    fclose(Text);

}

// setting pw jadi bintang pas diinput
void takePassword (char pwds[50]) {

    int is = 0;
    char chs;
    while(1) {
        chs = getch();
        if(chs == ENTER) {
            pwds[is]='\0';
            break;
        } else if(chs == BACKSPACE) {
            if(is > 0) {
                is--;
                printf("\b \b");
            }
        } else {
            pwds [is] = chs;
            printf("*");
            is++;
        }
    }
}

void takeZero (char pwds[50]) {

    int is;
    char chs;
    while(1) {
        chs = getch();
        if(chs == 13 || chs == 9) {
            pwds[is]='\0';
            break;
        } else if(chs == 8) {
            if(is > 0) {
                is--;
                printf("\b \b");
            }
        } else {
            pwds[is++] = chs;
            printf("  \b");
        }
    }

}

void Tanggal(int x, int y) {

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char *wday[] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};

    gotoxy(x, y);
    printf("%s, ", wday[tm.tm_wday]);
    gotoxy(x + 8, y);
    printf("%02d - %02d - %d", tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900);

}

void HapusKiri () {

    clearArea(4, 12, 21, 31);
}

void HapusTengah () {

    clearArea(27, 12, 118, 31);

}

void HapusKanan () {

    clearArea(147, 12, 21, 31);

}

void HapusAll () {

    clearArea(4, 2, 164, 40);
}

void Tunggu (int duration) {

    fflush(stdout);
    usleep(duration * 100000);

}

void remove_scrollbar() {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle, &info);
    COORD new_size =
            {
                    info.srWindow.Right - info.srWindow.Left + 1,
                    info.srWindow.Bottom - info.srWindow.Top + 1
            };
    SetConsoleScreenBufferSize(handle, new_size);
}

void gotoprint (int x, int y, char text [500]) {

    gotoxy(x, y);
    printf("%s", text);

}

void angka (char string[100]) {

    char ch;
    int length = 0;
    while (1) {
        karakter = getch();

        if (isdigit(karakter)) {
                printf("%c", karakter);
                string[length] = karakter;
                length++;
        } else if (karakter == 13) {  // 13 adalah kode ASCII untuk tombol Enter
            for (int l = length; l <= 100 ; l++) {
                string[l] = '\0';
            }
            break; // Keluar dari loop saat tombol Enter ditekan
        } else if (karakter == 8) {
            if (length > 0) {
                printf("%c %c", karakter, karakter);
                length--;
                string[length] = karakter;
            }

        }

    }

}

//void chartoint (int num) {
//
//    char ch;
//    int length = 0;
//    while (1) {
//        ch = getch();
//
//        if (isdigit(karakter)) {
//            printf("%c", karakter);
//            string[length] = karakter;
//            length++;
//        } else if (karakter == 13) {  // 13 adalah kode ASCII untuk tombol Enter
//            for (int l = length; l <= 100 ; l++) {
//                string[l] = '\0';
//            }
//            break; // Keluar dari loop saat tombol Enter ditekan
//        } else if (karakter == 8) {
//            if (length > 0) {
//                printf("%c %c", karakter, karakter);
//                length--;
//                string[length] = karakter;
//            }
//
//        }
//
//    }
//
//}

void stringtoint (int nilaiInteger) {
//    char karakter;
    char karakterStr[50]; // Ukuran string sesuaikan dengan kebutuhan

//    printf("Masukkan sebuah string angka (tekan Enter untuk selesai): ");

    i = 0;
    do {
        karakter = getch(); // Menerima karakter tanpa menampilkannya

        // Menyimpan karakter ke dalam string
        if (karakter != '\r' && karakter != '\n') {
            putchar(karakter); // Menampilkan karakter yang dimasukkan
            karakterStr[i] = karakter;
            i++;
        } else {
           break;
        }

    } while (karakter != '\r' && karakter != '\n');

    karakterStr[i] = '\0'; // Menambahkan null terminator untuk membentuk string

    // Mengonversi string ke integer
    nilaiInteger = atoi(karakterStr);


}

void TanggalJam(int x, int y) {

//    for (i = x; i <= x + 17;i++) {
//        gotoxy(i, y); printf("\xcd");
//        gotoxy(i, y + 4); printf("\xcd");
//    }

    DateTime dateNow;
    DateTimeNow(&dateNow);
    gotoxy(x, y);           printf("%02d/%02d/%04d", dateNow.tanggal, dateNow.bulan, dateNow.tahun);
    gotoxy(x + 1, y + 2);    printf("%02d:%02d WIB", dateNow.hour, dateNow.min);
}

void Pilihan(int x, int y, int lebar, char kalimat[20], int countmax, char Metode[5][20]) {

    int kali = 0;
    char ch;
    int selectedOption = 0;
    char kata[20];

    SetColorBlock(0,14);

    // Display the initial status
    gotoxy(x, y);
    printf("%s", Metode[selectedOption]);

    while (1) {
        ch = getch();

        kali++;
        if (ch == 13) {  // Enter key
            if (kali == 1) {
                selectedOption = 0;
                strcpy(kata, Metode[selectedOption]);
                strcpy(kalimat, kata);
            }
            break;
        } else if (ch == 72) {  // Up arrow key
            if (selectedOption > 0) {
                // Membersihkan tampilan sebelumnya
                clearArea(x, y, lebar, 1);
//                gotoxy(x, y);   printf("                    ");
                // Mengganti opsi
                selectedOption--;
//                selectedOption = (selectedOption - 1 + 2) % 2;
            }
        } else if (ch == 80) {  // Down arrow key
            if (selectedOption < countmax) {
                // Membersihkan tampilan sebelumnya
                clearArea(x, y, lebar, 1);
//                gotoxy(x, y);   printf("                    ");
                // Mengganti opsi
                selectedOption++;
//            selectedOption = (selectedOption + 1) % 2;
            }
        }

        // Update the display based on the selected option
        gotoxy(x, y);   printf("%s", Metode[selectedOption]);
        strcpy(kata, Metode[selectedOption]);
        strcpy(kalimat, kata);
    }
}


void ValidDate (int x, int y, int *date, int *month, int *year) {

    DateTime dateNow;
    DateTimeNow(&dateNow);

    int tgl, bulan, tahun;
    do {
        gotoxy(x, y); getnummin(&tahun, 3, 4);
        if (tahun == 0) {
            break;
        } else if (tahun > dateNow.tahun) {
            MessageBox (NULL, "Jangka tahun tidak boleh lebih dari tahun ini!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(x, y, 4, 1);
            gotoxy(x, y);   printf("YYYY");
        }
    } while (tahun > dateNow.tahun);
    *year = tahun;

    do {
        gotoxy(x + 5, y); getnum(&bulan, 2);
        if(bulan == 0) {
            break;
        } else if (bulan < 0 || bulan > 12) {
            MessageBox(NULL, "Jangka bulan tidak boleh lebih dari dari 12!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(x + 5, y, 2, 1);
            gotoxy(x + 5, y); printf("MM");
        }
    } while (bulan < 0 || bulan > 12);
    *month = bulan;

    int condi;
    do {
        gotoxy(x + 8,y);  getnummin(&tgl, 1, 2);
        if (tgl == 0) {
            break;
        } else if (tahun % 400 == 0 && bulan == 2 && tgl > 29) {
            condi = 1;
            MessageBox(NULL, "Tidak boleh dari 29!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(x + 8, y, 2, 1);
            gotoxy(x + 8, y); printf("DD");
        } else if (tahun % 400 != 0 && bulan == 2 && tgl > 28) {
            condi = 2;
            MessageBox(NULL, "Tidak boleh dari 28!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(x + 8, y, 2, 1);
            gotoxy(x + 8, y); printf("DD");
        } else if (bulan % 2 == 0 && tgl > 30) {
            condi = 3;
            MessageBox(NULL, "Tidak boleh dari 30!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(x + 8, y, 2, 1);
            gotoxy(x + 8, y); printf("DD");
        } else if (bulan % 2 != 0 && tgl > 31) {
            condi = 4;
            MessageBox(NULL, "Tidak boleh dari 31!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(x + 8, y, 2, 1);
            gotoxy(x + 8, y); printf("DD");
        } else {
            break;
        }
    } while (U.tgl < 0 || condi == 1 || condi == 2 || condi == 3 || condi == 4);
    *date = tgl;
}

void HapusTRKanan () {

    clearArea(98, 12, 70, 31);

}

void HapusTRKiri () {

    clearArea(27, 12, 70, 31);
}