#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Skrzynia {
    string nazwa;
    int id;
    int klucz;
};

vector<Skrzynia> ListaSkarbow(string sciezkaDoPliku) {
    vector<Skrzynia> lista;
    ifstream plik(sciezkaDoPliku);

    if (!plik.is_open()) {
        return lista;
    }

    string smiec;
    getline(plik, smiec);
    getline(plik, smiec);

    string n;
    int i, k;

    while (plik >> n >> i >> k) {
        Skrzynia nowaSkrzynia;
        nowaSkrzynia.nazwa = n;
        nowaSkrzynia.id = i;
        nowaSkrzynia.klucz = k;
        lista.push_back(nowaSkrzynia);
    }

    plik.close();
    return lista;
}

vector<int> ListaNiebezpiecznychSkarbow(vector<Skrzynia> wszystkieSkrzynie) {
    vector<int> idPulapek;

    for (int i = 0; i < wszystkieSkrzynie.size(); i++) {
        int id = wszystkieSkrzynie[i].id;
        int klucz = wszystkieSkrzynie[i].klucz;

        if (id != 0) {
            if (klucz % id == 0) {
                idPulapek.push_back(id);
            }
        }
    }

    return idPulapek;
}

int main() {
    string nazwaPliku = "ListaSkarbow.txt";

    vector<Skrzynia> mojeSkrzynie = ListaSkarbow(nazwaPliku);
    vector<int> niebezpieczneID = ListaNiebezpiecznychSkarbow(mojeSkrzynie);

    for (int i = 0; i < niebezpieczneID.size(); i++) {
        cout << niebezpieczneID[i] << " ";
    }

    return 0;
}
