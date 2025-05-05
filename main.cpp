#include <iostream>
#include <string>
#include "atm/ATM.h"  // include header-ul pentru ATM

int main() {
    ATM atm;  // instantiaza un obiect ATM

    // Meniu principal
    while (true) {
        std::cout << "\nMeniu ATM:\n";
        std::cout << "1. Adauga bancnote\n";
        std::cout << "2. Retrage bani\n";
        std::cout << "3. Afiseaza tranzactii\n";
        std::cout << "4. Sorteaza tranzactii\n";
        std::cout << "5. Iesire\n";
        std::cout << "Alege optiunea: ";

        int optiune;
        std::cin >> optiune;

        if (optiune == 1) {
            int valoare, numar;
            std::cout << "Introdu valoarea bancnotei: ";
            std::cin >> valoare;
            std::cout << "Introdu numarul de bancnote: ";
            std::cin >> numar;
            atm.adaugaBancnote(valoare, numar);  // adauga bancnote
            std::cout << "Bancnote adaugate cu succes!\n";
        } else if (optiune == 2) {
            int suma;
            std::string data;
            std::cout << "Introdu suma de retras: ";
            std::cin >> suma;
            std::cout << "Introdu data tranzactiei (format: zi/luna/an): ";
            std::cin >> data;
            atm.retrageBani(suma, data);  // retrage bani
        } else if (optiune == 3) {
            atm.afiseazaTranzactii();  // afiseaza tranzactiile
        } else if (optiune == 4) {
            atm.sorteazaTranzactii();  // sorteaza tranzactiile (se va face automat daca folosesti set-ul)
            std::cout << "Tranzactiile sunt deja ordonate dupa data.\n";
        } else if (optiune == 5) {
            std::cout << "La revedere!\n";
            break;  // iese din program
        } else {
            std::cout << "Optiune invalida! Incearca din nou.\n";
        }
    }

    return 0;
}
