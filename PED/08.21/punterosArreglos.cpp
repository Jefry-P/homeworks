#include <iostream>
using namespace std;

int *BuscarNumero(int[], int);

int main(){
    int vector[5] = {4, 5, 8, 1, 9};
    cout<<vector[2]<<endl;
    cout << *vector<< endl;
    cout << *(vector + 2)<< endl; //aritmetica de punteros

    int *ptr = vector;
    cout<<"Recorriendo: "<< endl;
    for (int i = 0; i < 5; i++)
    {
        cout << *(vector + i)<< "="<<ptr++<<endl;
    }
    
    
    //Ejercicio 1
    //Escribir una funcion que utilice punteros para buscar un numero dentro de un arreglo, si existe, devolver direccion de memoria
    int a = 5;
    cout<<"Ingrese un numero para buscar en el arreglo: " <<endl;
    cin>>a;
    cout<< "a= " << BuscarNumero(vector, a)<<endl;
    // cout<< "posicion de a= " << (ptr - BuscarNumero(vector, a))<<endl;

    return 0;
}

int *BuscarNumero(int a[], int valor){

    int longitud = sizeof(a) / sizeof(a[0]);

    for(int i = 0; i < longitud; i++){
        // if(a[i] == valor) return &a[i];
        if(*(a+1) == valor) return (a+i);
    }
    
    return nullptr;
}

