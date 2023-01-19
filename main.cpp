#include <iostream>
using namespace std;

void guestMenu();
int printMenu(string mArray[], int menuLength);


void registerUser();

void login();

int main() {
    cout <<  "----------------------"<< endl;
    cout <<  "//     DSA Forum    //"<< endl;
    cout <<  "----------------------"<< endl;

    guestMenu();
}

int printMenu(string mArray[], int menuLength) {
    int chosen = 0;
    for (int i = 0; i < menuLength; i++) {
        cout << mArray[i] << endl;
    }
    cout << "Enter your option : " << endl;
    cin >> chosen;
    return chosen;
}

void guestMenu() {
    string guestMenu[] = {"1. Register", "2. Log in", "3. Continue as Guest" };
    int option = printMenu(guestMenu, 3);
    switch(option) {
        case 1:
            cout << endl <<  "Register";
            registerUser();
            break;
        case 2:
            cout << endl << "Login";
            login();
            break;
        case 3:
            cout << "Guest menu thingie" << endl;
            break;
        default:
            cout << "Please enter a valid option" << endl;
    }
}

void registerUser() {
    //TODO: input validation for usernames more than one word long
    string username;
    string password;
    cout << endl << "Enter unique username: ";
    cin >> username;
    //TODO: search for username in user tree

    cout << "Enter password: ";
    cin >> password;

    //TODO: go to topic page
}

void login() {
    string username;
    string password;
    cout << endl << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    //TODO: search for username in user tree

    //TODO: go to topic page
}