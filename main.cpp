#include <iostream>

using namespace std;

struct nodo{
    
    int dato;
    nodo* siguiente;
    
};


nodo* CrearLista(int primervalor){
    
    nodo* raiz = (nodo*)malloc(sizeof(nodo));
    raiz->dato = primervalor;
    raiz->siguiente = nullptr;
    
    return raiz;
    
}

void Insertar(nodo* lista, int valor){
    
    nodo* ptr = (nodo*)malloc(sizeof(nodo));
    lista->siguiente = ptr;
    ptr->dato = valor;
    ptr->siguiente = nullptr;
}

nodo* Recorrer(nodo* lista){
    
    while(lista->siguiente != nullptr){
        lista = lista->siguiente;    
    }
    
    return lista;
    
}

void InsertarFinal(nodo* lista, int valor){
    
    nodo* nodofinal = Recorrer(lista);
    Insertar(nodofinal, valor);
    
}

void Mostrar(nodo* lista){
    
    while(lista->siguiente != nullptr){
        cout << lista->dato << " -> ";
        lista = lista->siguiente;    
    }
    
    cout << lista->dato;
    
}

int main(){
    
    nodo* Lista = CrearLista(1);
    
    InsertarFinal(Lista,2);
    InsertarFinal(Lista,3);
    InsertarFinal(Lista,4);
    
    Mostrar(Lista);
    
    return 0;
}


/*
class Nodo {
public:
    int dato;
    Nodo* siguiente;

    Nodo(int valor) : dato(valor), siguiente(nullptr) {}
};

class Lista {
private:
    Nodo* cabeza;

public:
    Lista() : cabeza(nullptr) {}

    ~Lista() {
        while (cabeza != nullptr) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }

    void insertarAlFinal(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (cabeza == nullptr) {
            cabeza = nuevo;
        } else {
            Nodo* temp = cabeza;
            while (temp->siguiente != nullptr) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevo;
        }
    }

    void insertarAlInicio(int valor) {
        Nodo* nuevo = new Nodo(valor);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    }

    bool eliminar(int valor) {
        if (cabeza == nullptr) return false;

        if (cabeza->dato == valor) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
            return true;
        }

        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr && actual->siguiente->dato != valor) {
            actual = actual->siguiente;
        }

        if (actual->siguiente == nullptr) return false;

        Nodo* temp = actual->siguiente;
        actual->siguiente = actual->siguiente->siguiente;
        delete temp;
        return true;
    }

    void mostrar() const {
        Nodo* temp = cabeza;
        while (temp != nullptr) {
            std::cout << temp->dato << " -> ";
            temp = temp->siguiente;
        }
        std::cout << "NULL\n";
    }

    bool buscar(int valor) const {
        Nodo* temp = cabeza;
        while (temp != nullptr) {
            if (temp->dato == valor) return true;
            temp = temp->siguiente;
        }
        return false;
    }

    bool estaVacia() const {
        return cabeza == nullptr;
    }
};


int main() {
    
    
    Lista miLista;

    miLista.insertarAlFinal(10);
    miLista.insertarAlFinal(20);
    miLista.insertarAlInicio(5);
    miLista.mostrar();

    miLista.eliminar(20);
    miLista.mostrar();

    std::cout << "¿Está 10?: " << (miLista.buscar(10) ? "Sí" : "No") << std::endl;
    
    
    return 0;
}
*/

