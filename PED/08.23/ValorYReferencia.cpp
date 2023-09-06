#include <iostream>
using namespace std;

int incrementarPorValor(int);
int incrementoPuntero(int *);
int incrementoReferencia(int &);


int main(){
    int i = 4;
    cout << i << endl;
    cout << incrementarPorValor(i)<<endl;
    cout << i << endl;

    cout << incrementoPuntero(&i)<<endl;
    cout << i << endl;

    cout << incrementoReferencia(i)<<endl;
    cout << i << endl;
    return 0;
}

int incrementarPorValor(int i){
    return i += 1;
}

int incrementoPuntero(int *i){
    return *i += 1;
}

int incrementoReferencia(int &i){
    return i+= 1;
}