#include <iostream>
#include <string>
#include <vector>
#include "Course.h"
//#include "Student.h"
using namespace std;

#ifndef TRANSCRIPT_H
#define TRANSCRIPT_H

#pragma once


class Transcript
{
public:
    Transcript();

    // getter for completed courses
    const vector<Course> getCompleted() const;

    // adder for completed, returns 0 for success & 1 for error
    int addCompleted(Course c, int g);

    // remove completed, returns 0 for success & 1 for error
    int removeCompleted(Course c);

    // change completed grade, returns 0 for success & 1 for error (IF THERE ARE MULTIPLE OF THE SAME COURSE, ONLY 1 WILL BE ERASED)
    int changeGrade(Course c, int g);

    // getter for grades
    const vector<int> getGrades() const;

    // getter for size
    int getSize();

    

    ~Transcript();

protected:
    vector<Course> completed;
    vector<int> grades;
    int size;
    void notifyObservers();
};

#endif