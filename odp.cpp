#include <iostream>
#include <cstdlib>

using namespace std;
// zad 1 dodawnie i odejmowanie 
int main() {
    int poprawne = 0; // licznik poprawnych odpowiedzi
    char decyzja;     // decyzja o powtórzeniu testu

    do {
        // losowanie dwóch liczb z zakresu <-100, 100>
        int a = rand() % 201 - 100;
        int b = rand() % 201 - 100;

        // losowanie typu działania: 0 - suma, 1 - różnica
        int typ = rand() % 2;

        int wynik;
        int odpowiedz;

        if (typ == 0) {
            wynik = a + b;
            cout << "Pytanie: " << a << " + " << b << " = ?" << endl;
        }
        else {
            wynik = a - b;
            cout << "Pytanie: " << a << " - " << b << " = ?" << endl;
        }

        cout << "Odpowiedz: ";
        cin >> odpowiedz;

        if (odpowiedz == wynik) {
            cout << "Brawo, udalo Ci sie odpowiedziec na pytanie starozytnej cywilizacji!" << endl;
            poprawne++;
        }
        else {
            cout << "Niestety, to bledna odpowiedz. Poprawny wynik to " << wynik << "." << endl;
        }

        cout << "\nCzy chcesz sprobowac ponownie? (t/n): ";
        cin >> decyzja;

        cout << endl;

    } while (decyzja == 't' || decyzja == 'T');

    cout << "Liczba poprawnych odpowiedzi: " << poprawne << endl;
    cout << "Dziekuje za udzial w treningu!" << endl;

    return 0;
}





// ZAD 2 szukanie skarbu w rzece
#include <iostream>
#include <string>
using namespace std;

int main() {
    string strumien;
    cout << "Podaj strumien: ";
    cin >> strumien;

    int dlugosc = strumien.length();
    bool odTylu = false; // czy występuje 'B' na końcu
    int liczbaSkarbow = 0;

    // Sprawdzenie, czy na końcu jest 'B'
    if (strumien.back() == 'B') {
        odTylu = true;
        strumien.pop_back(); // usuń 'B', bo nie jest częścią strumienia
        dlugosc--;
    }

    cout << endl;

    // Jeśli rzeka zaczyna się od końca, segmenty liczymy od tyłu
    if (odTylu) {
        int segment = 1;
        for (int i = dlugosc - 1; i >= 0; i--) {
            if (strumien[i] == '*') {
                cout << "Skarb jest w segmencie " << segment << endl;
                liczbaSkarbow++;
            }
            segment++;
        }
    }
    else {
        for (int i = 0; i < dlugosc; i++) {
            if (strumien[i] == '*') {
                cout << "Skarb jest w segmencie " << i + 1 << endl;
                liczbaSkarbow++;
            }
        }
    }

    cout << "\nW rzece jest " << liczbaSkarbow << " skarbow." << endl;
    return 0;
}



// ZAD 3 liczenie napraw

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Podaj liczbe napraw: ";
    cin >> n;

    // Pierwsze dwie naprawy
    int poprzednia1 = 1, poprzednia2 = 2;
    int koszt = 0;
    int suma = 0;

    for (int i = 1; i <= n; i++) {
        // Dla pierwszych dwóch napraw koszt ustalony z góry
        if (i == 1)
            koszt = poprzednia1;
        else if (i == 2)
            koszt = poprzednia2;
        else
            koszt = poprzednia1 + poprzednia2; // jak w ciągu Fibonacciego

        cout << "Cena [" << i << "] = " << koszt << " [1 - tak, 0 - nie]: ";

        int decyzja;
        cin >> decyzja;

        if (decyzja == 1)
            suma += koszt;

        // przesuwamy wartości jak w fibonaccim
        poprzednia1 = poprzednia2;
        poprzednia2 = koszt;
    }

    cout << "\nLaczna cena wybranych napraw: " << suma << endl;

    return 0;
}


// ZAD 4 rysownie dywanu

#include <iostream>
using namespace std;

int main() {
    char kolor1, kolor2, obram;
    int szer, dl;

    cout << "Kolor 1: ";
    cin >> kolor1;
    cout << "Kolor 2: ";
    cin >> kolor2;
    cout << "Szerokosc: ";
    cin >> szer;
    cout << "Dlugosc: ";
    cin >> dl;
    cout << "Rodzaj obszycia: ";
    cin >> obram;

    // wymiary w znakach (każda kratka to 2x2)
    int wysokosc = dl * 2;
    int szerokosc = szer * 2;

    // drukuj górną ramkę
    for (int i = 0; i < szerokosc + 2; i++) cout << obram;
    cout << endl;

    // drukuj środek obrusu
    for (int i = 0; i < wysokosc; i++) {
        cout << obram; // lewa ramka
        for (int j = 0; j < szerokosc; j++) {
            // naprzemienne kolory jak w szachownicy
            if (((i / 2) + (j / 2)) % 2 == 0)
                cout << kolor1;
            else
                cout << kolor2;
        }
        cout << obram << endl; // prawa ramka
    }

    // drukuj dolną ramkę
    for (int i = 0; i < szerokosc + 2; i++) cout << obram;
    cout << endl;

    return 0;
}


// Zad 5 wyscig slimakow

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL)); // inicjalizacja generatora losowego

    const int META = 50;
    const int LICZBA_SLIMAKOW = 5;
    int pozycja[LICZBA_SLIMAKOW] = { 0 };
    int tura = 0;
    bool koniec = false;

    while (!koniec) {
        tura++;
        cout << "R[" << tura << "]: ";
        for (int i = 0; i < LICZBA_SLIMAKOW; i++) {
            int krok = rand() % 4; // los od 0 do 3
            pozycja[i] += krok;
            cout << "T[" << i + 1 << "] " << pozycja[i] << "/" << META << "  ";
            if (pozycja[i] >= META) koniec = true;
        }
        cout << endl;
    }

    // znajdź zwycięzcę
    int zwyciezca = 0;
    for (int i = 1; i < LICZBA_SLIMAKOW; i++) {
        if (pozycja[i] > pozycja[zwyciezca])
            zwyciezca = i;
    }

    cout << "\nWygral slimak [" << zwyciezca + 1 << "]!" << endl;

    return 0;
}

// ZAD 6  kod cezara i rozszyfrowanie i szukanie litery

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string tekst;
    cout << "Podaj wiadomosc zaszyfrowana:\n";
    getline(cin, tekst);

    int licznik[26] = {0};

    // zliczanie wystąpień liter
    for (char c : tekst) {
        if (isalpha(c)) {
            licznik[tolower(c) - 'a']++;
        }
    }

    // znajdź najczęściej występującą literę
    int maxIndex = 0;
    for (int i = 1; i < 26; i++) {
        if (licznik[i] > licznik[maxIndex])
            maxIndex = i;
    }

    char najczestsza = 'a' + maxIndex;
    int przesuniecie = (najczestsza - 'a'); // przesunięcie względem 'a'

    cout << "\nNajczesciej wystepuje litera: " << najczestsza 
         << "\nPrzesuniecie to: " << przesuniecie << endl;

    // --- DESZYFROWANIE ---
    string odszyfrowane = "";
    for (char c : tekst) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char nowa = ((c - base - przesuniecie + 26) % 26) + base;
            odszyfrowane += nowa;
        } else {
            odszyfrowane += c; // spacje i inne znaki bez zmian
        }
    }

    cout << "\nOdszyfrowana wiadomosc:\n" << odszyfrowane << endl;

    return 0;
}


// ZAD 7 okrzyki w rundach
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Podaj liczbe rund: ";
    cin >> n;

    long long a = 1, b = 1, c;

    cout << "Runda 1: " << a << " -> ";
    if (a % 3 == 0 && a % 5 == 0)
        cout << "Aaaa Grrrrr!" << endl;
    else if (a % 3 == 0)
        cout << "Aaaa!" << endl;
    else if (a % 5 == 0)
        cout << "Grrrrr!" << endl;
    else
        cout << "(cisza)" << endl;

    cout << "Runda 2: " << b << " -> ";
    if (b % 3 == 0 && b % 5 == 0)
        cout << "Aaaa Grrrrr!" << endl;
    else if (b % 3 == 0)
        cout << "Aaaa!" << endl;
    else if (b % 5 == 0)
        cout << "Grrrrr!" << endl;
    else
        cout << "(cisza)" << endl;

    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;

        cout << "Runda " << i << ": " << c << " -> ";
        if (c % 3 == 0 && c % 5 == 0)
            cout << "Aaaa Grrrrr!" << endl;
        else if (c % 3 == 0)
            cout << "Aaaa!" << endl;
        else if (c % 5 == 0)
            cout << "Grrrrr!" << endl;
        else
            cout << "(cisza)" << endl;
    }

    return 0;
}


// ZAD 8 gra losowa 
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int N = 6;
    int plansza[N][N] = {0};
    int zajete = 0;
    int runda = 0;
    int punkty = 0;

    srand(time(NULL));

    while (zajete < N * N) {
        runda++;
        int k1 = rand() % 6 + 1; // 1–6
        int k2 = rand() % 6 + 1; // 1–6

        cout << "Runda " << runda << "\n";
        cout << k1 << " " << k2 << endl;

        // Indeksy tablicy (od 0)
        int x = k1 - 1;
        int y = k2 - 1;

        if (plansza[x][y] == 0) {
            plansza[x][y] = runda;
            cout << "Pkt: 0 (pole losowane po raz pierwszy)" << endl;
            zajete++;
        } else {
            punkty++;
            cout << "Pkt: 1 (pole bylo juz wczesniej zajete)" << endl;
        }

        // wyświetlenie planszy
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (plansza[i][j] == 0)
                    cout << setw(2) << "x";
                else
                    cout << setw(2) << plansza[i][j];
            }
            cout << endl;
        }

        cout << endl;
    }

    cout << "--------------------------------\n";
    cout << "Koniec gry! Wszystkie pola zajete.\n";
    cout << "Suma zdobytych punktow: " << punkty << endl;

    return 0;
}
