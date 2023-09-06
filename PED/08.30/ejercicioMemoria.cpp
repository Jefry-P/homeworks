#include <iostream>
using namespace std;

int main(){



    //Dos arrays
    string *lugarTur, *pais;
    int numLugar;
    cout<<"Cuantos lugares turisticos desea almacenar?: "<< "\n";
    cin >> numLugar;
    cin.ignore();
    lugarTur = new string[numLugar];
    pais = new string[numLugar];
    for (int i = 0; i < numLugar; i++)
    {
        cout<<"Ingrese lugar: " << "\n";
        getline(cin, lugarTur[i]);
        
        cout<<"Ingrese pais: " << "\n";
        getline(cin, pais[i]);

    }
    
    for(int i = 0; i < numLugar; i++){
        cout<<"Lugar: " << lugarTur[i] << "\n";
        cout<<"Pais: " << pais[i] << "\n";

    }

    delete []lugarTur;
    delete []pais;
    lugarTur = nullptr;
    pais = nullptr;


    //Un array
    int numLugares;
    cout<<"Cuantos lugares turisticos desea almacenar?: "<< "\n";
    cin >> numLugares;
    cin.ignore();
    string **lugaresTuristicos;
    lugaresTuristicos = new string*[numLugares];
    
    for( int i=0; i<numLugares; i++ ){
        lugaresTuristicos[i] = new string[2];
    }

    for (int i = 0; i < 2; i++)
    {
        cout<<"Lugar: ";
        getline(cin, lugaresTuristicos[i][0]);
        cout<<"pais: ";
        getline(cin, lugaresTuristicos[i][1]);
        
    }

    for (int i = 0; i < numLugares; i++)
    {
        delete[] lugaresTuristicos[i];
    }
    delete [] lugaresTuristicos;
    
    
    return 0;
}