#include <iostream>
using namespace std;

// Devolver varios valores usando referencia
float Calculadora(int, int, int &, int &, int &);

int main(){
    int a, b;
    int suma = 0, resta = 0, multiplicacion = 0;
    cout<< "Ingrese el primer numero: " << endl;
    cin>>a;
    cout<< "Ingrese el segundo numero: " << endl;
    cin>>b;
    Calculadora(a, b, suma, resta, multiplicacion);
    cout<<endl<<"RESULTADOS"<<endl<<"Suma: " << suma <<endl << "Resta: " << resta << endl << "Multiplicacion: " << multiplicacion<<endl;

    return 0;
}

float Calculadora(int a, int b, int &suma, int &resta, int &multiplicacion){
    
    suma = a+b;
    resta = a-b;
    multiplicacion = a*b;

}