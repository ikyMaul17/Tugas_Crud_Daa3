// Program CRUD
#include <iostream>
#include <string>
using namespace std;

struct dataMahasiswa
{
    int no;
    string nama;
    string nim;
    string TanggalLahir;
    string mataKuliah;
};

int jumlahMahasiswa = 0;
struct dataMahasiswa mahasiswa[100];

void addNewData(int no)
{
    cin.ignore();
    cout << "Isilah data-data berikut !" << endl;
    cout << "Nama : ";
    getline(cin, mahasiswa[no].nama);
    cout << "NIM  : ";
    getline(cin, mahasiswa[no].nim);
    cout << "Tanggal lahir : ";
    getline(cin, mahasiswa[no].TanggalLahir);
    cout << "Mata Kuliah : ";
    getline(cin, mahasiswa[no].mataKuliah);
}

void create()
{
    addNewData(jumlahMahasiswa);
    mahasiswa[jumlahMahasiswa].no = jumlahMahasiswa + 1;
    jumlahMahasiswa++;
}

void read()
{
    system("cls");
    cout << "Data yang tersimpan" << endl;
    puts("+-------------------------------------------------------+");
    puts("| No  | Nama\t| NIM\t| Tgl Lahir\t| Mata Kuliah\t|");
    puts("+-------------------------------------------------------+");

    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        if (!mahasiswa[i].no)
            continue;
        printf("| %d   | %s\t| %s\t| %s\t| %s\t\t|\n", mahasiswa[i].no, mahasiswa[i].nama.c_str(), mahasiswa[i].nim.c_str(), mahasiswa[i].TanggalLahir.c_str(), mahasiswa[i].mataKuliah.c_str());
    }
    puts("+-------------------------------------------------------+\n");
}

void update()
{
    int no;
    cout << "Perbarui data" << endl;
    cout << "Masukkan no mahasiswa : ";
    cin >> no;
    addNewData(no - 1);
}

void ddelete()
{
    int no;
    cout << "Hapus data" << endl;
    cout << "Masukkan no mahasiswa yang ingin dihapus : ";
    cin >> no;
    no--;
    mahasiswa[no].no = 0;
    mahasiswa[no].nama = "";
    mahasiswa[no].nim = "";
    mahasiswa[no].TanggalLahir = "";
    mahasiswa[no].mataKuliah = "";
}

int main()
{
    system("cls");
    while (true)
    {
        int operasi;
        cout << "+==================================+" << endl;
        cout << "| CRUD DENGAN STRUKTUR DATA STATIS |" << endl;
        cout << "+==================================+" << endl;
        cout << "1. Tambahkan data baru (Create)" << endl;
        cout << "2. Tampilkan data (Read)" << endl;
        cout << "3. Perbarui data (Update)" << endl;
        cout << "4. Hapus data (Delete)" << endl;
        cout << "5. Keluar Program" << endl;
        cout << "Pilih operasi yang ingin anda lakukan!" << endl;
        cin >> operasi;

        if (operasi == 1)
        {
            create();
        }
        else if (operasi == 2)
        {
            read();
        }
        else if (operasi == 3)
        {
            update();
        }
        else if (operasi == 4)
        {
            ddelete();
        }
        else if (operasi == 5)
        {
            cout << "Selesai..." << endl;
            goto end;
        }
        else
        {
            cout << "Opsi yang anda pilih tidak ada";
        }
    }
end:
    return 0;
}