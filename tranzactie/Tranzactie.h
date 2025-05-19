#ifndef TRANZACTIE_H
#define TRANZACTIE_H

#include <map>     // pentru map
#include <string>  // pentru string

class Tranzactie {
private:
    int id;
    int suma;
    std::map<int, int> bancnote;  // map pentru bancnote
    std::string data;  // data tranzactiei

public:
    Tranzactie(int id, int suma, const std::map<int, int>& bancnote, const std::string& data);

    int getId() const;
    int getSuma() const;
    const std::map<int, int>& getBancnote() const;
    const std::string& getData() const;


    int getNrBancnote() const;

    void afiseaza() const;
};

#endif
