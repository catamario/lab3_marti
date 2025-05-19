#ifndef ATM_H
#define ATM_H

#include "../colectie/Colectie.h"
#include "../tranzactie/Tranzactie.h"
#include "../multime/MultimeOrdonata.h"

class ATM {
private:
    Colectie<int> colectie;                           // Colectie de bancnote
    MultimeOrdonata<Tranzactie> tranzactii;           // Multime ordonata generic, reprezentare inlantuita
    int nextID = 1;

public:
    ATM();

    void adaugaBancnote(int valoare, int numar);      // Adauga bancnote in colectie
    void retrageBani(int suma, const std::string& data); // Creeaza si insereaza o tranzactie
    void afiseazaTranzactii() const;                  // Afiseaza tranzactiile in ordinea curenta
    void sorteazaTranzactii(int criteriu);            // Refactorizeaza tranzactii ordonate dupa criteriu
};

#endif
