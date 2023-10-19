#include <iostream>
using namespace std;

struct Producto{
    string name;
    float price;
};

//Recursividad
int factorial(int n);
int fibonacci(int n);

//Punteros
int *BuscarNumero(int *a, int valor);

Producto *fillArray(int n);
void showArray(Producto *, int );

int main(){
    //cout<<factorial(3)<<"\n";
    // for (int i = 1; i < 10; i++)
    // {
    //     cout<<fibonacci(i)<<"\n";
    // }
    
    
    // int vector[5] = {1, 2, 3, 4, 5};
    // int *ptr = vector;
    // cout<<"Recorriendo: "<< endl;
    // for (int i = 0; i < 5; i++)
    // {
    //     //cout << "Arreglo en " << i  << ":"<< ptr[i] << endl <<"Direccion: " << &ptr[i] <<endl;
    //     cout<< "Arreglo en " << i  << ": "<< *ptr << endl <<"Direccion: " << ptr <<endl;
    //     ptr++;
       
    // }

    // cout<<*(BuscarNumero(vector, 4)) << endl;


    Producto *producto = fillArray(1);
    showArray(producto, 1);

    // No olvides liberar la memoria dinámica al final
    delete[] producto;
    return 0;
}


//recursividad
int factorial(int n){
    if(n==1) return 1;
    return n*factorial(n-1);
}

int fibonacci(int n){
    if(n<2) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

//Punteros
int *BuscarNumero(int *a, int valor){

    for(int i = 0; i < 5; i++){
        // if(a[i] == valor) return &a[i];
        if((a[i]) == valor) return &(a[i]);
    }
    
    return nullptr;
}

Producto *fillArray(int n){
    Producto* producto = new Producto[n];
    for(int i = 0; i < n; i++){
        cout<<"Ingrese el nombre del producto: " << endl;
        cin >> producto[i].name;
        
        cout<<"Ingrese el precio del producto: " << endl;
        cin >> producto[i].price;
    }    

    return producto;
}

void showArray(Producto *producto, int n){

    for (int i = 0; i < n; i++)
    {
        cout<<producto[i].name<<endl;
        cout<<producto[i].price<<endl;
    }
    
}

