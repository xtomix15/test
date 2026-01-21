#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void DecodeAndPrint(const string& coded) {

    cout << "Wiadomosc zakodowana:" << endl;
    cout << coded << endl;

    cout << "Wiadomosc zdekodowana:" << endl;
    
    stringstream ss(coded);
    string token;

 
    while (ss >> token) {
        char type = token[0];

        if (type == 'L') {
           
            int val = stoi(token.substr(1));
            cout << (char)('A' + val);
        } else if (type == 'N') {
            
            cout << token.substr(1);
        } else if (type == 'X') {
          
            cout << ' ';
        }
    }
    cout << endl;
}
