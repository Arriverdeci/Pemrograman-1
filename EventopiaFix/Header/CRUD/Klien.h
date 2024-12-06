KL Klien;

FILE *ArsKlien;
FILE *Asal;
FILE *Temp;
int dicari;

void createCL ();
int readCL();
int updateCL();
int deleteCL();

void MasterKlien () {

//    garismenu();
    int pilih;

    SetColorBlock(0, 14);

    HapusAll();
    garismenu();
    gotoxy(12, 16);
    printf("M A S T E R");
    gotoxy(10, 18);
    printf("K L I E N");

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
            createCL();
            MasterKlien();
            break;
        case 2:
            readCL();
            gotoxy(80, 41);
            printf("========== klik apapun untuk melanjutkan ==========");
            getch();
            MasterKlien();
            break;
        case 3:
            updateCL();
            MasterKlien();
            break;
        case 4:
            deleteCL();
            MasterKlien();
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
            MessageBoxA(NULL,"Incorrect input","ATTENTION",MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
            MasterUser();
            break;
    }

}

void createCL ()
{
    int id;
    int loop;

    ArsKlien = fopen("Klien.dat", "ab+");
    fread(&Klien, sizeof (Klien), 1, ArsKlien);
    while (!feof(ArsKlien))
    {
        fread(&Klien, sizeof (Klien), 1, ArsKlien);
        id = Klien.idKlien;
        loop++;
    }

    if (loop == 0)
    {
        Klien.idKlien = 1;
    }
    else
    {
        Klien.idKlien = id + 1;
    }
    fclose(ArsKlien);

    printf("Masukkan Data!!!\n");
    printf("Id Klien    :KLN%d\n", Klien.idKlien);

    printf("Nama        :");
    getletter(Klien.nama, 15);

    printf("\n");
    printf("No Telepon  :");
    getteksnummin(Klien.notelp, 11,13);

    printf("\n");
    printf("Email       :");
    scanf("%s", Klien.email);
    strlwr(Klien.email);

    printf("Alamat      :");
    scanf(" %[^\n]", Klien.alamat);

    ArsKlien = fopen("Klien.dat", "ab");
    fwrite(&Klien, sizeof (Klien), 1, ArsKlien);
    fclose(ArsKlien);

    MessageBox(NULL,"Data Berhasil Ditambahkan","Information", MB_OK | MB_ICONASTERISK);

}

int readCL ()
{
    ArsKlien = fopen("Klien.dat", "rb");
    printf("\n");
    if (ArsKlien == NULL)
    {
        printf("Data tidak ditemukan\n");
    }
    else
    {
        printf("Data Klien:\n");
        printf("Id\t|Nama\t\t|No Telepon\t|Email\t\t\t|Alamat\n");
        while(fread(&Klien, sizeof(Klien), 1, ArsKlien) == 1)
        {
            printf("KLN%d", Klien.idKlien);
            printf("\t|%s", Klien.nama);
            printf("\t|%s", Klien.notelp);
            printf("\t|%s", Klien.email);
            printf("\t|%s", Klien.alamat);
            printf("\n");
        }
    }
    fclose(ArsKlien);
}

int updateCL ()
{
    Data DataBaru;
    int ditemukan;
    int pilihan;
    ArsKlien = fopen("Klien.dat", "rb");
    printf("\n");

    printf("Data Klien:\n");
    printf("Id\t|Nama\t\t|No Telepon\t|Email\t\t\t|Alamat\n");
    while (fread(&Klien, sizeof(Klien), 1, ArsKlien) == 1) {
        printf("KLN%d", Klien.idKlien);
        printf("\t|%s", Klien.nama);
        printf("\t|%s", Klien.notelp);
        printf("\t|%s", Klien.email);
        printf("\t|%s", Klien.alamat);
        printf("\n");
    }
    fclose(ArsKlien);

    printf("Masukkan Id yang ingin diubah:\tKLN");
    scanf("%d", &dicari);

    Asal = fopen("Klien.dat", "rb");
    Temp = fopen("Temp.dat", "wb");

    ditemukan = 0;
    while (ditemukan == 0 && fread(&Klien, sizeof (Klien), 1, Asal) == 1)
    {
        if (Klien.idKlien == dicari)
        {
            ditemukan = 1;
        }
        else
        {
            fwrite(&Klien, sizeof (Klien), 1, Temp);
        }
    }
    if (ditemukan == 1)
    {
        do
        {
            printf("\n[1]. Ubah Semua Data\n");
            printf("[2]. Ubah Nama\n");
            printf("[3]. Ubah No Telepon\n");
//            printf("[4]. Ubah Email\n");
//            printf("[5]. Ubah Alamat\n");
            printf("[0]. Kembali\n");
            printf("Pilih menu:");
            scanf("%d", &pilihan);

            if(pilihan == 1)
            {
                printf("Masukkan Nama Baru      :");
                scanf(" %[^\n]", DataBaru.nama);
                strcpy(Klien.nama, DataBaru.nama);

                printf("Masukkan No Telepon Baru:");
                getteksnummin(DataBaru.notelp, 11,13);
                strcpy(Klien.notelp, DataBaru.notelp);

//                printf("Masukkan Email Baru     :");
//                scanf("%s", DataBaru.email);
//                strcpy(Klien.email, DataBaru.email);
//
//                printf("Masukkan Alamat Baru    :");
//                scanf(" %[^\n]", DataBaru.alamat);
//                strcpy(Klien.alamat, DataBaru.alamat);

                MessageBox(NULL, "Data Berhasil Diubah","Information", MB_OK | MB_ICONASTERISK);
            }
            else if(pilihan == 2)
            {
                printf("Masukkan Nama Baru:");
                scanf(" %[^\n]", DataBaru.nama);
                strcpy(Klien.nama, DataBaru.nama);
                MessageBox(NULL, "Data Berhasil Diubah","Information", MB_OK | MB_ICONASTERISK);
            }
            else if (pilihan == 3)
            {
                printf("Masukkan No Telepon Baru:");
                getteksnummin(DataBaru.notelp, 11,13);
                strcpy(Klien.notelp, DataBaru.notelp);

                MessageBox(NULL, "Data Berhasil Diubah","Information", MB_OK | MB_ICONASTERISK);
            }
//            else if (pilihan == 4)
//            {
//                printf("Masukkan Email Baru     :");
//                scanf("%s", DataBaru.email);
//                strcpy(Klien.email, DataBaru.email);
//
//                MessageBox(NULL, "Data Berhasil Diubah","Information", MB_OK | MB_ICONASTERISK);
//            }
//            else if (pilihan == 5)
//            {
//                printf("Masukkan Alamat Baru    :");
//                scanf(" %[^\n]", DataBaru.alamat);
//                strcpy(Klien.alamat, DataBaru.alamat);
//
//                MessageBox(NULL, "Data Berhasil Diubah","Information", MB_OK | MB_ICONASTERISK);
//            }
            else if (pilihan == 0)
            {
                break;
            }
            else
            {
                MessageBox(NULL, "Pilihan Tidak Sesuai","Error", MB_OK | MB_ICONERROR);
            }
        } while (pilihan != 0);
        fwrite(&Klien, sizeof (Klien), 1, Temp);
        while (fread(&Klien, sizeof (Klien), 1, Asal) == 1)
        {
            fwrite(&Klien, sizeof (Klien), 1, Temp);
        }
    }
    else
    {
        MessageBox(NULL, "Kode tidak ditemukan di dalam arsip asal", "Error", MB_OK | MB_ICONERROR);
    }
    fclose(Asal);
    fclose(Temp);

    Asal = fopen("Klien.dat", "wb");
    Temp = fopen("Temp.dat", "rb");

    while (fread(&Klien, sizeof (Klien), 1, Temp) == 1)
    {
        fwrite(&Klien, sizeof (Klien), 1, Asal);
    }
    fclose(Temp);
    fclose(Asal);
}


int deleteCL () {
    int ditemukan;
    Asal = fopen("Klien.dat", "rb");
    printf("\n");

    printf("Data Klien:\n");
    printf("Id\t|Nama\t\t|No Telepon\t|Email\t\t\t|Alamat\n");
    while (fread(&Klien, sizeof(Klien), 1, Asal) == 1) {
        printf("KLN%d", Klien.idKlien);
        printf("\t|%s", Klien.nama);
        printf("\t|%s", Klien.notelp);
        printf("\t|%s", Klien.email);
        printf("\t|%s", Klien.alamat);
        printf("\n");
    }
    fclose(Asal);
    printf("\nMasukkan Id yang ingin dihapus:\tKLN");
    scanf("%d", &dicari);

    Asal = fopen("Klien.dat", "rb");
    Temp = fopen("Temp.dat", "wb");

    ditemukan = 0;
    while (ditemukan == 0 && fread(&Klien, sizeof(Klien), 1, Asal) == 1)
    {
        if (Klien.idKlien == dicari)
        {
            ditemukan = 1;
        }
        else
        {
            fwrite(&Klien, sizeof(Klien), 1, Temp);
        }
    }

    if (ditemukan == 1)
    {
        printf("\n");
        printf("Data Klien berikut berhasil dihapus\n");
        printf("Id\t|Nama\t\t|No Telepon\t|Email\t\t\t|Alamat\n");
        printf("KLN%d", Klien.idKlien);
        printf("\t|%s", Klien.nama);
        printf("\t|%s", Klien.notelp);
        printf("\t|%s", Klien.email);
        printf("\t|%s", Klien.alamat);
        printf("\n");

        while (fread(&Klien, sizeof(Klien), 1, Asal) == 1)
        {
            fwrite(&Klien, sizeof (Klien), 1, Temp);
        }
        fclose(Asal);
        fclose(Temp);

        Asal = fopen("Klien.dat", "wb");
        Temp = fopen("Temp.dat", "rb");

        while (fread(&Klien, sizeof(Klien), 1, Temp) == 1)
        {
            fwrite(&Klien, sizeof(Klien), 1, Asal);
        }
        fclose(Asal);
        fclose(Temp);
    }
    else
    {
        MessageBox(NULL, "Kode tidak ditemukan di dalam arsip asal", "Error", MB_OK | MB_ICONERROR);
    }
}

//int main (int pilihan)
//{
//    int cari;
//    FILE *Temp;
//    FILE *Asal;
//    FILE *ArsKlien;
//
//    do
//    {
//        printf("\n========Data Klien========\n");
//        printf("[1]. Menambahkan Data\n");
//        printf("[2]. Menampilkan Data\n");
//        printf("[3]. Mengubah Data\n");
//        printf("[4]. Menghapus Data\n");
//        printf("[0]. Keluar\n");
//        printf("Pilih menu:");
//        scanf("%d", &pilihan);
//
//        if(pilihan == 1)
//        {
//            MenambahkanData (ArsKlien);
//        }
//        else if(pilihan == 2)
//        {
//            MenampilkanData(ArsKlien);
//        }
//        else if (pilihan == 3)
//        {
//            MengubahData(Temp, ArsKlien, Asal, cari);
//        }
//        else if (pilihan == 4)
//        {
//            MenghapusData(Asal, Temp, cari);
//        }
//        else if (pilihan == 0)
//        {
//            MessageBox(NULL, "Terimakasih","Notification", MB_OK);
//        }
//        else
//        {
//            MessageBox(NULL, "Pilihan Tidak Sesuai","Error", MB_OK | MB_ICONERROR);
//        }
//    }
//    while (pilihan != 0);
//}