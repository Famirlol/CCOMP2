#include <iostream>
#include <string>
using namespace std;

string convertir_unidades(int x) {
    string numeros[] = { "cero","uno","dos","tres","cuatro","cinco","seis","siete","ocho","nueve","diez",
                         "once","doce","trece","catorce", "quince", "dieciséis", "diecisiete",
                         "dieciocho", "diecinueve" };
    return numeros[x];
}

string decenas(int x) {
    if (x < 20) {
        return convertir_unidades(x);
    }
    string decena[] = { "", "", "veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa" };
    int z = x / 10;
    int unidad = x % 10;

    string resultado = decena[z];
    if (unidad > 0) {
        if (x < 30) {
            resultado += convertir_unidades(unidad);
        }
        else {
            resultado += " y " + convertir_unidades(unidad);
        }
    }
    return resultado;
}

string centenas(int x) {
    if (x < 100) {
        return decenas(x);
    }
    string centena[] = { "", "ciento", "doscientos", "trescientos", "cuatrocientos", "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos" };
    int z = x / 100;
    int resto = x % 100;

    string resultado = centena[z];
    if (resto > 0) {
        resultado += " " + decenas(resto);
    }
    return resultado;
}

string miles(int x) {
    if (x < 1000) {
        return centenas(x);
    }
    int z = x / 1000;
    int resto = x % 1000;

    string resultado = "";
    if (z == 1) {
        resultado = "mil";
    }
    else {
        resultado = centenas(z) + " mil";
    }

    if (resto > 0) {
        resultado += " " + centenas(resto);
    }
    return resultado;
}

int main() {
    int x;
    cout << "Ingrese un número hasta 999,999: ";
    cin >> x;
    if (x > 999999 || x < 0) {
        cout << "El número está fuera del rango permitido." << endl;
    }
    else {
        cout << miles(x) << endl;
    }
    return 0;
}
