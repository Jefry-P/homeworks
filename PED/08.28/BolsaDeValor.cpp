#include <iostream>
#include <unistd.h>
#include <time.h> //La necesita windows
using namespace std;

struct Empresa{
    string nombreEmpresa;
    float precioVenta;
    float precioCompra;
} empresa;

void random(float &, float &);
void registroEmp(Empresa &e);

int main(){
    empresa.precioCompra = 0;
    empresa.precioVenta = 100;
    cout<<"Ingrese el nombre de la empresa que desea visualizar: " << endl;
    cin >> empresa.nombreEmpresa;

    cout<<"Precios de "<< empresa.nombreEmpresa<<" en vivo: "<<endl;

    while(true){
        registroEmp(empresa);
        cout<< "Precio venta: " << empresa.precioVenta <<" - Precio compra: " << empresa.precioCompra << endl;
        sleep(2);
    }
    return 0;
}


void random(float &actual1, float &actual2){
    int t = time(NULL);
    srand(t);
    //cout << " - tiempo: " << t << endl;
    actual1 = rand() % (300 + 100); //rando de 100 a 399
    actual2 = rand() % (300 + 100);
    
}

void registroEmp(Empresa &e){
    float actual1 = 0;
    float actual2 = 0;

    random(actual1, actual2);

    if(actual1 != e.precioVenta && actual1 <= e.precioCompra){
        e.precioVenta= actual1;
    }
    if(actual2 != e.precioCompra && actual2 >= e.precioVenta){
        e.precioCompra = actual2;
    }
}