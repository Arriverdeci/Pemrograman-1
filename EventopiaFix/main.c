#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <utilapiset.h>
#include <time.h>
#include <stdbool.h>
//#include <strtol>


#include "Header/Interface/Deklarasi.h"
#include "Header/Interface/lib.h"
#include "Header/Interface/Design.h"
#include "Header/Interface/Tampilan.h"
#include "Header/Interface/KeyUpDown.h"
#include "Header/Interface/Procedure.h"

#include "Header/CRUD/Master Tempat.h"
#include "Header/CRUD/Master Jasa.h"
#include "Header/CRUD/Master Karyawan.h"
#include "Header/CRUD/Sponsor.h"
//#include "Header/CRUD/Pembawa Acara.h"
#include "Header/CRUD/Dekorasi.h"
#include "Header/CRUD/Promo.h"
//#include "Header/CRUD/Klien.h"
#include "Header/CRUD/Master Pemasok.h"
#include "Header/CRUD/Master Suvenir.h"
#include "Header/CRUD/Penjualan.h"
#include "Header/CRUD/Pengajuan.h"
#include "Header/CRUD/Laporan.h"
#include "Header/CRUD/Login.h"

char kalimat [20];

//void Pilihan(int x, int y, int lebar, char kata[20], int countmax, char Metode[5][20]) {
//
//    int kali = 0;
//    char ch;
//    int selectedOption = 0;
//
//    SetColorBlock(0,14);
//    // Daftar cabang daerah
////    char Metode[5][20] = {"Admin", "EO", "Manajer", "Pemasaran"};
//
//    // Display the initial status
//    gotoxy(x, y);
//    printf("%s", Metode[selectedOption]);
//
//    while (1) {
//        ch = getch();
//
//        kali++;
//        if (ch == 13) {  // Enter key
//            if (kali == 1) {
//                selectedOption = 0;
//                strcpy(kata, Metode[selectedOption]);
//                strcpy(kalimat, kata);
//            }
//            break;
//        } else if (ch == 72) {  // Up arrow key
//            if (selectedOption > 0) {
//                // Membersihkan tampilan sebelumnya
//                clearArea(x, y, lebar, 1);
////                gotoxy(x, y);   printf("                    ");
//                // Mengganti opsi
//                selectedOption--;
////                selectedOption = (selectedOption - 1 + 2) % 2;
//            }
//        } else if (ch == 80) {  // Down arrow key
//            if (selectedOption < countmax) {
//                // Membersihkan tampilan sebelumnya
//                clearArea(x, y, lebar, 1);
////                gotoxy(x, y);   printf("                    ");
//                // Mengganti opsi
//                selectedOption++;
////            selectedOption = (selectedOption + 1) % 2;
//            }
//        }
//
//        // Update the display based on the selected option
//        gotoxy(x, y);   printf("%s", Metode[selectedOption]);
//        strcpy(kata, Metode[selectedOption]);
//        strcpy(kalimat, kata);
//    }
//}

int main() {

    fullscreen();
    remove_scrollbar();
    Login();

//    Background();
//    garismenu();
//    readTempat();
//    getch();
//    SpecialkeyloginVertical(menuupdatetempat, 147, 13, 19, 3, 4, 7, &updt);


//    Background();
////    MasterUser();
//    TransaksiPenjualanSUvenir();
//    MasterSuvenir();

//    garismenu();
//
//    SetColorBlock(0, 14);
//    // garis berdiri kanan
//    for ( i = 12; i < 43; i++) {
//        for ( j = 145; j < 147; j++) {
//            gotoprintchar(j, i, 32);
//        }
//    }

//    SetColorBlock(0, 0);
//    // garis kiri
//    for ( i = 12; i < 44; i++) {
//        for ( j = 83; j < 84; j++) {
//            gotoprintchar(j, i, 32);
//        }
//    }

    // garis transaksi
//    SetColorBlock(0, 0);
//    for ( i = 12; i < 44; i++) {
//        for ( j = 97; j < 98; j++) {
//            gotoprintchar(j, i, 32);
//
//        }
//    }
//    getch();

//    MasterPemasok();
//    MasterUser()
//TransaksiPenjualanSUvenir();
//    char str [30];
//    SetColorBlock(0, 14);
//    char metode[5][20] = {"Admin", "EO", "Manajer", "Pemasaran"};
//    pilihMetode(5, 5, 15, str, 3, metode);
//    gotoxy(10, 10); printf("%s", str);
//    getch();
}