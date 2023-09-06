#include <iostream>
using namespace std;

int main(){
    int a = 15;
    int b = 60;
    int *ptr;
    int *ptr2;

    ptr = &a;
    ptr2 = ptr;
    *ptr = 20;//Modificamos la variable a
    cout<< &ptr <<endl << &ptr2 <<endl;
    if(!(&ptr == &ptr2)) cout<<"no son iguales"<<endl; //Comparamos el espacio en memoria de los punteros, no de la variable a la que apuntan
    //cout<<ptr; //Direccion de memoria de la variable
    //cout<<*ptr<< "-"<<ptr<<endl<<ptr2<<endl; //Valor de la direccion de memoria


    //Ejercicio 1
    //Son iguales o diferentes las direcciones de memoria r y n? por que?
    // int n = 33;
    // int &r = n;
    // cout<<"&n = "<< &n<<". &r= "<<&r<<endl;
    //Son iguales

    //Ejercicio 2
    //Cual es la salida del siguiente programa?
    // int n = 35;
    // int *p = &n; //Puntero y a quien apunta
    // int &r= *p; //
    // cout<<"r = " << r << endl;

    //Ejercicio 3
    //Cual es la salida del siguiente programa?
    int n = 35;
    int *p = &n;
    cout<< "*p = "<< *p<<endl<<"p = " << p<<endl;
    return 0;
}