#include <iostream>
#include <unistd.h>
using namespace std;

struct Bomba{
    float cantidadGasolina;
    float cantidadDiesel;
} bomba;

void random(float &, float &);
void actualizarBomba(Bomba &, int);
int main(){
    int opcion;
    cout << "Que desea visualizar? " << endl<<"1- Gasolina" << endl<< "2- Diesel"<< endl;
    cin >> opcion;

    while(true){
        if(opcion == 1) cout<< "Gasolina: " << bomba.cantidadGasolina << endl;
        else cout<< "Diesel: " << bomba.cantidadDiesel << endl;
            

        if(bomba.cantidadGasolina>=4){
            cout<<"Tanque de gasolina lleno" << endl;
            break;
        }
        else if(bomba.cantidadDiesel >=4) {
            cout<<"Tanque de diesel lleno" << endl;   
            break;
        }
        actualizarBomba(bomba, opcion);
        sleep(2);
    }
        
    return 0;
}

void random(float &actual1, float &actual2){
    int t = time(NULL);
    srand(t);
    //cout << " - tiempo: " << t << endl;
    actual1 = (rand() % (10 + 1)); //random de 100 a 399
    actual2 = (rand() % (10 + 1));
    actual1 /=10;
    actual2 /=10;
}

void actualizarBomba(Bomba &b, int opcion){
    float actual1 = 0;
    float actual2 = 0;

    random(actual1, actual2);
    opcion == 1 ? b.cantidadGasolina+=actual1 : b.cantidadDiesel+=actual2;  
    
}