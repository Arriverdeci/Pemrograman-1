void TransaksiPenjualanSuvenir ();
void CreateTSuvenir ();
void ReadTSuvenir ();
void TambahDetailSV();
void BayarTSV();
void LihatDetail();
void menuTransaksiSuvenir();

int total;

void TransaksiPenjualanSUvenir () {

    HapusKiri();
    HapusTengah();
    garisTrnsksi();
    menuTransaksiSuvenir();

}

void menutransaksi () {

    // garis berdiri
    SetColorBlock(0, 14);
    for ( i = 12; i < 43; i++) {
        for ( j = 145; j < 147; j++) {
            gotoprintchar(j, i, 32);
        }
    }

    SetColorBlock(0, 14);
    gotoxy(6, 18);   printf("   T A M B A H   ");
    gotoxy(6, 20);   printf("T R A N S A K S I");
    gotoxy(6, 23);   printf("    L I H A T    ");
    gotoxy(6, 25);   printf("T R A N S A K S I");
    gotoxy(6, 28);   printf("   D E T A I L   ");
    gotoxy(6, 30);   printf("T R A N S A K S I");
    gotoxy(6, 34);   printf("  K E M B A L I  ");

}

void menuTransaksiSuvenir() {
    int choose;

    SpecialkeyloginVertical(menutransaksi, 4, 17, 19, 3, 5, 4, &choose);
    switch (choose) {
        case 1 :
            CreateTSuvenir();
            break;
        case 2 :
            ReadTSuvenir();
            gotoxy(22, 31);
            getch();
            TransaksiPenjualanSUvenir();
            break;
        case 3 :
            LihatDetail();
            gotoxy(22, 31);
            getch();
            HapusAll();
            TransaksiPenjualanSUvenir();
            break;
        case 4 :
            // garis tengah
            SetColorBlock(0, 14);
            for (i = 12; i < 43; i++) {
                for ( j = 97; j < 98; j++) {
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
}

void CreateTSuvenir() {

    FILE *trsv;
    int id;
    int ans;

    total = 0;

    arskrj = fopen ("../Dat/Keranjang.dat", "wb");
    fclose(arskrj);

    readMerchTrnsksi(); /* menampilkan menu makanan */
    gotoxy(65,42);	printf("--0 untuk kembali--");
    trs.total = 0;

    /* buka file transaksi untuk dibaca (id otomatis) */
    trsv = fopen("../Dat/Transaksi Penjualan Suvenir.dat", "ab+");
    fread(&trs,sizeof(trs),1,trsv);

    while(!feof(trsv)){
        fread(&trs,sizeof(trs),1,trsv);
        id = trs.id;
        i++;
    }

    if(i==0){
        trs.id = 1;
    }else{
        trs.id = id+1;
    }
    fclose(trsv); /* tutup file setelah dibaca */

    gotoxy(46, 13);   printf("T R A N S A K S I  S U V E N I R");
    gotoxy(33,16);	printf("ID Transaksi : TRS%03d", trs.id);

    TambahDetailSV(); /* prosedur tambah item makanan */
}


void YNTR () {

    gotoxy(54, 41);   printf("Y A");
    gotoxy(66, 41);   printf("TIDAK");

}

void TambahDetailSV() {

    int cekstok, ans;
    char uang[25];
    found=0;

    dtTrSv.idTPS = trs.id; /* id trm menjadi FK karna masih dalam transaksi yg sama */

//    FILE *SV = fopen("../Dat/Suvenir.dat", "rb");
//    while(fread(&sv, sizeof(sv), 1, SV) == 1) {
//
//    }
//    stoktemp = sv.stok;

    readMerchTrnsksi();

    gotoxy(33, 16); printf("ID Transaksi    : TRS%03d", dtTrSv.idTPS);
    gotoxy(33, 18); printf("ID Suvenir      : MERCH");
    gotoxy(33, 20); printf("Nama Suvenir    :");
    gotoxy(33, 22); printf("Harga Suvenir   : Rp");
    gotoxy(33, 24); printf("Banyak item     :");
    gotoxy(33, 26); printf("Sub Total       : Rp");
    gotoxy(33, 28); printf("Total Harga     : Rp");

    do{
        fflush(stdin);
        gotoxy(56, 18); getnum(&dtTrSv.idS, 3);

        if (dtTrSv.idS == 0){
            HapusTRKanan();
            HapusTRKiri();
            TransaksiPenjualanSUvenir();
        }

        /* buka file makanan untuk melihat data makanan */
        FILE *SV = fopen("../Dat/Suvenir.dat","rb");
        fread(&sv,sizeof(sv),1,SV);

        while(!feof(SV) && !found){
            if (dtTrSv.idS == sv.id){
                strcpy(dtTrSv.namaS,sv.nama);
                dtTrSv.hargaS = sv.harga;
                cekstok = sv.stok;
                found = 1;
            }
            fread(&sv,sizeof(sv),1,SV);
        }
        fclose(SV);

        if (!found){
            MessageBoxA(NULL,"ID Suvenir tidak ada!","ATTENTION",MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(56, 18, 10, 1);
        }

    } while (!found);

    gotoxy(51,20);	printf("%s", dtTrSv.namaS);
    rupiah(dtTrSv.hargaS,uang);
    gotoxy(54,22);	printf("%s", uang);

    do {
        fflush(stdin);
        gotoxy(51,24); getnum(&dtTrSv.qty, 10);

        if(dtTrSv.qty <= 0){
            HapusTRKiri();
            HapusTRKanan();
            TransaksiPenjualanSUvenir();
        }else if(dtTrSv.qty > cekstok){				//jika jumlah yg dibeli lebih banyak dari jumlah stock
            MessageBoxA(NULL,"Stok Tidak Mencukupi","Notification", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(51, 24, 10, 1);
        } else {
//            stoktemp = stoktemp - dtTrSv.qty;

            FILE *SV = fopen("../Dat/Suvenir.dat", "rb");
            FILE *Temp = fopen("../Dat/Temp.dat", "wb");

            while(fread(&sv, sizeof(sv), 1, SV) == 1) {
                if (sv.id == dtTrSv.idS) {
                    sv.stok = sv.stok - dtTrSv.qty;
                    break;
                } else {
                    fwrite(&sv, sizeof(sv), 1, Temp);
                }
            }

            fwrite(&sv, sizeof(sv), 1, Temp);

            while(fread(&sv, sizeof(sv), 1, SV) == 1) {
                fwrite(&sv, sizeof(sv), 1, Temp);
            }

            fclose(SV);
            fclose(Temp);

            remove("../Dat/Suvenir.dat");
            rename("../Dat/Temp.dat", "../Dat/Suvenir.dat");
        }

    } while (dtTrSv.qty > cekstok);

    dtTrSv.subtotal = dtTrSv.qty * dtTrSv.hargaS;
    rupiah(dtTrSv.subtotal,uang);
    gotoxy(54,26); printf("%s", uang);

    strcpy(uang, "0");
    fflush(stdin);
    total = total + dtTrSv.subtotal;
    rupiah(total,uang);
    gotoxy(54,28); printf("%s", uang);

    krj.id = dtTrSv.idS;
    strcpy(krj.nama,dtTrSv.namaS);
    krj.qty = dtTrSv.qty;

    gotoxy(30,31); printf("Keranjang Suvenir");

    arskrj = fopen ("../Dat/Keranjang.dat", "ab");
    fwrite(&krj,sizeof(krj),1,arskrj);
    fclose(arskrj);

    i = 33;
    arskrj = fopen ("../Dat/Keranjang.dat", "rb");
    while(fread(&krj,sizeof(krj),1,arskrj) == 1) {
        gotoxy(30,i); printf("- %s X %d", krj.nama,krj.qty);
        i++;
    }
    fclose(arskrj);

    do {
        clearArea(65, 42, 25, 1);
        gotoxy(53,39); printf("Tambah item lagi ?");
        SpecialkeyloginHorizontal(YNTR, 50, 40, 9, 1, 13, 2, &ans);

        switch(ans){
            case 1 :
//                HapusTengah();
                HapusTRKiri();
                HapusTRKanan();
                TambahDetailSV();
                break;
            case 2:
//                trs.total = total;
                BayarTSV();
                break;
        }
    } while (ans != 1 && ans != 2);
}

void YNTRTGH () {
    gotoxy(54, 28); printf("Y A");
    gotoxy(66, 28); printf("TIDAK");
}

void BayarTSV() {

    int tunai, kembali, ans;
    char uang[25];
    int PromoID;
    int diskon;
    int harga_diskon;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    trs.bulan = tm.tm_mon;
    trs.tahun = tm.tm_year + 1900;

    gotoxy(60, 31); printf("ID Promo : PRM");
    found = 0;
    do{
        gotoxy(74, 31); getnum(&PromoID, 3);
        if(PromoID == 0) {
            diskon = 0;
            break;
        }
        FILE *PR = fopen("../Dat/Master Promo", "rb");
        while(fread(&Promo, sizeof(Promo), 1, PR) == 1) {
//            if (PromoID == 0) {
//                diskon = 0;
//            } else
            if (PromoID == Promo.idPromo) {
                diskon = Promo.diskon;
                found = 1;
            }
        }
        fclose(PR);

        if(!found) {
            clearArea(74, 31, 15, 1);
        }
    } while (!found);

    harga_diskon = (diskon/100) * total;
    trs.total = (total - harga_diskon);

    strcpy(uang, "0");
    rupiah(trs.total, uang);
    gotoxy(60,32);  printf("Total Akhir : Rp %s", uang);
    gotoxy(60,33);  printf("Uang Tunai  : Rp ");
    fflush(stdin);
    getRp(&tunai,4,9,77,33);

    while (tunai < trs.total){ /* perulangan jika uang tunai kurang dari total */
//        gotoxy(33,32);	printf("Uang kurang");
//        getch();
        MessageBox(NULL, "Uang tunai kurang !", "Attention", MB_OK | MB_ICONWARNING | MB_DEFAULT_DESKTOP_ONLY);
        gotoxy(60,33);	printf("Uang Tunai  : Rp ");
        fflush(stdin);
        getRp(&tunai,4,9,77,33);
    }

    kembali = tunai - trs.total;

    gotoxy(60,34);	rupiah(kembali,uang); printf("Kembalian  : Rp %s", uang);

    strcpy(trs.EMPname,emp);
    gotoxy(60,35);	printf("Kasir      : %s", trs.EMPname);

    trs.tgl = tm.tm_mday;
    trs.bulan = tm.tm_mon + 1;
    trs.tahun = tm.tm_year + 1900;
    gotoxy(60,36);	printf("Tanggal    : %02d/%02d/%d",  trs.tgl, trs.bulan, trs.tahun);

    FILE *TRS = fopen("../Dat/Transaksi Penjualan Suvenir.dat", "ab");
    fwrite(&trs,sizeof(trs),1,TRS);
    fclose(TRS);

    FILE * DT = fopen("../Dat/Detail Suvenir.dat", "ab");
    FILE * KRJ = fopen("../Dat/Keranjang.dat", "rb");
    while(fread(&krj, sizeof(krj), 1, KRJ) == 1) {
        dtTrSv.idTPS = trs.id;
        dtTrSv.idS = krj.id;
        strcpy(dtTrSv.namaS, krj.nama);
        dtTrSv.qty = krj.qty;
        fwrite(&dtTrSv, sizeof(dtTrSv), 1, DT);
    }
    fclose(KRJ);
    fclose(DT);

//    /* buka file untuk menambah data */
//    DT = fopen("../Dat/Detail Suvenir.dat","ab");
//    fwrite(&dtTrSv,sizeof(dtTrSv),1,DT);
//    fclose(DT);

    /* proses pengurangan stok */
//    FILE * SV = fopen("../Dat/Suvenir.dat","rb");
//    Temp  = fopen("../Dat/Temp.dat","wb");
//    fread(&sv,sizeof(sv),1,SV);
//    while(!feof(SV)){
//        if(dtTrSv.idS == sv.id) {
//            sv.stok = sv.stok - dtTrSv.qty;
//            fwrite(&sv,sizeof(sv),1,Temp);
//        } else {
//            fwrite(&sv,sizeof(sv),1,Temp);
//        }
//        fread(&sv,sizeof(sv),1,SV);
//    }
//    fclose(SV);
//    fclose(Temp);
//
//    /* mengganti data makanan terbaru */
//    remove("../Dat/Suvenir.dat");
//    rename("../Dat/Temp.dat","../Dat/Suvenir.dat");

    MessageBox(NULL,"Transaksi berhasil!","NOTIFICATION",MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
    getch();

    do {
        HapusTRKiri();
        gotoxy(51,25);	printf("Tambah transaksi lagi?");
        SpecialkeyloginHorizontal(YNTRTGH, 50, 27, 9, 1, 13, 2, &ans);

        switch (ans){
            case 1:
                HapusAll();
                CreateTSuvenir();
                break;
            case 2:
                HapusAll();
                TransaksiPenjualanSUvenir();
                break;
        }
    } while (ans != 1 && ans != 2); /* lakukan perulangan selama jawaban bukan Y atau N */
}

void ReadTSuvenir() {

    FILE *TRS;
    char uang[25];

    TRS = fopen("../Dat/Transaksi Penjualan Suvenir.dat", "rb");;

    if(TRS == NULL) {
        MessageBox(NULL, "Data Transaksi tidak ditemukan", "Attention", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
    } else {
        gotoxy(32, 13); printf("D A T A  T R A N S A K S I  P E N J U A L A N  S U V E N I R");

        // border
        for (j = 29; j < 95; j++) {
            gotoprintchar(j, 15, 205);
            gotoprintchar(j, 17, 205);
        }

        gotoxy(31, 16); printf("ID");
        gotoxy(42, 16); printf("TOTAL");
        gotoxy(65, 16); printf("TANGGAL");
        gotoxy(80, 16); printf("KASIR");

        i = 18;
        while (fread(&trs, sizeof(trs), 1, TRS) == 1) {
            gotoxy(31, i);  printf("TRS%03d", trs.id);  fflush(stdin);
            rupiah(trs.total, uang);
            gotoxy(42, i);  printf("Rp %s", uang);   fflush(stdin);
            gotoxy(65, i);  printf("%02d/%02d/%04d", trs.tgl, trs.bulan, trs.tahun);    fflush(stdin);
            gotoxy(80, i);  printf("%s", emp);
            i++;
        }
    }
    fclose(TRS);

//    int Baris=16, Kolom=36, Next=0;
//    int i=0;
//
//    gotoxy(75,44);	printf("--Klik apapun untuk kembali--\n\n");
//
//    /* buka file transaksi untuk dibaca */
//    TRS = fopen("../Dat/TransaksiPenjualanSuvenir.dat", "rb");
//    fread(&trs,sizeof(trs),1,TRS);
//    while(!feof(TRS)){
//        fread(&trs,sizeof(trs),1,TRS);
//        i++;
//    }
//    fclose(TRS);
//
//
//    for (int x = Kolom; x <= 131; x++) {
//        gotoxy(x,14);printf("%c",205);
//        gotoxy(x,16);printf("%c",205);
//    }
//
//    gotoxy(36,15);printf("\t\t ID_TRM             Total              Tanggal             Kasir");
//
//    if(i==0){
//        MessageBoxA(NULL,"Data Tidak Ada, Pilih 1 untuk Menambah Data!","ATTENTION",MB_OK | MB_ICONWARNING | MB_DEFAULT_DESKTOP_ONLY);
//        TransaksiPenjualanSUvenir();
//    }else{
//        /* buka file transaksi untuk dibaca */
//        TRS = fopen("../Dat/TransaksiPenjualanSuvenir.dat","rb");
//        fread(&trs,sizeof(trs),1,TRS);
//        while(!feof(TRS)){
//            Baris++; Next++;
//            if(Baris%2==0) {
//                gotoxy(Kolom,Baris);
//            }
//            else
//            {
//                gotoxy(Kolom,Baris);
//            }
//            for(i=1;i<=Kolom+54;i++)
//            {
//                printf(" ");
//            }
//            gotoxy(Kolom+14,Baris);	 printf("TRS%d",trs.id);
//            gotoxy(Kolom+30,Baris);	 rupiah (trs.total,uang); printf("Rp %s",uang);
//            gotoxy(Kolom+49,Baris);	 printf("%02d/%02d/%d", trs.tgl,trs.bulan,trs.tahun);
//            gotoxy(Kolom+69,Baris);	 printf("%s",trs.EMPname);
//            fread(&trs,sizeof(trs),1,TRS);
//        }
//        fclose(TRS);
//    }
}

void LihatDetail() {
    int Baris=16, Kolom=36, Next=0;
    int cekId=0;
    char uang[25];
    found=0;

    ReadTSuvenir(); /* menampilkan transaksi makanan */

    gotoxy(35,i + 3); printf("Lihat detail");
    gotoxy(35,i + 5); printf("ID Transaksi : TRS");
    fflush(stdin);  getnum(&cekId, 3);
    if(cekId == 0) {
        HapusKiri();
        TransaksiPenjualanSUvenir();
    }

    /* buka file detail untuk dibaca */
    FILE *DT = fopen ("../Dat/Detail Suvenir.dat", "rb");
    i = 18;
    while(fread(&dtTrSv,sizeof(dtTrSv),1,DT) == 1){
        if (cekId == dtTrSv.idTPS){ /* mengecek apakah id yang dicari ada dalam id transaksi */
            found = 1;

            // border
            for (j = 100; j < 166; j++) {
                gotoprintchar(j, 15, 205);
                gotoprintchar(j, 17, 205);
            }

            gotoxy(102, 16); printf("ID");
            gotoxy(112, 16); printf("ID_SV");
            gotoxy(122, 16); printf("NAMA");
            gotoxy(146, 16); printf("QTY");
            gotoxy(151, 16); printf("SUB TOTAL");

            gotoxy(102,i);	 printf("TRS%03d", dtTrSv.idTPS);
            gotoxy(112,i);	 printf("MERCH%03d", dtTrSv.idS);
            gotoxy(122,i);	 printf("%s", dtTrSv.namaS);
            gotoxy(146,i);	 printf("%d", dtTrSv.qty);
            gotoxy(151,i);	rupiah(dtTrSv.subtotal,uang); printf("Rp %s",uang);
            i++;
        }

    }
    fclose(DT);

    if (!found){
        MessageBoxA(NULL,"ID Transaksi tidak ada!","ATTENTION",MB_OK | MB_DEFAULT_DESKTOP_ONLY);
        HapusTRKiri();
        HapusTRKanan();
        LihatDetail();
    }


    gotoxy(55,42);	printf("--Klik apapun untuk kembali--\n\n");
}