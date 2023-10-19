#include "Lib.hpp"
///VARIABLES GENERALES
int opcLogin = 0, opcPremium = 0, opcNormal = 0;

User currentUser;


void displayLoginMenu(){
    bool access = false;
    int countLog = 0;
    do
    {
        cout<<"----------------------------"<<endl;
        cout<<"           LOGIN"<<endl;
        cout<<"----------------------------"<<endl;
        cout<<"1. Iniciar sesion"<<endl;
        cout<<"2. Registrarse"<<endl;
        cout<<"3. Salir"<<endl;
        cout<<"----------------------------"<<endl;
        cout<<"Tu opcion >>"; cin>>opcLogin;
        switch (opcLogin)
        {
        case 1:
            access = false;
            countLog = 0;
            do
            {
                access = login();
                countLog++;
                cout<<"Intentos: " << countLog << endl;
            } while (!access && countLog < 3);
            if(countLog == 3){
                cout<<"Numero maximo de intentos fallidos alcanzado, saliendo..."<<endl;
                break;
            }

            break;
        case 2:
            access = false;
            access = registerUser();
            break;
        default:
            break;
        }

        if(access){
            do
            {
                if(currentUser.premium){
                    displayMainMenuPremium();
                } else {
                    displayMainMenu();
                }
            } while ((currentUser.premium ? conditionPremium(opcPremium) : conditionNormal(opcNormal)));
            cout<<"Cerrando sesion..." << endl;
            
        }
    } while (opcLogin!=3);
    
}

bool login(){
    string user, pass;
    cin.ignore();
    cout<<"----------------------------"<<endl;
    cout<<"    INICIO DE SESION"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"Ingrese su usuario >> ";cin>>user;
    cout<<"Ingrese su contrasena >> ";cin>>pass;
  
  //implementar logica de buscar usuario con esas credenciales en archivo en lugar de correctUser y correctPas
    string correctUser = "user", correctPass = "pass";
    if(user == correctUser && pass == correctPass){
        cout<<"Inicio de sesion satisfactorio"<<endl;
        currentUser = findUser(user, pass);
        return true;
    }
    else{
        cout<<"Usuario o contrasena incorrecto"<<endl;
        return false;
    } 
}

bool registerUser(){
    string user, pass1, pass2;
    cin.ignore();
    cout<<"----------------------------"<<endl;
    cout<<"    REGISTRO DE USUARIO"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"Ingrese su usuario >> ";cin>>user;
    do
    {
        cout<<"Ingrese su contrasena >> ";cin>>pass1;
        cout<<"Confirme su contrasena >> ";cin>>pass2;
        if(pass1!=pass2){
            cout<<"Contrasenas distintas, vuelve a ingresarlas"<<endl;
        }
    } while (pass1!=pass2);
    currentUser = createUser(user, pass2);
    cout<<"Usuario creado exitosamente, iniciando sesion automaticamente..."<<endl;
    return true;
}

User findUser(string username, string pass){
    //Buscar usuario por credenciales y retornarlo
    User user;
    user.username = "admin";
    user.password = "pass";
    return user;
}

User createUser(string username, string pass){
    //Registra el usuario en archivo txt y retorna su informacion
    User newUser;
    newUser.username = "admin";
    newUser.password = "pass";
    return newUser;
}

void displayMainMenu(){
    cout<<"----------------------------"<<endl;
    cout<<"           MENU"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"1. Reproducir playlist"<<endl;
    cout<<"2. Actualizar plan"<<endl;
    cout<<"3. Cerrar sesion"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"Tu opcion >>"; cin>>opcNormal;
}

void displayMainMenuPremium(){
    cout<<"----------------------------"<<endl;
    cout<<"           MENU"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"1. Ver playlist disponibles"<<endl;
    cout<<"2. Crear playlist"<<endl;
    cout<<"3. Ver mis playlist"<<endl;
    cout<<"4. Cerrar sesion"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"Tu opcion >>"; cin>>opcPremium;
}

bool conditionNormal(int opc){
    if(opc!=3) return true;
    else return false;
}

bool conditionPremium(int opc){
    if(opc!=4) return true;
    else return false;
}