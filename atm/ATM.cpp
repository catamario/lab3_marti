#include "ATM.h"
#include <iostream>

ATM::ATM() {}

void ATM::adaugaBancnote(int valoare, int numar) {
    for (int i = 0; i < numar; i++) {
        colectie.add(valoare);  // adauga bancnote in colectie
    }
}

void ATM::retrageBani(int suma, const std::string& data) {
    std::map<int, int> bancnoteFolosite;
    int sumaRamasa = suma;

    for (int i = colectie.getSize() - 1; i >= 0; i--) {
        int val = colectie.getAt(i);
        if (sumaRamasa >= val) {
            int numarNecesare = sumaRamasa / val;
            bancnoteFolosite[val] = numarNecesare;
            sumaRamasa -= numarNecesare * val;
        }
    }

    if (sumaRamasa == 0) {
        for (const auto& p : bancnoteFolosite) {
            for (int i = 0; i < p.second; i++) {
                colectie.remove(p.first);  // sterge bancnote din colectie
            }
        }
        Tranzactie t(1, suma, bancnoteFolosite, data);  // creaza tranzactie
        tranzactii.insert(t);  // adauga tranzactia in set
        std::cout << "Retragere reusita!\n";
    } else {
        std::cout << "Retragere esuata! Nu sunt suficiente bancnote.\n";
    }
}

void ATM::afiseazaTranzactii() const {
    std::cout << "Tranzactii:\n";
    for (const auto& tranzactie : tranzactii) {
        tranzactie.afiseaza();  // afiseaza tranzactiile
    }
}

void ATM::sorteazaTranzactii() {
    // Setul este deja ordonat, deci nu mai trebuie sa facem nimic
}
