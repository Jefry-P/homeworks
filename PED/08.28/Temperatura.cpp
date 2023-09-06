#include <iostream>
#include <unistd.h>
using namespace std;

struct Temperatura {
    float alta;
    float baja;
} temp;

void leertempactual(float &actual);
void registrotemp(Temperatura &t);

int main(){
    temp.alta = 0;
    temp.baja = 100;
    while(true){
        registrotemp(temp);
        cout<< "Temperaturas: " << temp.baja << " - " << temp.alta << endl;
        sleep(2);
    }
    return 0;
}

void leertempactual(float &actual){
    int t = time(NULL);
    srand(t);
    cout << " - tiempo: " << t;
    actual = rand() % (48 +1);
}

void registrotemp(Temperatura &t){
    float actual = 0;
    leertempactual(actual);
    cout << " -> Lectura actual: " << actual << "\n";
    if(actual > t.alta){
        t.alta = actual;
    }
    if(actual < t.baja){
        t.baja = actual;
    }
}