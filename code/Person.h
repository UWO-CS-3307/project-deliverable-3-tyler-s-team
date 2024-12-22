#include <iostream>
#include <string>
using namespace std;

#ifndef PERSON_H
#define PERSON_H

#pragma once 

class Person
{
public:
    // constructor 1 (default): sets default values to ID and name
    Person();

    // Constructor 2: Sets ID and name
    Person(int i, string n);

    // Constructor 3: Sets ID, name, and email
    Person(int i, string n, string e);

    // Setter for email
    void setEmail(string e);

    // Getter for ID
    int getID() const;

    // Getter for name
    string getName() const;

    // Getter for email
    string getEmail() const;

    // destructor
    ~Person(); 

protected:
    int ID;
    string name;
    string email;
};

#endif