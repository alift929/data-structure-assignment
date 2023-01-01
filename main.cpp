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

    cout<<"Menghapus negara Vietnam dari List"<<endl<<endl;

    deleteNegara(LN,"Vietnam");
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
    }
    
    connectKGroup(LN,LK,"Indonesia","ITZY");
    connectKGroup(LN,LK,"Philippines","ITZY");
    connectKGroup(LN,LK,"Singapore","ITZY");
    connectKGroup(LN,LK,"Indonesia","Blackpink");
    connectKGroup(LN,LK,"Singapore","Blackpink");
    connectKGroup(LN,LK,"Japan","Blackpink");
    connectKGroup(LN,LK,"South Korea","Blackpink");
    connectKGroup(LN,LK,"Singapore","TWICE");
    connectKGroup(LN,LK,"Philippines","TWICE");
    connectKGroup(LN,LK,"Indonesia","BTS");

    cout<<"====================================================================="<<endl;

    showAll(LN);

    cout<<"====================================================================="<<endl;

    cout<<"Menghapus data K-POP Group yang telah selesai concert di negara Japan"<<endl;
    deleteKGroup(LN,"Japan");
    showAll(LN);

    cout<<"====================================================================="<<endl;

    cout<<"Menghitung K-POP Group yang akan concert di negara Singapore"<<endl;
    cout<<jumlahKGroup(LN,"Singapore")<<" K-POP Group"<<endl;

    cout<<"====================================================================="<<endl;

    return 0;
}
