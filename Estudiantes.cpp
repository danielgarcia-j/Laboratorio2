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

    void imprimirLista() {
        Nodo* actual = cabeza;

        while (actual != nullptr) {
            cout << "Nombre: " << actual->estudiante.nombre
                 << " | Nota: " << actual->estudiante.nota << endl;
            actual = actual->siguiente;
        }
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
    lista.agregarEstudiante("Mario", 8.4);
    lista.agregarEstudiante("Nathalia", 9.0);
    lista.agregarEstudiante("Elena", 8.7);
     lista.agregarEstudiante("Alessandra", 6.0);
    lista.imprimirLista();

    return 0;
}
