#include "Tranzactie.h"
#include <iostream>

Tranzactie::Tranzactie(int id, int suma, const std::map<int, int>& bancnote, const std::string& data)
    : id(id), suma(suma), bancnote(bancnote), data(data) {}

int Tranzactie::getId() const {
    return id;
}

int Tranzactie::getSuma() const {
    return suma;
}

const std::map<int, int>& Tranzactie::getBancnote() const {
    return bancnote;
}

const std::string& Tranzactie::getData() const {
    return data;
}

// Implementarea operatorului < pentru compararea tranzacțiilor
bool Tranzactie::operator<(const Tranzactie& other) const {
    // Compară după data tranzacției, apoi după suma retrasă și numărul de bancnote
    if (data != other.data) {
        return data < other.data;
    }
    if (suma != other.suma) {
        return suma < other.suma;
    }
    return bancnote.size() < other.bancnote.size();
}


void Tranzactie::afiseaza() const {
    std::cout << "Tranzactie ID: " << id << ", Suma: " << suma << ", Data: " << data << "\nBancnote: ";
    for (const auto& p : bancnote) {
        std::cout << p.second << " x " << p.first << " RON ";
    }
    std::cout << std::endl;
}


