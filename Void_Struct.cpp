#include <iostream>
using namespace std;

struct nilai {
    float uts, uas, tugas;
};

struct tanggal {
    int hari, bulan, tahun;
};

struct siswa {
    string nama;
    int umur;
    string jurusan;
    tanggal lahir;
    nilai us;
};

float hitungNilai(nilai n) {
    return (n.uas * 0.40) + (n.uts * 0.35) + (n.tugas * 0.25);
}

void input(int &jumlah, siswa s[]) {
    for (int x = 0; x < jumlah; x++) {
        cout << "------------------------------" << endl;
        cout << " Masukan Data Siswa Ke-" << x + 1 << endl;

        cout << "Masukan Nama Siswa : ";
        cin >> s[x].nama;

        cout << "Masukkan Umur Siswa : ";
        cin >> s[x].umur;

        cout << "Masukkan jurusan Siswa: ";
        cin >> s[x].jurusan;

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
    }
}

void hasil(int jumlah, siswa s[]) {
    
    for (int x = 0; x < jumlah; x++) {
        cout << "DATA SISWA KE-" << (x + 1) << endl;
        cout << "Nama : " << s[x].nama << endl;
        cout << "Umur : " << s[x].umur << endl;
        cout << "Jurusan : " << s[x].jurusan << endl;
        cout << "Tanggal Lahir : " << s[x].lahir.hari << "-" << s[x].lahir.bulan << "-" << s[x].lahir.tahun << endl;

        cout << "--NILAI--" << endl;
        cout << "Nilai UAS : " << s[x].us.uas << endl;
        cout << "Nilai UTS : " << s[x].us.uts << endl;
        cout << "Nilai TUGAS : " << s[x].us.tugas << endl;

        float nilaiAkhir = hitungNilai(s[x].us);
        cout << "NILAI AKHIR (Rata-Rata) : " << nilaiAkhir << endl;

        cout << "------------------------------" << endl;
    }
}

int main() {
    int jumlah;

    cout << "Masukkan Jumlah Siswa Yang akan di Data : ";
    cin >> jumlah;

    siswa s[jumlah];

    input(jumlah, s);

    cout << endl;
    cout << "==============================" << endl;
    cout << endl;

    hasil(jumlah, s);

    return 0;
}
