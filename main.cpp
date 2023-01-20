#include <iostream>
#include "UserDictionary.h"

using namespace std;

User* guestMenu(UserDictionary *users);
int printMenu(string mArray[], int menuLength);
User* registerUser(UserDictionary *users);
User* login(UserDictionary *users);
void topicMenu();
void postMenu();

int main() {
    cout <<  "----------------------"<< endl;
    cout <<  "//     DSA Forum    //"<< endl;
    cout <<  "----------------------"<< endl;

    //TODO: init users with text file(?)
    UserDictionary users;

    User *user = guestMenu(&users);

    cout << (user == nullptr ? "guest" : user->username) << endl;

    return 0;
}

User* guestMenu(UserDictionary *users) {
    string guestMenu[] = {"1. Register", "2. Log in", "3. Continue as Guest" };
    while (true) {
        User *user = nullptr;
        int option = printMenu(guestMenu, 3);
        switch (option) {
            case 1:
                cout << endl <<  "Register";
                user = registerUser(users);
                break;
            case 2:
                cout << endl << "Login";
                user = login(users);
                break;
            case 3:
                cout << "Guest menu " << endl;
                return nullptr;
            default:
                cout << "Please enter a valid option" << endl << endl;
                break;
        }
        if (user == nullptr) continue;
        else return user;
    }
}

int printMenu(string mArray[], int menuLength) {
    int chosen = 0;
    for (int i = 0; i < menuLength; i++) {
        cout << mArray[i] << endl;
    }
    cout << "Enter your option : ";
    cin >> chosen;
    cout << endl;
    return chosen;
}

User* registerUser(UserDictionary *users) {
    //TODO: input validation for usernames more than one word long
    string username;
    string password;

    cout << endl << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    bool result = users->add(username, password);
    cout << (result ? "User has been registered!" : "Username already exists!") << endl << endl;
    return result ? users->getUser(username, password) : nullptr;
}

User* login(UserDictionary *users) {
    string username;
    string password;

    cout << endl << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    User *user = users->getUser(username, password);

    cout << (user != nullptr ? "User has been logged in!" : "Incorrect Username or Password!") << endl << endl;
    return user;
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

