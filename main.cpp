#include <iostream>
#include "UserDictionary.h"

using namespace std;

User* mainMenu(UserDictionary *users);
int printMenu(string mArray[], int menuLength);
User* registerUser(UserDictionary *users);
User* login(UserDictionary *users);
void guestMenu();
void userMenu();
User* userProfile(UserDictionary *users);
void topicMenu();
void createTopic();
void postMenu();

int main() {
    cout <<  "----------------------"<< endl;
    cout <<  "//     DSA Forum    //"<< endl;
    cout <<  "----------------------"<< endl;

    //TODO: init users with text file(?)
    UserDictionary users;

    User *user = mainMenu(&users);
    cout << (user == nullptr ? "guest" : user->username) << endl;

    return 0;
}

User* mainMenu(UserDictionary *users) {
    string guestMenu[] = {"1. Register", "2. Log in", "3. Continue as Guest", "Press CTRL + C to exit" };
    while (true) {
        User *user = nullptr;
        int option = printMenu(guestMenu, 4);
        switch (option) {
            case 1:
                cout <<  "Register";
                user = registerUser(users);
                break;
            case 2:
                cout << "Login";
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

void guestMenu() {
    string guestMenu[] = {"1. View Topics", "2. Search", "3. Exit"};
    int option = printMenu(guestMenu, 3);
    switch (option) {
        case 1:
            cout << "Display Topics Menu";
            break;
        case 2:
            cout << "Display Search Menu";
            break;
        case 3:
            cout << "Exit to Main Menu";

            break;
        default:
            cout << "Please enter a valid option";
            break;
    }
}

void userMenu() {
    string userMenu[] = {"1. View User Info", "2. View Topics", "3. Search", "4.Logout"};
    int option = printMenu(userMenu, 4);
    switch (option) {
        case 1:
            cout << "Display User Profile";
            break;
        case 2:
            cout << "Display Topics Menu";
            break;
        case 3:
            cout << "Display Search Options";
            break;
        case 4:
            cout << "Bring to main menu";
            break;
        default:
            cout << "Please enter a valid input" << endl;
            break;
    }
}

User* userProfile(UserDictionary *user) {
    cout << "Display Current User's Username";
    string userProfileMenu[] = {"1. View All Created Topics", "2. View All Created Posts", "3. Back"};
    int option = printMenu(userProfileMenu,3);
    switch (option) {
        case 1:
            cout << "Display all topics created by user";
            break;
        case 2:
            cout << "Display all posts created by user";
            break;
        case 3:
            cout << "Return to User Menu";
            break;
        default:
            cout << "Please enter a valid input" << endl;
            break;
    }
}

void topicMenu() {
    string topicMenu[] = {"1. View All Topics","2. Create Topic", "3. Search Topics", "4. Back"};
    int option = printMenu(topicMenu, 4);
    //TODO: make it loop
//    while (true) {
        switch (option) {
            case 1:
                cout << "Display topics";
                break;
            case 2:
                cout << "Creating new topic";
                createTopic();
                break;
            case 3:
                cout << "Search Topics";
                break;
            case 4:
                cout << "Back to User Menu or Guest Menu";
                // Check if user ==
                break;
            default:
                cout << "Please enter a valid option" << endl;
                break;
//        }
    }
}

void createTopic() {
    string title;

    cout << endl << "Enter the topic title: ";
    cin >> title;

    //Add topic
    cout << "Topic Created" << endl;
}



void postMenu() {
    string postMenu[11];
    //TODO: Read posts from data, add to array, add back to topics page;
}

