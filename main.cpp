#include "tubes.h"
#include <iostream>

using namespace std;

int main()
{
    listNegara LN;
    listKGroup LK;
    createListNegara(LN);
    createListKGroup(LK);

    string namaNegara,namaKGroup,kota,tour;
    int n,tahun,personel;
    cout<<"Jumlah negara yang akan diadakan konser: ";
    cin>>n;
    cin.ignore(10000,'\n');
    for(int i=1; i<=n; i++){
        cout<<endl<<"Masukkan nama negara: ";
        getline(cin,namaNegara);
        cout<<"Masukkan nama kota: ";
        getline(cin,kota);
        cout<<"Masukkan tahun: ";
        cin>>tahun;
        insertNegara(LN,newNegara(namaNegara,kota,tahun));
        cin.get();
    }

    cout<<"====================================================================="<<endl;

    showNegara(LN);

    cout<<"====================================================================="<<endl;

    cout<<"Masukkan nama negara yang akan dihapus dari list: ";
    getline(cin,namaNegara);
    cout<<"Menghapus negara "<<namaNegara<<" dari List\n\n";

    deleteNegara(LN,namaNegara);
    showNegara(LN);

    cout<<"====================================================================="<<endl;

    cout<<"Jumlah K-POP Group yang akan mengadakan konser: ";
    cin>>n;
    cin.ignore(10000,'\n');
    for(int i=1; i<=n; i++){
        cout<<endl<<"Masukkan nama K-POP Group: ";
        getline(cin,namaKGroup);
        cout<<"Masukkan jumlah personel: ";
        cin>>personel;
        cout<<"Masukkan nama tour: ";
        cin.ignore(10000,'\n');
        getline(cin,tour);
        insertKGroup(LK,newKGroup(namaKGroup,personel,tour));
        namaNegara=" ";
        while(namaNegara!="-"){
            cout<<"Masukkan negara yang akan dikunjungi: ";
            getline(cin,namaNegara);
            connectKGroup(LN,LK,namaNegara,namaKGroup);
        }
    }

    cout<<"====================================================================="<<endl;

    showAll(LN);

    cout<<"====================================================================="<<endl;

    cout<<"Masukkan negara yang telah selesai concert: ";
    getline(cin,namaNegara);
    cout<<"\nMenghapus data K-POP Group yang telah selesai concert di negara "<<namaNegara<<endl;
    deleteKGroup(LN,namaNegara);
    showAll(LN);

    cout<<"====================================================================="<<endl;

    cout<<"Masukkan negara yang akan dihitung berapa concert yang akan datang: ";
    getline(cin,namaNegara);
    cout<<"K-POP Group yang akan concert di negara"<<namaNegara<<endl;
    cout<<jumlahKGroup(LN,namaNegara)<<" K-POP Group"<<endl;

    cout<<"====================================================================="<<endl;

    return 0;
}
