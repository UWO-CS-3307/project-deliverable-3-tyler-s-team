//#include "Person.h"
#include "Student.h"
#include <iostream>
#include <string>
//#include "all_headers.h"
#include <iostream>
#include <string>
using namespace std;

#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H

#pragma once


// TO DO: -add REGISTER option!!


class Authenticator
{
public:
    // Delete copy constructor and assignment operator to prevent cloning
    Authenticator(const Authenticator&) = delete;
    Authenticator& operator=(const Authenticator&) = delete;

    // returns the instance of Authenticator, if it's not initialized, it creates the instance then returns it
    static Authenticator* getInstance();

    // returns student object that is logged in
    Student* getUser();

    // logs in user and opens main screen
    int loginAttempt(const string& username, const string& password);

    Student* printLogin();

    // logs out user and opens login screen
    void logout();

    


private:
    static Authenticator* instance; 
    Student loggedInUser;
    Student savedStudent;
    string loggedIn = "no";
    // Student* user;

    // constructor
    Authenticator();

    // destructor
    ~Authenticator();
};


#endif