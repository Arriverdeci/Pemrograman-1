#include <stdio.h>
#include <stdlib.h>

struct TransaksiSuvenir {
    int id;
    double total;
    int tgl;
    int bulan;
    int tahun;
    char EMPname[50];
};

void LaporanPenjualan();


void LaporanSV () {

    garismenu();
    LaporanPenjualan();

}


void LaporanPenjualan() {
    FILE *TRS;
    char uang[25];

    TRS = fopen("../Dat/Transaksi Penjualan Suvenir.dat", "rb");

//    if (TRS == NULL) {
//        printf("Data Transaksi tidak ditemukan\n");
//        return;
//    }

    printf("D A T A  T R A N S A K S I  P E N J U A L A N  S U V E N I R\n");

    printf("| %-10s | %-15s | %-15s | %-20s |\n", "ID", "TOTAL", "TANGGAL", "KASIR");
    printf("|------------|-----------------|-----------------|----------------------|\n");

//    struct TransaksiSuvenir trs;

    while (fread(&trs, sizeof(trs), 1, TRS) == 1) {
        printf("| %-10d | Rp %d | %02d/%02d/%04d      | %-20s |\n",
               trs.id, trs.total, trs.tgl, trs.bulan, trs.tahun, trs.EMPname);
    }

    fclose(TRS);
}


void generateLaporan();
void LaporanAcara () {

    garismenu();
    generateLaporan();

}

Acara Event;

void generateLaporan() {
    FILE *ArsEvent;
    char Biaya[25];

    ArsEvent = fopen("Event.dat", "rb");

    if (ArsEvent == NULL) {
        printf("Data Event tidak ditemukan\n");
        return;
    }

    printf("Laporan Data Acara:\n");
    printf("| %-10s | %-10s | %-10s | %-10s | %-10s | %-30s | %-30s | %-30s | %-20s | %-20s | %-20s | %-20s | %-20s | %-20s |\n",
           "ID Acara", "ID Karyawan", "ID Klien", "ID Tempat", "ID Jasa", "Nama Event", "Bintang Tamu", "Jenis Event",
           "Tgl Pengajuan", "Tgl Mulai", "Tgl Selesai", "Status Pengajuan", "Status Pelaksanaan", "Total Biaya");


    while (fread(&Event, sizeof(Event), 1, ArsEvent) == 1) {
        printf("| %-10d | %-10d | %-10d | %-10d | %-10d | %-30s | %-30s | %-30s | %02d-%02d-%d | %02d-%02d-%d | %02d-%02d-%d | %-20s | %-20s | %-20d |\n",
               Event.idEvent, Event.idKaryawan, Event.idKlien, Event.idTempat, Event.idJasa,
               Event.namaEvent, Event.bintangTamu, Event.jenisEvent,
               Event.tglPengajuan, Event.blnPengajuan, Event.thnPengajuan,
               Event.tglMulai, Event.blnMulai, Event.thnMulai,
               Event.tglSelesai, Event.blnSelesai, Event.thnSelesai,
               Event.statusPengajuan, Event.statusPelaksanaan, Event.totalBiaya);
    }

    fclose(ArsEvent);
}