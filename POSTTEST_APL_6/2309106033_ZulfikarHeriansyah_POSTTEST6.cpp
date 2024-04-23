#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;

//Melakukan deklarasi variable
struct detailNovel {
    string penerbit;
    int tahunTerbit;
};
struct novel {
    string judul;
    string genre;
    detailNovel detail;
};
//nama username dan password 
struct user {
    string namaUser; 
    string Password;
};

//memberi warna pada tampilan teks
void setTextColor(int color){
    cout << "\033[1;" << color << "m";
}
//fungsi untuk membersihkan terminal
void clear(){
    system("cls");

}
bool menuLogin(user login , int percobaan){
    //perulangan untuk melakukan login
    string username,password;
    cout << "MASUKKAN USERNAME : ";
    getline(cin,username);
    cout << "MASUKKAN PASSWORD : ";
    getline(cin,password);
    if (username == login.namaUser && password == login.Password){
        clear();
        setTextColor(32);
        cout << "LOGIN BERHASIL\n\n";
        setTextColor(0);
        return true;
    }else if(percobaan < 3){
        setTextColor(31);
        cout << "\nDATA TIDAK SESUAI , KESEMPATAN TERSISA " << 3-percobaan << " KALI\n";
        setTextColor(0);
        return menuLogin(login , percobaan+1);
    }else{
        setTextColor(31);
        cout << "\nMAAF KESEMPATAN SUDAH HABIS";
        setTextColor(0);
        return false;
    }
}

int menuPilihan(){
    int choice;
    while(true){
    setTextColor(33);
        cout << "====================\n";
        cout << "    MENU PROGRAM    \n";
        cout << "====================\n\n";
        setTextColor(0);
        cout << "[1] MENAMBAH NOVEL\n";
        cout << "[2] MELIHAT DAFTAR NOVEL\n";
        cout << "[3] MENGEDIT NOVEL\n";
        cout << "[4] MENGHAPUS NOVEL\n";
        cout << "[5] SORTING\n";
        cout << "[6] EXIT PROGRAM\n\n";
        cout << "MEMILIH MENU NOMOR : ";
        cin >> choice;
        cin.ignore();
        if(cin.fail()){//percabangan ketika hasil yang diinput user tidak sesuai
            clear();
            setTextColor(31);
            cout << "INPUT TIDAK SESUAI\n\n";
            setTextColor(0);
            cin.clear();//menangkap dan membersihkan output error sehingga cin dapat menginput kembali
            cin.ignore(numeric_limits<streamsize>::max(), '\n');//membersihkan sisa sisa karakter di buffer
        }else if (choice < 1 || choice >  6){
            clear();
            setTextColor(31);
            cout << "PILIHAN YANG TERSEDIA HANYA 1 - 6\n\n";
            setTextColor(0);
            continue;
        }else{
            return choice;
        }
    }
}
//insertion sort
void insertionSort(novel dataNovel[], int n){
    int i,j;
    novel key;
    for ( i = 1; i < n; i++){
        key = dataNovel[i];
        j = i - 1;
        while (j >= 0 && dataNovel[j].judul > key.judul){
            dataNovel[j + 1] = dataNovel[j];
            j = j - 1;
        }
        dataNovel[j + 1] = key; //menempatkan key pada posisi yang benar
    }
}

//merge sort descending untuk tahun terbit
void merge(novel dataNovel[], int low, int mid, int high){
    novel temp[high-low+1]; // Membuat array sementara untuk penyimpanan sementara data
    int i = low, j = mid + 1, k = 0;

    // Merging dua bagian yang sudah diurutkan
    while (i <= mid && j <= high){
        if (dataNovel[i].detail.tahunTerbit >= dataNovel[j].detail.tahunTerbit){
            temp[k] = dataNovel[i];
            k++;
            i++;
        }else{
            temp[k] = dataNovel[j];
            k++;
            j++;
        }
    }

    // Menyalin sisa elemen dari bagian pertama
    while (i <= mid){
        temp[k] = dataNovel[i];
        k++;
        i++;
    }
    // Menyalin sisa elemen dari bagian kedua
    while (j <= high){
        temp[k] = dataNovel[j];
        k++;
        j++;
    }
    // Menyalin kembali elemen dari array temp ke array asli
    for (i = low; i <= high; i++){
        dataNovel[i] = temp[i-low];
    }
}

//mergesort
void mergeSort(novel dataNovel[], int low, int high){
    if(low < high){
        int mid = (low + high)/2;
        mergeSort(dataNovel, low, mid);
        mergeSort(dataNovel, mid+1, high);
        merge(dataNovel, low, mid, high);
    }
}
//prosedur bubblesort
void bubbleSort(novel dataNovel[], int n){
    int i, j;
    novel temp;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if(dataNovel[j].detail.penerbit > dataNovel[j+1].detail.penerbit){
                // Tukar elemen jika elemen saat ini lebih besar dari elemen berikutnya
                temp = dataNovel[j];
                dataNovel[j] = dataNovel[j+1];
                dataNovel[j+1] = temp;
            }
        }
    }
}
// menampilkan hasil setelah bubble sorting secara ascending (sorting berdasarkan penerbit)
void afterBubbleSort(novel dataNovel[], int *jumlahNovelDitambahkan){
    bubbleSort(dataNovel, *jumlahNovelDitambahkan);
    for (int i=0;i<*jumlahNovelDitambahkan;i++){ //menampilkan data novel
        cout << i+1 <<". " << "JUDUL : " << dataNovel[i].judul << endl 
        << "GENRE : " << dataNovel[i].genre << endl 
        << "TAHUN TERBIT : " << dataNovel[i].detail.tahunTerbit << endl 
        << "NAMA PENERBIT : " << dataNovel[i].detail.penerbit << endl << endl;
    }
}
// menampilkan hasil setelah insertion sorting secara ascending (sorting berdasarkan judul novel)
void afterInsertionSort(novel dataNovel[],int *jumlahNovelDitambahkan){
    insertionSort(dataNovel, *jumlahNovelDitambahkan);
    for (int i=0;i<*jumlahNovelDitambahkan;i++){ //menampilkan data novel
        cout << i+1 <<". " << "JUDUL : " << dataNovel[i].judul << endl 
        << "GENRE : " << dataNovel[i].genre << endl 
        << "TAHUN TERBIT : " << dataNovel[i].detail.tahunTerbit << endl 
        << "NAMA PENERBIT : " << dataNovel[i].detail.penerbit << endl << endl;
    }
}
// menampilkan hasil sorting setelah dilakukan proses sorting merge (sorting berdasarkan tahun terbit)
void afterMergeSort(novel dataNovel[], int *jumlahNovelDitambahkan){
    mergeSort(dataNovel, 0, *jumlahNovelDitambahkan - 1);
    for (int i=0;i<*jumlahNovelDitambahkan;i++){ //menampilkan data novel
        cout << i+1 <<". " << "JUDUL : " << dataNovel[i].judul << endl 
        << "GENRE : " << dataNovel[i].genre << endl 
        << "TAHUN TERBIT : " << dataNovel[i].detail.tahunTerbit << endl 
        << "NAMA PENERBIT : " << dataNovel[i].detail.penerbit << endl << endl;
    }
}
//fungsi interpolation search
int interpolationSearch(novel dataNovel[], int n, string x) {
    int low = 0, high = n - 1;
    while (low <= high && x >= dataNovel[low].judul && x <= dataNovel[high].judul) {
        // Konversi huruf pertama dalam kata menjadi nilai ASCII
        int firstCharX = x[0];
        int firstCharLow = dataNovel[low].judul[0];
        int firstCharHigh = dataNovel[high].judul[0];
        // Perhitungan posisi perkiraan
        int pos = low + ((double)(high - low) / (dataNovel[high].judul.length() - dataNovel[low].judul.length())) * (x.length() - dataNovel[low].judul.length());

        // Jika elemen ditemukan pada posisi perkiraan
        if (dataNovel[pos].judul == x)
            return pos;

        // Jika elemen kurang dari posisi perkiraan, cari di bagian kiri
        if (dataNovel[pos].judul < x)
            low = pos + 1;

        // Jika elemen lebih dari posisi perkiraan, cari di bagian kanan
        else
            high = pos - 1;
    }
    return -1; // Jika elemen tidak ditemukan
}

// Binary Search
int binarySearch(novel dataNovel[], int n, int tahunTerbit) {
    int awal = 0;
    int akhir = n - 1;
    while (awal <= akhir) {
        int tengah = awal + (akhir - awal) / 2 ;
        if (dataNovel[tengah].detail.tahunTerbit == tahunTerbit) {
            return tengah; // Jika ditemukan, kembalikan indeksnya
        } else if (dataNovel[tengah].detail.tahunTerbit < tahunTerbit) {
            akhir = tengah - 1; // Cari di sebelah kanan tengah
        } else {
            awal = tengah + 1; // Cari di sebelah kiri tengah
        }
    }
    return -1; // Jika tidak ditemukan
}

//diberikan pointer pada jumlahnovelditambahkan agar variable lokal ini bisa mengambil nilai dari variable yang diinginkan
void menuSatu(novel dataNovel[],int *jumlahNovelDitambahkan){
    string newNovel,newGenre,newPenerbit;
    int newTerbit;
    cout << "MASUKKAN NAMA NOVEL BARU : ";
    getline(cin, newNovel);
    cout << "MASUKKAN GENRE NOVEL BARU : ";
    getline(cin, newGenre);
    cout << "TAHUN TERBIT : ";
    cin >> newTerbit;
    if (cin.fail()) {
        return;
    }
    cin.ignore();
    cout << "NAMA PENERBIT : ";
    getline(cin, newPenerbit);
    //menambahkan novel ke index baru 
    dataNovel[*jumlahNovelDitambahkan].judul = newNovel;
    dataNovel[*jumlahNovelDitambahkan].genre = newGenre;
    dataNovel[*jumlahNovelDitambahkan].detail.tahunTerbit = newTerbit;
    dataNovel[*jumlahNovelDitambahkan].detail.penerbit = newPenerbit;
    *jumlahNovelDitambahkan+= 1;
    mergeSort(dataNovel, 0, *jumlahNovelDitambahkan - 1);
    setTextColor(32);
    clear();
    cout << "NOVEL BERHASIL DITAMBAHKAN\n\n";
    setTextColor(0);
}
void menuDua(novel dataNovel[],int *jumlahNovelDitambahkan){
    for (int i=0;i<*jumlahNovelDitambahkan;i++){ //menampilkan data novel
        cout << i+1 <<". " << "JUDUL : " << dataNovel[i].judul << endl 
        << "GENRE : " << dataNovel[i].genre << endl 
        << "TAHUN TERBIT : " << dataNovel[i].detail.tahunTerbit << endl 
        << "NAMA PENERBIT : " << dataNovel[i].detail.penerbit << endl << endl;
    }
}
void menuTiga(novel dataNovel[],int *jumlahNovelDitambahkan){
    string newNameNovel,newGenreNovel,newNamaPenulis;
    int editNovel, newTahunTerbit;
    menuDua(dataNovel,jumlahNovelDitambahkan);
            cout << "NOMOR NOVEL YANG INGIN DI EDIT : ";
            cin >> editNovel;
            if (editNovel <= (*jumlahNovelDitambahkan) && editNovel > 0){
                editNovel = editNovel - 1;
                cout << "NAMA BARU NOVEL : ";
                cin.ignore();
                getline(cin,newNameNovel);
                cout << "GENRE NOVEL : ";
                getline(cin,newGenreNovel);
                cout << "TAHUN TERBIT : ";
                cin >> newTahunTerbit;
                cin.ignore();
                cout << "NAMA PENERBIT : ";
                getline(cin,newNamaPenulis);
                dataNovel[editNovel].judul = newNameNovel;
                dataNovel[editNovel].genre = newGenreNovel;
                dataNovel[editNovel].detail.tahunTerbit = newTahunTerbit;
                dataNovel[editNovel].detail.penerbit = newNamaPenulis;
                clear();
                setTextColor(32);
                cout << "NOVEL BERHASIL DI EDIT\n";
                setTextColor(0);
            }else{
                clear();
                setTextColor(31);
                cout << "INPUT SALAH , MOHON MASUKKAN INPUT DENGAN BENAR\n";
                setTextColor(0);
    }
}
void menuEmpat(novel dataNovel[],int *jumlahNovelDitambahkan){
    int delNovel;
    if ((*jumlahNovelDitambahkan) > 0){
        menuDua(dataNovel,jumlahNovelDitambahkan);   
        cout << "MASUKKAN NOMOR NOVEL YANG INGIN DI HAPUS : ";
        cin >> delNovel;
        cin.ignore();
        delNovel--;
        if(delNovel<(*jumlahNovelDitambahkan) && delNovel>=0){
            for(int i=delNovel;i<(*jumlahNovelDitambahkan-1);i++){
                dataNovel[i].judul = dataNovel[i+1].judul;
                dataNovel[i].genre = dataNovel[i+1].genre;
                dataNovel[i].detail.tahunTerbit = dataNovel[i+1].detail.tahunTerbit;
                dataNovel[i].detail.penerbit = dataNovel[i+1].detail.penerbit;
            }
            (*jumlahNovelDitambahkan)--;
            clear();
            setTextColor(32);
            cout << "NOVEL BERHASIL DI HAPUS\n";
            setTextColor(0);
        }else {
            clear();
            setTextColor(31);
            cout << "NOMOR NOVEL YANG KAMU INGIN HAPUS TIDAK ADA\n";
            setTextColor(0);
        }
    }else{
        clear();
        setTextColor(31);
        cout << "NOVEL SUDAH HABIS , TAMBAHKAN DULU BEBERAPA NOVEL\n";
        setTextColor(0);
    }
}

void menuLima(novel dataNovel[],int *jumlahNovelDitambahkan){
    int pilihan;
    //menu sorting 
    clear();
    setTextColor(33);
    cout << "====================\n";
    cout << "      SORTING    \n";
    cout << "====================\n\n";
    setTextColor(0);
    cout << "1. INSERTION SORTING (ASCENDING JUDUL NOVEL)\n"; //sorting judul
    cout << "2. MERGE SORTING (DESCENDING TAHUN TERBIT)\n"; //sorting tahun terbit 
    cout << "3. BUBBLE SORT (ASCENDING PENERBIT)\n\n";//sorting penerbit
    cout << "PILIH MENU : ";
    setTextColor(0);
    cin >> pilihan;
    cin.ignore();
    switch(pilihan){
        case 1: 
        {
            afterInsertionSort(dataNovel, jumlahNovelDitambahkan);
            string benar,search;
            int index;
            cout << "APAKAH ANDA INGIN MELAKUKAN SEARCHING ? [y/n] : ";
            cin >> benar;
            if (benar == "y" || benar == "Y" ){
                cout << "INGIN MENCARI DATA NOVEL : ";
                cin >> search;
                index = interpolationSearch(dataNovel, *jumlahNovelDitambahkan, search);
                if (index != -1){
                    clear();
                    cout << "DATA NOVEL YANG DICARI\n";
                    cout << "JUDUL : " << dataNovel[index].judul << endl;
                    cout << "GENRE : " << dataNovel[index].genre << endl;
                    cout << "TAHUN TERBIT : " << dataNovel[index].detail.tahunTerbit << endl;
                    cout << "PENERBIT : " << dataNovel[index].detail.penerbit << endl;
                }else {
                    clear();
                    setTextColor(31);
                    cout << "DATA NOVEL TIDAK DITEMUKAN \n\n";
                    setTextColor(0);
                }
            }else {
                return;
            }
            break;
        }

        case 2: 
        {
            afterMergeSort(dataNovel, jumlahNovelDitambahkan);
            int searchTahun;
            string benar;
            cout << "APAKAH ANDA INGIN MELAKUKAN SEARCHING ? [y/n] : ";
            cin >> benar;
            if (benar == "y" || benar == "Y" ){
                cout << "MASUKKAN TAHUN TERBIT NOVEL YANG INGIN DICARI : ";
                cin >> searchTahun;
                int hasilPencarian = binarySearch(dataNovel, *jumlahNovelDitambahkan, searchTahun);
                if (hasilPencarian != -1){
                    clear();
                    cout << "DATA NOVEL YANG DICARI\n";
                    cout << "JUDUL : " << dataNovel[hasilPencarian].judul << endl;
                    cout << "GENRE : " << dataNovel[hasilPencarian].genre << endl;
                    cout << "TAHUN TERBIT : " << dataNovel[hasilPencarian].detail.tahunTerbit << endl;
                    cout << "PENERBIT : " << dataNovel[hasilPencarian].detail.penerbit << endl;
                }else {
                    clear();
                    setTextColor(31);
                    cout << "DATA NOVEL TIDAK DITEMUKAN\n";
                    setTextColor(0);
                }
            }else {
                return;
            }
            break;
        }

        case 3: 
        {
            afterBubbleSort(dataNovel, jumlahNovelDitambahkan);
            break;
        }
    }

}

//main program
int main(){
    user login;
    int jumlahNovelDitambahkan = 2; 
    novel dataNovel[100];
    login.namaUser = "Heri";
    login.Password = "2309106033";
    dataNovel[0].judul = "Malioboro at Midnight";//judul novel
    dataNovel[0].genre = "Drama"; // genre novel
    dataNovel[0].detail.tahunTerbit = 2019;
    dataNovel[0].detail.penerbit = "Bukune";
    dataNovel[1].judul = "Bumi";// judul novel
    dataNovel[1].genre = "Action";// genre novel
    dataNovel[1].detail.tahunTerbit = 2023;
    dataNovel[1].detail.penerbit = "Media Kita";

    setTextColor(33);
    clear();
    cout << "=============================\n";
    cout << "   PROGRAM CRUD LIST NOVEL  \n";
    cout << "=============================\n\n";
    setTextColor(0);
    //kondisi untuk ke menu login
    if (menuLogin(login , 1) == false){
        return 0;
    }
    while(true){
        switch(menuPilihan()){
            case 1:
            {
                clear();
                menuSatu(dataNovel,&jumlahNovelDitambahkan);
                break;
            }
            case 2:
            {   
                clear();
                menuDua(dataNovel,&jumlahNovelDitambahkan);
                break;
            }
            case 3:
            {
                clear();
                menuTiga(dataNovel,&jumlahNovelDitambahkan);
                break;
            }
            case 4:
            {
                clear();
                menuEmpat(dataNovel,&jumlahNovelDitambahkan);
                break;
            }
            case 5:
            {
                clear();
                menuLima(dataNovel,&jumlahNovelDitambahkan);
                break;
            }
            case 6:
            {
                return 0;
            }
        }
    }
    return 0;
}


