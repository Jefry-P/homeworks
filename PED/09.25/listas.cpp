#include <iostream>
using namespace std;

//lista simple
struct Nodo {
    int elemento;
    Nodo *siguiente;
};

Nodo *lista = nullptr;
void Insertar(int n);
void EliminarFinal();

int main(){
    
    return 0;
}

void Insertar(int n){
    Nodo *nuevoNodo;
    ///Reserva de memeoria
    Nodo *temporal = lista;
    if(){

    } else {
        //Agregar un nodo al final
        while(temporal != nullptr){
            temporal = temporal->siguiente;
        }
        temporal->siguiente = nuevoNodo;

        //Agregar nodo al inicio
        // nuevoNodo->siguiente = lista;
        // lista = nuevoNodo;
    }
}

void EliminarFinal(){
    Nodo *temporal = lista;
    Nodo *temporal2;
    if(lista != nullptr){
        while(temporal->siguiente!=nullptr){
            //Guardamos el nodo anterior al ultimo
            temporal2 = temporal;
            //Guardamos el ultimonodo que es el que vamos a borrar
            temporal = temporal->siguiente;
        }
        //Hacemos que el penultimo apunte a nullptr
        temporal2->siguiente = nullptr;

        //Liberamos memoria
        delete temporal;
        temporal = nullptr;

    }
    lista = temporal2;

    
}