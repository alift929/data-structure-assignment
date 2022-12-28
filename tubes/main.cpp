#include "tubes.h"
#include <iostream>

using namespace std;

int main()
{
    listNegara LN;
    listKGroup LK;
    createListNegara(LN);
    createListKGroup(LK);

    insertNegara(LN,newNegara("Indonesia","Jakarta",2022));
    insertNegara(LN,newNegara("Japan","Tokyo",2023));
    insertNegara(LN,newNegara("South Korea","Seoul",2023));
    insertNegara(LN,newNegara("Singapore","Singapore",2024));
    insertNegara(LN,newNegara("Philippines","Manila",2022));
    insertNegara(LN,newNegara("Vietnam","Hanoi",2023));

    insertKGroup(LK,newKGroup("Blackpink",4,"Born Pink"));
    insertKGroup(LK,newKGroup("Seventeen",13,"be The Sun"));
    insertKGroup(LK,newKGroup("ITZY",5,"World Tour"));
    insertKGroup(LK,newKGroup("MAMAMOO",4,"My Con World Tour"));

    connectKGroup(LN,LK,"Indonesia","ITZY");
    connectKGroup(LN,LK,"Philippines","ITZY");
    connectKGroup(LN,LK,"Singapore","ITZY");
    connectKGroup(LN,LK,"Indonesia","Blackpink");
    connectKGroup(LN,LK,"Singapore","Blackpink");
    connectKGroup(LN,LK,"Japan","Blackpink");
    connectKGroup(LN,LK,"South Korea","Blackpink");
    connectKGroup(LN,LK,"Singapore","MAMAMOO");
    connectKGroup(LN,LK,"Philippines","MAMAMOO");

    deleteKGroup(LN,"Japan");

    showNegara(LN);
    showAll(LN);

    cout<<endl<<jumlahKGroup(LN,"Singapore");

    return 0;
}
