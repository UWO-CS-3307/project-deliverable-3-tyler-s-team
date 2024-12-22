#include <iostream>
#include <string>
#include "Observer.h"
#include "Student.h"
//#include "all_headers.h"
using namespace std;

#ifndef COURSENAVIGATOR_H
#define COURSENAVIGATOR_H

#pragma once


class CourseNavigator : public Observer
{
public:
    CourseNavigator();

    void printCompletedCourses(Student* u);

    //void printCurrentCourses(Student u);

    void printUpcomingCourses(Student* u);

    void update(Student* u);

    ~CourseNavigator();

private:

};

#endif