#include "Authenticator.h"
using namespace std;

// ||| SINGLETON |||

// constructor
Authenticator::Authenticator() {}

// getter for instance, if the authenticator is not initialized, it creates the instance then returns it
Authenticator* Authenticator::getInstance() 
{
    // if the instance hasn't been initialized yet, call the constructor then return the instance
    if (instance == nullptr) instance = new Authenticator();
    return instance;
}

// returns the user that is currently logged in
Student* Authenticator::getUser()
{
    if (loggedIn == "no") perror("Error: No user is currently logged in.");
    return &loggedInUser;
}

// logs in user and opens main screen
int Authenticator::loginAttempt(const string& username, const string& password)
{
    // ADD IN CALL TO DATABASE LATER!!!!!!!!

    // test username and password for saved user
    if (username == "tlarson3" && password == "abcd") {
        Student *loggedInUser = new Student(251207256, "Tyler Larson", 2026, "tlarson3@uwo.ca");
        loggedIn = "yes";
        return 0;
    }

    else if (username != "tlarson3") {
        loggedIn = "yes";
        return 1;
    }

    else {
        printf("incorrect password, please try again.\n");
        return 2;
    }
}

// logs out user and opens login screen
void Authenticator::logout()
{
    loggedIn = "no";
    delete &loggedInUser;
    //loggedInUser = nullptr;
}

Student* Authenticator::printLogin()
{
    printf("\n---------------------------------------------------------\n");
    printf("\n------------------------~LOGIN~--------------------------\n");

    string username;
    string password;

    cout << "Enter username: ";
    getline(cin, username);

    cout << "Enter password: ";
    getline(cin, password);

    printf("~\n");
    printf("~\n");
    printf("~\n");

    int l = loginAttempt(username, password);

    if (l == 0) {
        cout << "Login success!" << endl;
    } 
    
    else if (l == 1) {
        cout << "Welcome! Please sign up" << endl;

        int id;
        std::string name;
        int graduationYear;

        // Ask the user for student ID
        std::cout << "Enter Student ID: ";
        std::cin >> id;

        // Clear the input buffer to avoid issues with getline
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Ask the user for name
        std::cout << "Enter Name: ";
        std::getline(std::cin, name);

        // Ask the user for expected graduation year
        std::cout << "Enter Expected Graduation Year: ";
        std::cin >> graduationYear;

        // Create a new Student object
        Student *loggedInUser = new Student(id, name, graduationYear);
    }

    else {
        cout << "Invalid username or password. please try again." << endl;
        printLogin();
    }

    printf("~\n");
    printf("~\n");
    printf("~\n");

    return &loggedInUser;
}



// destructor
Authenticator::~Authenticator()
{

}

Authenticator* Authenticator::instance = nullptr;