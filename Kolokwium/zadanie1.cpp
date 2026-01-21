#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <cctype>

using namespace std;

int main() {
    ifstream file("tawerna.txt");
    map<string, int> counts;
    string line;

    while (getline(file, line)) {
        size_t delimPos = line.find(" : ");
        if (delimPos == string::npos) continue;

        string name = line.substr(0, delimPos);
        string content = line.substr(delimPos + 3);

        // Zamiana znakow interpunkcyjnych na spacje i liter na male
        for (char &c : content) {
            if (isalpha(c)) {
                c = tolower(c);
            } else {
                c = ' ';
            }
        }

        stringstream ss(content);
        string word;
        while (ss >> word) {
            if (word == "rum" || word == "napoj" || word == "soczek") {
                counts[name]++;
            }
        }
    }

    file.close();

    string winner;
    int maxPoints = -1;

    for (auto const &entry : counts) {
        if (entry.second > maxPoints) {
            maxPoints = entry.second;
            winner = entry.first;
        }
    }

    cout << winner << endl;
    cout << maxPoints << endl;

    return 0;
}
