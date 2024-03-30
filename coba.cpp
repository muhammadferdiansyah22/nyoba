#include <iostream>
#include <ctime>
using namespace std;

template <class T>
class PerhitunganUmur{
    private:
        T* tanggal;
        T* bulan;
        T* tahun;
    public:
        PerhitunganUmur(T* tanggal, T* bulan, T* tahun) : tanggal(tanggal), bulan(bulan), tahun(tahun){
        }
        
        T* getTanggal() const{
            return tanggal;
        }
        void setTanggal(T* tanggal){
            this->tanggal = tanggal;
        }
        
        T* getBulan() const{
            return bulan;
        }
        void setBulan(T* bulan){
            this->bulan = bulan;
        }
        
        T* getTahun() const{
            return tahun;
        }
        void setTahun(T* tahun){
            this->tahun = tahun;
        }

        void HitungUmur() const{

            int tahun_lahir = *tahun;
            int bulan_lahir = *bulan;
            int tanggal_lahir = *tanggal;
            
           
            time_t now = time(0);
            tm *ltm = localtime(&now);
            int tahun_sekarang = 1900 + ltm->tm_year;
            int bulan_sekarang = 1 + ltm->tm_mon;
            int tanggal_sekarang = ltm->tm_mday;

            int umur_tahun = tahun_sekarang - tahun_lahir;
            int umur_bulan = bulan_sekarang - bulan_lahir;
            int umur_tanggal = tanggal_sekarang - tanggal_lahir;

            if (umur_bulan < 0) {
                umur_tahun--;
                umur_bulan += 12;
            }

            cout << "Umur Anda adalah " << umur_tahun << " tahun, " << umur_bulan << " bulan, dan " << umur_tanggal << " hari" << endl;
        }

        void HitungHari(int bulan, int tahun) const{
            
            int jumlah_hari;

            if (bulan == 2) {
                if ((tahun % 4 == 0 && tahun % 100 != 0) || tahun % 400 == 0) {
                    jumlah_hari = 29;
                } else {
                    jumlah_hari = 28;
                }
            } else if (bulan == 4 || bulan == 6 || bulan == 9 || bulan == 11) {
                jumlah_hari = 30;
            } else {
                jumlah_hari = 31;
            }

            cout << "Jumlah hari dalam bulan " << bulan << " tahun " << tahun << " adalah " << jumlah_hari << " hari." << endl;
        }

        bool HitungKabisat() const{
            
            int tahun_kabisat = *tahun;
            if (tahun_kabisat % 4 == 0) {
                if (tahun_kabisat % 100 == 0) {
                    if (tahun_kabisat % 400 == 0) {
                        return true;
                    } else {
                        return false;
                    }
                } else {
                    return true;
                }
            } else {
                return false;
            }
        }
};

int main(){
    int tanggal, bulan, tahun;
    cout << "Masukkan tanggal, bulan, dan tahun lahir anda \n";
    cin >> tanggal >> bulan >> tahun;

    PerhitunganUmur <int> umur(&tanggal, &bulan, &tahun);
    umur.HitungUmur();

    int bulan_input, tahun_input;
    cout << "\nMasukkan bulan dan tahun untuk menghitung jumlah hari dalam bulan tersebut : " ;
    cin >> bulan_input >> tahun_input;
    
    umur.HitungHari(bulan_input, tahun_input);

    if(umur.HitungKabisat()){
        cout << tahun_input << " adalah tahun kabisat" << endl;
    }
    else{
        cout << tahun_input << " bukan tahun kabisat" << endl;
    }

    return 0;
}
