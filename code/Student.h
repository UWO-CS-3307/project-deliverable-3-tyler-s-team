#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
#include "Course.h"
#include "Module.h"
#include "Transcript.h"
using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

#pragma once


class RequirementDashboard;
class CourseNavigator;
class ProgressBar;


class Student : public Person
{
public:
    // constructor 1 (default)
    Student();

    // constructor 2
    Student(int i, string n, int g);
    
    // constructor 3
    Student(int i, string n, int g, string e);

    // getter for grad year
    int getGradYear();

    // setter for grad year
    void setGradYear(int i);

    // getter for academic status
    string getAcademicStatus();

    // setter for academic status
    void setAcademicStatus(string a);

    // getter for modules
    const vector<Module> getModules() const;

    // adder for modules
    int addModule(Module m);

    // remover for module
    int removeModule(Module m);

    // getter for transcript
    Transcript getTranscript();

    // getter for classes
    const vector<Course> getClasses() const; 

    // adder for classes
    int addClass(Course c); 

    // remover for classes
    int removeClass(Course c);

    // getter for requirementDashboard
    RequirementDashboard* getRequirementDashboard();

    // getter for course navigator
    CourseNavigator* getCourseNavigator();

    // getter for progressBar
    ProgressBar* getProgressBar();

    // destructor
    ~Student();

private:
    int gradYear;
    vector<Module> modules;
    string academicStatus;
    Transcript transcript;
    vector<Course> classes;
    int size;
    RequirementDashboard *requirementDashboard;
    CourseNavigator *courseNavigator;
    ProgressBar *progressBar;
    // add more later !!
};

#endif