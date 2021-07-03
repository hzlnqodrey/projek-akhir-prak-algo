#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>

using namespace std;

//--- global filename
string filename;

/* DEKLARASI VAR FILE */
ofstream ofs;
ifstream ifs;
//-------------------

// data struct

struct dataDrone
{
    char id_drone[100], nama_drone[100];
    char id_peminjam[100], nama_peminjam[100];
    int waktu_sewa, id_sewa;
    int harga_sewa_per_jam = 50000;
    double total_harga_sewa;
    // var pembantu
    int banyak_data;
};

// global struct variabel
dataDrone Temp[1000];

/* PROTOTYPE FUNGSI */

// ----- Fungsi Menu

void DroneASCII();
void MenuInputData(dataDrone Drone[1000], dataDrone jmlData);
void MenuTampilData();

// Searching Menu
void MenuSearchingData();

// Sequential
void MenuSequentialSearch();
void IDSequentialSearch();
void NamaSequentialSearch();
// Binary
void MenuBinarySearch();
void IDBinarySearch();
void NamaBinarySearch();

// Sorting Menu
void MenuSortingData();

// Bubble Sort
void MenuBubbleSort();
void IDSewaBubbleSort();
void IDBubbleSort();
void NamaBubbleSort();
// Selection
void MenuSelectionSort();
void IDSewaSelectionSort();
void IDSelectionSort();
void NamaSelectionSort();
// Insertion
void MenuInsertionSort();
void IDSewaInsertionSort();
void IDInsertionSort();
void NamaInsertionSort();
// Shell
void MenuShellSort();
void IDSewaShellSort();
void IDShellSort();
void NamaShellSort();
// Quick
void MenuQuickSort();
void IDSewaQuickSort();
void IDQuickSort();
void NamaQuickSort();
// Merge
void MenuMergeSort();
void IDSewaMergeSort();
void IDMergeSort();
void NamaMergeSort();

// Transaksi Menu
void MenuTransaksi();

// Merging Sambung
void MenuMergingSambung();
// Updating
void MenuUpdating();

// -------------------------------------------------------------------

// ------ Fungsi Pembantu
// [1] - fungsi replace spasi
string replacespasi(string str)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == ' ')
        {
            str.replace(i, 1, 1, '_');
        }
    }
    return str;
}

// [2] - fungsi replace underscore
string replaceunderscore(string str)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '_')
        {
            str.replace(i, 1, 1, ' ');
        }
    }
    return str;
}

// [3] - fungsi ifstream, data file ditimpa dengan var struct temp
int ifstream_fungsi()
{
    int dataCount = 0;
    ifs.open(filename);
    if (ifs.is_open())
    {
        while (!ifs.eof())
        {
            ifs >> Temp[dataCount].id_sewa >> Temp[dataCount].id_drone >> Temp[dataCount].nama_drone >> Temp[dataCount].id_peminjam >> Temp[dataCount].nama_peminjam >> Temp[dataCount].waktu_sewa >> Temp[dataCount].harga_sewa_per_jam >> Temp[dataCount].total_harga_sewa;
            dataCount++;
        }
        dataCount -= 1;
        ifs.close();
    }
    else
    {
        cout << "File tidak ada atau gagal dibuka" << endl;
        return 0;
    }

    return dataCount;
}

int ambil_file(int dataCount)
{
    ifs.open(filename);
    if (ifs.is_open())
    {
        while (!ifs.eof())
        {
            ifs >> Temp[dataCount].id_sewa >> Temp[dataCount].id_drone >> Temp[dataCount].nama_drone >> Temp[dataCount].id_peminjam >> Temp[dataCount].nama_peminjam >> Temp[dataCount].waktu_sewa >> Temp[dataCount].harga_sewa_per_jam >> Temp[dataCount].total_harga_sewa;
            dataCount++;
        }
        dataCount -= 1;
        ifs.close();
    }
    else
    {
        cout << "File tidak ada atau gagal dibuka" << endl;
        return 0;
    }

    return dataCount;
}

// [4] - fungsi tabel, menampilkan tabel hasil dari tampilData, searching, dan sorting
void tabel_output(int dataCount, int i)
{

    /* TEMPLATE TABEL, PENGATURAN ALIGNMENT DENGAN IOMANIP DISINI */
    // tampilkan data terformat table
    cout << "\n\n\n+" << setfill('=') << setw(148) << "+\n";
    cout << "|" << left << setfill(' ') << setw(9) << " ID Sewa "
         << "|"
         << setw(8) << " ID Drone "
         << "|"
         << setw(20) << " Nama Drone "
         << "|"
         << setw(20) << " ID Peminjam "
         << "|"
         << setw(30) << " Nama Peminjam "
         << "|"
         << setw(10) << " Waktu Sewa "
         << "|"
         << setw(8) << " Harga Sewa Per Jam "
         << "|"
         << right << setw(15) << setprecision(12) << " Total Harga Sewa "
         << "|" << endl;
    cout << "+" << setfill('=') << setw(148) << "+\n";

    for (; i < dataCount; i++)
    {
        cout << "| " << left << setfill(' ') << setw(8) << Temp[i].id_sewa << "| "
             << setw(9) << replaceunderscore(Temp[i].id_drone) << "| "
             << setw(19) << replaceunderscore(Temp[i].nama_drone) << "| "
             << setw(19) << replaceunderscore(Temp[i].id_peminjam) << "| "
             << setw(29) << replaceunderscore(Temp[i].nama_peminjam) << "| "
             << setw(11) << Temp[i].waktu_sewa << "| "
             << setw(19) << Temp[i].harga_sewa_per_jam << "| "
             << right << setw(16) << setprecision(12) << Temp[i].total_harga_sewa << " |" << endl;
    }
    cout << "+" << setfill('=') << setw(148) << "+\n";
}

// [5] - fungsi quick sort

//(1) - Quick sort untuk ID Sewa
void quickSortIDSewa(int first, int last)
{
    dataDrone temporary_swap;
    dataDrone list_separator;
    int low, high;
    low = first;
    high = last - 1;
    list_separator = Temp[(first + last) / 2];
    do
    {
        while (Temp[low].id_sewa < list_separator.id_sewa)
            low++;
        while (Temp[high].id_sewa > list_separator.id_sewa)
            high--;
        if (low <= high)
        {
            temporary_swap = Temp[low];
            Temp[low++] = Temp[high];
            Temp[high--] = temporary_swap;
        }
    } while (low <= high);
    if (first < high)
        quickSortIDSewa(first, high);
    if (low < last)
        quickSortIDSewa(low, last);
}

// (2) - Quick sort untuk ID Peminjam
void quickSortIDPeminjam(int first, int last)
{
    dataDrone temporary_swap;
    dataDrone list_separator;
    int low, high;
    low = first;
    high = last - 1;
    list_separator = Temp[(first + last) / 2];
    do
    {
        while (strcmp(Temp[low].id_peminjam, list_separator.id_peminjam) < 0)
            low++;
        while (strcmp(Temp[high].id_peminjam, list_separator.id_peminjam) > 0)
            high--;
        if (low <= high)
        {
            temporary_swap = Temp[low];
            Temp[low++] = Temp[high];
            Temp[high--] = temporary_swap;
        }
    } while (low <= high);
    if (first < high)
        quickSortIDPeminjam(first, high);
    if (low < last)
        quickSortIDPeminjam(low, last);
}

// (3) - Quick sort untuk Nama Peminjam
void quickSortNamaPeminjam(int first, int last)
{
    dataDrone temporary_swap;
    dataDrone list_separator;
    int low, high;
    low = first;
    high = last - 1;
    list_separator = Temp[(first + last) / 2];
    do
    {
        while (strcmp(Temp[low].nama_peminjam, list_separator.nama_peminjam) < 0)
            low++;
        while (strcmp(Temp[high].nama_peminjam, list_separator.nama_peminjam) > 0)
            high--;
        if (low <= high)
        {
            temporary_swap = Temp[low];
            Temp[low++] = Temp[high];
            Temp[high--] = temporary_swap;
        }
    } while (low <= high);
    if (first < high)
        quickSortNamaPeminjam(first, high);
    if (low < last)
        quickSortNamaPeminjam(low, last);
}

// [6] - fungsi Merge Sort

// (1) - fungsi merge untuk ID Sewa
void mergeIDSewa(int start, int mid, int end)
{
    // create a temp array
    dataDrone temporary_swap[100];

    // crawlers for both intervals and for temp
    int i = start, j = mid + 1, k = 0;

    // traverse both arrays and in each iteration add smaller of both elements in temp
    while (i <= mid && j <= end)
    {
        if (Temp[i].id_sewa <= Temp[j].id_sewa)
        {
            temporary_swap[k] = Temp[i];
            k += 1;
            i += 1;
        }
        else
        {
            temporary_swap[k] = Temp[j];
            k += 1;
            j += 1;
        }
    }

    // add elements left in the first interval
    while (i <= mid)
    {
        temporary_swap[k] = Temp[i];
        k += 1;
        i += 1;
    }

    // add elements left in the second interval
    while (j <= end)
    {
        temporary_swap[k] = Temp[j];
        k += 1;
        j += 1;
    }

    // copy temp to original interval
    for (i = start; i <= end; i += 1)
    {
        Temp[i] = temporary_swap[i - start];
    }
}

void mergeSortIDSewa(int start, int end)
{

    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSortIDSewa(start, mid);
        mergeSortIDSewa(mid + 1, end);
        mergeIDSewa(start, mid, end);
    }
}

// (2) - fungsi merge untuk ID Peminjam
void mergeIDPeminjam(int start, int mid, int end)
{
    // create a temp array
    dataDrone temporary_swap[100];

    // crawlers for both intervals and for temp
    int i = start, j = mid + 1, k = 0;

    // traverse both arrays and in each iteration add smaller of both elements in temp
    while (i <= mid && j <= end)
    {
        if (strcmp(Temp[i].id_peminjam, Temp[j].id_peminjam) > 0)
        {
            temporary_swap[k] = Temp[i];
            k += 1;
            i += 1;
        }
        else
        {
            temporary_swap[k] = Temp[j];
            k += 1;
            j += 1;
        }
    }

    // add elements left in the first interval
    while (i <= mid)
    {
        temporary_swap[k] = Temp[i];
        k += 1;
        i += 1;
    }

    // add elements left in the second interval
    while (j <= end)
    {
        temporary_swap[k] = Temp[j];
        k += 1;
        j += 1;
    }

    // copy temp to original interval
    for (i = start; i <= end; i += 1)
    {
        Temp[i] = temporary_swap[i - start];
    }
}

void mergeSortIDPeminjam(int start, int end)
{

    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSortIDPeminjam(start, mid);
        mergeSortIDPeminjam(mid + 1, end);
        mergeIDPeminjam(start, mid, end);
    }
}

// (3) - fungsi merge untuk Nama Peminjam
void mergeNamaPeminjam(int start, int mid, int end)
{
    // create a temp array
    dataDrone temporary_swap[100];

    // crawlers for both intervals and for temp
    int i = start, j = mid + 1, k = 0;

    // traverse both arrays and in each iteration add smaller of both elements in temp
    while (i <= mid && j <= end)
    {
        if (strcmp(Temp[i].nama_peminjam, Temp[j].nama_peminjam) > 0)
        {
            temporary_swap[k] = Temp[i];
            k += 1;
            i += 1;
        }
        else
        {
            temporary_swap[k] = Temp[j];
            k += 1;
            j += 1;
        }
    }

    // add elements left in the first interval
    while (i <= mid)
    {
        temporary_swap[k] = Temp[i];
        k += 1;
        i += 1;
    }

    // add elements left in the second interval
    while (j <= end)
    {
        temporary_swap[k] = Temp[j];
        k += 1;
        j += 1;
    }

    // copy temp to original interval
    for (i = start; i <= end; i += 1)
    {
        Temp[i] = temporary_swap[i - start];
    }
}

void mergeSortNamaPeminjam(int start, int end)
{

    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSortNamaPeminjam(start, mid);
        mergeSortNamaPeminjam(mid + 1, end);
        mergeNamaPeminjam(start, mid, end);
    }
}

//-------------------------

int main()
{

    // DEKLARASI STRUCT
    // data yang dimasukkan ke ofstream
    dataDrone Drone[1000];
    // jumlah data
    dataDrone jmlData;
    // data temp yang dimasukkan ke ifstream

    /* DEKLARASI VAR PEMBANTU DI MENU UTAMA */
    int pilih;
    char pilih_main_menu;

    DroneASCII();
    system("CLS");

    cout << setfill(' ') << setw(26) << " "
         << "\n";
    cout << setfill(' ') << setw(15) << " "
         << "===== KELOMPOK 26 ====="
         << "\n";
    cout << setfill(' ') << setw(6) << " "
         << "1. Hazlan Muhammad Qodri [123190080]"
         << "\n";

    cout << "\n\n";
    cout << setfill('=') << setw(31) << "\n";
    cout << " TUGAS PROJECT PRAK ALGO 2021" << endl;
    cout << setfill('=') << setw(26) << "\n";
    cout << setfill(' ') << setw(8) << " " << right << "1. INPUT DATA"
         << "\n";
    cout << setfill(' ') << setw(8) << " " << right << "2. TAMPILKAN DATA"
         << "\n";
    cout << setfill(' ') << setw(8) << " " << right << "3. SEARCHING DATA"
         << "\n";
    cout << setfill(' ') << setw(8) << " " << right << "4. SORTING DATA"
         << "\n";
    cout << setfill(' ') << setw(8) << " " << right << "5. TRANSAKSI"
         << "\n";
    cout << setfill(' ') << setw(8) << " " << right << "6. KELUAR"
         << "\n";
    cout << setfill('=') << setw(31) << "\n";
    cout << setfill('=') << setw(31) << "\n";

    cout << "Masukkan Pilihan        = ";
    cin >> pilih;
    cin.ignore();

    switch (pilih)
    {
    case 1:
        MenuInputData(Drone, jmlData);
        break;
    case 2:
        MenuTampilData();
        break;
    case 3:
        cout << "\nNama File            = ";
        cin >> filename;

        MenuSearchingData();

        break;
        // UNTUK BINARY SEARCH HARUS DIURUTKAN TERLEBIH DAHULU

    case 4:
        cout << "\nNama File            = ";
        cin >> filename;

        MenuSortingData();

        break;
    case 5:
        MenuTransaksi();
        break;
    case 6:
        cout << "\nSelamat Tinggal\n";
        system("pause");
        exit(1);
        break;
    default:
        cout << "\n\nTolong Inputkan dengan benar" << endl;
        break;
    }

    cout << "\n\nKembali Ke Menu Utama ?" << endl;
    cout << "\nY = KEMBALI ";
    cout << "\nN = KELUAR ";
    cout << "\n\nMasukkan Pilihan       = ";
    cin >> pilih_main_menu;

    if (pilih_main_menu == 'Y' || pilih_main_menu == 'y')
    {
        system("CLS");
        main();
    }
    return 0;
}

void DroneASCII()
{
    /* MENU UTAMA */
    cout << "         88                                                 " << endl;
    cout << "         88                                                 " << endl;
    cout << "         88                                                 " << endl;
    cout << " ,adPPYb,88 8b,dPPYba,  ,adPPYba,  8b,dPPYba,   ,adPPYba,   " << endl;
    cout << "a8'    `Y88 88P'   'Y8 a8'     '8a 88P'   `'8a a8P_____88   " << endl;
    cout << "8b       88 88         8b       d8 88       88 8PP'''''''   " << endl;
    cout << "'8a,   ,d88 88         '8a,   ,a8' 88       88 '8b,   ,aa   " << endl;
    cout << " `'8bbdP'Y8 88          `'YbbdP''  88       88  `'Ybbd8''   " << endl;
    cout << "\n\n\n";
    cout << "Sewa Drone" << endl;
    cout << "==========" << endl;
    cout << "1 Jam = Rp50.000" << endl;
    cout << "\n\n\n";

    system("pause");
}

void MenuInputData(dataDrone Drone[1000], dataDrone jmlData)
{
    system("CLS");

    char pilih;

    cout << "        Tabel Penyewaan Drone           " << endl;
    // tampilkan data terformat table
    cout << "+" << setfill('=') << setw(38) << "+\n";
    cout << "|" << left << setfill(' ') << setw(15) << " ID"
         << "|"
         << right << setw(20) << "NAMA DRONE "
         << "|" << endl;
    cout << "+" << setfill('=') << setw(38) << "+\n";
    cout << "|" << left << setfill(' ') << setw(15) << " DELDR"
         << "|"
         << right << setprecision(9) << setw(20) << "Delivery Drone "
         << "|" << endl;
    cout << "|" << left << setfill(' ') << setw(15) << " PHODR"
         << "|"
         << right << setprecision(9) << setw(20) << "Photography Drone "
         << "|" << endl;
    cout << "|" << left << setfill(' ') << setw(15) << " RACDR"
         << "|"
         << right << setprecision(9) << setw(20) << "Racing Drone "
         << "|" << endl;
    cout << "+" << setfill('=') << setw(38) << "+\n";

    cout << "\n";
    cout << "1 Jam = Rp50.000" << endl;
    cout << "\n=KETENTUAN=" << endl;
    cout << "1. Silahkan Memasukkan id dan nama drone yang telah tersedia" << endl;
    cout << "2. Pastikan mengembalikan barang yang dipinjam tepat waktu" << endl;
    cout << "3. Barang rusak saat pemakaian bukan tanggung jawab kami" << endl;
    cout << "4. Gunakan drone dengan baik dan sopan" << endl;

    cout << "\n\n\n";
    cout << setfill('=') << setw(24) << "\n";
    cout << " INPUT DATA SEWA DRONE " << endl;
    cout << setfill('=') << setw(24) << "\n";
    cout << "Masukkan nama file    = ";
    cin >> filename;
    //------------------------------------------

    // INPUT NAMA FILE DENGAN BERTIPE FILE -- DIBAWAH SINI
    ofs.open(filename, ios::app | ios::out);

    // BANYAKNYA DATA - TIPE STRUCT ARRAY -- DIBAWAH SINI
    cout << "\nMasukkan Banyaknya Data = ";
    cin >> jmlData.banyak_data;
    cin.ignore();

    // ISI FIELD MASING2 -- DIBAWAH SINI
    // Input Data memakai perulangan sampai batas ke-jmlData.banyak_data
    for (size_t i = 0; i < jmlData.banyak_data; i++)
    {
        cout << "\n\nData ke " << i + 1 << endl;
        cout << setw(28) << setfill('-') << "\n";

        // ID Sewa
        cout << "ID Sewa                     : ";
        cin >> Drone[i].id_sewa;
        cin.ignore();

        // Input ID Drone
        cout << "ID Drone                    : ";
        cin >> Drone[i].id_drone;
        cin.ignore(5, '\n');

        // Input Nama Drone
        cout << "Nama Drone                  : ";
        cin.get(Drone[i].nama_drone, 100);
        cin.ignore();

        // Input ID Peminjam
        cout << "ID Peminjam (KTP/SIM)       : ";
        cin.get(Drone[i].id_peminjam, 100);
        cin.ignore();

        // Input Nama Peminjam
        cout << "Nama Peminjam               : ";
        cin.get(Drone[i].nama_peminjam, 100);
        cin.ignore();

        // Input Waktu Lama Sewa
        cout << "Lama Waktu Sewa (dalam JAM) : ";
        cin >> Drone[i].waktu_sewa;
        cin.ignore();

        // Kalkulasi Total Harga Sewa = Waktu Sewa x Harga Sewa Per Jam
        Drone[i].total_harga_sewa = 0;
        Drone[i].total_harga_sewa += (Drone[i].waktu_sewa * Drone[i].harga_sewa_per_jam);
    }

    // fungsi replace SPASI untuk variabel yg bertipe char, untuk keperluan i/o file
    for (int i = 0; i < jmlData.banyak_data; i++)
    {
        string str1 = Drone[i].id_drone;
        string str2 = Drone[i].nama_drone;
        string str3 = Drone[i].id_peminjam;
        string str4 = Drone[i].nama_peminjam;

        strcpy(Drone[i].id_drone, replacespasi(str1).c_str());
        strcpy(Drone[i].nama_drone, replacespasi(str2).c_str());
        strcpy(Drone[i].id_peminjam, replacespasi(str3).c_str());
        strcpy(Drone[i].nama_peminjam, replacespasi(str4).c_str());
    }

    // masukkan data ke file
    if (ofs.is_open())
    {
        // data terformat
        for (int i = 0; i < jmlData.banyak_data; i++)
        {
            ofs << setw(8) << Drone[i].id_sewa
                << setw(8) << Drone[i].id_drone
                << setw(30) << Drone[i].nama_drone
                << setw(20) << Drone[i].id_peminjam
                << setw(50) << Drone[i].nama_peminjam
                << setw(8) << Drone[i].waktu_sewa
                << setw(8) << Drone[i].harga_sewa_per_jam
                << setw(20) << Drone[i].total_harga_sewa << endl;
        }
        ofs.close();
    }
    else
    {
        cout << "File tidak ada atau gagal dibuka" << endl;
    }
    // ------------------------------------------

    cout << "\n\nKembali Ke Menu Utama ?" << endl;
    cout << "\nY = KEMBALI ";
    cout << "\nN = KELUAR ";
    cout << "\n\nMasukkan Pilihan       = ";
    cin >> pilih;

    if (pilih == 'Y' || pilih == 'y')
    {
        system("CLS");
        main();
    }
}

void MenuTampilData()
{
    system("CLS");

    char pilih;

    cout << setfill('=') << setw(25) << "\n";
    cout << " OUTPUT DATA SEWA DRONE " << endl;
    cout << setfill('=') << setw(25) << "\n";
    cout << "Nama File              = ";
    cin >> filename;

    int dataCount = ifstream_fungsi();

    if (dataCount != 0)
    {
        tabel_output(dataCount, 0);
    }

    cout << "\n\nKembali Ke Menu Utama ?" << endl;
    cout << "\nY = KEMBALI ";
    cout << "\nN = KELUAR ";
    cout << "\n\nMasukkan Pilihan       = ";
    cin >> pilih;

    if (pilih == 'Y' || pilih == 'y')
    {
        system("CLS");
        main();
    }
}

void MenuSearchingData()
{
    system("CLS");

    int pilih;

    cout << setfill('=') << setw(23) << "\n";
    cout << " CARI DATA SEWA DRONE " << endl;
    cout << setfill('=') << setw(23) << "\n";
    cout << setfill(' ') << setw(5) << " " << right << "1. Sequential"
         << "\n";
    cout << setfill(' ') << setw(5) << " " << right << "2. Binary"
         << "\n";
    cout << setfill('=') << setw(23) << "\n";
    cout << "Masukkan Pilihan     = ";
    cin >> pilih;
    cin.ignore();

    switch (pilih)
    {
    case 1:
        MenuSequentialSearch();
        break;
    case 2:
        MenuBinarySearch();
        break;

    default:
        cout << "\n\nTolong Inputkan dengan benar" << endl;
        break;
    }
}

void MenuSequentialSearch()
{
    system("CLS");

    int pilih;
    char pilih_seq_menu, pilih_search_menu, pilih_main_menu;

    cout << setfill('=') << setw(30) << "\n";
    cout << " PENCARIAN DENGAN SEQUENTIAL " << endl;
    cout << setfill('=') << setw(30) << "\n";
    cout << setfill(' ') << setw(5) << " " << right << "1. ID Peminjam (KTP/SIM)"
         << "\n";
    cout << setfill(' ') << setw(5) << " " << right << "2. Nama Peminjam"
         << "\n";
    cout << setfill('=') << setw(30) << "\n";
    cout << "Masukkan Pilihan            = ";
    cin >> pilih;
    cin.ignore();

    switch (pilih)
    {
    case 1:
        IDSequentialSearch();
        break;
    case 2:
        NamaSequentialSearch();
        break;
    default:
        cout << "\n\nTolong Inputkan dengan benar" << endl;
        break;
    }

    cout << "\n\nKembali Ke Sequential Search ?" << endl;
    cout << "\nY = KEMBALI ";
    cout << "\nN = KELUAR ";
    cout << "\n\nMasukkan Pilihan       = ";
    cin >> pilih_seq_menu;

    if (pilih_seq_menu == 'Y' || pilih_seq_menu == 'y')
    {
        MenuSequentialSearch();
    }
    else
    {
        cout << "\n\nKembali Ke Menu Searching  ?" << endl;
        cout << "\nY = KEMBALI ";
        cout << "\nN = KELUAR ";
        cout << "\n\nMasukkan Pilihan       = ";
        cin >> pilih_search_menu;

        if (pilih_search_menu == 'Y' || pilih_search_menu == 'y')
        {
            MenuSearchingData();
        }
        else
        {
            cout << "\n\nKembali Ke Menu Utama ?" << endl;
            cout << "\nY = KEMBALI ";
            cout << "\nN = KELUAR ";
            cout << "\n\nMasukkan Pilihan       = ";
            cin >> pilih_main_menu;

            if (pilih_main_menu == 'Y' || pilih_main_menu == 'y')
            {
                system("CLS");
                main();
            }
        }
    }
}

void IDSequentialSearch()
{
    // tanpa cls

    string cari;
    int k = 0;
    bool ketemu = false;

    int dataCount = ifstream_fungsi();

    if (dataCount != 0)
    {
        cout << "Masukkan ID Peminjam yang akan dicari      = ";
        getline(cin, cari);

        while ((k < dataCount) && (!ketemu))
        {
            if (Temp[k].id_peminjam == cari)
            {
                ketemu = true;
            }
            else
            {
                k++;
            }
        }

        // HASIL PENCAHARIAN DI BAWAH INI
        if (ketemu)
        {
            tabel_output(k + 1, k);
        }
        else
        {
            cout << "\n\nTidak bisa menemukan data yang dicari\n"
                 << endl;
        }
    }
}

void NamaSequentialSearch()
{
    // tanpa cls
    char cari[100];
    int k = 0;
    bool ketemu = false;

    int dataCount = ifstream_fungsi();

    if (dataCount != 0)
    {
        cout << "Masukkan Nama Peminjam yang akan dicari      = ";
        cin.get(cari, 100);
        cin.ignore();

        while ((k < dataCount) && (!ketemu))
        {
            if (replaceunderscore(Temp[k].nama_peminjam) == cari)
            {
                ketemu = true;
            }
            else
            {
                k++;
            }
        }

        // HASIL PENCAHARIAN DI BAWAH INI
        if (ketemu)
        {
            tabel_output(k + 1, k);
        }
        else
        {
            cout << "\n\nTidak bisa menemukan data yang dicari\n"
                 << endl;
        }
    }
}

void MenuBinarySearch()
{
    system("CLS");

    int pilih;
    char pilih_seq_menu, pilih_search_menu, pilih_main_menu;

    cout << setfill('=') << setw(26) << "\n";
    cout << " PENCARIAN DENGAN BINARY " << endl;
    cout << setfill('=') << setw(26) << "\n";
    cout << setfill(' ') << setw(1) << " " << right << "1. ID Peminjam (KTP/SIM)"
         << "\n";
    cout << setfill(' ') << setw(1) << " " << right << "2. Nama Peminjam"
         << "\n";
    cout << setfill('=') << setw(26) << "\n";
    cout << "Masukkan Pilihan        = ";
    cin >> pilih;
    cin.ignore();

    switch (pilih)
    {
    case 1:
        IDBinarySearch();
        break;
    case 2:
        NamaBinarySearch();
        break;
    default:
        cout << "\n\nTolong Inputkan dengan benar" << endl;
        break;
    }

    cout << "\n\nKembali Ke Binary Search ?" << endl;
    cout << "\nY = KEMBALI ";
    cout << "\nN = KELUAR ";
    cout << "\n\nMasukkan Pilihan       = ";
    cin >> pilih_seq_menu;

    if (pilih_seq_menu == 'Y' || pilih_seq_menu == 'y')
    {
        MenuBinarySearch();
    }
    else
    {
        cout << "\n\nKembali Ke Menu Searching  ?" << endl;
        cout << "\nY = KEMBALI ";
        cout << "\nN = KELUAR ";
        cout << "\n\nMasukkan Pilihan       = ";
        cin >> pilih_search_menu;

        if (pilih_search_menu == 'Y' || pilih_search_menu == 'y')
        {
            MenuSearchingData();
        }
        else
        {
            cout << "\n\nKembali Ke Menu Utama ?" << endl;
            cout << "\nY = KEMBALI ";
            cout << "\nN = KELUAR ";
            cout << "\n\nMasukkan Pilihan       = ";
            cin >> pilih_main_menu;

            if (pilih_main_menu == 'Y' || pilih_main_menu == 'y')
            {
                system("CLS");
                main();
            }
        }
    }
}

void IDBinarySearch()
{
    // tanpa cls

    int dataCount = ifstream_fungsi();

    // Variabel
    if (dataCount != 0)
    {
        // sorting
        for (int i = 0; i < dataCount - 1; i++)
        {
            for (int j = 0; j < dataCount - 1 - i; j++)
            {
                if (strcmp(Temp[j].id_peminjam, Temp[j + 1].id_peminjam) > 0)
                {
                    dataDrone temporary_swap = Temp[j];
                    Temp[j] = Temp[j + 1];
                    Temp[j + 1] = temporary_swap;
                }
            }
        }

        string cari;
        int awal = 0;
        int akhir = dataCount;
        int tengah;
        bool ketemu = false;

        cout << "Masukkan ID Peminjam yang akan dicari      = ";
        getline(cin, cari);

        while ((awal <= akhir) && (!ketemu))
        {
            tengah = ((awal + akhir) / 2);

            if (Temp[tengah].id_peminjam == cari)
            {
                ketemu = true;
            }
            else
            {
                if (cari < Temp[tengah].id_peminjam)
                {
                    akhir = tengah - 1; // awal tetap
                }
                else if (cari > Temp[tengah].id_peminjam)
                {
                    awal = tengah + 1; // n atau batas index tetap;
                }
            }
        }

        // HASIL PENCAHARIAN DI BAWAH INI
        if (ketemu)
        {
            tabel_output(tengah + 1, tengah);
        }
        else
        {
            cout << "\n\nTidak bisa menemukan data yang dicari\n"
                 << endl;
        }
    }
}

void NamaBinarySearch()
{
    // tanpa cls

    int dataCount = ifstream_fungsi();

    if (dataCount != 0)
    {
        // sorting
        for (int i = 0; i < dataCount - 1; i++)
        {
            for (int j = 0; j < dataCount - 1 - i; j++)
            {
                if (strcmp(Temp[j].nama_peminjam, Temp[j + 1].nama_peminjam) > 0)
                {
                    dataDrone temporary_swap = Temp[j];
                    Temp[j] = Temp[j + 1];
                    Temp[j + 1] = temporary_swap;
                }
            }
        }
        // Variabel
        string cari;
        int awal = 0;
        int akhir = dataCount;
        int tengah;
        bool ketemu = false;

        cout << "Masukkan Nama Peminjam yang akan dicari      = ";
        getline(cin, cari);

        while ((awal <= akhir) && (!ketemu))
        {
            tengah = ((awal + akhir) / 2);

            if (replaceunderscore(Temp[tengah].nama_peminjam) == cari)
            {
                ketemu = true;
            }
            else
            {
                if (cari < replaceunderscore(Temp[tengah].nama_peminjam))
                {
                    akhir = tengah - 1; // awal tetap
                }
                else if (cari > replaceunderscore(Temp[tengah].nama_peminjam))
                {
                    awal = tengah + 1; // n atau batas index tetap;
                }
            }
        }

        // HASIL PENCAHARIAN DI BAWAH INI
        if (ketemu)
        {
            tabel_output(tengah + 1, tengah);
        }
        else
        {
            cout << "\n\nTidak bisa menemukan file yang dicari\n"
                 << endl;
        }
    }
}

void MenuSortingData()
{
    system("CLS");

    int pilih;

    cout << setfill('=') << setw(29) << "\n";
    cout << " PENGURUTAN DATA SEWA DRONE " << endl;
    cout << setfill('=') << setw(29) << "\n";
    cout << setfill(' ') << setw(5) << " " << right << "1. Bubble Sort"
         << "\n";
    cout << setfill(' ') << setw(5) << " " << right << "2. Selection Sort"
         << "\n";
    cout << setfill(' ') << setw(5) << " " << right << "3. Insertion Sort"
         << "\n";
    cout << setfill(' ') << setw(5) << " " << right << "4. Shell Sort"
         << "\n";
    cout << setfill(' ') << setw(5) << " " << right << "5. Quick Sort"
         << "\n";
    cout << setfill(' ') << setw(5) << " " << right << "6. Merge Sort"
         << "\n";
    cout << setfill('=') << setw(29) << "\n";
    cout << "Masukkan Pilihan     = ";
    cin >> pilih;
    cin.ignore();

    switch (pilih)
    {
    case 1:
        MenuBubbleSort();
        break;
    case 2:
        MenuSelectionSort();
        break;
    case 3:
        MenuInsertionSort();
        break;
    case 4:
        MenuShellSort();
        break;
    case 5:
        MenuQuickSort();
        break;
    case 6:
        MenuMergeSort();
        break;
    default:
        cout << "\n\nTolong Inputkan dengan benar" << endl;
        break;
    }
}

void MenuBubbleSort()
{
    system("CLS");

    int pilih;
    char pilih_bubble_menu, pilih_sorting_menu, pilih_main_menu;

    cout << setfill('=') << setw(30) << "\n";
    cout << " PENGURUTAN DATA BUBBLE " << endl;
    cout << setfill('=') << setw(30) << "\n";
    cout << setfill(' ') << setw(5) << " " << right << "1. ID Sewa"
         << "\n";
    cout << setfill(' ') << setw(5) << " " << right << "2. ID Peminjam (KTP/SIM)"
         << "\n";
    cout << setfill(' ') << setw(5) << " " << right << "3. Nama Peminjam"
         << "\n";
    cout << setfill('=') << setw(30) << "\n";
    cout << "Masukkan Pilihan            = ";
    cin >> pilih;
    cin.ignore();

    switch (pilih)
    {
    case 1:
        IDSewaBubbleSort();
        break;
    case 2:
        IDBubbleSort();
        break;
    case 3:
        NamaBubbleSort();
        break;
    default:
        cout << "\n\nTolong Inputkan dengan benar" << endl;
        break;
    }

    cout << "\n\nKembali Ke Bubble Sort Menu ?" << endl;
    cout << "\nY = KEMBALI ";
    cout << "\nN = KELUAR ";
    cout << "\n\nMasukkan Pilihan       = ";
    cin >> pilih_bubble_menu;

    if (pilih_bubble_menu == 'Y' || pilih_bubble_menu == 'y')
    {
        MenuBubbleSort();
    }
    else
    {
        cout << "\n\nKembali Ke Menu Sorting  ?" << endl;
        cout << "\nY = KEMBALI ";
        cout << "\nN = KELUAR ";
        cout << "\n\nMasukkan Pilihan       = ";
        cin >> pilih_sorting_menu;

        if (pilih_sorting_menu == 'Y' || pilih_sorting_menu == 'y')
        {
            MenuSortingData();
        }
        else
        {
            cout << "\n\nKembali Ke Menu Utama ?" << endl;
            cout << "\nY = KEMBALI ";
            cout << "\nN = KELUAR ";
            cout << "\n\nMasukkan Pilihan       = ";
            cin >> pilih_main_menu;

            if (pilih_main_menu == 'Y' || pilih_main_menu == 'y')
            {
                system("CLS");
                main();
            }
        }
    }
}

void IDSewaBubbleSort()
{
    // tanpa cls

    int dataCount = ifstream_fungsi();

    if (dataCount != 0)
    {
        cout << "\n\nHASIL BUBBLE SORT" << endl;

        for (int i = 0; i < dataCount - 1; i++)
        {
            for (int j = 0; j < dataCount - 1 - i; j++)
            {
                if (Temp[j].id_sewa > Temp[j + 1].id_sewa)
                {
                    dataDrone temporary_swap = Temp[j];
                    Temp[j] = Temp[j + 1];
                    Temp[j + 1] = temporary_swap;
                }
            }
        }

        tabel_output(dataCount, 0);
    }
}

void IDBubbleSort()
{
    // tanpa cls

    int dataCount = ifstream_fungsi();

    if (dataCount != 0)
    {
        cout << "\n\nHASIL BUBBLE SORT" << endl;

        for (int i = 0; i < dataCount - 1; i++)
        {
            for (int j = 0; j < dataCount - 1 - i; j++)
            {
                if (strcmp(Temp[j].id_peminjam, Temp[j + 1].id_peminjam) > 0)
                {
                    dataDrone temporary_swap = Temp[j];
                    Temp[j] = Temp[j + 1];
                    Temp[j + 1] = temporary_swap;
                }
            }
        }

        tabel_output(dataCount, 0);
    }
}

void NamaBubbleSort()
{
    // tanpa cls

    int dataCount = ifstream_fungsi();

    if (dataCount != 0)
    {
        cout << "\n\nHASIL BUBBLE SORT" << endl;

        for (int i = 0; i < dataCount - 1; i++)
        {
            for (int j = 0; j < dataCount - 1 - i; j++)
            {
                if (strcmp(Temp[j].nama_peminjam, Temp[j + 1].nama_peminjam) > 0)
                {
                    dataDrone temporary_swap = Temp[j];
                    Temp[j] = Temp[j + 1];
                    Temp[j + 1] = temporary_swap;
                }
            }
        }

        tabel_output(dataCount, 0);
    }
}

void MenuSelectionSort()
{
    system("CLS");

    int pilih;
    char pilih_selection_menu, pilih_sorting_menu, pilih_main_menu;

    cout << setfill('=') << setw(30) << "\n";
    cout << " PENGURUTAN DATA SELECTION " << endl;
    cout << setfill('=') << setw(30) << "\n";
    cout << setfill(' ') << setw(5) << " " << right << "1. ID Sewa"
         << "\n";
    cout << setfill(' ') << setw(5) << " " << right << "2. ID Peminjam (KTP/SIM)"
         << "\n";
    cout << setfill(' ') << setw(5) << " " << right << "3. Nama Peminjam"
         << "\n";
    cout << setfill('=') << setw(30) << "\n";
    cout << "Masukkan Pilihan            = ";
    cin >> pilih;
    cin.ignore();

    switch (pilih)
    {
    case 1:
        IDSewaSelectionSort();
        break;
    case 2:
        IDSelectionSort();
        break;
    case 3:
        NamaSelectionSort();
        break;

    default:
        cout << "\n\nTolong Inputkan dengan benar" << endl;
        break;
    }

    cout << "\n\nKembali Ke Selection Sort Menu ?" << endl;
    cout << "\nY = KEMBALI ";
    cout << "\nN = KELUAR ";
    cout << "\n\nMasukkan Pilihan       = ";
    cin >> pilih_selection_menu;

    if (pilih_selection_menu == 'Y' || pilih_selection_menu == 'y')
    {
        MenuSelectionSort();
    }
    else
    {
        cout << "\n\nKembali Ke Menu Sorting  ?" << endl;
        cout << "\nY = KEMBALI ";
        cout << "\nN = KELUAR ";
        cout << "\n\nMasukkan Pilihan       = ";
        cin >> pilih_sorting_menu;

        if (pilih_sorting_menu == 'Y' || pilih_sorting_menu == 'y')
        {
            MenuSortingData();
        }
        else
        {
            cout << "\n\nKembali Ke Menu Utama ?" << endl;
            cout << "\nY = KEMBALI ";
            cout << "\nN = KELUAR ";
            cout << "\n\nMasukkan Pilihan       = ";
            cin >> pilih_main_menu;

            if (pilih_main_menu == 'Y' || pilih_main_menu == 'y')
            {
                system("CLS");
                main();
            }
        }
    }
}

void IDSewaSelectionSort()
{
    int dataCount = ifstream_fungsi();

    if (dataCount != 0)
    {
        cout << "\n\nHASIL SELECTION SORT" << endl;

        for (int current = 0; current < dataCount; current++)
        {
            for (int j = current + 1; j < dataCount; j++)
            {
                if (Temp[current].id_sewa > Temp[j].id_sewa)
                {
                    dataDrone temporary_swap = Temp[current];
                    Temp[current] = Temp[j];
                    Temp[j] = temporary_swap;
                }
            }
        }

        tabel_output(dataCount, 0);
    }
}

void IDSelectionSort()
{
    int dataCount = ifstream_fungsi();

    if (dataCount != 0)
    {
        cout << "\n\nHASIL SELECTION SORT" << endl;

        for (int current = 0; current < dataCount; current++)
        {
            for (int j = current + 1; j < dataCount; j++)
            {
                if (strcmp(Temp[current].id_peminjam, Temp[j].id_peminjam) > 0)
                {
                    dataDrone temporary_swap = Temp[current];
                    Temp[current] = Temp[j];
                    Temp[j] = temporary_swap;
                }
            }
        }

        tabel_output(dataCount, 0);
    }
}

void NamaSelectionSort()
{
    int dataCount = ifstream_fungsi();

    if (dataCount != 0)
    {
        cout << "\n\nHASIL SELECTION SORT" << endl;

        for (int current = 0; current < dataCount; current++)
        {
            for (int j = current + 1; j < dataCount; j++)
            {
                if (strcmp(Temp[current].nama_peminjam, Temp[j].nama_peminjam) > 0)
                {
                    dataDrone temporary_swap = Temp[current];
                    Temp[current] = Temp[j];
                    Temp[j] = temporary_swap;
                }
            }
        }

        tabel_output(dataCount, 0);
    }
}

void MenuInsertionSort()
{
    system("CLS");

    int pilih;
    char pilih_insertion_menu, pilih_sorting_menu, pilih_main_menu;

    cout << setfill('=') << setw(30) << "\n";
    cout << " PENGURUTAN DATA INSERTION " << endl;
    cout << setfill('=') << setw(30) << "\n";
    cout << setfill(' ') << setw(5) << " " << right << "1. ID Sewa"
         << "\n";
    cout << setfill(' ') << setw(5) << " " << right << "2. ID Peminjam (KTP/SIM)"
         << "\n";
    cout << setfill(' ') << setw(5) << " " << right << "3. Nama Peminjam"
         << "\n";
    cout << setfill('=') << setw(30) << "\n";
    cout << "Masukkan Pilihan            = ";
    cin >> pilih;
    cin.ignore();

    switch (pilih)
    {
    case 1:
        IDSewaInsertionSort();
        break;
    case 2:
        IDInsertionSort();
        break;
    case 3:
        NamaInsertionSort();
        break;

    default:
        cout << "\n\nTolong Inputkan dengan benar" << endl;
        break;
    }

    cout << "\n\nKembali Ke Insertion Sort Menu ?" << endl;
    cout << "\nY = KEMBALI ";
    cout << "\nN = KELUAR ";
    cout << "\n\nMasukkan Pilihan       = ";
    cin >> pilih_insertion_menu;

    if (pilih_insertion_menu == 'Y' || pilih_insertion_menu == 'y')
    {
        MenuInsertionSort();
    }
    else
    {
        cout << "\n\nKembali Ke Menu Sorting  ?" << endl;
        cout << "\nY = KEMBALI ";
        cout << "\nN = KELUAR ";
        cout << "\n\nMasukkan Pilihan       = ";
        cin >> pilih_sorting_menu;

        if (pilih_sorting_menu == 'Y' || pilih_sorting_menu == 'y')
        {
            MenuSortingData();
        }
        else
        {
            cout << "\n\nKembali Ke Menu Utama ?" << endl;
            cout << "\nY = KEMBALI ";
            cout << "\nN = KELUAR ";
            cout << "\n\nMasukkan Pilihan       = ";
            cin >> pilih_main_menu;

            if (pilih_main_menu == 'Y' || pilih_main_menu == 'y')
            {
                system("CLS");
                main();
            }
        }
    }
}

void IDSewaInsertionSort()
{
    int dataCount = ifstream_fungsi();

    if (dataCount != 0)
    {
        cout << "\n\nHASIL INSERTION SORT" << endl;

        for (int i = 1; i < dataCount; i++)
        {
            dataDrone temporary_swap = Temp[i];
            int j = i - 1;
            while ((temporary_swap.id_sewa < Temp[j].id_sewa) & (j >= 0))
            {
                Temp[j + 1] = Temp[j];
                j = j - 1;
            }
            Temp[j + 1] = temporary_swap;
        }

        tabel_output(dataCount, 0);
    }
}

void IDInsertionSort()
{
    int dataCount = ifstream_fungsi();

    if (dataCount != 0)
    {
        cout << "\n\nHASIL INSERTION SORT" << endl;

        for (int i = 1; i < dataCount; i++)
        {
            dataDrone temporary_swap = Temp[i];
            int j = i - 1;
            while ((strcmp(temporary_swap.id_peminjam, Temp[j].id_peminjam) < 0) & (j >= 0))
            {
                Temp[j + 1] = Temp[j];
                j = j - 1;
            }
            Temp[j + 1] = temporary_swap;
        }

        tabel_output(dataCount, 0);
    }
}

void NamaInsertionSort()
{
    int dataCount = ifstream_fungsi();

    if (dataCount != 0)
    {
        cout << "\n\nHASIL INSERTION SORT" << endl;

        for (int i = 1; i < dataCount; i++)
        {
            dataDrone temporary_swap = Temp[i];
            int j = i - 1;
            while ((strcmp(temporary_swap.nama_peminjam, Temp[j].nama_peminjam) < 0) & (j >= 0))
            {
                Temp[j + 1] = Temp[j];
                j = j - 1;
            }
            Temp[j + 1] = temporary_swap;
        }

        tabel_output(dataCount, 0);
    }
}

void MenuShellSort()
{
    system("CLS");

    int pilih;
    char pilih_shell_menu, pilih_sorting_menu, pilih_main_menu;

    cout << setfill('=') << setw(30) << "\n";
    cout << " PENGURUTAN DATA SHELL " << endl;
    cout << setfill('=') << setw(30) << "\n";
    cout << setfill(' ') << setw(5) << " " << right << "1. ID Sewa"
         << "\n";
    cout << setfill(' ') << setw(5) << " " << right << "2. ID Peminjam (KTP/SIM)"
         << "\n";
    cout << setfill(' ') << setw(5) << " " << right << "2. Nama Peminjam"
         << "\n";
    cout << setfill('=') << setw(30) << "\n";
    cout << "Masukkan Pilihan            = ";
    cin >> pilih;
    cin.ignore();

    switch (pilih)
    {
    case 1:
        IDSewaShellSort();
        break;
    case 2:
        IDShellSort();
        break;
    case 3:
        NamaShellSort();
        break;

    default:
        cout << "\n\nTolong Inputkan dengan benar" << endl;
        break;
    }

    cout << "\n\nKembali Ke Shell Sort Menu ?" << endl;
    cout << "\nY = KEMBALI ";
    cout << "\nN = KELUAR ";
    cout << "\n\nMasukkan Pilihan       = ";
    cin >> pilih_shell_menu;

    if (pilih_shell_menu == 'Y' || pilih_shell_menu == 'y')
    {
        MenuShellSort();
    }
    else
    {
        cout << "\n\nKembali Ke Menu Sorting  ?" << endl;
        cout << "\nY = KEMBALI ";
        cout << "\nN = KELUAR ";
        cout << "\n\nMasukkan Pilihan       = ";
        cin >> pilih_sorting_menu;

        if (pilih_sorting_menu == 'Y' || pilih_sorting_menu == 'y')
        {
            MenuSortingData();
        }
        else
        {
            cout << "\n\nKembali Ke Menu Utama ?" << endl;
            cout << "\nY = KEMBALI ";
            cout << "\nN = KELUAR ";
            cout << "\n\nMasukkan Pilihan       = ";
            cin >> pilih_main_menu;

            if (pilih_main_menu == 'Y' || pilih_main_menu == 'y')
            {
                system("CLS");
                main();
            }
        }
    }
}

void IDSewaShellSort()
{
    int dataCount = ifstream_fungsi();

    if (dataCount != 0)
    {
        cout << "\n\nHASIL SHELL SORT" << endl;

        for (int gap = dataCount / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < dataCount; i += 1)
            {

                dataDrone temporary_swap = Temp[i];

                int j;
                for (j = i; j >= gap && Temp[j - gap].id_sewa > temporary_swap.id_sewa; j -= gap)
                    Temp[j] = Temp[j - gap];

                Temp[j] = temporary_swap;
            }
        }

        tabel_output(dataCount, 0);
    }
}

void IDShellSort()
{
    int dataCount = ifstream_fungsi();

    if (dataCount != 0)
    {
        cout << "\n\nHASIL SHELL SORT" << endl;

        for (int gap = dataCount / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < dataCount; i += 1)
            {

                dataDrone temporary_swap = Temp[i];

                int j;
                for (j = i; (j >= gap) && (strcmp(temporary_swap.id_peminjam, Temp[j - gap].id_peminjam) < 0); j -= gap)
                    Temp[j] = Temp[j - gap];

                Temp[j] = temporary_swap;
            }
        }

        tabel_output(dataCount, 0);
    }
}

void NamaShellSort()
{
    int dataCount = ifstream_fungsi();

    if (dataCount != 0)
    {
        cout << "\n\nHASIL SHELL SORT" << endl;

        for (int gap = dataCount / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < dataCount; i += 1)
            {

                dataDrone temporary_swap = Temp[i];

                int j;
                for (j = i; (j >= gap) && (strcmp(temporary_swap.nama_peminjam, Temp[j - gap].nama_peminjam) < 0); j -= gap)
                    Temp[j] = Temp[j - gap];

                Temp[j] = temporary_swap;
            }
        }

        tabel_output(dataCount, 0);
    }
}

void MenuQuickSort()
{
    system("CLS");

    int pilih;
    char pilih_quick_menu, pilih_sorting_menu, pilih_main_menu;

    cout << setfill('=') << setw(30) << "\n";
    cout << " PENGURUTAN DATA QUICK " << endl;
    cout << setfill('=') << setw(30) << "\n";
    cout << setfill(' ') << setw(5) << " " << right << "1. ID Sewa"
         << "\n";
    cout << setfill(' ') << setw(5) << " " << right << "2. ID Peminjam (KTP/SIM)"
         << "\n";
    cout << setfill(' ') << setw(5) << " " << right << "3. Nama Peminjam"
         << "\n";
    cout << setfill('=') << setw(30) << "\n";
    cout << "Masukkan Pilihan            = ";
    cin >> pilih;
    cin.ignore();

    switch (pilih)
    {
    case 1:
        IDSewaQuickSort();
        break;
    case 2:
        IDQuickSort();
        break;
    case 3:
        NamaQuickSort();
        break;

    default:
        cout << "\n\nTolong Inputkan dengan benar" << endl;
        break;
    }

    cout << "\n\nKembali Ke Quick Sort Menu ?" << endl;
    cout << "\nY = KEMBALI ";
    cout << "\nN = KELUAR ";
    cout << "\n\nMasukkan Pilihan       = ";
    cin >> pilih_quick_menu;

    if (pilih_quick_menu == 'Y' || pilih_quick_menu == 'y')
    {
        MenuQuickSort();
    }
    else
    {
        cout << "\n\nKembali Ke Menu Sorting  ?" << endl;
        cout << "\nY = KEMBALI ";
        cout << "\nN = KELUAR ";
        cout << "\n\nMasukkan Pilihan       = ";
        cin >> pilih_sorting_menu;

        if (pilih_sorting_menu == 'Y' || pilih_sorting_menu == 'y')
        {
            MenuSortingData();
        }
        else
        {
            cout << "\n\nKembali Ke Menu Utama ?" << endl;
            cout << "\nY = KEMBALI ";
            cout << "\nN = KELUAR ";
            cout << "\n\nMasukkan Pilihan       = ";
            cin >> pilih_main_menu;

            if (pilih_main_menu == 'Y' || pilih_main_menu == 'y')
            {
                system("CLS");
                main();
            }
        }
    }
}

void IDSewaQuickSort()
{
    int dataCount = ifstream_fungsi();

    if (dataCount != 0)
    {
        cout << "\n\nHASIL QUICK SORT" << endl;

        quickSortIDSewa(0, dataCount);

        tabel_output(dataCount, 0);
    }
}

void IDQuickSort()
{
    int dataCount = ifstream_fungsi();

    if (dataCount != 0)
    {
        cout << "\n\nHASIL QUICK SORT" << endl;

        quickSortIDPeminjam(0, dataCount);

        tabel_output(dataCount, 0);
    }
}

void NamaQuickSort()
{
    int dataCount = ifstream_fungsi();

    if (dataCount != 0)
    {
        cout << "\n\nHASIL QUICK SORT" << endl;

        quickSortNamaPeminjam(0, dataCount);

        tabel_output(dataCount, 0);
    }
}

void MenuMergeSort()
{
    system("CLS");

    int pilih;
    char pilih_merge_menu, pilih_sorting_menu, pilih_main_menu;

    cout << setfill('=') << setw(30) << "\n";
    cout << " PENGURUTAN DATA MERGE " << endl;
    cout << setfill('=') << setw(30) << "\n";
    cout << setfill(' ') << setw(5) << " " << right << "1. ID Sewa"
         << "\n";
    cout << setfill(' ') << setw(5) << " " << right << "2. ID Peminjam (KTP/SIM)"
         << "\n";
    cout << setfill(' ') << setw(5) << " " << right << "3. Nama Peminjam"
         << "\n";
    cout << setfill('=') << setw(30) << "\n";
    cout << "Masukkan Pilihan            = ";
    cin >> pilih;
    cin.ignore();

    switch (pilih)
    {
    case 1:
        IDSewaMergeSort();
        break;
    case 2:
        IDMergeSort();
        break;
    case 3:
        NamaMergeSort();
        break;

    default:
        cout << "\n\nTolong Inputkan dengan benar" << endl;
        break;
    }

    cout << "\n\nKembali Ke Merge Sort Menu ?" << endl;
    cout << "\nY = KEMBALI ";
    cout << "\nN = KELUAR ";
    cout << "\n\nMasukkan Pilihan       = ";
    cin >> pilih_merge_menu;

    if (pilih_merge_menu == 'Y' || pilih_merge_menu == 'y')
    {
        MenuQuickSort();
    }
    else
    {
        cout << "\n\nKembali Ke Menu Sorting  ?" << endl;
        cout << "\nY = KEMBALI ";
        cout << "\nN = KELUAR ";
        cout << "\n\nMasukkan Pilihan       = ";
        cin >> pilih_sorting_menu;

        if (pilih_sorting_menu == 'Y' || pilih_sorting_menu == 'y')
        {
            MenuSortingData();
        }
        else
        {
            cout << "\n\nKembali Ke Menu Utama ?" << endl;
            cout << "\nY = KEMBALI ";
            cout << "\nN = KELUAR ";
            cout << "\n\nMasukkan Pilihan       = ";
            cin >> pilih_main_menu;

            if (pilih_main_menu == 'Y' || pilih_main_menu == 'y')
            {
                system("CLS");
                main();
            }
        }
    }
}

void IDSewaMergeSort()
{
    int dataCount = ifstream_fungsi();

    if (dataCount != 0)
    {
        cout << "\n\nHASIL QUICK SORT" << endl;

        mergeSortIDSewa(0, dataCount - 1);

        tabel_output(dataCount, 0);
    }
}

void IDMergeSort()
{
    int dataCount = ifstream_fungsi();

    if (dataCount != 0)
    {
        cout << "\n\nHASIL QUICK SORT" << endl;

        mergeSortIDPeminjam(0, dataCount - 1);

        tabel_output(dataCount, 0);
    }
}

void NamaMergeSort()
{
    int dataCount = ifstream_fungsi();

    if (dataCount != 0)
    {
        cout << "\n\nHASIL QUICK SORT" << endl;

        mergeSortNamaPeminjam(0, dataCount - 1);

        tabel_output(dataCount, 0);
    }
}

void MenuTransaksi()
{
    system("CLS");

    int pilih;

    cout << setfill('=') << setw(12) << "\n";
    cout << " TRANSAKSI " << endl;
    cout << setfill('=') << setw(12) << "\n";
    cout << setfill(' ') << setw(1) << " " << right << "1. Merging Sambung"
         << "\n";
    cout << setfill(' ') << setw(1) << " " << right << "2. Updating"
         << "\n";
    cout << setfill('=') << setw(12) << "\n";
    cout << "Masukkan Pilihan     = ";
    cin >> pilih;
    cin.ignore();

    switch (pilih)
    {
    case 1:
        MenuMergingSambung();
        break;
    case 2:
        MenuUpdating();
        break;
    default:
        cout << "\n\nTolong Inputkan dengan benar" << endl;
        break;
    }
}

void MenuMergingSambung()
{
    system("CLS");

    char pilih_MergingSambung_menu, pilih_transaksi_menu, pilih_main_menu;

    cout << setfill('=') << setw(18) << "\n";
    cout << " MERGING SAMBUNG " << endl;
    cout << setfill('=') << setw(18) << "\n";
    cout << "Nama File 1        = ";
    cin >> filename;

    /* PROSES MERGING SAMBUNG DIBAWAH SINI */
    int dataCount = ambil_file(0);
    tabel_output(dataCount, 0);

    system("pause");

    cout << "\n\n";

    cout << "Nama File ke 2     = ";
    cin >> filename;

    int dataCount2 = ambil_file(dataCount);
    tabel_output(dataCount2, dataCount);

    system("pause");

    // -------------------------------------------------------------------------------------------------

    cout << "\n\nMasukkan nama file hasil merging sambung = ";
    cin >> filename;

    ofs.open(filename);

    if (!ofs.is_open())
    {
        cout << "file tidak dapat dibuka";
    }
    else
    {
        for (int i = 0; i < dataCount2; i++)
        {
            ofs << setw(8) << Temp[i].id_sewa
                << setw(8) << Temp[i].id_drone
                << setw(30) << Temp[i].nama_drone
                << setw(20) << Temp[i].id_peminjam
                << setw(50) << Temp[i].nama_peminjam
                << setw(8) << Temp[i].waktu_sewa
                << setw(8) << Temp[i].harga_sewa_per_jam
                << setw(20) << Temp[i].total_harga_sewa << endl;
        }
        ofs.close();
        cout << "Proses merging file berhasil" << endl;
    }

    /* ================================== */

    cout << "\n\nULANGI ?" << endl;
    cout << "\nY = KEMBALI ";
    cout << "\nN = KELUAR ";
    cout << "\n\nMasukkan Pilihan       = ";
    cin >> pilih_MergingSambung_menu;

    if (pilih_MergingSambung_menu == 'Y' || pilih_MergingSambung_menu == 'y')
    {
        MenuMergingSambung();
    }
    else
    {
        cout << "\n\nKembali Ke Menu Transaksi  ?" << endl;
        cout << "\nY = KEMBALI ";
        cout << "\nN = KELUAR ";
        cout << "\n\nMasukkan Pilihan       = ";
        cin >> pilih_transaksi_menu;

        if (pilih_transaksi_menu == 'Y' || pilih_transaksi_menu == 'y')
        {
            MenuTransaksi();
        }
        else
        {
            cout << "\n\nKembali Ke Menu Utama ?" << endl;
            cout << "\nY = KEMBALI ";
            cout << "\nN = KELUAR ";
            cout << "\n\nMasukkan Pilihan       = ";
            cin >> pilih_main_menu;

            if (pilih_main_menu == 'Y' || pilih_main_menu == 'y')
            {
                system("CLS");
                main();
            }
        }
    }
}

void MenuUpdating()
{
    system("CLS");

    char pilih_updating_menu, pilih_transaksi_menu, pilih_main_menu;

    cout << setfill('=') << setw(11) << "\n";
    cout << " UPDATING " << endl;
    cout << setfill('=') << setw(11) << "\n";
    cout << "Nama File   = ";
    cin >> filename;
    cin.ignore();
    /* PROSES MERGING SAMBUNG DIBAWAH SINI */

    // ambil data dari file dan tampilkan ke tabel
    int dataCount = ambil_file(0);

    if (dataCount != 0)
    {
        tabel_output(dataCount, 0);
        
        string cari;
        int k = 0;
        bool ketemu = false;
        // searching dan sekaligus pilih row mana yang mau di update

        cout << "Masukkan ID Peminjam yang akan diupdate      = ";
        getline(cin, cari);

        while ((k < dataCount) && (!ketemu))
        {
            if (Temp[k].id_peminjam == cari)
            {
                ketemu = true;
            }
            else
            {
                k++;
            }
        }

        // HASIL PENCAHARIAN DI BAWAH INI
        if (ketemu)
        {
            tabel_output(k + 1, k);
            // input data baru
            cout << "\nMasukkan data Update     : ";
            cout << "\n\tID Sewa           = ";
            cin >> Temp[k].id_sewa;
            cin.ignore();

            cout << "\tID Drone          = ";
            cin >> Temp[k].id_drone;
            cin.ignore(5, '\n');

            cout << "\tNama Drone        = ";
            cin.get(Temp[k].nama_drone, 100);
            cin.ignore();

            cout << "\tNama Peminjam     = ";
            cin.get(Temp[k].nama_peminjam, 100);
            cin.ignore();

            cout << "\tWaktu Sewa        = ";
            cin >> Temp[k].waktu_sewa;
            cin.ignore();

            // Kalkulasi Total Harga Sewa = Waktu Sewa x Harga Sewa Per Jam
            Temp[k].total_harga_sewa = 0;
            Temp[k].total_harga_sewa += (Temp[k].waktu_sewa * Temp[k].harga_sewa_per_jam);

            // input ke file
            cout << "\n\nMasukkan nama file hasil Updating          = ";
            cin >> filename;

            // fungsi replace SPASI untuk variabel yg bertipe char, untuk keperluan i/o file
            string str1 = Temp[k].id_drone;
            string str2 = Temp[k].nama_drone;
            string str3 = Temp[k].id_peminjam;
            string str4 = Temp[k].nama_peminjam;

            strcpy(Temp[k].id_drone, replacespasi(str1).c_str());
            strcpy(Temp[k].nama_drone, replacespasi(str2).c_str());
            strcpy(Temp[k].id_peminjam, replacespasi(str3).c_str());
            strcpy(Temp[k].nama_peminjam, replacespasi(str4).c_str());

            // masukkan ke filebaru
            ofs.open(filename);
            // masukkan data ke file
            if (ofs.is_open())
            {
                // data terformat
                for (int i = 0; i < dataCount; i++)
                {
                    ofs << setw(8) << Temp[i].id_sewa
                        << setw(8) << Temp[i].id_drone
                        << setw(30) << Temp[i].nama_drone
                        << setw(20) << Temp[i].id_peminjam
                        << setw(50) << Temp[i].nama_peminjam
                        << setw(8) << Temp[i].waktu_sewa
                        << setw(8) << Temp[i].harga_sewa_per_jam
                        << setw(20) << Temp[i].total_harga_sewa << endl;
                }
                ofs.close();
                cout << "\n\n File berhasil di-Update !!" << endl;
            }
            else
            {
                cout << "File tidak ada atau gagal dibuka" << endl;
            }
        }
        else
        {
            cout << "\n\nTidak bisa menemukan data yang dicari\n"
                 << endl;
        }
    }
    else
    {

        cout << "\n\nULANGI ?" << endl;
        cout << "\nY = KEMBALI ";
        cout << "\nN = KELUAR ";
        cout << "\n\nMasukkan Pilihan       = ";
        cin >> pilih_updating_menu;

        if (pilih_updating_menu == 'Y' || pilih_updating_menu == 'y')
        {
            MenuUpdating();
        }
        else
        {
            cout << "\n\nKembali Ke Menu Transaksi  ?" << endl;
            cout << "\nY = KEMBALI ";
            cout << "\nN = KELUAR ";
            cout << "\n\nMasukkan Pilihan       = ";
            cin >> pilih_transaksi_menu;

            if (pilih_transaksi_menu == 'Y' || pilih_transaksi_menu == 'y')
            {
                MenuTransaksi();
            }
            else
            {
                cout << "\n\nKembali Ke Menu Utama ?" << endl;
                cout << "\nY = KEMBALI ";
                cout << "\nN = KELUAR ";
                cout << "\n\nMasukkan Pilihan       = ";
                cin >> pilih_main_menu;

                if (pilih_main_menu == 'Y' || pilih_main_menu == 'y')
                {
                    system("CLS");
                    main();
                }
            }
        }
    }
}
