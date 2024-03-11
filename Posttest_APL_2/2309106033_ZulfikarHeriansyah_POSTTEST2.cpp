//library yang digunakan
#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;

//nama username dan password 
string namaUser = "Heri";
string Password = "2309106033";
int jumlahNovelDitambahkan = 2; 

//memberi warna pada tampilan teks
void setTextColor(int color){
    cout << "\033[1;" << color << "m";
}
//fungsi untuk membersihkan terminal
void clear(){
    system("cls");

}
//main program
int main(){
    string dataNovel[100][2];
    dataNovel[0][0] = "Malioboro at Midnight";//judul novel
    dataNovel[0][1] = "Drama"; // genre novel
    dataNovel[1][0] = "Bumi";// judul novel
    dataNovel[1][1] = "Action";// genre novel
    //deklarasi variable lokal
    string judul,genre,username,password,newNovel,newGenre,answer,newNameNovel,newGenreNovel; //deklarasi variable
    int choice,editNovel,delNovel;
    bool ulang;
    setTextColor(33);
    clear();
    cout << "=============================\n";
    cout << "   PROGRAM CRUD LIST NOVEL  \n";
    cout << "=============================\n\n";
    setTextColor(0);
    //perulangan untuk melakukan login
        for (int i=0;i<3;i++){
            cout << "MASUKKAN USERNAME : ";
            getline(cin,username);
            cout << "MASUKKAN PASSWORD : ";
            getline(cin,password);
            if (username == namaUser && password == Password){
                clear();
                setTextColor(32);
                cout << "LOGIN BERHASIL\n\n";
                setTextColor(0);
                break;
            }else if(i<2){
                setTextColor(31);
                cout << "\nDATA TIDAK SESUAI , KESEMPATAN TERSISA " << 2-i << " KALI\n";
                setTextColor(0);
            }else if (i==2){
                setTextColor(31);
                cout << "\nMAAF KESEMPATAN SUDAH HABIS";
                setTextColor(0);
                exit(0);
            }
        }

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
        cout << "[5] EXIT PROGRAM\n\n";
        cout << "MEMILIH MENU NOMOR : ";
        cin >> choice;
        if(cin.fail()){//percabangan ketika hasil yang diinput user tidak sesuai
            clear();
            setTextColor(31);
            cout << "INPUT TIDAK SESUAI\n\n";
            setTextColor(0);
            cin.clear();//menangkap dan membersihkan output error sehingga cin dapat menginput kembali
            cin.ignore(numeric_limits<streamsize>::max(), '\n');//membersihkan sisa sisa karakter di buffer
        }else if (choice < 1 || choice >  5){
            clear();
            setTextColor(31);
            cout << "PILIHAN YANG TERSEDIA HANYA 1 - 5\n\n";
            setTextColor(0);
            continue;
        }else{
            cin.ignore();
        switch(choice){
            case 1:
            {
                clear();
                cout << "MASUKKAN NAMA NOVEL BARU : ";
                getline(cin, newNovel);
                cout << "MASUKKAN GENRE NOVEL BARU : ";
                getline(cin, newGenre);
                //menambahkan novel ke index baru 
                dataNovel[jumlahNovelDitambahkan][0] = newNovel;
                dataNovel[jumlahNovelDitambahkan][1] = newGenre;
                jumlahNovelDitambahkan++;
                setTextColor(32);
                clear();
                cout << "NOVEL BERHASIL DITAMBAHKAN\n\n";
                setTextColor(0);
                break;
            }

            case 2:
            {   
                clear();
                for (int i=0;i<jumlahNovelDitambahkan;i++){ //menampilkan data novel
                    cout << i+1 <<". " << "Judul : " << dataNovel[i][0] << endl << "GENRE : " << dataNovel[i][1] << endl << endl;
                }
                break;
            }

            case 3:
            {
                clear();
            for (int i=0;i<jumlahNovelDitambahkan;i++){
                cout << i+1 << ". " << "Judul : " << dataNovel[i][0] << endl << "GENRE : " << dataNovel[i][1] << endl;
                }
            cout << "NOMOR NOVEL YANG INGIN DI EDIT : ";
            cin >> editNovel;
            if (editNovel <= jumlahNovelDitambahkan && editNovel > 0){
                editNovel = editNovel - 1;
                cout << "NAMA BARU NOVEL : ";
                cin.ignore();
                getline(cin,newNameNovel);
                cout << "GENRE NOVEL : ";
                getline(cin,newGenreNovel);
                dataNovel[editNovel][0] = newNameNovel;
                dataNovel[editNovel][1] = newGenreNovel;
                clear();
                setTextColor(32);
                cout << "NOVEL BERHASIL DI EDIT\n";
                setTextColor(0);
            }else{
                clear();
                setTextColor(31);
                cout << "INPUT SALAH , MOHON MASUKKAN INPUT DENGAN BENAR\n";
                setTextColor(0);
                continue;
                }
                break;
            }

            case 4:
            {
                clear();
                if (jumlahNovelDitambahkan > 0){
                    for (int i=0;i<jumlahNovelDitambahkan;i++){
                    cout << i+1 << ". "<< "Judul : " << dataNovel[i][0] << endl << "GENRE : " << dataNovel[i][1] << endl;
                    }   
                    cout << "MASUKKAN NOMOR NOVEL YANG INGIN DI HAPUS : ";
                    cin >> delNovel;
                    cin.ignore();
                    delNovel--;
                    if(delNovel<jumlahNovelDitambahkan && delNovel>=0){
                        for(int i=delNovel;i<jumlahNovelDitambahkan - 1;i++){
                            dataNovel[i][0] = dataNovel[i+1][0];
                            dataNovel[i][1] = dataNovel[i+1][1];
                        }
                        jumlahNovelDitambahkan--;
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
                break;
            }

            case 5:
            {
                return 0;
            }
        }
        }
    }
return 0;
}

