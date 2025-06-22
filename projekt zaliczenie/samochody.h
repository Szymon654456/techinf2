#ifndef SAMOCHODY_H
#define SAMOCHODY_H

#include <string>
#include <vector>

// Struktura opisująca samochód
struct Samochod {
    std::string marka;
    std::string model;
    int przebieg;
};

// Globalna lista wszystkich samochodów
extern std::vector<Samochod> baza;

// Deklaracje funkcji
void wczytaj();
void zapisz();
void dodaj();
void edytuj();
void usun();
void wyswietl();

#endif
