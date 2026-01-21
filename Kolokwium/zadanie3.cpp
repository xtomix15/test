#include <iostream>
#include <string>
#include <cctype>

using namespace std;

struct Crew {
    int id;
    string name;
    string role;
    Crew* next;
};

void PrintIDsContainingLetter(Crew* any, char letter) {
    if (any == nullptr) return;

    Crew* current = any;
    char target = tolower(letter);

    do {
        bool found = false;
        for (char c : current->name) {
            if (tolower(c) == target) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << current->id << endl;
        }

        current = current->next;
    } while (current != any);
}
