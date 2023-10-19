#include <iostream>
using namespace std;

struct User{
    string username;
    string password;
    bool premium = true;
};

struct Song{
    string name;
    string artist;
    string duration;
    string album;
    string gender;
};

void displayLoginMenu();

bool login();
User findUser(string username, string pass);
User createUser(string username, string pass);
bool registerUser();

void displayMainMenu();
void displayMainMenuPremium();
bool conditionNormal(int opc);
bool conditionPremium(int opc);