#include <iostream>
using namespace std;

struct Nodo{
    int elemento;
    struct Nodo *siguiente;
    struct Nodo *anterior;
};

//variable global donde se establece lista vacia
struct Nodo *lista = nullptr;

void InsertarInicio(int n){
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal = lista;

    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;
    nuevoNodo->elemento = n;
    
    if(lista == nullptr){
        lista = nuevoNodo;
    } else {
        //Enlace de nuevo nodo a nodo inicial (lista)
        nuevoNodo->siguiente = lista;
        //Enlace de lista hacia el nuevo nodo()
        lista->anterior = nuevoNodo;
        //Asignando valor nuevo que entra a la lista
        lista = nuevoNodo;
    }
}

void InsertarFinal(int n){
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal = lista;

    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;
    nuevoNodo->elemento = n;
    if(lista == nullptr){
        lista == nuevoNodo;
    } else {
        //viajando de inicio a final
        while(temporal->siguiente != nullptr){
            temporal = temporal->siguiente;
        }
        //agregamos nuevo nodo al final mediante el enlace
        temporal->siguiente = nuevoNodo;
        //conectamos el nuevo nodo con el anterior nodo
        nuevoNodo->anterior = temporal;
    }

}

void InsertarIntermedio(int n, int posicion){
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;


    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;
    nuevoNodo->elemento = n;

    posicion--;
    while(posicion != 1){
        //temporal guarda el nodo anterior donde queremos insertar
        temporal = temporal->siguiente;
        posicion--;
    }
    //haciendo espacio para nuevo nodo en medio de temporal y temporal 2, guarda el nodo siguiente donde queremos insertar
    temporal2 = temporal->siguiente;
    //enlace de temporal1 con nuevo nodo
    temporal->siguiente = nuevoNodo;
    //Enlace de temporal 2 con nuevo nodo
    temporal2->anterior = nuevoNodo;
    //enlace de nuevo nodo con temporal 2
    nuevoNodo->siguiente = temporal2;
    //enlace de nuevo nodo con temporal 1
    nuevoNodo->anterior = temporal;
}

void EliminarIntermedio(int posicion){
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;


    while(posicion != 1){
        //va siguiendo a temporal, anterior de temporal
        temporal2 = temporal;
        //tguarda nodo que queremos eliminar
        temporal = temporal->siguiente;
        posicion--;
    }
    //nodo anterior a borrar, lo enlazamos con el siguiente del que vamos a borrar 
    temporal2->siguiente = temporal->siguiente;
    //Enlazamos anterior del siguiente que vamos a borrar con el temporal 2
    temporal->siguiente->anterior = temporal2;
    //Borramos nodo
    delete temporal;
    temporal = nullptr;
    //enlace de temporal1 con nuevo nodo

}

void EliminarIntermedioBuscarValor(int valor){
    struct Nodo *temporal = lista;


    while(valor != temporal->elemento){
        //tguarda nodo que queremos eliminar
        temporal = temporal->siguiente;
    }

    if(temporal!=nullptr){
        cout<<"Valor encontrado " << temporal->elemento<<endl;
    //nodo anterior a borrar, lo enlazamos con el siguiente del que vamos a borrar 
        temporal->anterior->siguiente = temporal->siguiente;
        //Enlazamos anterior del siguiente que vamos a borrar con el temporal 2
        temporal->siguiente->anterior = temporal->anterior;
        //Borramos nodo
        delete temporal;
        temporal = nullptr;
    } else {
        cout<< "no se encontro el valor"<<endl;
    }
    
    //enlace de temporal1 con nuevo nodo

}

void Imprimir()
{
    struct Nodo *temporal = lista;
    if (lista != nullptr)
    {
        while (temporal != nullptr)
        {
            cout << "Lista " << temporal->elemento << " Direccion " << temporal << " dir nodo siguiente " << temporal->siguiente << endl;
            temporal = temporal->siguiente;
        }
    }
    else
    {
        cout << "Lista vacia";
    }
}

int main(){
    InsertarInicio(45);
    InsertarInicio(15);
    InsertarInicio(78);
    InsertarFinal(100);
    EliminarIntermedioBuscarValor(100);
    //EliminarIntermedio(3);
    Imprimir();

    return 0;
}