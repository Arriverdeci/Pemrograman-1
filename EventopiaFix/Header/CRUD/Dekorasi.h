

int createDCR (FILE *ArsDekor) {
    int id;
    int loop;

    ArsDekor = fopen("Dekorasi.dat", "ab+");
    fread(&Dekorasi, sizeof (Dekorasi), 1, ArsDekor);
    while (!feof(ArsDekor))
    {
        fread(&Dekorasi, sizeof (Dekorasi), 1, ArsDekor);
        id = Dekorasi.id_dekorasi;
        loop++;
    }

    if (loop == 0)
    {
        Dekorasi.id_dekorasi = 1;
    }
    else
    {
        Dekorasi.id_dekorasi = id + 1;
    }
    fclose(ArsDekor);

    printf("Masukkan Data!!!\n\n");
    printf("Id Dekorasi             :DECOR%d\n", Dekorasi.id_dekorasi);

    printf("Nama Dekorasi           :");
    scanf(" %[^\n]", Dekorasi.nama_dekorasi);

    printf("Deskripsi Dekorasi      :");
    scanf(" %[^\n]", Dekorasi.deskripsi_dekorasi);

    printf("Stok Dekorasi           :");
    scanf("%d", &Dekorasi.stok_dekorasi);

    printf("Harga Dekorasi          :");
    scanf("%d", &Dekorasi.harga_dekorasi);

    printf("Status Dekorasi         :");
    scanf(" %[^\n]", Dekorasi.status);

    fwrite(&Dekorasi, sizeof(Dekorasi), 1, ArsDekor);

    ArsDekor = fopen("Dekorasi.dat", "ab");
    fwrite(&Dekorasi, sizeof (Dekorasi), 1, ArsDekor);
    fclose(ArsDekor);

    MessageBox(NULL,"Data Berhasil Ditambahkan","Information", MB_OK | MB_ICONASTERISK);

}

int readDCR (FILE *ArsDekor)
{
    ArsDekor = fopen("Dekorasi.dat", "rb");
    printf("\n");
    if (ArsDekor == NULL)
    {
        printf("Data tidak ditemukan\n");
    }
    else
    {
        printf("Data Dekorasi:\n");
        printf("Id Dekorasi\t|Nama Dekorasi\t|Deskripsi Dekorasi\t|Stok Dekorasi\t|Harga Dekorasi\t|Status Dekorasi\n");
        while(fread(&Dekorasi, sizeof(Dekorasi), 1, ArsDekor) == 1)
        {
            printf("DECOR%d", Dekorasi.id_dekorasi);
            printf("\t|%s", Dekorasi.nama_dekorasi);
            printf("\t|%s", Dekorasi.deskripsi_dekorasi);
            printf("\t|%d", Dekorasi.stok_dekorasi);
            printf("\t|%d", Dekorasi.harga_dekorasi);
            printf("\t|%s", Dekorasi.status);
            printf("\n");
        }
    }
    fclose(ArsDekor);
}

int updateDCR (FILE *Temp, FILE *ArsDekor, FILE *Asal, int dicari)
{
    DC DataBaru;
    int ditemukan;
    int pilihan;
    ArsDekor = fopen("Dekorasi.dat", "rb");
    printf("\n");

    printf("Data Dekorasi:\n");
    printf("Id Dekorasi\t|Nama Dekorasi\t|Deskripsi Dekorasi\t|Stok Dekorasi\t|Harga Dekorasi\t|Status Dekorasi\n");
    while (fread(&Dekorasi, sizeof(Dekorasi), 1, ArsDekor) == 1) {
        printf("DECOR%d", Dekorasi.id_dekorasi);
        printf("\t|%s", Dekorasi.nama_dekorasi);
        printf("\t|%s", Dekorasi.deskripsi_dekorasi);
        printf("\t|%d", Dekorasi.stok_dekorasi);
        printf("\t|%d", Dekorasi.harga_dekorasi);
        printf("\t|%s", Dekorasi.status);
        printf("\n");
    }
    fclose(ArsDekor);

    printf("Masukkan Id yang ingin diubah:\nDECOR");
    scanf("%d", &dicari);

    Asal = fopen("Dekorasi.dat", "rb");
    Temp = fopen("Temp.dat", "wb");

    ditemukan = 0;
    while (ditemukan == 0 && fread(&Dekorasi, sizeof (Dekorasi), 1, Asal) == 1)
    {
        if (Dekorasi.id_dekorasi == dicari)
        {
            ditemukan = 1;
        }
        else
        {
            fwrite(&Dekorasi, sizeof (Dekorasi), 1, Temp);
        }
    }
    if (ditemukan == 1)
    {
        do
        {
            printf("\n[1]. Ubah Semua Data\n");
            printf("[2]. Ubah Nama\n");
            printf("[3]. Ubah Deskripsi\n");
            printf("[4]. Ubah Stok\n");
            printf("[5]. Ubah Harga\n");
            printf("[6]. Ubah Status\n");
            printf("[7]. Kembali\n");
            printf("Pilih menu:");
            scanf("%d", &pilihan);

            if(pilihan == 1)
            {
                printf("Masukkan Nama Baru      :");
                scanf(" %[^\n]", DataBaru.nama_dekorasi);
                strcpy(Dekorasi.nama_dekorasi, DataBaru.nama_dekorasi);

                printf("Masukkan Deskripsi Baru :");
                scanf(" %[^\n]", DataBaru.deskripsi_dekorasi);
                strcpy(Dekorasi.deskripsi_dekorasi, DataBaru.deskripsi_dekorasi);

                printf("Masukkan Stok Baru      :");
                scanf("%d", &DataBaru.stok_dekorasi);
                Dekorasi.stok_dekorasi = DataBaru.stok_dekorasi;

                printf("Masukkan Harga Baru     :");
                scanf("%d", &DataBaru.harga_dekorasi);
                Dekorasi.harga_dekorasi = DataBaru.harga_dekorasi;

                printf("Masukkan Status Baru    :");
                scanf(" %[^\n]", DataBaru.status);
                strcpy(Dekorasi.status, DataBaru.status);

                MessageBox(NULL, "Data Berhasil Diubah","Information", MB_OK | MB_ICONASTERISK);
            }
            else if(pilihan == 2)
            {
                printf("Masukkan Nama Baru      :");
                scanf(" %[^\n]", DataBaru.nama_dekorasi);
                strcpy(Dekorasi.nama_dekorasi, DataBaru.nama_dekorasi);

                MessageBox(NULL, "Data Berhasil Diubah","Information", MB_OK | MB_ICONASTERISK);
            }
            else if (pilihan == 3)
            {
                printf("Masukkan Deskripsi Baru :");
                scanf(" %[^\n]", DataBaru.deskripsi_dekorasi);
                strcpy(Dekorasi.deskripsi_dekorasi, DataBaru.deskripsi_dekorasi);

                MessageBox(NULL, "Data Berhasil Diubah","Information", MB_OK | MB_ICONASTERISK);
            }
            else if (pilihan == 4)
            {
                printf("Masukkan Stok Baru      :");
                scanf("%d", &DataBaru.stok_dekorasi);
                Dekorasi.stok_dekorasi = DataBaru.stok_dekorasi;

                MessageBox(NULL, "Data Berhasil Diubah","Information", MB_OK | MB_ICONASTERISK);
            }
            else if (pilihan == 5)
            {
                printf("Masukkan Harga Baru     :");
                scanf("%d", &DataBaru.harga_dekorasi);
                Dekorasi.harga_dekorasi = DataBaru.harga_dekorasi;

                MessageBox(NULL, "Data Berhasil Diubah","Information", MB_OK | MB_ICONASTERISK);
            }
            else if (pilihan == 6)
            {
                printf("Masukkan Status Baru    :");
                scanf(" %[^\n]", DataBaru.status);
                strcpy(Dekorasi.status, DataBaru.status);

                MessageBox(NULL, "Data Berhasil Diubah","Information", MB_OK | MB_ICONASTERISK);
            }
            else if (pilihan == 7)
            {
                break;
            }
            else
            {
                MessageBox(NULL, "Pilihan Tidak Sesuai","Error", MB_OK | MB_ICONERROR);
            }
        } while (pilihan != 7);
        fwrite(&Dekorasi, sizeof (Dekorasi), 1, Temp);
        while (fread(&Dekorasi, sizeof (Dekorasi), 1, Asal) == 1)
        {
            fwrite(&Dekorasi, sizeof (Dekorasi), 1, Temp);
        }
    }
    else
    {
        MessageBox(NULL, "Kode tidak ditemukan di dalam arsip asal", "Error", MB_OK | MB_ICONERROR);
    }
    fclose(Asal);
    fclose(Temp);

    Asal = fopen("Dekorasi.dat", "wb");
    Temp = fopen("Temp.dat", "rb");

    while (fread(&Dekorasi, sizeof (Dekorasi), 1, Temp) == 1)
    {
        fwrite(&Dekorasi, sizeof (Dekorasi), 1, Asal);
    }
    fclose(Temp);
    fclose(Asal);
}


int deleteDCR (FILE *Asal, FILE *Temp, int dicari) {
    int ditemukan;
    Asal = fopen("Dekorasi.dat", "rb");
    printf("\n");

    printf("Data Dekorasi:\n");
    printf("Id Dekorasi\t|Nama Dekorasi\t|Deskripsi Dekorasi\t|Stok Dekorasi\t|Harga Dekorasi\t|Status Dekorasi\n");
    while (fread(&Dekorasi, sizeof(Dekorasi), 1, Asal) == 1) {
        printf("DECOR%d", Dekorasi.id_dekorasi);
        printf("\t|%s", Dekorasi.nama_dekorasi);
        printf("\t|%s", Dekorasi.deskripsi_dekorasi);
        printf("\t|%d", Dekorasi.stok_dekorasi);
        printf("\t|%d", Dekorasi.harga_dekorasi);
        printf("\t|%s", Dekorasi.status);
        printf("\n");
    }
    fclose(Asal);
    printf("\nMasukkan Id yang ingin dihapus:\tDECOR");
    scanf("%d", &dicari);

    Asal = fopen("Dekorasi.dat", "rb");
    Temp = fopen("Temp.dat", "wb");

    ditemukan = 0;
    while (ditemukan == 0 && fread(&Dekorasi, sizeof(Dekorasi), 1, Asal) == 1)
    {
        if (Dekorasi.id_dekorasi == dicari)
        {
            ditemukan = 1;
        }
        else
        {
            fwrite(&Dekorasi, sizeof(Dekorasi), 1, Temp);
        }
    }

    if (ditemukan == 1)
    {
        printf("\n");
        printf("Data Dekorasi berikut berhasil dihapus\n");
        printf("Id Dekorasi\t|Nama Dekorasi\t|Deskripsi Dekorasi\t|Stok Dekorasi\t|Harga Dekorasi\t|Status Dekorasi\n");
        printf("DECOR%d", Dekorasi.id_dekorasi);
        printf("\t|%s", Dekorasi.nama_dekorasi);
        printf("\t|%s", Dekorasi.deskripsi_dekorasi);
        printf("\t|%d", Dekorasi.stok_dekorasi);
        printf("\t|%d", Dekorasi.harga_dekorasi);
        printf("\t|%s", Dekorasi.status);
        printf("\n");

        while (fread(&Dekorasi, sizeof(Dekorasi), 1, Asal) == 1)
        {
            fwrite(&Dekorasi, sizeof (Dekorasi), 1, Temp);
        }

        fclose(Asal);
        fclose(Temp);

        Asal = fopen("Dekorasi.dat", "wb");
        Temp = fopen("Temp.dat", "rb");

        while (fread(&Dekorasi, sizeof(Dekorasi), 1, Temp) == 1)
        {
            fwrite(&Dekorasi, sizeof(Dekorasi), 1, Asal);
        }
        fclose(Asal);
        fclose(Temp);
    }
    else
    {
        MessageBox(NULL, "Kode tidak ditemukan di dalam arsip asal", "Error", MB_OK | MB_ICONERROR);
    }
}

int menuDCR ()
{
    int pilihan;
    int cari;
    FILE *Temp;
    FILE *Asal;
    FILE *ArsDekor;

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
            MenambahkanData (ArsDekor);
        }
        else if(pilihan == 2)
        {
            MenampilkanData(ArsDekor);
        }
        else if (pilihan == 3)
        {
            MengubahData(Temp, ArsDekor, Asal, cari);
        }
        else if (pilihan == 4)
        {
            MenghapusData(Asal, Temp, cari);
        }
        else if (pilihan == 5)
        {
            MessageBox(NULL, "Terimakasih","Notification", MB_OK);
        }
        else
        {
            MessageBox(NULL, "Pilihan Tidak Sesuai","Error", MB_OK | MB_ICONERROR);
        }
    }
    while (pilihan != 5);
}

void MasterDCR () {

    garismenu();
    menuDCR();

}