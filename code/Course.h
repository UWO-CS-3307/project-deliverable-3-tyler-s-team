#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifndef COURSE_H
#define COURSE_H

#pragma once

// Forward declaration of CourseList
// class CourseList;

class Course {
public:
    Course();
    Course(std::string f, int i, char t, char b, float c);

    std::string getFaculty();
    void setFaculty(std::string f);

    int getCourseID();
    void setCourseID(int i);

    std::string getTitle();
    void setTitle(std::string t);

    char getType();
    void setType(char t);

    float getNumCredits();
    void setNumCredits(float n);

    const vector<Course> getPrereqs() const;
    int addPrereq(Course p);
    int removePrereq(Course p);

    std::string getCourseName();

    void setBreadth(char b);
    char getBreadth();

    ~Course();

private:
    std::string faculty;
    int courseID;
    std::string title;
    char type;
    float numCredits;
    vector<Course> prereqs;
    char breadth;
    int size;
};

#endif


/*#include <iostream>
#include <string>
//#include "CourseList.h"
using namespace std;

#ifndef COURSE_H
#define COURSE_H

#pragma once

// Forward declaration of CourseList
class CourseList;


class Course
{
public:
    // constructor 1 (default)
    Course();

    // constructor 2, only initializes faculty and course ID
    Course(string f, int i);

    //void setPrereqCount(int c);

    //int getPrereqCount();

    // getter for faculty
    string getFaculty();

    // setter for faculty
    void setFaculty(string f);

    // getter for course ID
    int getCourseID();

    // setter for course ID
    void setCourseID(int i);

    // getter for title
    string getTitle();

    // setter for title
    void setTitle(string t);

    // getter for type
    char getType();

    // setter for type
    void setType(char t);

    // getter for number of credits
    float getNumCredits();

    // setter for num credits
    void setNumCredits(float n);

    // getter for prereqs
    const vector<Course> getPrereqs() const;

    // setter for prereqs
    int addPrereq(Course p);

    // to remove a prereq, returns 0 for success, and returns 1 for class not found
    int removePrereq(Course p);

    // get the course name  (returns the facult + course number)
    string getCourseName();

    // setter for breadth
    void setBreadth(char b);

    // getter for breadth
    char getBreadth();


    // destructor
    ~Course();

private:
    string faculty;
    int courseID;
    string title;
    char type;
    float numCredits;
    CourseList prereqs;
    char breadth;
    //int prereqCount;
    int size;
    // later - add prereq count attribute !!
};

#endif*/