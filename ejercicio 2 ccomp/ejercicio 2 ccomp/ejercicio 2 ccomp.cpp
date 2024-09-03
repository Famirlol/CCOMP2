#include <iostream>
using namespace std;

void dinero_repartido(int x) {
    int d;
    double y[11] = { 200, 100, 50, 20, 10, 5, 2, 1, 0.50, 0.20, 0.10 };

    for (d = 0; d < 11; d++) {
        int z = x / y[d];
        if (z > 0 && d<=4) {
            cout << "Se necesitan " << z << " billetes de " << y[d] << endl;
            x -= z * y[d];
        }
        if (z > 0 && d>=5 ) {
            cout << "Se necesitan " << z << "monedas de " << y[d] << endl;
            x -= z * y[d];
        }
    }
}

int main() {
    int x;
    cout << "¿Que cantidad quieres? ";
    cin >> x;
    dinero_repartido(x);
    return 0;
}
