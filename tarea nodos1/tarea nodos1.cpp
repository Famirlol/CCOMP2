#include <iostream>
using namespace std;

template <class T>
struct nodo {
    T valor;
    nodo* siguiente;

    nodo(T v) : valor(v), siguiente(nullptr) {}
};

template <class T>
void merge(nodo<T>*& A, nodo<T>*& B) {
    nodo<T>* q = nullptr; 
    nodo<T>** p = &q;    

    while (A != nullptr && B != nullptr) {
        if (A->valor <= B->valor) {
            *p = A;
            A = A->siguiente;
        }
        else {
            *p = B;
            B = B->siguiente;
        }
        p = &((*p)->siguiente);
    }

    if (A != nullptr) {
        *p = A;
    }
    else {
        *p = B;
    }

    A = q;
}

template <class T>
void imprimirlista(nodo<T>* head) {
    while (head != nullptr) {
        cout << head->valor << " -> ";
        head = head->siguiente;
    }
    cout << "nullptr" << endl;
}

int main() {
    nodo<int>* lista1 = new nodo<int>(1);
    lista1->siguiente = new nodo<int>(3);
    lista1->siguiente->siguiente = new nodo<int>(5);
    lista1->siguiente->siguiente->siguiente = new nodo<int>(8);

    nodo<int>* lista2 = new nodo<int>(0);
    lista2->siguiente = new nodo<int>(4);
    lista2->siguiente->siguiente = new nodo<int>(6);
    lista2->siguiente->siguiente->siguiente = new nodo<int>(8);
    lista2->siguiente->siguiente->siguiente->siguiente = new nodo<int>(10);

    cout << "Lista 1: ";
    imprimirlista(lista1);
    cout << "Lista 2: ";
    imprimirlista(lista2);

    merge(lista1, lista2);

    cout << "Lista fusionada: ";
    imprimirlista(lista1);


    return 0;
}
