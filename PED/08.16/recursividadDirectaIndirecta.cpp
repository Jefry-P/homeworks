#include <iostream>
using namespace std;

int mcd(int a, int b);
int mcm(int a, int b);
int potencia(int a, int b);
int conteo(int);
void conteo2(int);


int main(){
    cout<<"MCD: " << mcd(6, 5)<<endl;
    cout<<"MCM: " << mcm(15, 1)<<endl;
    cout<<"Potencia: " << potencia(2, 4)<<endl;
    conteo2(5);


    return 0;
}

int mcd(int a, int b){
    if(b == 0){
        return a;
    }
    //Dividir el divisor entre el resto hasta que lleguemos a resto 0
    return mcd(b, a%b);
}

int mcm(int a, int b){
    //Si alguno de ambos numeros es 0, mcm es 0
    if( a==0 || b==0 ) return 0;
    return (a*b)/mcd(a, b);
}

int potencia(int a, int b){
    if(b == 0) return 1;
    return a*potencia(a, b-1);
}

int conteo(int a){
    if(a == 0) {
        return 0;
    }
    else{
        cout<<conteo(a)<<"\n";
        return conteo(a-1);
    }
    
}

void conteo2(int a){
    if(a == 0)
    return ;
    cout<<a<<endl;
    conteo2(a-1);
}