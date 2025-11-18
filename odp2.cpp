zad 1;
#include <iostream>
using namespace std;

int main() {
	int liczba;
	cout << "Podaj liczbe: ";
	cin >> liczba;

	int l5 = (liczba % 5 == 0);
	int l7 = (liczba % 7 == 0);
	if (liczba > 0 && liczba < 1000000) {
		if (l5 && l7) {
			cout << "Aaaa Grrrr";
		}
		else if (l5) {
			cout << "Aaaa";
		}
		else if (l7) {
			cout << "Grrrr";
		}
		else {
			cout << "...";
		}
	}
	return 0;
}


zad 2;

#include <iostream>
#include <string>
#include <cctype>

using namespace std;
int main() {

    string radar="1239~23wa1";
    int n=radar.length();
    int x=0;

    for(int i=0;i<n;i++) {
        x=0;
        if(isdigit(radar[i])) {
            x=radar[i]-48;
        }
        if(radar[i]=='~') {
            x=10;
        }
        for(int j=0;j<x;j++) {
            cout<<"#";
        }
        if (x!=0) {
            cout<<endl;
        }
    }

}


zad 3;

#include <iostream>
using namespace std;

int main() {
    int X;
    cin >> X;

    int mid = X / 2;   // środkowy wiersz

    // GÓRNA POŁOWA (łącznie z wierszem środkowym)
    for (int i = 0; i <= mid; i++) {

        // spacje
        for (int s = 0; s < mid - i; s++) {
            cout << " ";
        }

        // ile znaków w wierszu
        int count = 2 * i + 1;

        for (int j = 0; j < count; j++) {

            if (i == 0 && j == count / 2) {
                cout << "N";                    // góra
            }
            else if (i == mid && j == 0) {
                cout << "W";                    // lewo środek
            }
            else if (i == mid && j == count - 1) {
                cout << "E";                    // prawo środek
            }
            else {
                cout << "#";                    // normalny znak
            }
        }
        cout << endl;
    }

    // DOLNA POŁOWA
    for (int i = mid - 1; i >= 0; i--) {

        // spacje
        for (int s = 0; s < mid - i; s++) {
            cout << " ";
        }

        // ile znaków w wierszu
        int count = 2 * i + 1;

        for (int j = 0; j < count; j++) {

            if (i == 0 && j == count / 2) {
                cout << "S";                    // dół
            }
            else {
                cout << "#";
            }
        }
        cout << endl;
    }

    return 0;
}

zad 4;
#include <iostream>
using namespace std;

int main() {

    int x;
    int y;

    char c=0;
    while (c != '@') {
        cin >> c;
        if (c == 'N') {
            y++;
        }
        else if (c == 'S') {
            y--;
        }
        else if (c == 'E') {
            x++;
        }
        else if (c == 'W') {
            x--;
        }
    }
    cout << x << " " << y;
}

zad 5;

#include <iostream>
#include <cctype>
using namespace std;

int main() {

    string radar="12003009~23wa1";
    int s=radar.length();
    int max=-1;
    int locmax=-1;
    int min=10;
    int locmin=-1;

    for(int i=0;i<s;i++) {
        if(isdigit(radar[i])) {

            int digit = radar[i]-'0';

            if (digit < min) {
                min = digit;
                locmin = i;
            }

            if (digit > max) {
                max = digit;
                locmax = i;
            }
        }
    }
    cout<<"min poziom: "<<min<<", pozycja "<<locmin<<endl;
    cout<<"max poziom: "<<max<<", pozycja "<<locmax;
}
