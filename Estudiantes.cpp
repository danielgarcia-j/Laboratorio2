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
    float sumaRecu(Nodo* nodo){
        if(nodo == nullptr){
            return 0;
        }
        return nodo->estudiante.nota + sumaRecu(nodo->siguiente);
    }
    
    int contarRecu(Nodo* nodo){
        if(nodo == nullptr){
            return 0;
        }
        return 1 + contarRecu(nodo->siguiente);
    }

public:
    ListaEnlazada(){
        cabeza = nullptr;
    }
    
    float calcularPromedio(){
        if(cabeza == nullptr){
            return 0;
        }

        float suma = sumaRecu(cabeza);
        int contador = contarRecu(cabeza);

        return suma / contador;
    }

    void imprimirLista() {
        Nodo* actual = cabeza;

        if (actual == nullptr) {
            cout << "La lista esta vacia.\n";
            return;
        }

        int i = 1;
        while (actual != nullptr) {
            cout << i << ". Nombre: " << actual->estudiante.nombre
                 << " | Nota: " << actual->estudiante.nota << endl;
            actual = actual->siguiente;
            i++;
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

    int contarEstudiantes() {
        Nodo* actual = cabeza;
        int contador = 0;

        while (actual != nullptr) {
            contador++;
            actual = actual->siguiente;
        }
        return contador;
    }
};

int main() {
    ListaEnlazada lista;
    int opcion;
    int n;

    cout << "Cuantos estudiantes vas a ingresar? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string nombre;
        float nota;

        cout << "Nombre del estudiante " << i + 1 << ": ";
        cin >> ws;
        getline(cin, nombre);

        cout << "Nota del estudiante " << i + 1 << ": ";
        cin >> nota;

        lista.agregarEstudiante(nombre, nota);
    }

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Ver lista de estudiantes\n";
        cout << "2. Agregar mas estudiantes\n";
        cout << "3. Ver promedio notas\n";
        cout << "4. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                lista.imprimirLista();
                break;
            case 2: {
                int mas;
                cout << "Cuantos estudiantes mas quieres agregar? ";
                cin >> mas;

                for (int i = 0; i < mas; i++) {
                    string nombre;
                    float nota;

                    cout << "Nombre del estudiante " << lista.contarEstudiantes() + 1 << ": ";
                    cin >> ws;
                    getline(cin, nombre);

                    cout << "Nota del estudiante " << lista.contarEstudiantes() + 1 << ": ";
                    cin >> nota;

                    lista.agregarEstudiante(nombre, nota);
                }
                break;
            }
            case 3:
                cout << "Promedio de notas: " << lista.calcularPromedio() << endl;
                break;
            case 4:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 4);

    return 0;
}
