#include <iostream>
#include <string>
using namespace std;

class Estudiante {
public:
    string nombre;
    float notaFinal;

    Estudiante(string n, float nota) {
        nombre = n;
        notaFinal = nota;
    }

    void imprimir() {
        cout << nombre << " - " << notaFinal << endl;
    }
};

class Nodo {
public:
    Estudiante estudiante;
    Nodo* siguiente;

    Nodo(Estudiante e) : estudiante(e) {
        siguiente = nullptr;
    }
};

int main() {
    cout << "Laboratorio 2 - Base creada" << endl;
    return 0;
}
