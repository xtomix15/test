#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

void normalizeAndSum(const string& path) {
    ifstream file(path);

    map<string, int> cargo;
    string line;

    while (getline(file, line)) {
        size_t delim = line.find(';');
        if (delim == string::npos) continue;

        string namePart = line.substr(0, delim);
        string qtyPart = line.substr(delim + 1);
        string cleanName = "";


        for (char c : namePart) {
            if (!isspace(c)) {
                cleanName += tolower(c);
            }
        }

        if (!cleanName.empty()) {
           
            cargo[cleanName] += stoi(qtyPart);
        }
    }
    file.close();

    ofstream outFile("cargo_clear.txt");
    for (auto const &entry : cargo) {
        outFile << entry.first << ";" << entry.second << endl;
    }
    outFile.close();
}

int main() {
    normalizeAndSum("cargo.txt");
    return 0;
}
