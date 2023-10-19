#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    struct Nodo *izquierdo;
    struct Nodo *derecho;
};

struct Nodo *ABB = nullptr; //(Arbol de Busqueda Binaria)

struct Nodo *Crear(int n){
    //Reservar memoria
    struct Nodo *nuevoNodo = new Nodo;
    //Asignar elemento nuevo
    nuevoNodo->dato = n;
    nuevoNodo->izquierdo = nullptr;
    nuevoNodo->derecho = nullptr;

    return nuevoNodo;
}

struct Nodo *Insertar(struct Nodo *ABB, int n){
    if(ABB == nullptr){
        return Crear(n);
    }
    if(n< ABB->dato){
        ABB->izquierdo = Insertar(ABB->izquierdo, n);
    }
    else {
        ABB->derecho = Insertar(ABB->derecho, n);
    }
}

void Inorden(struct Nodo *ABB){
    if(ABB == nullptr){
        return;
    }
    else {
        Inorden(ABB->izquierdo);
        //Raiz
        cout<<ABB->dato<<" - ";
        Inorden(ABB->derecho);
    }
}


void Preorden(struct Nodo *ABB){
    if(ABB == nullptr){
        return;
    }
    else {

        cout<<ABB->dato<<" - ";
        Preorden(ABB->izquierdo);
        Preorden(ABB->derecho);
    }
}

void Postorden(struct Nodo *ABB){
    if(ABB == nullptr){
        return;
    }
    else {
        Postorden(ABB->izquierdo);
        Postorden(ABB->derecho);
        cout<<ABB->dato<<" - ";
    }
}

//Tarea, como imprimir un arbol, de forma matematica


int main(){
    
    return 0;
}