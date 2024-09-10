#include <iostream>

using namespace std;

void ordenar(int* ini, int* mitad) {
    int* fin = ini + (mitad - ini) * 2;
    for (int* i = ini; i < mitad; ++i) {
        for (int* j = mitad; j < fin; ++j) {
            if (*j < *i) {
                swap(*i, *j);
            }
        }
    }

    for (int* i = ini; i < fin - 1; ++i) {
        for (int* j = i + 1; j < fin; ++j) {
            if (*j < *i) {
                swap(*i, *j); 
            }
        }
    }
}

int main() {
    int e[] = { 2, 4, 6, 8, 22, 3, 5, 11, 25, 33 };
    int* ini = e;
    int* mitad = e + 5;

    ordenar(ini, mitad);

    for (int i = 0; i < 10; i++) {
        cout << e[i] << " ";
    }
}