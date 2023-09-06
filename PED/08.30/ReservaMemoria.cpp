#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    
    //Utilizada en c
    // int *ptr;
    //Reserva de memoria utilizando malloc
    // ptr = (int*)malloc(100*sizeof(int));

    //Liberacion
    // free(ptr);

    //FORMA QUE SI VAMOS A UTILIZAR EN C++
    int *p;
    p = new int; //int *ptr = new int;
    //para arreglo
    // int tamanio;
    // p = new int[tamanio];

    if(p == NULL){
        cout << "Error de asignacion de memoria"<<"\n";
    } else {
        cout << "Direccion de memoria: "<<p<<"\n";
    }
    delete p;

    //Arreglos dinamico
    int *edad, numEdad;
    cout<<"Cuantas edades se registraran?: " << "\n";
    cin>>numEdad;
    edad = new int[numEdad];

    for(int i=0; i<numEdad; i++)
    {
        cout<<"Ingrese la edad("<<i+1<<")"<<"\n";
        cin>>edad[i];
    }

    delete [] edad;
    return 0;
}