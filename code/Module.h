#include "Course.h"
#include <iostream>
#include <string>
#include <vector>
//#include "CourseList.h"
//#include "all_headers.h"
using namespace std;

#ifndef MODULE_H
#define MODULE_H

#pragma once

class Course;
class CourseList;

class Module
{
public:
    // constructor 1 (default constructor)
    Module();

    // constructor 2, initializes name
    Module(string n);

    // getter for name
    string getName();

    // setter for name
    void setName(string n);

    // getter for class list
    vector<Course> getClassList() const;

    // method to add a class to the class list
    int addClass(Course* c); 

    // method to remove a class from the class list
    int removeClass(Course* c); 

    // getter for num credits
    float getNumcredits(); // maybe implement num credits as a variable that is set by itself by adding up the credits !!

    // setter for num credits
    void setNumCredits(float n);

    // add credits
    void addCredits(float c);

    // getter for type
    string getType();

    // setter for type
    void setType(string t);

    // getter for size
    int getSize();

    // destructor
    ~Module();

private:
    string name;
    vector<Course> classList;
    float numCredits;
    string type; // type is major, minor, specialization, etc...
    int size;
    // add entrance & grad requirements later !!!
};

#endif