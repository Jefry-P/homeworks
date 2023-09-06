#include <iostream>
using namespace std;

void CambioVariables(int &, int &);
void CambioVariables2(int *, int *);
int main(){
    //Funcion que cambie dos variables entre ellas con punteros o referencia 
    int a = 5, b = 10;
    cout<< "a="<<a<<" b="<<b<<endl;
    CambioVariables(a, b);
    CambioVariables2(&a, &b);

    cout<< "a="<<a<<" b="<<b<<endl;

    

    return 0;
}

void CambioVariables(int &x, int &y){
    int aux = x;
    x = y;
    y = aux;
}

void CambioVariables2(int *x, int *y){
    int aux = *x;
    *x = *y;
    *y = aux;
}