#ifndef LIST_LINKED_H
#define LIST_LINKED_H

#include <ostream>
#include <stdexcept>
#include "list.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

private:
    Node<T>* first;
    int n;

public:
    ListLinked();
    ~ListLinked();

    T operator[](int pos);

    friend std::ostream& operator<<(std::ostream& out,
                                    const ListLinked<T>& list){

    Node<T>* aux = list.first;

        out << "[";

        while (aux != nullptr) {
            out << aux->data;

            if (aux->next != nullptr) {
                out << ", ";
            }

            aux = aux->next;
        }

        out << "]";

        return out;
    }
};

template <typename T>
ListLinked<T>::ListLinked()
{
    first = nullptr;
    n = 0;
}

template <typename T>
ListLinked<T>::~ListLinked()
{
    Node<T>* aux;

    while (first != nullptr) {
        aux = first;
        first = first->next;
        delete aux;
    }
}

template <typename T>
T ListLinked<T>::operatorint pos
{
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("Posicion no valida");
    }

    Node<T>* aux = first;

    for (int i = 0; i < pos; i++) {
        aux = aux->next;
    }

    return aux->data;
}

};


#endif LIST_LINKED_H

