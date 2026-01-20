#include <iostream>
#include <vector>

struct Map {
    int width;      
    int height;     
    char** TheMap;  
};

int policzSkarbyWPromieniu(Map mapa, int x, int y) {
    int licznikSkarbow = 0;

    for (int wiersz = x - 2; wiersz <= x + 2; ++wiersz) {
        for (int kolumna = y - 2; kolumna <= y + 2; ++kolumna) {
            
            if (wiersz >= 0 && wiersz < mapa.height && 
                kolumna >= 0 && kolumna < mapa.width) {
                
                char znak = mapa.TheMap[wiersz][kolumna];
                
                if (znak == 'x' || znak == 'X') {
                    licznikSkarbow++;
                }
            }
        }
    }

    return licznikSkarbow;
}

void zwolnijPamiec(Map& mapa) {
    for (int i = 0; i < mapa.height; ++i) {
        delete[] mapa.TheMap[i];
    }
    delete[] mapa.TheMap;
}

int main() {
  
    Map mojaMapa;
    mojaMapa.width = 10;
    mojaMapa.height = 10;

    mojaMapa.TheMap = new char*[mojaMapa.height];
    for (int i = 0; i < mojaMapa.height; ++i) {
        mojaMapa.TheMap[i] = new char[mojaMapa.width];
        // Wypełnijmy mapę wodą '~'
        for (int j = 0; j < mojaMapa.width; ++j) {
            mojaMapa.TheMap[i][j] = '~';
        }
    }

    mojaMapa.TheMap[5][5] = 'x'; 
    mojaMapa.TheMap[4][5] = 'x'; 
    mojaMapa.TheMap[3][3] = 'x'; 
    mojaMapa.TheMap[2][2] = 'x'; 

    int celWiersz = 5;
    int celKolumna = 5;

    std::cout << "Skanowanie obszaru wokol (" << celWiersz << ", " << celKolumna << ")..." << std::endl;
    
    int znalezione = policzSkarbyWPromieniu(mojaMapa, celWiersz, celKolumna);

    std::cout << "Liczba znalezionych skarbow: " << znalezione << std::endl;
   
    zwolnijPamiec(mojaMapa);

    return 0;
}
