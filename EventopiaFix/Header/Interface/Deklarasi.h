#define ENTER 13
#define BACKSPACE 8
#define TAB 9
//Ascii keyboard atas dan bawah
#define UP_KEY 72
#define DWN_KEY 80
#define RIGHT_KEY 77
#define LEFT_KEY 75

// tengah = 118
// kiri = 21
// kanan = 21

int i;
int j;
int out;
int found;
int updt;
char rp[50];
char karakter;
int ROLES;
char emp [50];
bool EscPressed;

typedef struct{
    int tanggal, bulan, tahun, hour, min, sec;
}DateTime;
DateTime now;

void DateTimeNow(DateTime *TglOutput) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    TglOutput->tanggal = tm.tm_mday;
    TglOutput->bulan = tm.tm_mon+1;
    TglOutput->tahun = tm.tm_year+1900;
    TglOutput->sec = tm.tm_sec;
    TglOutput->min = tm.tm_min;
    TglOutput->hour = tm.tm_hour;
}

// Master Dekorasi
typedef struct  {
    int id_dekorasi;
    char nama_dekorasi[25];
    char deskripsi_dekorasi [150];
    int stok_dekorasi;
    int harga_dekorasi;
    char status[20];

} DC;
DC Dekorasi;

// Master Jasa
typedef struct {
    int id;
    char jenis [100];
    int biaya;
} Jasa ;
Jasa jasa;

// Master Karyawan
typedef struct {
    int id;
    char nama [50];
    char username [10];
    char password [10];
    char role [15];
    char notelp [15];
    int tgl, bulan, tahun;
} User ;
User U;
User uNew;

// Master Klien


// Master Pembawa Acara


// Master Sponsor


// Master Tempat
typedef struct {
    int id;
    char nama [25];
    char alamat [50];
    int kapasitas;
    int harga;
    char status [15];
} Tempat ;
Tempat tempat;

// Master Pemasok
typedef struct {
    int id;
    char nama[30];
    char kategori[30];
    char notelp[15];
} Pemasok ;
Pemasok sp;

// Master Promo


// Master Sponsor


// Master Suvenir
typedef struct {
    int id;
    int idSup;
    char namaSup[25];
    char nama[25];
    int stok;
    int harga;
} Suvenir ;
Suvenir sv;


// Transaksi Penjualan Suvenir
typedef struct {
    int id;
    int idSup;
    int idEMp;
    char EMPname [25];
    int idPrm;
    int tgl;
    int bulan;
    int tahun;
    int total;
    int uang;
    int kembali;
    char status [15];
} Penjualan;
Penjualan trs;

// Detail Penjualan Suvenir
typedef struct {
    int idTPS;
    int idS;
    char namaS [25];
    int hargaS;
    int qty;
    int subtotal;

} DetailSuvenir;
DetailSuvenir dtTrSv;

// Keranjang
typedef struct{
    int id;
    char nama [25];
    int qty;
}keranjang;
keranjang krj;
FILE *arskrj;

// Master Klien
typedef struct  {
    int idKlien;
    char nama[15];
    char notelp[14];
    char email[50];
    char alamat[50];
} KL;
KL cln;


// Transaksi Pengajuan Acara
typedef struct {
    int idEvent;
    int idKaryawan;
    int idKlien;
    int idTempat;
    int idJasa;
    char namaEvent [30];
    char jenisEvent [30];
    char bintangTamu [30];
    int tglPengajuan, blnPengajuan, thnPengajuan;
    int tglMulai, blnMulai, thnMulai;
    int tglSelesai, blnSelesai, thnSelesai;
    char statusPengajuan [20];
    char statusPelaksanaan [20];
    int totalBiaya;
} Acara;
Acara evnt;

// Detail Master Sponsor
typedef struct{
    int idDT;
    int idPerusahaanSponsor;
    int tglTRS, blnTRS, thnTRS;
}DTLSPNSR;
DTLSPNSR dtlspnsr;

// Detail Master Dekorasi
typedef struct{
    int idDT;
    int idDekorasi;
    int tglTRS, blnTRS, thnTRS;
    int qty;
    int harga;
    int totalBiaya;
}DTLDCR;
DTLDCR dtldcr;

// Detail Master Pembawa Acara
typedef struct {
    int idDT;
    int idPembawaAcara;
    int tglTRS, blnTRS, thnTRS;
    int totalBiaya;
}DTLMC;
DTLMC dtlmc;

// Master Sponsor
typedef struct {
    int idPerusahaanSponsor;
    char namaPerusahaanSponsor[50];
    char alamatPerusahaanSponsor[100];
    char noTelpPerusahaanSponsor[15];
    char emailPerusahaanSponsor[50];
    char benefit[100];
    char statusKetersediaanSponsor[1];
} SPNSR;
SPNSR spnsr;

// Master Dekorasi
typedef struct  {
    int idDekorasi;
    char namaDekorasi[25];
    char deskripsiDekorasi [150];
    int stokDekorasi;
    int hargaDekorasi;
    char status[20];
} DCR;
DCR dcr;

// Master Pembawa Acara
typedef struct{
    int idPembawaAcara;
    char nama[30];
    char notelp[13];
    int biaya;
} MC;
MC mc;