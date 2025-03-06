#include <iostream>
using namespace std;

void inputdatakendaraan();
void tampildatakendaraan();
void bubblesort();
void sequentialsearch();

struct Kendaraan {
    string platnomer;
    string jenis;
    string merk;
    string model;
    string nama_pemilik;
    int tahun_produksi;
};

Kendaraan kndr[100];
int jumlah_kendaraan = 0; 

int main() {
    int pilihan;

    do {
        cout << "\nMenu : " << endl;
        cout << "1. Input Data Kendaraan" << endl;
        cout << "2. Tampilkan Seluruh Data Kendaraan" << endl;
        cout << "3. Urutkan Data Kendaraan (Bubble Sort)" << endl;
        cout << "4. Cari Data kendaraan (sequentialsearch)" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                inputdatakendaraan();
                break;
            case 2:
                tampildatakendaraan();
                break;
            case 3:
                bubblesort();
                cout << "Data berhasil diurutkan menggunakan Bubble Sort berdasarkan Tahun Produksi.\n";
                tampildatakendaraan(); 
                break;
            case 4:
                sequentialsearch();
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Nggak gitu bang, pilih yang bener!\n";
        }
    } while (pilihan != 5);

    return 0;
}

void inputdatakendaraan() {
    int jumlah_kendaraan1;
    cout << "Masukkan jumlah kendaraan yang ingin ditambahkan: ";
    cin >> jumlah_kendaraan1;

    if (jumlah_kendaraan + jumlah_kendaraan1 > 100) {
        cout << "Jangan memasukkan data terlalu banyak!\n";
        return;
    }

    for (int i = 0; i < jumlah_kendaraan1; i++) {
        cout << "Masukkan Plat Nomor Kendaraan ke-" << (jumlah_kendaraan + 1) << ": ";
        cin >> kndr[jumlah_kendaraan].platnomer;

        cout << "Masukkan Jenis Kendaraan ke-" << (jumlah_kendaraan + 1) << ": ";
        cin >> kndr[jumlah_kendaraan].jenis;

        cout << "Masukkan Merk Kendaraan ke-" << (jumlah_kendaraan + 1) << ": ";
        cin >> kndr[jumlah_kendaraan].merk;

        cout << "Masukkan Model Kendaraan ke-" << (jumlah_kendaraan + 1) << ": ";
        cin >> kndr[jumlah_kendaraan].model;

        cout << "Masukkan Nama Pemilik Kendaraan ke-" << (jumlah_kendaraan + 1) << ": ";
        cin >> kndr[jumlah_kendaraan].nama_pemilik;

        cout << "Masukkan Tahun Produksi Kendaraan ke-" << (jumlah_kendaraan + 1) << ": ";
        cin >> kndr[jumlah_kendaraan].tahun_produksi;

        if (kndr[jumlah_kendaraan].tahun_produksi < 1900 || kndr[jumlah_kendaraan].tahun_produksi > 2025) {
            cout << "Tahun produksi tidak valid! Harus antara 1900 - 2025.\n";
            return;
        }

        jumlah_kendaraan++;
    }
    cout << "Data kendaraan berhasil ditambahkan.\n";
}

void tampildatakendaraan() {
    if (jumlah_kendaraan == 0) {
        cout << "Tidak ada data kendaraan.\n";
    } else {
        cout << "\nData Kendaraan:\n";
        for (int i = 0; i < jumlah_kendaraan; i++) {
            cout << "Kendaraan ke-" << i + 1 << ":\n";
            cout << "Plat Nomor: " << kndr[i].platnomer << endl;
            cout << "Jenis: " << kndr[i].jenis << endl;
            cout << "Merk: " << kndr[i].merk << endl;
            cout << "Model: " << kndr[i].model << endl;
            cout << "Nama Pemilik: " << kndr[i].nama_pemilik << endl;
            cout << "Tahun Produksi: " << kndr[i].tahun_produksi << endl;
            cout << "-----------------------\n";
        }
    }
}

void bubblesort() {
    for (int i = 0; i < jumlah_kendaraan - 1; i++) {
        for (int j = 0; j < jumlah_kendaraan - i - 1; j++) {
            if (kndr[j].tahun_produksi > kndr[j + 1].tahun_produksi) {
                swap(kndr[j], kndr[j + 1]);
            }
        }
    }
}


void sequentialsearch() {
    if (jumlah_kendaraan == 0) {
        cout << "Data kendaraan masih kosong.\n";
        return;
    }

    string pemilik;
    cout << "Masukkan Nama Pemilik Kendaraan yang ingin dicari: ";
    cin >> pemilik;

    bool ditemukan = false;
    for (int i = 0; i < jumlah_kendaraan; i++) {
        if (kndr[i].nama_pemilik == pemilik) {
            cout << "\nKendaraan ditemukan!\n";
            cout << "Plat Nomor  : " << kndr[i].platnomer << endl;
            cout << "Jenis       : " << kndr[i].jenis << endl;
            cout << "Merk        : " << kndr[i].merk << endl;
            cout << "Model       : " << kndr[i].model << endl;
            cout << "Nama Pemilik: " << kndr[i].nama_pemilik << endl;
            cout << "Tahun Produksi: " << kndr[i].tahun_produksi << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Nama Pemilik Kendaraan Tidak di Temukan " << pemilik << " tidak ditemukan.\n";
    }
}
