#include "tubes.h"

void createListNegara(listNegara &L){
    first(L)=NULL;
}

void createListKGroup(listKGroup &L){
    first(L)=NULL;
}

adrNegara newNegara(string nama, string kota, int tahun){
    adrNegara n = new Negara;
    info(n).namaNegara=nama;
    info(n).kota=kota;
    info(n).tahun=tahun;
    first(firstKGroup(n))=NULL;
    next(n)=NULL;
    return n;
}

adrKGroup newKGroup(string nama, int personel, string tour){
    adrKGroup k = new KGroup;
    info(k).namaGroup=nama;
    info(k).personel=personel;
    info(k).tour=tour;
    next(k)=NULL;
    return k;
}

void insertNegara(listNegara &L, adrNegara n){
    if(first(L)==NULL){
        first(L)=n;
        next(n)=first(L);
    }else{
        adrNegara q=first(L);
        next(n)=first(L);
        while(next(q)!=first(L)){
            q=next(q);
        }
        next(q)=n;
    }
}

void showNegara(listNegara L){
    if(first(L)==NULL){
        cout<<"List Negara Kosong"<<endl;
    }else{
        adrNegara n=first(L);
        cout<<"List Negara:"<<endl;
        while(next(n)!=first(L)){
            cout<<info(n).namaNegara<<" - "<<info(n).kota<<" - "<<info(n).tahun<<"\n";
            n=next(n);
        }
        cout<<info(n).namaNegara<<" - "<<info(n).kota<<" - "<<info(n).tahun<<"\n";
        cout<<endl;
    }
}

void deleteNegara(listNegara &L, string nama){
    adrNegara n = searchNegara(L,nama);
    if(n!=NULL){
        first(firstKGroup(n))=NULL;
    }
    adrNegara p;
    if(first(L)==n&&next(first(L))==first(L)){
        p=first(L);
        next(p)=NULL;
        first(L)=NULL;
    }else if(first(L)==n&&next(first(L))!=first(L)){
        adrNegara q=first(L);
        while(next(q)!=first(L)){
            q=next(q);
        }
        first(L)=next(first(L));
        next(q)=first(L);
        next(n)=NULL;
    }else{
        p=first(L);
        while(next(p)!=first(L)&&next(p)!=n){
            p=next(p);
        }
        next(p)=next(n);
        next(n)=NULL;
    }
}

adrNegara searchNegara(listNegara L, string nama){
    if(first(L)==NULL){
        return NULL;
    }else{
        adrNegara n = first(L);
        while(info(n).namaNegara!=nama&&next(n)!=first(L)){
            n=next(n);
        }
        if(info(n).namaNegara==nama){
            return n;
        }else{
            return NULL;
        }
    }
}

void insertKGroup(listKGroup &L, adrKGroup k){
    if(first(L)==NULL){
        first(L)=k;
    }else{
        adrKGroup p=first(L);
        while(next(p)!=NULL){
            p=next(p);
        }
        next(p)=k;
    }
}

adrKGroup searchListKGroup(listKGroup L, string nama){
    if(first(L)==NULL){
        return NULL;
    }else{
        adrKGroup k=first(L);
        while(info(k).namaGroup!=nama&&next(k)!=NULL){
            k=next(k);
        }
        if(info(k).namaGroup==nama){
            return k;
        }else{
            return NULL;
        }
    }
}

void connectKGroup(listNegara &L1, listKGroup L2, string namaNegara, string namaKGroup){
    listKGroup L3;
    adrNegara n = searchNegara(L1,namaNegara);
    adrKGroup k = searchListKGroup(L2,namaKGroup);
    if(n!=NULL&&k!=NULL){
        adrKGroup g = new KGroup;
        info(g)=info(k);
        next(g)=NULL;
        if(first(firstKGroup(n))==NULL){
            first(firstKGroup(n))=g;
        }else{
            adrKGroup p=first(firstKGroup(n));
            while(next(p)!=NULL){
                p=next(p);
            }
            next(p)=g;
        }
    }
}

void showAll(listNegara L){
    if(first(L)==NULL){
        cout<<"List Negara Kosong"<<endl;
    }else{
        int i;
        adrKGroup k;
        adrNegara n=first(L);
        while(next(n)!=first(L)){
            cout<<info(n).namaNegara<<": \n";
            k=first(firstKGroup(n));
            i=1;
            if(first(firstKGroup(n))==NULL){
                cout<<"List Concert Kosong"<<endl;
            }else{
                while(k!=NULL){
                    cout<<i<<". "<<info(k).namaGroup<<" - "<<info(k).personel<<" personel - "<<info(k).tour<<endl;
                    k=next(k);
                    i++;
                }
            }
            n=next(n);
            cout<<endl;
        }
        cout<<info(n).namaNegara<<": \n";
        k=first(firstKGroup(n));
        if(first(firstKGroup(n))==NULL){
            cout<<"List Concert Kosong"<<endl;
        }else{
            while(k!=NULL){
                cout<<i<<". "<<info(k).namaGroup<<" - "<<info(k).personel<<"orang - "<<info(k).tour<<endl;
                k=next(k);
            }
        }
    }
}



adrKGroup searchKGroup(listNegara L, string namaNegara, string namaKGroup){
    adrNegara n=searchNegara(L,namaNegara);
    if(first(L)==NULL||n==NULL){
        return NULL;
    }else{
        adrKGroup k=first(firstKGroup(n));
        while(info(k).namaGroup!=namaKGroup&&next(k)!=NULL){
            k=next(k);
        }
        if(info(k).namaGroup==namaKGroup){
            return k;
        }else{
            return NULL;
        }
    }
}

void deleteKGroup(listNegara &L, string namaNegara){
    adrNegara n = searchNegara(L,namaNegara);
    listKGroup L1;
    if(n!=NULL){
        first(firstKGroup(n))=next(first(firstKGroup(n)));
    }
}

int jumlahKGroup(listNegara L, string namaNegara){
    int total=0;
    adrNegara n=searchNegara(L,namaNegara);
    adrKGroup k=first(firstKGroup(n));
    while(k!=NULL){
        total++;
        k=next(k);
    }
    return total;
}
