
typedef struct{ int idPembawaAcara;
    char nama[30];
    char notelp[13];
    char gayaBicara[20];
    float biaya;
} Data;
Data MC;

int createMC (FILE *ArsMC)
{
    int id;
    int loop;

    ArsMC = fopen("PembawaAcara.dat", "ab+");
    fread(&MC, sizeof (MC), 1, ArsMC);
    while (!feof(ArsMC))
    {
        fread(&MC, sizeof (MC), 1, ArsMC);
        id = MC.idPembawaAcara;
        loop++;
    }

    if (loop == 0)
    {
        MC.idPembawaAcara = 1;
    }
    else
    {
        MC.idPembawaAcara = id + 1;
    }
    fclose(ArsMC);

    printf("Masukkan Data!!!\n\n");
    printf("Id Pembawa Acara    :MC%d\n", MC.idPembawaAcara);

    printf("Nama Pembawa Acara  :");
    scanf(" %[^\n]",  MC.nama);

    printf("No Telepon          :");
    scanf("%s", MC.notelp);

    printf("Gaya Bicara         :");
    scanf(" %[^\n]", MC.gayaBicara);

    printf("Biaya               :");
    scanf("%f", &MC.biaya);

    fwrite(&MC, sizeof(MC), 1, ArsMC);

    ArsMC = fopen("PembawaAcara.dat", "ab");
    fwrite(&MC, sizeof (MC), 1, ArsMC);
    fclose(ArsMC);

    MessageBox(0,"Data Berhasil Ditambahkan","Information", MB_OK | MB_ICONASTERISK);

}

int readMC (FILE *ArsMC)
{
    ArsMC = fopen("PembawaAcara.dat", "rb");
    printf("\n");
    if (ArsMC == NULL)
    {
        printf("Data tidak ditemukan\n");
    }
    else
    {
        printf("Data Pembawa Acara:\n");
        printf("Id\t|Nama\t|No Telepon\t|Gaya Bicara\t|Biaya\n");
        while(fread(&MC, sizeof(MC), 1, ArsMC) == 1)
        {
            printf("MC%d", MC.idPembawaAcara);
            printf("\t|%s", MC.nama);
            printf("\t|%s", MC.notelp);
            printf("\t|%s", MC.gayaBicara);
            printf("\t|%.2f", MC.biaya);
            printf("\n");
        }
    }
    fclose(ArsMC);
}

int updateMC (FILE *Temp, FILE *ArsMC, FILE *Asal, int dicari)
{
    Data DataBaru;
    int ditemukan;
    int pilihan;
    ArsMC = fopen("PembawaAcara.dat", "rb");
    printf("\n");

    printf("Data Pembawa Acara:\n");
    printf("Id\t|Nama\t|No Telepon\t|Gaya Bicara\t|Biaya\n");
    while (fread(&MC, sizeof(MC), 1, ArsMC) == 1) {
        printf("MC%d", MC.idPembawaAcara);
        printf("\t|%s", MC.nama);
        printf("\t|%s", MC.notelp);
        printf("\t|%s", MC.gayaBicara);
        printf("\t|%.2f", MC.biaya);
        printf("\n");
    }
    fclose(ArsMC);

    printf("Masukkan Id yang ingin diubah:\tMC");
    scanf("%d", &dicari);

    Asal = fopen("PembawaAcara.dat", "rb");
    Temp = fopen("Temp.dat", "wb");

    ditemukan = 0;
    while (ditemukan == 0 && fread(&MC, sizeof (MC), 1, Asal) == 1)
    {
        if (MC.idPembawaAcara == dicari)
        {
            ditemukan = 1;
        }
        else
        {
            fwrite(&MC, sizeof (MC), 1, Temp);
        }
    }
    if (ditemukan == 1)
    {
        do
        {
            printf("\n[1]. Ubah Semua Data\n");
            printf("[2]. Ubah Nama\n");
            printf("[3]. Ubah No Telepon\n");
            printf("[4]. Ubah Gaya Bicara\n");
            printf("[5]. Ubah Biaya\n");
            printf("[6]. Kembali\n");
            printf("Pilih menu:");
            scanf("%d", &pilihan);

            if(pilihan == 1)
            {
                printf("Masukkan Nama Baru:");
                scanf(" %[^\n]", DataBaru.nama);
                strcpy(MC.nama, DataBaru.nama);

                printf("Masukkan No Telepon Baru:");
                scanf("%s", DataBaru.notelp);
                strcpy(MC.notelp, DataBaru.notelp);

                printf("Masukkan Gaya Bicara Baru:");
                scanf(" %[^\n]", DataBaru.gayaBicara);
                strcpy(MC.gayaBicara, DataBaru.gayaBicara);

                printf("Masukkan Biaya Baru:");
                scanf("%f", &DataBaru.biaya);
                MC.biaya = DataBaru.biaya;

                MessageBox(NULL, "Data Berhasil Diubah","Information", MB_OK | MB_ICONASTERISK);
            }
            else if(pilihan == 2)
            {
                printf("Masukkan Nama Baru:");
                scanf(" %[^\n]", DataBaru.nama);
                strcpy(MC.nama, DataBaru.nama);

                MessageBox(NULL, "Data Berhasil Diubah","Information", MB_OK | MB_ICONASTERISK);
            }
            else if (pilihan == 3)
            {
                printf("Masukkan No Telepon Baru:");
                scanf("%s", DataBaru.notelp);
                strcpy(MC.notelp, DataBaru.notelp);
                MessageBox(NULL, "Data Berhasil Diubah","Information", MB_OK | MB_ICONASTERISK);
            }
            else if (pilihan == 4)
            {
                printf("Masukkan Gaya Bicara Baru:");
                scanf(" %[^\n]", DataBaru.gayaBicara);
                strcpy(MC.gayaBicara, DataBaru.gayaBicara);
                MessageBox(NULL, "Data Berhasil Diubah","Information", MB_OK | MB_ICONASTERISK);
            }
            else if (pilihan == 5)
            {
                printf("Masukkan Biaya Baru:");
                scanf("%f", &DataBaru.biaya);
                MC.biaya = DataBaru.biaya;
                MessageBox(NULL, "Data Berhasil Diubah","Information", MB_OK | MB_ICONASTERISK);
            }
            else if (pilihan == 6)
            {
                break;
            }
            else
            {
                MessageBox(NULL, "Pilihan Tidak Sesuai","Error", MB_OK | MB_ICONERROR);
            }
        } while (pilihan != 6);
        fwrite(&MC, sizeof (MC), 1, Temp);
        while (fread(&MC, sizeof (MC), 1, Asal) == 1)
        {
            fwrite(&MC, sizeof (MC), 1, Temp);
        }
    }
    else
    {
        MessageBox(NULL, "Kode tidak ditemukan di dalam arsip asal", "Error", MB_OK | MB_ICONERROR);
    }
    fclose(Asal);
    fclose(Temp);

    Asal = fopen("PembawaAcara.dat", "wb");
    Temp = fopen("Temp.dat", "rb");

    while (fread(&MC, sizeof (MC), 1, Temp) == 1)
    {
        fwrite(&MC, sizeof (MC), 1, Asal);
    }
    fclose(Temp);
    fclose(Asal);
}


int deleteMC (FILE *Asal, FILE *Temp, int dicari) {
    int ditemukan;
    Asal = fopen("PembawaAcara.dat", "rb");
    printf("\n");

    printf("Data Pembawa Acara:\n");
    printf("Id\t|Nama\t|No Telepon\t|Gaya Bicara\t|Biaya\n");
    while (fread(&MC, sizeof(MC), 1, Asal) == 1) {
        printf("MC%d", MC.idPembawaAcara);
        printf("\t|%s", MC.nama);
        printf("\t|%s", MC.notelp);
        printf("\t|%s", MC.gayaBicara);
        printf("\t|%.2f", MC.biaya);
        printf("\n");
    }
    fclose(Asal);
    printf("\nMasukkan Id yang ingin dihapus:\tMC");
    scanf("%d", &dicari);

    Asal = fopen("PembawaAcara.dat", "rb");
    Temp = fopen("Temp.dat", "wb");

    ditemukan = 0;
    while (ditemukan == 0 && fread(&MC, sizeof(MC), 1, Asal) == 1)
    {
        if (MC.idPembawaAcara == dicari)
        {
            ditemukan = 1;
        }
        else
        {
            fwrite(&MC, sizeof(MC), 1, Temp);
        }
    }

    if (ditemukan == 1)
    {
        printf("\n");
        printf("Data Pembawa Acara berikut berhasil dihapus\n");
        printf("Id\t|Nama\t|No Telepon\t|Gaya Bicara\t|Biaya\n");
        printf("MC%d", MC.idPembawaAcara);
        printf("\t|%s", MC.nama);
        printf("\t|%s", MC.notelp);
        printf("\t|%s", MC.gayaBicara);
        printf("\t|%.2f", MC.biaya);
        printf("\n");

        while (fread(&MC, sizeof(MC), 1, Asal) == 1)
        {
            fwrite(&MC, sizeof (MC), 1, Temp);
        }

        fclose(Asal);
        fclose(Temp);

        Asal = fopen("PembawaAcara.dat", "wb");
        Temp = fopen("Temp.dat", "rb");

        while (fread(&MC, sizeof(MC), 1, Temp) == 1)
        {
            fwrite(&MC, sizeof(MC), 1, Asal);
        }
        fclose(Asal);
        fclose(Temp);
    }
    else
    {
        MessageBox(NULL, "Kode tidak ditemukan di dalam arsip asal", "Error", MB_OK | MB_ICONERROR);
    }
}

int menuMC ()
{
    int cari;
    FILE *Temp;
    FILE *Asal;
    FILE *ArsMC;
    int pilihan;

    do
    {
        printf("\n========Data Klien========\n");
        printf("[1]. Menambahkan Data\n");
        printf("[2]. Menampilkan Data\n");
        printf("[3]. Mengubah Data\n");
        printf("[4]. Menghapus Data\n");
        printf("[5]. Keluar\n");
        printf("Pilih menu:");
        scanf("%d", &pilihan);

        if(pilihan == 1)
        {
            createMC (ArsMC);
        }
        else if(pilihan == 2)
        {
            readMC(ArsMC);
        }
        else if (pilihan == 3)
        {
            updateMC(Temp, ArsMC, Asal, cari);
        }
        else if (pilihan == 4)
        {
            deleteMC(Asal, Temp, cari);
        }
        else if (pilihan == 5)
        {
            MessageBox(NULL, "Terimakasih","Information", MB_OK | MB_ICONASTERISK);
        }
        else
        {
            MessageBox(NULL, "Pilihan Tidak Sesuai","Error", MB_OK | MB_ICONERROR);
        }
    }
    while (pilihan != 5);
}

void MasterMC () {

    garismenu();
    menuMC();
}