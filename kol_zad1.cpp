#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Mapa {
    int wysokosc;
    int szerokosc;
    std::vector<std::string> plansza;
};

Mapa wczytajMape(std::string sciezkaDoPliku) {
    Mapa nowaMapa;
    nowaMapa.wysokosc = 0;
    nowaMapa.szerokosc = 0;

    std::ifstream plik(sciezkaDoPliku);

    if (!plik.is_open()) {
        std::cerr << "Blad: Nie mozna otworzyc pliku: " << sciezkaDoPliku << std::endl;
        return nowaMapa;
    }

    std::string linia;
    while (std::getline(plik, linia)) {
        if (!linia.empty() && linia.back() == '\r') {
            linia.pop_back();
        }
        nowaMapa.plansza.push_back(linia);
    }

    plik.close();

    if (!nowaMapa.plansza.empty()) {
        nowaMapa.wysokosc = nowaMapa.plansza.size();
        nowaMapa.szerokosc = nowaMapa.plansza[0].length();
    }

    return nowaMapa;
}

int main() {
    std::string nazwaPliku = "map_1.txt";
    
    Mapa pirackaMapa = wczytajMape(nazwaPliku);

    if (pirackaMapa.wysokosc > 0) {
        std::cout << "Udalo sie wczytac plik: " << nazwaPliku << std::endl;
        std::cout << "Wymiary: " << pirackaMapa.szerokosc << "x" << pirackaMapa.wysokosc << std::endl;
        
        std::cout << "Pierwsza linia mapy: " << pirackaMapa.plansza[0] << std::endl;
    } else {
        std::cout << "Mapa jest pusta lub blad pliku." << std::endl;
    }

    return 0;
}
