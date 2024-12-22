#include "Course.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


#ifndef COURSELIST_H
#define COURSELIST_H

#pragma once

class CourseList
{
public:
    // Constructor (default)
    CourseList();

    // getter
    const vector<Course> getCourseList() const;

    // adder
    int addCourse(Course c);

    // remover
    int removeCourse(Course c);

    // getter for credits
    float getCredits();

    // find a course in the list
    int findCourse(Course c);

    // destructor
    ~CourseList();

private:
    vector<Course> list;
    float credits;
};

#endif