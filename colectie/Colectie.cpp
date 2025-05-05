#include "Colectie.h"
#include <iostream>

template <typename TElem>
Colectie<TElem>::Colectie() {
    size = 0;
}

template <typename TElem>
void Colectie<TElem>::add(TElem elem) {
    if (size < 100) { // Să nu depășim limita de 100 de elemente
        elems[size++] = elem;
    }
}

template <typename TElem>
bool Colectie<TElem>::remove(TElem elem) {
    for (int i = 0; i < size; i++) {
        if (elems[i] == elem) {
            for (int j = i; j < size - 1; j++) {
                elems[j] = elems[j + 1]; // Mută elementele la stânga
            }
            size--;
            return true;
        }
    }
    return false;
}

template <typename TElem>
bool Colectie<TElem>::search(TElem elem) {
    for (int i = 0; i < size; i++) {
        if (elems[i] == elem) {
            return true;
        }
    }
    return false;
}

template <typename TElem>
int Colectie<TElem>::getSize() const {
    return size;
}

template <typename TElem>
TElem Colectie<TElem>::getAt(int position) const {
    if (position >= 0 && position < size) {
        return elems[position];
    }
    return TElem(); // returnează un element implicit (poate fi 0, NULL sau ceva relevant)
}

// Instanțierea explicită a template-ului pentru tipul int
template class Colectie<int>;
