#ifndef COLECTIE_H
#define COLECTIE_H

template <typename TElem>
struct NodColectie {
    TElem val;
    NodColectie* next;
};

template <typename TElem>
class Colectie {
private:
    NodColectie<TElem>* head;
    int size;

public:
    Colectie();
    ~Colectie();

    void add(TElem elem);
    bool remove(TElem elem);
    bool search(TElem elem);
    int getSize() const;
    TElem getAt(int position) const;
};

template <typename TElem>
Colectie<TElem>::Colectie() {
    head = nullptr;
    size = 0;
}

template <typename TElem>
Colectie<TElem>::~Colectie() {
    NodColectie<TElem>* curent = head;
    while (curent != nullptr) {
        NodColectie<TElem>* urmator = curent->next;
        delete curent;
        curent = urmator;
    }
}

template <typename TElem>
void Colectie<TElem>::add(TElem elem) {
    NodColectie<TElem>* nou = new NodColectie<TElem>{elem, head};
    head = nou;
    size++;
}

template <typename TElem>
bool Colectie<TElem>::remove(TElem elem) {
    NodColectie<TElem>* curent = head;
    NodColectie<TElem>* anterior = nullptr;

    while (curent != nullptr) {
        if (curent->val == elem) {
            if (anterior == nullptr) {
                head = curent->next;
            } else {
                anterior->next = curent->next;
            }
            delete curent;
            size--;
            return true;
        }
        anterior = curent;
        curent = curent->next;
    }
    return false;
}

template <typename TElem>
bool Colectie<TElem>::search(TElem elem) {
    NodColectie<TElem>* curent = head;
    while (curent != nullptr) {
        if (curent->val == elem)
            return true;
        curent = curent->next;
    }
    return false;
}

template <typename TElem>
int Colectie<TElem>::getSize() const {
    return size;
}

template <typename TElem>
TElem Colectie<TElem>::getAt(int position) const {
    if (position < 0 || position >= size)
        return TElem();

    NodColectie<TElem>* curent = head;
    for (int i = 0; i < position; i++) {
        curent = curent->next;
    }
    return curent->val;
}

#endif
