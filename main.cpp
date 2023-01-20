#include <iostream>

using namespace std;

int printMenu(string mArray[], int menuLength);
int guestMenu();
void registerUser();
void login();
void topicMenu();

void postMenu();

int main() {
    cout <<  "----------------------"<< endl;
    cout <<  "//     DSA Forum    //"<< endl;
    cout <<  "----------------------"<< endl;

    int status = guestMenu();

    return 0;
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

int guestMenu() {
    string guestMenu[] = {"1. Register", "2. Log in", "3. Continue as Guest" };
    int option = printMenu(guestMenu, 3);
    switch(option) {
        case 1:
            cout << endl <<  "Register";
            registerUser();
            return 1;
        case 2:
            cout << endl << "Login";
            login();
            return 1;
        case 3:
            cout << "Guest menu " << endl;
        default:
            cout << "Please enter a valid option" << endl;
    }
    return 0;
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

    //TODO: Add user into user class

    cout<< "User has been registered!" << endl << endl;
}

void login() {
    string username;
    string password;
    cout << endl << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    //TODO: search for username in user tree

    cout<< "User has been logged in!" << endl << endl;
}

void topicMenu() {
    string topicMenu[] = {"1. View Topics","2.Create Topic"};
    int option = printMenu(topicMenu, 2);
    switch (option) {
        case 1:
            cout << endl << "Display topics";
            break;
        case 2:
            cout << endl << "Creating new topic";
            break;
    }
}

void postMenu() {
    string postMenu[11];
    //TODO: Read posts from data, add to array, add back to topics page;
}

