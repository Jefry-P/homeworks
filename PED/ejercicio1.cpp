#include <iostream>
#include <list>
#include <vector>
using namespace std;


int idRestaurant = 0;
int idDelivery = 0;

struct ItemPrice {
    string item;
    float price;
};

struct Order {
    int id;
    string name;
    vector<ItemPrice> mainDish;
    vector<ItemPrice> drink;
    vector<ItemPrice> entry;
    int type;
    int paymentMethod;
    string address;
    float totalOrder = 0;
};


list<Order> OrderlistDelivery;
list<Order> OrderlistRestaurant;


bool login(string user, string pass){
    string correctUser = "user", correctPass = "pass";
    if(user == correctUser && pass == correctPass) return true;
    else return false;
}


void showMenu(){
    cout<<"Platos principales:"<<endl;
    cout<<"1. Pizza de pepperoni - 5.99"<< endl<< "2. Pizza de jamon - 4.99"<<endl;
    cout<<"Bebidas:"<<endl;
    cout<<"1. Te helado" << endl<< "2. Soda" <<endl;
    cout<<"Entradas:"<<endl;
    cout<<"1. Nuditos de ajo" << endl<< "2. Pan con ajo" <<endl;
}

ItemPrice getMainDish(int dish){
    ItemPrice item;
    switch (dish)
    {
    case 1:
        item.item = "Pizza de pepperoni"; 
        item.price = 5.99;
        return item;
        break;
    case 2:
        item.item = "Pizza de jamon"; 
        item.price = 4.99;
        return item;
        break;
    default:
        item.item = "Invalid Dish";
        item.price = 0.0;
        return item;
        break;
    }

}

ItemPrice getDrink(int drink){
    ItemPrice item;
    switch (drink)
    {
    case 1:
        item.item = "Te helado"; 
        item.price = 2.50;
        return item;
        break;
    case 2:
        item.item = "Soda"; 
        item.price = 2.00;
        return item;
        break;
    default:
        item.item = "Invalid Dish";
        item.price = 0.0;
        return item;
        break;
    }

}

void addOrder(){
    Order item;
    string name, address;
    item.totalOrder = 0;
    bool anotherEntry = false, anotherMainDish = false, anotherDrink = false;
    int paymentMethod, type, mainDish, selectedDrink, entry;

    cout<<"Tipo de orden: " << endl << "1. Comer en local  2. A domicilio"<< endl;
    cin>> type;
    item.type = type;
    

    cout<<"Ingrese su nombre"<< endl;
    cin >> name;
    item.name = name;
    ItemPrice dish;
    do
    {
        showMenu();
        cout<<"Seleccione un plato principal"<< endl;
        cin>>mainDish;
        dish = getMainDish(mainDish);
        item.mainDish.push_back(dish);
        cout<<"Desea agregar otro plato principal?"<<endl<<"1. Si  2. No"<<endl;
        cin>>mainDish;
        mainDish == 1 ? anotherMainDish = true: anotherMainDish = false;
    } while (anotherMainDish);

    ItemPrice drink;
    do
    {
        showMenu();
        cout<<"Seleccione una bebida"<< endl;
        cin>>selectedDrink;
        dish = getDrink(selectedDrink);
        item.mainDish.push_back(dish);
        cout<<"Desea agregar otro plato principal?"<<endl<<"1. Si  2. No"<<endl;
        cin>>selectedDrink;
        selectedDrink == 1 ? anotherDrink = true: anotherDrink = false;
    } while (anotherDrink);

    bool paymentMethodBool = false;
    do
    {   
        paymentMethod = false;
        cout<<"Metodos de pago: " << endl<< "1. Efectivo  2. Tarjeta"<<endl;
        cin>>paymentMethod;
        paymentMethodBool = true;
        if(type == 2 && paymentMethod == 1){
            cout<<"Metodo de pago invalido para ordenes a domicilio, seleccione pago por tarjeta" << endl;
            paymentMethodBool = false;
        }
        
    } while (!paymentMethodBool);
    
    item.paymentMethod = paymentMethod;
    
    

    for (int i = 0; i < item.mainDish.size(); i++)
    {
        item.totalOrder += item.mainDish[i].price;
    }

    for (int i = 0; i < item.drink.size(); i++)
    {
        item.totalOrder += item.drink[i].price;
    }

    cout<<"Total de orden: " << item.totalOrder<<endl;

    if(type == 2){
        cout<<"Ingrese la direccion de entrega: " << endl;
        cin>>address;
        item.address = address;

        idDelivery++;
        item.id = idDelivery;
        OrderlistDelivery.push_back(item);
        
    } else {
        idRestaurant++;
        item.id = idRestaurant;
        OrderlistRestaurant.push_back(item);
    }
}

void showOrdersRestaurant(){
    for (auto item : OrderlistRestaurant)
    {
        cout<<"Orden numero: " << item.id <<endl;
        cout<<"Nombre: " << item.name<<endl;
        cout<< "Platos:"<<endl;

        for (int j = 0; j < item.mainDish.size(); j++)
        {
            cout<< item.mainDish[j].item<< " - "<< item.mainDish[j].price<<endl;
        }
        cout<<"Total orden: " << item.totalOrder<<endl;
        cout<<"Metodo de pago: " << item.paymentMethod<<endl;
    }
}

void showOrdersDelivery(){
    
}

// Función recursiva para calcular la suma total de los campos "totalOrder"
float calcularSumaTotalRecursiva(const std::list<Order>& orders, std::list<Order>::const_iterator orderIt) {
    // Caso base: si llegamos al final de la lista, retornamos 0
    if (orderIt == orders.end()) {
        return 0.0;
    }

    // Llamada recursiva para el siguiente elemento de la lista
    return orderIt->totalOrder + calcularSumaTotalRecursiva(orders, std::next(orderIt));
}


int main(){
    bool inicioSesion = false;
    string user, pass;

    // Llenar la lista con datos ficticios
    Order order1, order2, order3;
    order1.totalOrder = 50.0;
    order2.totalOrder = 30.0;
    order3.totalOrder = 40.0;

    OrderlistDelivery.push_back(order1);
    OrderlistDelivery.push_back(order2);
    OrderlistDelivery.push_back(order3);


    do
    {   
        cout<<"Ingrese su usuario: " << endl;
        cin >> user;
        cout<<"Ingrese su contraseña: " << endl;
        cin>>pass;
        inicioSesion = login(user, pass);
        if(inicioSesion == false) { 
            cout<<"Credenciales incorrectas, vuelva a intentarlo..." << endl;
        }
    } while (!inicioSesion);
    
    int option;
    bool continueMenu = true;
    float total = 0;
    do
    {
        cout<<"Menu" << endl;
        cout<<"1. Agregar orden"<<endl;
        cout<<"2. Mostrar ordenes en local"<<endl;
        cout<<"3. Mostrar ordenes a domicilio"<<endl;
        cout<<"4. Mostrar total de todas las ordenes en local"<<endl;
        cout<<"5. Mostrar total de todas las ordenes a domicilio"<<endl;
        cin>>option;
        switch (option)
        {
        case 1:
            addOrder();
            break;
        case 2:
            showOrdersRestaurant();
            break;
        case 3:
            showOrdersRestaurant();
            break;
        case 4:
            total = calcularSumaTotalRecursiva(OrderlistDelivery, OrderlistDelivery.begin());
            cout<< "Total de todas las ordendes delivery: "<< total<<endl;
            break;
        default:
            continueMenu = false;
            break;
        }

    } while (continueMenu);
    
    
    return 0;
} 


