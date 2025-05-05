#ifndef ATM_H
#define ATM_H

#include "../colectie/Colectie.h"
#include "../tranzactie/Tranzactie.h"
#include <set>  // pentru set

class ATM {
private:
    Colectie<int> colectie;  // Colectie de bancnote
    std::set<Tranzactie> tranzactii;  // Set de tranzactii ordonate

public:
    ATM();

    void adaugaBancnote(int valoare, int numar);

    void retrageBani(int suma, const std::string& data);

    void afiseazaTranzactii() const;

    void sorteazaTranzactii();
};

#endif
