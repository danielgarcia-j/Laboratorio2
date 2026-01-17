#include <iostream>
using namespace std;

class Estudiante {
public:
    string nombre;
    float nota;

    Estudiante(string n, float no) {
        nombre = n;
        nota = no;
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

class ListaEnlazada {
private:
    Nodo* cabeza;

public:
    ListaEnlazada() {
        cabeza = nullptr;
    }

    
    void agregarEstudiante(string nombre, float nota) {
        Estudiante nuevoEstudiante(nombre, nota);
        Nodo* nuevoNodo = new Nodo(nuevoEstudiante);

        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
        } else {
            Nodo* actual = cabeza;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevoNodo;
        }
    }
    
};
int main() {
    ListaEnlazada lista;
    lista.agregarEstudiante("Juan", 8.5);
    lista.agregarEstudiante("Maria", 9.0);

    return 0;
}