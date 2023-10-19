#include <iostream>
using namespace std;

struct Nodo{
    int elemento;
    struct Nodo *siguiente;

};

Nodo *frenteCola = nullptr;
Nodo *finalCola = nullptr;

bool Vacia(){
    if(frenteCola == nullptr){
        return true;
    } else {
        return false;
    }
}


void Insertar(int n){
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = nullptr;

    if(Vacia()){
        //No hay nadie en frente de la cola el elemento queda al frente
        frenteCola=nuevoNodo;
    } else {
        //Si habian elementos en la cola, por lo tanto se posiciona despues del elemento en cola
        finalCola->siguiente = nuevoNodo;
    }
    //Se establece el final de la cola
    finalCola = nuevoNodo;
}

void Imprimir(){
    struct Nodo *temporal = frenteCola;
    while(temporal != nullptr){
        cout<<"Elementos de la cola " << temporal->elemento << endl;
        temporal = temporal->siguiente;
    }
}

void Frente(){
    cout << "Elemento en el frente de la cola: " <<frenteCola->elemento << endl;
}

void Eliminar(){
    if(!Vacia){
        Nodo *temporal = frenteCola;
        if(frenteCola == finalCola) {
            //Si hay un solo elemento en la cola
            frenteCola == nullptr;
            finalCola == nullptr;
        } else {
            //si hay mas de un elemento
            frenteCola = frenteCola->siguiente;
        }
        delete temporal;
    }
}

void Final(){
    
}

int main(){
    int valor;
    for (int i = 0; i < 5; i++)
    {
        cout<<"Ingrese el valor:" << endl;
        cin>>valor;
        Insertar(valor);
    }
    Imprimir();
    Frente();
    return 0;
}


