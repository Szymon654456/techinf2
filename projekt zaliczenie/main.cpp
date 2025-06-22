#include <iostream>
#include "samochody.h"
using namespace std;

int main() {
    wczytaj(); // Wczytaj dane z pliku przy starcie programu

    int wybor;
    do {
        // Menu użytkownika
        cout << "\n=== MENU ===\n";
        cout << "1. Dodaj samochod\n";
        cout << "2. Edytuj samochod\n";
        cout << "3. Usun samochod\n";
        cout << "4. Wyswietl liste\n";
        cout << "5. Zapisz dane\n";
        cout << "0. Wyjscie\n";
        cout << "Wybierz opcje: ";

        cin >> wybor;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Nieprawidlowa opcja! Sprobuj ponownie.\n";
            continue;
        }

        switch (wybor) {
            case 1: dodaj(); break;
            case 2: edytuj(); break;
            case 3: usun(); break;
            case 4: wyswietl(); break;
            case 5: zapisz(); cout << "Dane zapisane.\n"; break;
            case 0: cout << "Zamykanie programu...\n"; break;
            default: cout << "Nieznana komenda!\n"; break;
        }

    } while (wybor != 0);

    zapisz(); // Zapisz dane przed wyjściem
    return 0;
}
