#include <iostream>
using namespace std;

void calcularTicket(float, int, float&, float&, float&);

int main(){
    int cantidad;
    float totalPago = 0, precio, totalPagoDesc = 0, descuento = 0;
    
    cout << "Ingrese el precio del producto: " << endl;
    cin >> precio;

    cout<<"Ingrese la cantidad de producto: " << endl;
    cin >> cantidad;

    calcularTicket(precio, cantidad, descuento, totalPago, totalPagoDesc);
    cout<<"==========TICKET============="<<endl<<"Total: $" << totalPago << endl << "Descuento aplicado (20%): $" << descuento<<endl<<"Total a pagar: $" << totalPagoDesc<<endl<<"============================="<<endl;

    return 0;
}

void calcularTicket(float precio, int cant, float &desc, float &totalPagar, float &totalPagarDesc){

    totalPagar = precio*cant;
    desc =  totalPagar*.2;
    totalPagarDesc = totalPagar - desc;
}