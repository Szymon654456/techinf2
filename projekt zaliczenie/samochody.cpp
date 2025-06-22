#include "samochody.h"
#include <iostream>
#include <fstream>
using namespace std;

// Lista samochodów – dostępna globalnie
vector<Samochod> baza;

// Wczytuje dane z pliku tekstowego do listy
void wczytaj() {
    baza.clear();
    ifstream plik("baza.txt");
    Samochod s;
    while (plik >> s.marka >> s.model >> s.przebieg)
        baza.push_back(s);
    plik.close();
}

// Zapisuje aktualną listę do pliku (nadpisuje całość)
void zapisz() {
    ofstream plik("baza.txt");
    for (auto& s : baza)
        plik << s.marka << " " << s.model << " " << s.przebieg << "\n";
    plik.close();
}

// Dodaje nowy samochód
void dodaj() {
    Samochod s;
    cout << "Podaj marke: ";
    cin >> s.marka;
    cout << "Podaj model: ";
    cin >> s.model;

    cout << "Podaj przebieg (liczba): ";
    while (!(cin >> s.przebieg)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Bledny przebieg! Sprobuj ponownie: ";
    }

    baza.push_back(s);
    cout << "Samochod dodany.\n";
}

// Edytuje samochód o podanym indeksie
void edytuj() {
    int i;
    cout << "Podaj index samochodu do edycji: ";
    if (!(cin >> i)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Nieprawidlowy indeks!\n";
        return;
    }

    if (i >= 0 && i < baza.size()) {
        cout << "Nowa marka: ";
        cin >> baza[i].marka;
        cout << "Nowy model: ";
        cin >> baza[i].model;
        cout << "Nowy przebieg: ";
        while (!(cin >> baza[i].przebieg)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Bledny przebieg! Sprobuj ponownie: ";
        }
        cout << "Dane zaktualizowane.\n";
    } else {
        cout << "Nieprawidlowy indeks!\n";
    }
}

// Usuwa samochód z listy
void usun() {
    int i;
    cout << "Podaj index samochodu do usuniecia: ";
    if (!(cin >> i)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Nieprawidlowy indeks!\n";
        return;
    }

    if (i >= 0 && i < baza.size()) {
        baza.erase(baza.begin() + i);
        cout << "Samochod usuniety.\n";
    } else {
        cout << "Nieprawidlowy indeks!\n";
    }
}

// Wyświetla listę samochodów
void wyswietl() {
    if (baza.empty()) {
        cout << "Brak danych do wyswietlenia.\n";
        return;
    }

    for (int i = 0; i < baza.size(); ++i) {
        cout << "[" << i << "] "
             << "Marka: " << baza[i].marka
             << " | Model: " << baza[i].model
             << " | Przebieg: " << baza[i].przebieg << " km\n";
    }
}
