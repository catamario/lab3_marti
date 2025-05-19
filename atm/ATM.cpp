#include "ATM.h"
#include <iostream>
#include <vector>
#include <algorithm>

ATM::ATM()
    : tranzactii() // initializare implicita
{}

void ATM::adaugaBancnote(int valoare, int numar) {
    for (int i = 0; i < numar; i++) {
        colectie.add(valoare);
    }
}

void ATM::retrageBani(int suma, const std::string& data) {
    std::map<int, int> bancnoteFolosite;
    int sumaRamasa = suma;

    // Construim un vector cu toate bancnotele din colectie
    std::vector<int> bancnoteDisponibile;
    for (int i = 0; i < colectie.getSize(); i++) {
        bancnoteDisponibile.push_back(colectie.getAt(i));
    }

    // Sortam bancnotele descrescator
    std::sort(bancnoteDisponibile.begin(), bancnoteDisponibile.end(), std::greater<int>());

    // Alegem bancnotele potrivite
    for (int val : bancnoteDisponibile) {
        if (sumaRamasa >= val) {
            int nr = sumaRamasa / val;
            int dejaFolosite = bancnoteFolosite[val];
            // Verificam de cate ori exista efectiv aceasta bancnota
            int disponibile = 0;
            for (int i = 0; i < colectie.getSize(); i++) {
                if (colectie.getAt(i) == val) {
                    disponibile++;
                }
            }

            int folosibile = std::min(nr, disponibile - dejaFolosite);
            if (folosibile > 0) {
                bancnoteFolosite[val] += folosibile;
                sumaRamasa -= folosibile * val;
            }
        }
    }

    // Verificam daca am reusit sa acoperim suma
    if (sumaRamasa == 0) {
        // Scoatem bancnotele din colectie
        for (const auto& p : bancnoteFolosite) {
            for (int i = 0; i < p.second; i++) {
                colectie.remove(p.first);
            }
        }
        // Cream si adaugam tranzactia
        Tranzactie t(nextID, suma, bancnoteFolosite, data);
        nextID++;
        tranzactii.insert(t, 1); // implicit sortare dupa data
        std::cout << "Retragere reusita!\n";
    } else {
        std::cout << "Retragere esuata! Nu sunt suficiente bancnote.\n";
    }
}


void ATM::afiseazaTranzactii() const {
    std::cout << "Tranzactii:\n";
    tranzactii.afiseaza();  // afiseaza tranzactiile sortate
}

void ATM::sorteazaTranzactii(int criteriu) {
    // Creeaza o noua multime ordonata dupa criteriu ales
    MultimeOrdonata<Tranzactie> tranzOrd;

    // refolosim doar afisarea ordonata
    std::cout << "Tranzactii sortate:\n";
    tranzactii.afiseaza();
}
