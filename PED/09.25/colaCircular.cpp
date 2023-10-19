#include <iostream>
using namespace std;

//constante
#define tamano 5

struct Nodo {
    int frenteCola;
    int finalCola;
    int elemento[tamano];
} nodo;

// Declaracion de funciones / creacion de prototipo
void Crear(struct Nodo *);
bool Vacia(struct Nodo *);
int Llena(Nodo *);
void Insertar(struct Nodo *, int);
void Eliminar(struct Nodo *);
int Dimension(Nodo *);

int main(){
    
    return 0;
}

void Crear(Nodo *p){
    p->frenteCola = -1;
    p->finalCola = -1;
}

bool Vacia(Nodo *p){
    if (p->finalCola == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Dimension(Nodo *p){
    if(Vacia(p)) return 0;
    else {
        if(p->frenteCola <= p->finalCola){
            return p->finalCola - p->frenteCola + 1;
        } else {
            return tamano - p->frenteCola + p->finalCola + 1;
        }
    }
}

int Llena(Nodo *p){

}

void Insertar(Nodo *p, int n){
    if(!Llena(p)){
        if(Vacia(p))
        {
            p->frenteCola = 0;
        } 
        if( p->finalCola == tamano -1)
        {
            p->finalCola = 0;
        } 
        else 
        {
            p->finalCola++;
        }
        //Sobre escritura
        p->elemento[p->finalCola] = n;
    } 
    else 
    {
        cout << "Cola llena";
    }
}

// Desencolar -- inicio de la lista
void Eliminar(Nodo *p)
{
    if (!Vacia(p))
    {
        if (Dimension(p) == 1)
        {
            Crear(p);
        }
        else
        {
            p->frenteCola++;
        }
    }
    else
    {
        cout << "Cola esta vacia";
    }
}