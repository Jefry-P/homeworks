#include <iostream>
using namespace std;

void areaFiguras(float , float, float &, float &);

int main(){
    float resultadoTriangulo = 0, resultadoRectangulo = 0, base = 0, altura = 0;
    int opcion;

    cout << "Seleccione la figura de la cual desea calcular el area: "<<endl<<"1. Triangulo" << endl<< "2. Rectangulo" << endl;
    cin>>opcion;    
    cout<<"Ingrese la base: " << endl;
    cin >> base;
    cout<<"Ingrese la altura: " << endl;
    cin >> altura;
    areaFiguras(base, altura, resultadoTriangulo, resultadoRectangulo);
    opcion == 1 ? cout<<"Area del triangulo: " << resultadoTriangulo<<endl : cout<<"Area del rectangulo: " << resultadoRectangulo<<endl;

    return 0;
}

void areaFiguras(float base, float altura, float &resultado1, float &resultado2){
    resultado1 = base*altura/2;
    resultado2 = base*altura;
}