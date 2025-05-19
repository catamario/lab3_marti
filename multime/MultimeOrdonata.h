#ifndef MULTIME_ORDONATA_H
#define MULTIME_ORDONATA_H

template <typename T>
struct Nod {
    T val;
    Nod* next;
};

template <typename T>
class MultimeOrdonata {
private:
    Nod<T>* head;

public:
    MultimeOrdonata();
    ~MultimeOrdonata();

    void insert(const T& elem, int criteriu); // 1=data, 2=suma, 3=nr bancnote
    void afiseaza() const;
    void clear();
};

// Constructor
template <typename T>
MultimeOrdonata<T>::MultimeOrdonata() {
    head = nullptr;
}

// Destructor
template <typename T>
MultimeOrdonata<T>::~MultimeOrdonata() {
    clear();
}

// Inserare ordonata in functie de criteriu
template <typename T>
void MultimeOrdonata<T>::insert(const T& elem, int criteriu) {
    Nod<T>* nou = new Nod<T>{elem, nullptr};

    auto compar = [&](const T& a, const T& b) {
        if (criteriu == 1) return a.getData() < b.getData();
        if (criteriu == 2) return a.getSuma() < b.getSuma();
        if (criteriu == 3) return a.getNrBancnote() < b.getNrBancnote();
        return false;
    };

    if (!head || compar(elem, head->val)) {
        nou->next = head;
        head = nou;
        return;
    }

    Nod<T>* curent = head;
    // Mergem atata timp cat nodul urmator e mai mic decat elem, ca sa inseram dupa el
    while (curent->next && compar(curent->next->val, elem)) {
        curent = curent->next;
    }

    nou->next = curent->next;
    curent->next = nou;
}


// Afisare lista
template <typename T>
void MultimeOrdonata<T>::afiseaza() const {
    Nod<T>* curent = head;
    while (curent) {
        curent->val.afiseaza();
        curent = curent->next;
    }
}

// Eliberare memorie
template <typename T>
void MultimeOrdonata<T>::clear() {
    while (head) {
        Nod<T>* tmp = head;
        head = head->next;
        delete tmp;
    }
}

#endif
