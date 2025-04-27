#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Stack.h"
#include "IntStack.h"
#include "Queue.h"
#include "ToONP.h"
#include "ONPConv.h"
#include "ONPCounter.h"




using namespace std;



int main()
{
   int liczbaDziałań;
    cin >> liczbaDziałań;
    for (int i = 0; i < liczbaDziałań; i++) {
        ONPConv ONPConv;
        char znak[20];
        while (cin >> znak && (znak[0] != '.')) {
            ONPConv.addChar(znak);
        }

        ONPConv.endParse();

        ONPConv.print();

        ONPCounter ONPCounter;
        cout << endl;

        ONPCounter.fillQueue(ONPConv.getOutput());
        
        ONPConv.destroy();

        int wynik;
        wynik =  ONPCounter.count();
 
        if (ONPCounter.is_flag()) {
            cout << wynik;
            cout << endl;
        }
        
    }

 

    
    //ONPConv proba;
    //char znak[20];
    //while (cin >> znak && (znak[0] != '.')) {
    //    proba.addChar(znak);
    //}
    //char wyjscie[20];

    //proba.print();
    //cout << endl;
    //// Jak chcesz wypisać ostatni znak czyli dequeue to musisz skopiowac pamiec i wtedy to wypisac
    //std::strcpy(wyjscie, (*proba.getOutput()).dequeue());
    //cout << wyjscie;
    //cout << endl;
    //proba.print();

   

    return 0;
}

