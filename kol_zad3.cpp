#include <iostream>

using namespace std;

struct Map {
    int width;      
    int height;    
    char** TheMap;  
};

struct planeta {
    Map Mapa;           
    int IleSkarbow;     
    int ID;            
    planeta* wsk_nst;  
};

int liczSkarby(Map mapa, int x, int y) {
    int licznik = 0; 

    for (int i = x - 2; i <= x + 2; i++) {
        for (int j = y - 2; j <= y + 2; j++) {
            if (i >= 0 && i < mapa.height && j >= 0 && j < mapa.width) {              
                char znak = mapa.TheMap[i][j];
                if (znak == 'x' || znak == 'X') {
                    licznik++; 
                }
            }
        }
    }

    return licznik;
}

void wypiszDobrePlanety(planeta* pierwsza) {
    
    if (pierwsza == NULL) {
        return;
    }
    planeta* aktualna = pierwsza; 

    do {
       
        if (aktualna->IleSkarbow > 15) {
            cout << "Planeta o ID: " << aktualna->ID << " ma duzo skarbow!" << endl;
        }
        aktualna = aktualna->wsk_nst;
    } while (aktualna != pierwsza); 
}

int main() {
 
    cout << "--- TEST ZADANIA 2 ---" << endl;
    Map mojaMapa;
    mojaMapa.width = 10;
    mojaMapa.height = 10;

   
    mojaMapa.TheMap = new char* [10];
    for (int i = 0; i < 10; i++) {
        mojaMapa.TheMap[i] = new char[10];
        for (int j = 0; j < 10; j++) {
            mojaMapa.TheMap[i][j] = '~'; 
        }
    }
    mojaMapa.TheMap[5][5] = 'x'; 
    mojaMapa.TheMap[4][5] = 'X'; 
    mojaMapa.TheMap[3][3] = 'x'; 
    mojaMapa.TheMap[1][1] = 'x';

    int wynik = liczSkarby(mojaMapa, 5, 5);
    cout << "Liczba skarbow wokol (5,5): " << wynik << endl;
 
    cout << endl << "--- TEST ZADANIA 3 ---" << endl;
    planeta p1, p2, p3;

  
    p1.ID = 1;
    p1.IleSkarbow = 10;

    p2.ID = 2;
    p2.IleSkarbow = 100; 

    p3.ID = 3;
    p3.IleSkarbow = 20; 
    p1.wsk_nst = &p2; 
    p2.wsk_nst = &p3; 
    p3.wsk_nst = &p1; 

    wypiszDobrePlanety(&p1);

    return 0;
}
