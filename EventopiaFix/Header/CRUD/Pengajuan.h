void menuTAcara ();
void createTAcara ();
void readTAcara ();
void DetailSponsor ();
void DetailPembawaAcara ();
void DetailDekorasi ();
void BayarDCR ();

void TransaksiPengajuanAcara () {
    HapusKiri();
    HapusTengah();
    garismenu();
    menuTAcara();
}

void menuTAcara()
{
    int choose;

    SpecialkeyloginVertical(menutransaksi, 4, 17, 19, 3, 5, 4, &choose);
    switch (choose) {
        case 1 :
            createTAcara();
            break;
        case 2 :
            readTAcara();
            gotoxy(22, 31);
            getch();
            TransaksiPengajuanAcara();
            break;
        case 3 :
            LihatDetail();
            gotoxy(22, 31);
            getch();
            HapusTengah();
            TransaksiPengajuanAcara();
            break;
        case 4 :
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

char stsPengajuan[5][20] = {"Disetujui", "Ditolak", "Dalam Pertimbangan"};
char stsPelaksanaan[5][20] = {"Terlaksana", "Belum Dilaksanakan", "Tidak Terlaksan"};

void createTAcara ()
{
    FILE *EVNT;
    FILE *CLN;
    FILE *VEN;
    FILE *JS;
    FILE *EMP;

    int id;
    int loop = 0;
    int found;

    EVNT = fopen("../Dat/TransaksiPengajuanAcara.dat", "ab+");

    while (fread(&evnt, sizeof(evnt), 1, EVNT) == 1) {
        id = evnt.idEvent;
        loop++;
    }

    if (loop == 0) {
        evnt.idEvent = 1;
    } else {
        evnt.idEvent = id + 1;
    }
    fclose(EVNT);

    printf("Masukkan Data!\n");
    printf("Id Acara                :EVNT%03d\n", evnt.idEvent);
    printf("Id Klien                :CLN");
    printf("Id Tempat               :VEN");
    printf("Id Jasa                 :JS");
    printf("Id Karyawan             :EMP");
    printf("Nama Acara              :");
    printf("Bintang Tamu            :");
    printf("Jenis Acara             :");
    printf("Tanggal Pengajuan       :");
    printf("Tanggal Mulai Acara     :");
    printf("Tanggal Selesai Acara   :");
    printf("Status Pengajuan        :");
    printf("Status Pelaksanaan      :");
    printf("Total Biaya             :Rp");

    //ID KLIEN
    do {
        getnum(&evnt.idKlien, 3);
        if (evnt.idKlien == 0) {
            HapusTengah();
            TransaksiPengajuanAcara();
        }

        found = 0;
        CLN = fopen("../Dat/Klien.dat", "rb");
        while(fread(&evnt, sizeof (evnt), 1, CLN) == 1) {
            if (evnt.idKlien == cln.idKlien) {
                found = 1;
            }
        }
        fclose(CLN);

        if (!found) {
            MessageBox(NULL, "ID Klien tidak valid!", "ATTENTION", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(58, 18, 3, 1);
        }
    } while (!found);

    //ID TEMPAT
    do {
        getnum(&evnt.idTempat, 3);
        if (evnt.idTempat == 0) {
            HapusTengah();
            TransaksiPengajuanAcara();
        }

        found = 0;
        VEN = fopen("../Dat/Tempat.dat", "rb");
        while(fread(&evnt, sizeof (evnt), 1, VEN) == 1) {
            if (evnt.idKlien == tempat.id) {
                found = 1;
            }
        }
        fclose(VEN);

        if (!found) {
            MessageBox(NULL, "ID Tempat tidak valid!", "ATTENTION", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(58, 18, 3, 1);
        }
    } while (!found);

    //ID JASA
    do {
        getnum(&evnt.idJasa, 3);
        if (evnt.idJasa == 0) {
            HapusTengah();
            TransaksiPengajuanAcara();
        }

        found = 0;
        JS = fopen("../Dat/Jasa.dat", "rb");
        while(fread(&evnt, sizeof (evnt), 1, JS) == 1) {
            if (evnt.idJasa == jasa.id) {
                found = 1;
            }
        }
        fclose(JS);

        if (!found) {
            MessageBox(NULL, "ID Jasa tidak valid!", "ATTENTION", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(58, 18, 3, 1);
        }
    } while (!found);

    //ID KARYAWAN
    do {
        getnum(&evnt.idKaryawan, 3);
        if (evnt.idKaryawan == 0) {
            HapusTengah();
            TransaksiPengajuanAcara();
        }

        found = 0;
        EMP = fopen("../Dat/Karyawan.dat", "rb");
        while(fread(&evnt, sizeof (evnt), 1, EMP) == 1) {
            if (evnt.idKaryawan == U.id) {
                found = 1;
            }
        }
        fclose(EMP);

        if (!found) {
            MessageBox(NULL, "ID Karyawan tidak valid!", "ATTENTION", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(58, 18, 3, 1);
        }
    } while (!found);

    //NAMA ACARA
    getteks(evnt.namaEvent, 30);
    if (strcmp(evnt.namaEvent, "0") == 0) {
        TransaksiPengajuanAcara();
    }

    //BINTANG TAMU
    getletter(evnt.bintangTamu, 30);

    //JENIS ACARA
    getletter(evnt.jenisEvent, 30);

    //DATE PENGAJUAN
    int a = 54;
    int b = 30;
    DateTime dateNow;
    DateTimeNow(&dateNow);

    gotoxy(a, b); getnum(&evnt.thnPengajuan, 4);
    if (evnt.thnPengajuan == 0) {
        TransaksiPengajuanAcara();
    }

    do {
        gotoxy(a + 5, b); getnum(&evnt.blnPengajuan, 2);
        if(evnt.blnPengajuan == 0) {
            TransaksiPengajuanAcara();
            break;
        } else if (evnt.blnPengajuan < 0 || evnt.blnPengajuan > 12) {
            MessageBox(NULL, "Jangka bulan tidak boleh lebih dari dari 12!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(a + 5, b, 2, 1);
            gotoxy(a + 5, b); printf("MM");
        }
    } while (evnt.blnPengajuan < 0 || evnt.blnPengajuan > 12);

    int condi;
    do {
        gotoxy(a + 8,b);  getnummin(&U.tgl, 1, 2);
        if (evnt.tglPengajuan == 0) {
            TransaksiPengajuanAcara();
        } else if (evnt.thnPengajuan % 400 == 0 && evnt.blnPengajuan == 2 && evnt.tglPengajuan > 29) {
            condi = 1;
            MessageBox(NULL, "Tidak boleh dari 29!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(a + 8, b, 2, 1);
            gotoxy(a + 8, b); printf("DD");
        } else if (evnt.thnPengajuan % 400 != 0 && evnt.blnPengajuan == 2 && evnt.tglPengajuan > 28) {
            condi = 2;
            MessageBox(NULL, "Tidak boleh dari 28!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(a + 8, b, 2, 1);
            gotoxy(a + 8, b); printf("DD");
        } else if (evnt.blnPengajuan % 2 == 0 && evnt.tglPengajuan > 30) {
            condi = 3;
            MessageBox(NULL, "Tidak boleh dari 30!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(a + 8, b, 2, 1);
            gotoxy(a + 8, b); printf("DD");
        } else if (evnt.blnPengajuan % 2 != 0 && evnt.tglPengajuan > 31) {
            condi = 4;
            MessageBox(NULL, "Tidak boleh dari 31!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(a + 8, b, 2, 1);
            gotoxy(a + 8, b); printf("DD");
        } else {
            break;
        }
    } while (evnt.tglPengajuan < 0 || condi == 1 || condi == 2 || condi == 3 || condi == 4);


    //DATE MULAI ACARA
    a = 54;
    b = 32;
    DateTimeNow(&dateNow);

    gotoxy(a, b); getnum(&evnt.thnMulai, 4);
    if (evnt.thnMulai == 0) {
        TransaksiPengajuanAcara();
    }

    do {
        gotoxy(a + 5, b); getnum(&evnt.blnMulai, 2);
        if(evnt.blnMulai == 0) {
            TransaksiPengajuanAcara();
            break;
        } else if (evnt.blnMulai < 0 || evnt.blnMulai > 12) {
            MessageBox(NULL, "Jangka bulan tidak boleh lebih dari dari 12!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(a + 5, b, 2, 1);
            gotoxy(a + 5, b); printf("MM");
        }
    } while (evnt.blnMulai < 0 || evnt.blnMulai > 12);

    do {
        gotoxy(a + 8,b);  getnummin(&U.tgl, 1, 2);
        if (evnt.tglMulai == 0) {
            TransaksiPengajuanAcara();
        } else if (evnt.thnMulai % 400 == 0 && evnt.blnMulai == 2 && evnt.tglMulai > 29) {
            condi = 1;
            MessageBox(NULL, "Tidak boleh dari 29!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(a + 8, b, 2, 1);
            gotoxy(a + 8, b); printf("DD");
        } else if (evnt.thnMulai % 400 != 0 && evnt.blnMulai == 2 && evnt.tglMulai > 28) {
            condi = 2;
            MessageBox(NULL, "Tidak boleh dari 28!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(a + 8, b, 2, 1);
            gotoxy(a + 8, b); printf("DD");
        } else if (evnt.blnMulai % 2 == 0 && evnt.tglMulai > 30) {
            condi = 3;
            MessageBox(NULL, "Tidak boleh dari 30!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(a + 8, b, 2, 1);
            gotoxy(a + 8, b); printf("DD");
        } else if (evnt.blnMulai % 2 != 0 && evnt.tglMulai > 31) {
            condi = 4;
            MessageBox(NULL, "Tidak boleh dari 31!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(a + 8, b, 2, 1);
            gotoxy(a + 8, b); printf("DD");
        } else {
            break;
        }
    } while (evnt.tglMulai < 0 || condi == 1 || condi == 2 || condi == 3 || condi == 4);

    //DATE SELESAI ACARA
    a = 54;
    b = 34;
    DateTimeNow(&dateNow);

    gotoxy(a, b); getnum(&evnt.thnSelesai, 4);
    if (evnt.thnSelesai == 0) {
        TransaksiPengajuanAcara();
    }

    do {
        gotoxy(a + 5, b); getnum(&evnt.blnSelesai, 2);
        if(evnt.blnSelesai == 0) {
            TransaksiPengajuanAcara();
            break;
        } else if (evnt.blnSelesai < 0 || evnt.blnSelesai > 12) {
            MessageBox(NULL, "Jangka bulan tidak boleh lebih dari dari 12!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(a + 5, b, 2, 1);
            gotoxy(a + 5, b); printf("MM");
        }
    } while (evnt.blnSelesai < 0 || evnt.blnSelesai > 12);

    do {
        gotoxy(a + 8,b);  getnummin(&U.tgl, 1, 2);
        if (evnt.tglSelesai == 0) {
            TransaksiPengajuanAcara();
        } else if (evnt.thnSelesai % 400 == 0 && evnt.blnSelesai == 2 && evnt.tglSelesai > 29) {
            condi = 1;
            MessageBox(NULL, "Tidak boleh dari 29!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(a + 8, b, 2, 1);
            gotoxy(a + 8, b); printf("DD");
        } else if (evnt.thnSelesai % 400 != 0 && evnt.blnSelesai == 2 && evnt.tglSelesai > 28) {
            condi = 2;
            MessageBox(NULL, "Tidak boleh dari 28!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(a + 8, b, 2, 1);
            gotoxy(a + 8, b); printf("DD");
        } else if (evnt.blnSelesai % 2 == 0 && evnt.tglSelesai > 30) {
            condi = 3;
            MessageBox(NULL, "Tidak boleh dari 30!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(a + 8, b, 2, 1);
            gotoxy(a + 8, b); printf("DD");
        } else if (evnt.blnSelesai % 2 != 0 && evnt.tglSelesai > 31) {
            condi = 4;
            MessageBox(NULL, "Tidak boleh dari 31!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
            clearArea(a + 8, b, 2, 1);
            gotoxy(a + 8, b); printf("DD");
        } else {
            break;
        }
    } while (evnt.tglSelesai < 0 || condi == 1 || condi == 2 || condi == 3 || condi == 4);

    //STATUS PENGAJUAN
    Pilihan(54, 36, 20, evnt.statusPengajuan, 2, stsPengajuan);

    //STATUS PELAKSANAAN
    Pilihan(54, 38, 20, evnt.statusPelaksanaan, 2, stsPelaksanaan);


    getRp(&evnt.totalBiaya, 5,9, 54,40);
    if (evnt.totalBiaya == 0){
        TransaksiPengajuanAcara();
    }

    EVNT = fopen("../Dat/TransaksiPengajuanAcara.dat", "ab");
    fwrite(&evnt, sizeof(evnt), 1, EVNT);
    fclose(EVNT);

    MessageBox(NULL, "Data Berhasil Ditambahkan", "Information", MB_OK | MB_ICONASTERISK);
}

void readTAcara ()
{
    FILE *EVNT;
    char Biaya[25];
    EVNT = fopen("../Dat/TransaksiPengajuanAcara.dat", "rb");

    if (EVNT == NULL)
    {
        MessageBox(NULL, "Data Transaksi Tidak Ditemukan", "Error", MB_OK | MB_ICONERROR);
    }
    else
    {
        printf("D A T A  T R A N S A K S I  A C A R A");

        printf("ID ACARA                :");
        printf("ID KLIEN                :");
        printf("ID TEMPAT               :");
        printf("ID JASA                 :");
        printf("ID KARYAWAN             :");
        printf("NAMA ACARA              :");
        printf("BINTANG TAMU            :");
//        printf("JENIS ACARA             :");
        printf("TANGGAL PENGAJUAN       :");
//        printf("TANGGAL MULAI ACARA     :");
//        printf("TANGGAL SELESAI ACARA   :");
        printf("STATUS PENGAJUAN        :");
//        printf("STATUS PELAKSANAAN      :");
        printf("TOTAL BIAYA             :");

        i = 18;
        while(fread(&evnt, sizeof(evnt), 1, EVNT) == 1)
        {
            printf("EVNT%03d", evnt.idEvent);
            printf("CLN%03d", evnt.idKlien);
            printf("VEN%03d", evnt.idTempat);
            printf("JS%03d", evnt.idJasa);
            printf("EMP%03d", evnt.idKaryawan);
            printf("%s", evnt.namaEvent);
            printf("%s", evnt.bintangTamu);
            printf("%s", evnt.jenisEvent);
            printf("%02d/%02d/%d", evnt.tglPengajuan, evnt.blnPengajuan, evnt.thnPengajuan);
//            printf("\t\t|%02d-%02d-%d", Event.tglMulai, Event.blnMulai, Event.thnMulai);
//            printf("\t\t|%02d-%02d-%d", Event.tglSelesai, Event.blnSelesai, Event.thnSelesai);
            printf("%s", evnt.statusPengajuan);
//            printf("\t\t|%s", Event.statusPelaksanaan);
            printf("Rp");
            rupiah(evnt.totalBiaya, Biaya);
            printf("%s", Biaya);
        }
    }
    fclose(EVNT);
}

void DetailSponsor () {
    FILE *Temp;
    FILE *DTSPNSR;
    FILE *SPNSR;
    int found = 0;
    char ans;
    int total = 0;

    dtlspnsr.idDT = evnt.idEvent;

    int b = 1 + 3;
    gotoxy(100,b);  printf("ID Transaksi    : TSPNSR%03d", dtlspnsr.idDT);
    do{
        gotoxy(100, b + 2); printf("ID Sponsor      : SPNSR");
        fflush(stdin);
        getnum(&dtlspnsr.idPerusahaanSponsor, 3);

        if (dtlspnsr.idPerusahaanSponsor == 0){
            HapusTengah();
            TransaksiPengajuanAcara();
        }

        /* buka file makanan untuk melihat data makanan */
        SPNSR = fopen("../Dat/Sponsor.dat","rb");
        fread(&spnsr,sizeof(spnsr),1,SPNSR);

        while(!feof(SPNSR) && !found){
            if (dtlspnsr.idPerusahaanSponsor == spnsr.idPerusahaanSponsor){
                found = 1;
            }
            fread(&spnsr,sizeof(spnsr),1,SPNSR);
        }
        fclose(SPNSR);

        if (!found){
            MessageBoxA(NULL,"ID Sponsor tidak ada!","ATTENTION",MB_OK | MB_DEFAULT_DESKTOP_ONLY);
            createTAcara();
        }
    } while (!found);

    gotoxy(134,17);	printf("ID Transaksi        : EVNT%03d", evnt.idEvent);
    gotoxy(134,18);	printf("ID Sponsor          : SPNSR%03d", dtlspnsr.idPerusahaanSponsor);
    gotoxy(134,19);	printf("Tanggal Transaksi   : %02d/%02d/%d",dtlspnsr.tglTRS, dtlspnsr.blnTRS, dtlspnsr.thnTRS);

}


void DetailDekorasi () {
    FILE *Temp;
    FILE *DTDCR;
    FILE *DCR;
    int found = 0, cekstok;
    char ans, uang[25];
    int Baris = 32, Kolom = 134;
    int total = 0;

    dtldcr.idDT = evnt.idEvent;

    int b = i + 3;
    gotoxy(100, b);
    printf("ID Transaksi    : TDCR%03d", dtldcr.idDT);
    do{
        gotoxy(100, b + 2);
        printf("ID Dekorasi     : DECOR");
        fflush(stdin);
        getnum(&dtldcr.idDekorasi, 3);

        if (dtldcr.idDekorasi == 0){
            HapusTengah();
            TransaksiPengajuanAcara();
        }

        DCR = fopen("../Dat/Dekorasi.dat", "rb");
        fread(&dcr, sizeof (dcr), 1, DCR);

        while(!feof(DCR) && !found){
            if (dtldcr.idDekorasi == dcr.idDekorasi){
                dtldcr.harga = dcr.hargaDekorasi;
                cekstok = dcr.stokDekorasi;
                found = 1;
            }
            fread(&dcr, sizeof (dcr), 1, DCR);
        }
        fclose(DCR);

        if (!found){
            MessageBoxA(NULL,"ID Dekorasi tidak ada!","ATTENTION",MB_OK | MB_DEFAULT_DESKTOP_ONLY);
            createTAcara();
        }
    } while (!found);


    gotoxy(134,17);	printf("ID Transaksi    : EVNT%03d", evnt.idEvent);
    gotoxy(134,18);	printf("ID Dekorasi     : DECOR%03d", dtldcr.idDekorasi);
    rupiah(dtldcr.harga,uang);
    gotoxy(134,19);	printf("Harga Dekorasi  : Rp %s", uang);

    do {
        gotoxy(134,20);	printf("Banyak item     : ");
        fflush(stdin);
        gotoxy(152,20); getnum(&dtldcr.qty, 10);

        if(dtldcr.qty <= 0){
            HapusTengah();
            createTAcara();
        }else if(dtldcr.qty > cekstok){				//jika jumlah yg dibeli lebih banyak dari jumlah stock
            MessageBoxA(NULL,"Stok Tidak Mencukupi","Notification", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        }
    } while (dtldcr.qty > cekstok);

    dtldcr.totalBiaya = dtldcr.qty * dtldcr.harga;
    rupiah(dtldcr.totalBiaya,uang);
    gotoxy(134,21); printf("Total Biaya        : Rp %s", uang);

    krj.qty = dtldcr.qty;

    /* buka file untuk menambah data */
    DTDCR = fopen("../Dat/DetailDekorasi.dat","ab");
    fwrite(&dtldcr,sizeof(dtldcr),1,DTDCR);
    fclose(DTDCR);

    /* proses pengurangan stok */
    DCR = fopen("../Dat/Dekorasi.dat","rb");
    Temp  = fopen("../Dat/Temp.dat","wb");
    fread(&dcr,sizeof(dcr),1,DCR);
    while(!feof(DCR)){
        if(dtldcr.idDekorasi == dcr.idDekorasi) {
            dcr.stokDekorasi = dcr.stokDekorasi - dtldcr.qty;
            fwrite(&dcr,sizeof(dcr),1,Temp);
        } else {
            fwrite(&dcr,sizeof(dcr),1,Temp);
        }
        fread(&dcr,sizeof(dcr),1,DCR);
    }
    fclose(DCR);
    fclose(Temp);

    /* mengganti data makanan terbaru */
    remove("../Dat/Dekorasi.dat");
    rename("../Dat/Temp.dat","../Dat/Dekorasi.dat");

    gotoxy(134,32); printf("Keranjang");

    arskrj = fopen ("../Dat/Keranjang.dat", "ab");
    fwrite(&krj,sizeof(krj),1,arskrj);
    fclose(arskrj);

    arskrj = fopen ("../Dat/Keranjang.dat", "rb");
    fread(&krj,sizeof(krj),1,arskrj);
    while(!feof(arskrj)){
        Baris++;
        if(Baris % 2 == 0) {
            gotoxy(Kolom,Baris);
        } else {
            gotoxy(Kolom,Baris);
        }

        gotoxy(Kolom + 1,Baris); printf("- %s X %d", krj.nama,krj.qty);
        fread(&krj,sizeof(krj),1,arskrj);
    }
    fclose(arskrj);

    do {
        gotoxy(134,23); printf("Tambah item lagi? [Y/N] ");
        gotoxy(157,23); scanf("%s", &ans);

        switch(toupper(ans)){
            case 'Y' :
                HapusTengah();
                DetailDekorasi();
                break;
            case 'N' :
                evnt.totalBiaya = total;
                BayarDCR();
                break;
        }
    } while (toupper(ans) != 'Y' && toupper(ans) != 'N');
}

void BayarDCR () {
    int tunai, kembali, ans;
    char uang[25];

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    dtldcr.blnTRS = tm.tm_mon;
    dtldcr.thnTRS = tm.tm_year + 1900;

    strcpy(uang, "0");
    rupiah(evnt.totalBiaya, uang);
    gotoxy(60,32);  printf("Total Akhir : Rp %s", uang);
    gotoxy(60,33);  printf("Uang Tunai  : Rp ");
    fflush(stdin);
    getRp(&tunai,4,9,77,33);

    while (tunai < evnt.totalBiaya){ /* perulangan jika uang tunai kurang dari total */
//        gotoxy(33,32);	printf("Uang kurang");
//        getch();
        MessageBox(NULL, "Uang tunai kurang !", "Attention", MB_OK | MB_ICONWARNING | MB_DEFAULT_DESKTOP_ONLY);
        gotoxy(60,33);	printf("Uang Tunai  : Rp ");
        fflush(stdin);
        getRp(&tunai,4,9,77,33);
    }

    kembali = tunai - evnt.totalBiaya;

    gotoxy(60,34);	rupiah(kembali,uang); printf("Kembalian  : Rp %s", uang);

    dtldcr.tglTRS = tm.tm_mday;
    dtldcr.blnTRS = tm.tm_mon + 1;
    dtldcr.thnTRS = tm.tm_year + 1900;
    gotoxy(60,36);	printf("Tanggal    : %02d/%02d/%d",  dtldcr.tglTRS, dtldcr.blnTRS, dtldcr.thnTRS);

    FILE *EVNT = fopen("../Dat/Transaksi Pengajuan Acara.dat", "ab");
    fwrite(&evnt,sizeof(evnt),1,EVNT);
    fclose(EVNT);

    FILE * DTDCR = fopen("../Dat/DetailDekorasi.dat", "ab");
    FILE * KRJ = fopen("../Dat/Keranjang.dat", "rb");
    while(fread(&krj, sizeof(krj), 1, KRJ) == 1) {
        dtldcr.idDT = evnt.idEvent;
        dtldcr.idDekorasi = krj.id;
        dtldcr.qty = krj.qty;
        fwrite(&dtldcr, sizeof(dtldcr), 1, DTDCR);
    }
    fclose(KRJ);
    fclose(DTDCR);

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
                createTAcara();
                break;
            case 2:
                HapusAll();
                TransaksiPengajuanAcara();
                break;
        }
    } while (ans != 1 && ans != 2); /* lakukan perulangan selama jawaban bukan Y atau N */
}

void DetailPembawaAcara () {
    FILE *Temp;
    FILE *DTMC;
    FILE *MC;
    char uang [25];
    int found = 0;

    dtlmc.idDT = evnt.idEvent;

    int b = i + 3;
    gotoxy(100, b);
    printf("ID Transaksi    : TMC%03d", dtlmc.idDT);
    do{
        gotoxy(100, b + 2);
        printf("ID Pembawa Acara     : MC");
        fflush(stdin);
        getnum(&dtlmc.idPembawaAcara, 3);

        if (dtlmc.idPembawaAcara == 0){
            HapusTengah();
            TransaksiPengajuanAcara();
        }

        MC = fopen("../Dat/PembawaAcara.dat", "rb");
        fread(&mc, sizeof (mc), 1, MC);

        while(!feof(MC) && !found){
            if (dtlmc.idPembawaAcara == mc.idPembawaAcara){
                dtlmc.totalBiaya = mc.biaya;
                found = 1;
            }
            fread(&mc, sizeof (mc), 1, MC);
        }
        fclose(MC);

        if (!found){
            MessageBoxA(NULL,"ID Pembawa Acara tidak ada!","ATTENTION",MB_OK | MB_DEFAULT_DESKTOP_ONLY);
            createTAcara();
        }
    } while (!found);


    gotoxy(134,17);	printf("ID Transaksi        : EVNT%03d", evnt.idEvent);
    gotoxy(134,18);	printf("ID Pembawa Acara    : MC%03d", dtlmc.idPembawaAcara);
    rupiah(dtlmc.totalBiaya,uang);
    gotoxy(134,19);	printf("Harga Pembawa Acara : Rp %s", uang);

}