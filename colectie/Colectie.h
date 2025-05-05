#ifndef COLECTIE_H
#define COLECTIE_H

template <typename TElem>
class Colectie {
private:
    TElem elems[100]; // Exemplu de dimensiune fixă
    int size;

public:
    Colectie(); // Constructor

    void add(TElem elem); // Adăugare bancnotă
    bool remove(TElem elem); // Înlăturare bancnotă
    bool search(TElem elem); // Căutare bancnotă
    int getSize() const; // Obținere număr bancnote
    TElem getAt(int position) const; // Obținere element pe poziție
};

#endif
