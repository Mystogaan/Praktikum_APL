//library yang dipakai
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <limits>
using namespace std;
//memberi warna pada tampilan teks
void setTextColor(int color){
    cout << "\033[1;" << color << "m";
}
//nama username dan password 
string namaUser = "Zulfikar Heriansyah";
string Password = "2309106033";
//deklarasi variabel
string username,password,answer;
int pilihan,rupiah,dollar,euro,yen;
//fungsi untuk membersihkan terminal
void clear(){
    system("cls");
}
//main program
int main () {
    clear();
setTextColor(33);
cout << "========================\n";
cout << "PROGRAM CONVERT MATA UANG\n";
cout << "========================\n\n";
setTextColor(0);
    for(int i = 0; i<3 ;i++){ //perulangan meminta sampai 3 kali inputan
        cout << "Masukkan Username : ";
        getline(cin,username);
        cout << "Masukkan Password : ";
        getline(cin,password);
        if(username == namaUser && password == Password){//kondisi jika benar
            break;
            clear();
        }else if (i<2) {
            setTextColor(31);
            cout << "DATA SALAH , KESEMPATAN TERSISA " << 2-i << " KALI" << endl;
            setTextColor(0);
        }else if (i==2){
            setTextColor(31);
            cout << "MAAF KESEMPATAN HABIS";
            setTextColor(0);
            exit(0);
        }
    } 
    do { // perulangan agar bisa meminta input yes or no kepada user
        clear();
        while(true){
        setTextColor(33);
        cout << "=====================" << endl;
        cout << "    MENU KONVERSI    " << endl;
        cout << "=====================" << endl;
        setTextColor(0);
        cout << "[1] Rupiah ke (Dollar, Euro, Yen)\n";
        cout << "[2] Dollar ke (Rupiah, Euro, Yen)\n";
        cout << "[3] Euro ke (Rupiah, Dollar, Yen)\n";
        cout << "[4] Yen ke (Rupiah, Dollar, Euro)\n";
        cout << "[5] EXIT PROGRAM\n\n";
        cout << "Memilih Menu Nomor : ";
        cin >> pilihan;
        
        if(pilihan < 1 || pilihan > 5){//error handling agar inputan hanya di range 1 - 5
            setTextColor(31);
            clear();
            cout << "PILIHAN HANYA TERSEDIA 1 SAMPAI 5 , MOHON TINGKATKAN LITERASINYA" << endl;
            setTextColor(0);
            continue;
        }
        break;
        }

        //switch case untuk menentukan kondisi
        switch(pilihan) {
            case 1:
            clear();
            for (int i=0;i<3;i++){
                cout << "Masukkan Jumlah RUPIAH (IDR) : ";
                cin >> rupiah;
                //menangani kesalahan input 
                if (cin.fail()) {
                    //membersihkan status fail jika cin.fail ketrigereed
                    cin.clear();
                    //menghapus karakter yang tidak valid 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');//numeric limit untuk memberikann range dari tipe data yang diminta dan cin.ignore untuk membersihkan buffer input
                        if(i==2){
                        setTextColor(31);
                        cout << "MAAF KESEMPATAN HABIS";
                        setTextColor(0);
                        break;//keluar dari perulanngan
                }
                    setTextColor(31);
                    cout << "INPUT TIDAK VALID , KESEMPATAN TERSISA " << 2-i << endl;
                    setTextColor(0);
                }else {
                    cin.ignore();
                    break;
                }
            }   //fungsi untuk mengkonversi uang
                dollar = rupiah * 0.000064;
                euro = rupiah * 0.00006;
                yen = rupiah * 0.0096;
                cout << rupiah << " Rupiah ke dollar adalah " << dollar <<" USD\n";
                cout << rupiah << " Rupiah ke euro adalah " << euro << " EUR\n";
                cout << rupiah << " Rupiah ke yen adalah " << yen << " JPY\n";
                break;

            case 2:
             clear();
            for (int i=0;i<3;i++){
                cout << "Masukkan Jumlah DOLLAR (USD) : ";
                cin >> dollar;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        if(i==2){
                        setTextColor(31);
                        cout << "MAAF KESEMPATAN HABIS";
                        setTextColor(0);
                        break;
                }
                    setTextColor(31);
                    cout << "INPUT TIDAK VALID , KESEMPATAN TERSISA " << 2-i << endl;
                    setTextColor(0);
                }else {
                    break;
                }
            }
                rupiah = dollar * 15701.95;
                euro = dollar * 0.92;
                yen = dollar * 150.09;
                cout << dollar << " Dollar ke rupiah adalah " << rupiah << " IDR\n";
                cout << dollar << " Dollar ke euro adalah " << euro << " EUR\n";
                cout << dollar << "Dollar ke yen adalah " << yen << " JPY\n";
                break;
            
            case 3:
            clear();
            for (int i=0;i<3;i++){
                cout << "Masukkan Jumlah EURO (EUR) : ";
                cin >> euro;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        if(i==2){
                        setTextColor(31);
                        cout << "MAAF KESEMPATAN HABIS";
                        setTextColor(0);
                        break;
                }
                    setTextColor(31);
                    cout << "INPUT TIDAK VALID , KESEMPATAN TERSISA " << 2-i << endl;
                    setTextColor(0);
                }else {
                    break;
                }
            }
                rupiah = euro * 17043.68;
                dollar = euro * 1.09;
                yen = euro * 162.93;
                cout << euro << " Euro ke rupiah adalah " << rupiah << " IDR\n";
                cout << euro << " Euro ke dollar adalah " << dollar << " USD\n";
                cout << euro << " Euro ke yen adalah " << yen << " JPY\n";
                break;
            
            case 4:
            clear();
            for (int i=0;i<3;i++){
                cout << "Masukkan Jumlah YEN (JPY) : ";
                cin >> yen;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        if(i==2){
                        setTextColor(31);
                        cout << "MAAF KESEMPATAN HABIS\n";
                        setTextColor(0);
                        break;

                }
                    setTextColor(31);
                    cout << "INPUT TIDAK VALID , KESEMPATAN TERSISA " << 2-i << endl;
                    setTextColor(0);
                }else {
                    break;
                }
            }
                rupiah = yen * 104.61;
                dollar = yen * 0.0067;
                euro = yen * 0.0061;
                cout << yen << " Yen ke rupiah adalah " << rupiah << " IDR\n";
                cout << yen << " Yen ke dollar adalah " << dollar << " USD\n";
                cout << yen << " Yen ke euro adalah " << euro << " EUR\n";
                break;
            case 5:
                exit(0);
        }
            while(true){
            cout << "\nAPAKAH ANDA INGIN MENGULANG PROGRAM [y/n] : ";
            cin >> answer;
            //percabangan untuk meminta input user ingin mengulang program atau tidak
            if (answer != "y" && answer != "Y" && answer != "n" && answer != "N"){
                setTextColor(31);
                cout << "PILIHAN HANYA y atau n , MOHON TINGKATKAN LITERASINYA" << endl;
                setTextColor(1);
            }else {
                break;
            } 
            }
    } while(answer == "y" || answer == "Y");//perulangan untuk mengulang program
    return 0;
}


