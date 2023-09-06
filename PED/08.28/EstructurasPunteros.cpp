#include <iostream>
using namespace std;

struct Producto {
    string nombre;
    float precio;
    string categoria[2];
} producto[2];

void llenarProductos(Producto *,int);
void imprimirProductos(Producto *,int);

int main(){
    //Declaracion de puntero
    Producto *ptr_producto;
    ptr_producto = producto;

    llenarProductos(ptr_producto, 2);
    imprimirProductos(ptr_producto, 2);

    return 0;
}

//Funcion que permita almacenar informacion de 3 producto, que imprima la informacion;
void llenarProductos(Producto *aProducto, int n){
    cout << "Llenado de informacion"<<endl;
    for (int i = 0; i < n; i++)
    {   
        cout << "Ingrese el nombre del producto("<<i+1<<"): "<<endl;
        cin >> aProducto[i].nombre;
        cout << "Ingrese el precio del producto("<<i+1<<"): "<<endl;
        cin >> aProducto[i].precio;

        cout << "Categorias: "<< endl;
        for (int j = 0; j < 2; j++)
        {
            cout << "Ingrese la categoria ("<<j+1<<") del producto("<<i+1<<"): "<<endl;
            cin >> aProducto[i].categoria[j];
        }
        
    }
}

void imprimirProductos(Producto *aProducto, int n){
    cout<<"Datos ingresados: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Producto ("<<i+1<<"): " << aProducto[i].nombre<<endl;
        cout << "Precio del producto ("<<i+1<<"): " << aProducto[i].precio<<endl;
        for (int j = 0; j < 2; j++)
        {
            cout << "Categoria ("<<j+1<<") del producto("<<i+1<<"): "<<aProducto[i].categoria[j]<<endl;
        }

    }
}