#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct nilai {
    float uts, uas, tugas;
    float Mtk, BIn, Big, IPA;
};

struct tanggal {
    int hari, bulan, tahun;
};

struct siswa {
    string nama;
    int umur;
    string jurusan;
    string NISN;
    tanggal lahir;
    nilai us;
    nilai Nilai;
};

float nilaiAkhirUjian(nilai n) {
    return (n.uas * 0.40) + (n.uts * 0.35) + (n.tugas * 0.25);
}

float nilaiAkhirMapel(nilai n) {
    return (n.Mtk * 0.35) + (n.IPA * 0.25) + (n.BIn * 0.20) + (n.Big * 0.20);
}

//hitung totl nilai
float totalNilaiAkhir(nilai n) {
    float TotalNilai;
      TotalNilai=(n.uas + n.uts + n.tugas + n.Mtk + n.IPA + n.BIn + n.Big + n.uts + n.tugas + n.Big);
 return (TotalNilai / 2);
}

//Menginput data dari user
void input(int &jumlah, siswa s[]) {
    for (int x = 0; x < jumlah; x++) {
        cout << "------------------------------" << endl;
        cout << " Masukan Data Siswa Ke-" << x + 1 << endl;

        cin.ignore();
        cout << "Masukan Nama Siswa : ";
        getline(cin, s[x].nama);

        cout << "Masukkan NISN Siswa : ";
        cin >> s[x].NISN;

        cout << "Masukkan Umur Siswa : ";
        cin >> s[x].umur;

        cin.ignore();
        cout << "Masukkan Jurusan Siswa: ";
        getline(cin, s[x].jurusan);

        cout << "Masukkan tanggal lahir: ";
        cin >> s[x].lahir.hari;

        cout << "Masukkan bulan lahir: ";
        cin >> s[x].lahir.bulan;

        cout << "Masukkan tahun lahir: ";
        cin >> s[x].lahir.tahun;

        cout << "Masukkan nilai UAS: ";
        cin >> s[x].us.uas;

        cout << "Masukkan nilai UTS: ";
        cin >> s[x].us.uts;

        cout << "Masukkan nilai TUGAS: ";
        cin >> s[x].us.tugas;

        cout << "Masukkan nilai Matematika: ";
        cin >> s[x].Nilai.Mtk;

        cout << "Masukkan nilai B. Indonesia: ";
        cin >> s[x].Nilai.BIn;

        cout << "Masukkan nilai B. Inggris: ";
        cin >> s[x].Nilai.Big;

        cout << "Masukkan nilai IPA: ";
        cin >> s[x].Nilai.IPA;
    }
}



//Menyimpan data
void tambahDataSiswa(int jumlah, siswa s[]) {
    ofstream file("Data_siswa.txt", ios::app);
    if (!file) {
        cout << "Gagal membuka file untuk menulis data!" << endl;
        return;
    }

    for (int x = 0; x < jumlah; x++) {
        file << "Nama : " << s[x].nama << endl;
        file << "NISN " << s[x].NISN << endl;
        file << "Umur : " << s[x].umur << endl;
        file << "Jurusan : " << s[x].jurusan << endl;
        file << "Tanggal Lahhir : " << s[x].lahir.hari << " " << s[x].lahir.bulan << " " << s[x].lahir.tahun << endl;

        file << endl;
        file << "---NILAI UJIAN---" << endl;
        file << "Nilai UAS : " << s[x].us.uas << endl;
        file << "Nilai UTS : " << s[x].us.uts << endl;
        file << "Nilai Tugas : " << s[x].us.tugas << endl;

        file << endl;
        file << "--NILAI MAPEL--" << endl;
        file << "Nilai MTK : " << s[x].Nilai.Mtk << endl;
        file << "Nilai Bahasa Indonesia : " << s[x].Nilai.BIn << endl;
        file << "Nilai Bahasa Inggris : " << s[x].Nilai.Big << endl;
        file << "Nilai IPA : " << s[x].Nilai.IPA << endl;
        file << endl;

        file << "-Nilai Akhir-" << endl;
        file << "Nilai Akhir Ujian : " << nilaiAkhirUjian(s[x].us) << endl;
        file << "Nilai Akhir Mapel : " << nilaiAkhirMapel(s[x].Nilai) << endl;
        file << "Total Nilai Akhir : " << totalNilaiAkhir(s[x].Nilai) << endl;
        file << "------------------------------" << endl;
    }

    file.close();
    cout << "Data siswa berhasil disimpan ke file 'Data_siswa.txt'!" << endl;
}

void cariSiswa(const string &nisn) {
    ifstream file("Data_siswa.txt");
    if (!file.is_open()) {
        cout << "File 'Data_siswa.txt' tidak dapat dibuka atau tidak ada.\n";
        return;
    }

    bool ketemu = false;
    string line;
    string prev_line = "";

    while (getline(file, line)) {

        if (line.size() >= 5 && line.substr(0, 5) == "NISN ") {
            string file_nisn = line.substr(5);
            if (file_nisn == nisn) {
                ketemu = true;
                cout << "Data siswa ditemukan: " << endl;
                if (!prev_line.empty()) cout << prev_line << endl;
                cout << line << endl;

                while (getline(file, line)) {
                    if (line == "------------------------------") break;
                    cout << line << endl;
                }
                cout << "------------------------------" << endl;
                break;
            }
        }
        prev_line = line;
    }

    if (!ketemu) {
        cout << "Data siswa dengan NISN " << nisn << " tidak ditemukan." << endl;
    }

    file.close();
}

//Menampilkan hasil
void hasil(int jumlah, siswa s[]) {
    for (int x = 0; x < jumlah; x++) {
        cout << "DATA SISWA" << (x + 1) << endl;
        cout << "Nama : " << s[x].nama << endl;
        cout << "NISN : " << s[x].NISN << endl;
        cout << "Umur : " << s[x].umur << endl;
        cout << "Jurusan : " << s[x].jurusan << endl;
        cout << "Tanggal Lahir : " << s[x].lahir.hari << "-" << s[x].lahir.bulan << "-" << s[x].lahir.tahun << endl;
        cout << endl;
        
        cout << "--NILAI UMUM--" << endl;
        cout << "Nilai UAS : " << s[x].us.uas << endl;
        cout << "Nilai UTS : " << s[x].us.uts << endl;
        cout << "Nilai TUGAS : " << s[x].us.tugas << endl;

        cout << endl;
        cout << "--NILAI PELAJARAN--" << endl;
        cout << "Matematika : " << s[x].Nilai.Mtk << endl;
        cout << "B. Indonesia : " << s[x].Nilai.BIn << endl;
        cout << "B. Inggris : " << s[x].Nilai.Big << endl;
        cout << "IPA : " << s[x].Nilai.IPA << endl;
        cout << endl;

        float nilaiA = nilaiAkhirUjian(s[x].us);
        cout << "Nilai Akhir Ujian : " << nilaiA << endl;

        float nilaiB = nilaiAkhirMapel(s[x].Nilai);
        cout << "Nilai Akhir Mapel : " << nilaiB << endl;

        cout << "------------------------------" << endl;
    }
}

//Memproses rangking siswa
void tampilRangking(int jumlah, siswa s[]) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (nilaiAkhirMapel(s[j].Nilai) < nilaiAkhirMapel(s[j + 1].Nilai)) {
                siswa temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    cout << "URUTAN RANGKING SISWA" << endl;

    for (int i = 0; i < jumlah; i++) {
        cout << "Rangking " << i + 1 << ": " << s[i].nama << " | NISN: " << s[i].NISN << " | Total Nilai Akhir: " << nilaiAkhirMapel(s[i].Nilai) << endl;
    }
    cout << "==============================" << endl;
}

int main() {
    int jumlah;
    cout << "Masukkan Jumlah Siswa Yang akan di Data : ";
    cin >> jumlah;

    siswa s[jumlah];
    input(jumlah, s);

    tambahDataSiswa(jumlah, s);

    cout << endl;
    cout << "==============================" << endl;
    cout << "DATA SISWA BERHASIL DI SIMPAN DI ( Data_siswa.txt)" << endl;
    cout << "==============================" << endl;
    cout << endl;
    cout << "HASIL INPUT DATA SISWA" << endl;
    cout << endl;

    hasil(jumlah, s);
    tampilRangking(jumlah, s);

    int pilih;
    do {
        cout << endl;
        cout << "===================================" << endl;
        cout << "Apa Yang mau anda lakukan setelah ini?" << endl;
        cout << "(1) Cari data siswa lewat NISN" << endl;
        cout << "(2) Tambah data siswa lagi" << endl;
        cout << "(3) Keluar dari program" << endl;
        cout << "===================================" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> pilih;

        if (pilih == 1) {
            string nisn;
            cout << "Masukkan NISN yang ingin dicari: ";
            cin >> nisn;
            cariSiswa(nisn);

        } else if (pilih == 2) {
            int tambahan;
            cout << "Masukkan jumlah siswa tambahan: ";
            cin >> tambahan;

            siswa sBaru[tambahan];
            input(tambahan, sBaru);
            tambahDataSiswa(tambahan, sBaru);
            hasil(tambahan, sBaru);
            tampilRangking(tambahan, sBaru);

        } else if (pilih == 3) {
            cout << "Terima kasih! Program selesai." << endl;
            break;

        } else {
            cout << "Pilihan tidak valid! Silakan coba lagi." << endl;
        }

    } while (pilih != 3);

    return 0;
}
