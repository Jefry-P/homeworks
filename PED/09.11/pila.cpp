#include <iostream>
using namespace std;

struct Nodo{
    int elemento;
    struct Nodo *siguiente;
};

//variable global
struct Nodo *pila = nullptr;

//Declarando funciones
void Insertar(int);
void Eliminar(int &);
void Imprimir();
void Vacia();
void Llena();
Nodo *Cima();

int main(){
    int valor;
    for (int i = 0; i < 5; i++)
    {
        cout<< "Ingrese un valor:  ";
        cin>>valor;

        Insertar(valor);
    }
    Imprimir();
    Eliminar(valor);
    Imprimir();

    cout<<"Elemento de la cima: " << Cima()->elemento<< endl;
    cout<<"Direccion de la ultima estructura o ultimo elemento: "<<pila<<endl;
    cout<<"Direccion del ultimo puntero"<<&pila<<endl;


    return 0;
}

void Insertar(int n){
    //Reserva de memoria
    struct Nodo *nuevoNodo = new Nodo();
    //Asignar valor
    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = pila;
    pila = nuevoNodo;
}

void Imprimir(){
    struct Nodo *temporal = pila;
    while(temporal != nullptr){
        cout << "Elementos de la pila: " << temporal->elemento << endl;
        temporal = temporal->siguiente;
    }
}

void Eliminar(int &n){
    if(pila != nullptr){
        struct Nodo *temporal = pila;
        n = temporal->elemento;
        cout<<"Valor eliminado: " << temporal->elemento<<endl;
        pila = temporal->siguiente;
        delete temporal;
    }
}

void Vacia(){
    if(pila == nullptr) cout<<"La pila esta vacia";
}

void Llena(){
    if(pila != nullptr) cout<<"La pila esta llena";
}

Nodo *Cima(){
    return pila;
}