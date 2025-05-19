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

int Tranzactie::getNrBancnote() const {
    int total = 0;
    for (const auto& p : bancnote) {
        total += p.second;
    }
    return total;
}


const std::string& Tranzactie::getData() const {
    return data;
}

void Tranzactie::afiseaza() const {
    std::cout << "Tranzactie ID: " << id << ", Suma: " << suma << ", Data: " << data << "\nBancnote: ";
    for (const auto& p : bancnote) {
        std::cout << p.second << " x " << p.first << " RON ";
    }
    std::cout << std::endl;
}


