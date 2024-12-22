#include "Student.h"
#include "RequirementDashboard.h"
#include "CourseNavigator.h"
#include "ProgressBar.h"
using namespace std;


// constructor 1, default constructor, takes no inputs & uses default values
Student::Student() 
{
    //classes = new CourseList();
    //modules = new ModuleList();
    ID = 0;
    name = "student name";

    RequirementDashboard *requirementDashboard = new RequirementDashboard();
    CourseNavigator *courseNavigator = new CourseNavigator();
    ProgressBar *progressBar = new ProgressBar();
}


// constructor 2, initializes ID, name, classes, modules, and grad year
Student::Student(int i, string n, int g) 
{
    //classes = new CourseList();
    //modules = new ModuleList();
    ID = i;
    name = n;
    gradYear = g;

    RequirementDashboard *requirementDashboard = new RequirementDashboard();
    CourseNavigator *courseNavigator = new CourseNavigator();
    ProgressBar *progressBar = new ProgressBar();
}

// constructor 3, initializes ID, name, grade year, classes, modules, and also email
Student::Student(int i, string n, int g, string e)
{
    //classes = new CourseList();
    //modules = new ModuleList();
    ID = i;
    name = n;
    gradYear = g;
    email = e;

    RequirementDashboard *requirementDashboard = new RequirementDashboard();
    CourseNavigator *courseNavigator = new CourseNavigator();
    ProgressBar *progressBar = new ProgressBar();
}

// getter for grad year
int Student::getGradYear()
{
    return gradYear;
}

// setter for grad year
void Student::setGradYear(int g)
{
    gradYear = g;
}

// getter for academic status
string Student::getAcademicStatus()
{
    return academicStatus;
}

// setter for academic status
void Student::setAcademicStatus(string a)
{
    academicStatus = a;
}

// getter for modules
const vector<Module> Student::getModules() const
{
    return modules;
}

// adder for modules, returns 0 for success & 1 for error
int Student::addModule(Module m)
{
    // check if the module is already in the list
    for (int i = 0; i < modules.size(); i++) {
        if (modules[i].getName() == m.getName() && modules[i].getType() == m.getType()) {
            printf("module is already in list\n");
            return 1;
        }
    }

    // add module to list
    modules.push_back(m);
    return 0;


    /*// check and return 1 if the module is already in the list
    for (int i = 0; i < size; i++) {
        if (modules[i].getName() == m.getName()) {
            return 1;
        }
    }

    // returns 1 if there are already 3 or more modules in the list
    if (size > 2) return 1;

    // create new classList & size variables 1 larger than the exsisting
    int newSize = size + 1;
    Module* newModules = new Module[newSize]; 

    // copy old courses to new array
    if (modules) { 
        memcpy(newModules, modules, size * sizeof(Course));
    }

    newModules[size] = m;

    // clear old courses data & replace it with the new courses array
    delete[] modules;
    modules = newModules;

    // replace old size attribute
    size = newSize;

    return 0;*/
}

// remover for modules
int Student::removeModule(Module m)
{
    // look for module in list
    int index = -1;
    for (int i = 0; i < modules.size(); i++) {
        if (modules[i].getName() == m.getName() && modules[i].getType() == m.getType()) index = i;
    }

    // if the course is not in the list, return 1
    if (index == -1) {
        printf("module not found in list\n");
        return 1;
    }

    // remove the course from the list and decrement credits
    else {
        modules.erase(modules.begin()+index); // test this !!!!!!!!!!!!!!!!!
        return 0;
    }


    /*// look through modules array to find the index of the module to remove 
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (modules[i].getName() == m.getName()) index = i;
    }

    // if the module isnt in the array, return 1
    if (index == -1) return 1;

    // create new size and modules variables
    int newSize = size - 1;
    Module* newModules = new Module[newSize];

    // copy everything from the old array to the new array, except the module to remove
    for (int i = 0; i < newSize; i++) {
        if (i < index) {
            newModules[i] = modules[i];
        }

        else {
            newModules[i] = modules[i + 1];
        }
    }

    // clear old array & update attributes
    delete[] modules;
    modules = newModules;

    size = newSize;

    return 0;*/
}

// getter for transcript
Transcript Student::getTranscript()
{
    return transcript;
}

// getter for classes
const vector<Course> Student::getClasses() const
{
    return classes;
}

// adder for classes, won't accept duplicate courses, returns 0 for success or 1 for error
int Student::addClass(Course c) 
{
    // check if the course is already in the list
    for (int i = 0; i < classes.size(); i++) {
        if (classes[i].getCourseName() == c.getCourseName()) {
            printf("course is already in list\n");
            return 1;
        }
    }

    // add course to list and incrament credits
    classes.push_back(c);
    //credits += c.getNumCredits();
    return 0;


    /*// check and return 1 if the course is already in the list
    for (int i = 0; i < size; i++) {
        if (classes[i].getCourseID() == c.getCourseID() && classes[i].getFaculty() == c.getFaculty()) {
            return 1;
        }
    }

    // create new classes & size variables 1 larger than the exsisting
    int newSize = size + 1;
    Course* newClasses = new Course[newSize]; 

    // copy old courses to new array
    if (newClasses) { 
        memcpy(newClasses, classes, size * sizeof(Course));
    }

    newClasses[size] = c;

    // clear old classes data & replace it with the new classes array
    delete[] classes;
    classes = newClasses;

    // replace old size attribute
    size = newSize;

    return 0;*/
}

// remover for classes
int Student::removeClass(Course c) 
{
    // look for course in list
    int index = -1;
    for (int i = 0; i < classes.size(); i++) {
        if (classes[i].getCourseName() == c.getCourseName()) index = i;
    }

    // if the course is not in the list, return 1
    if (index == -1) {
        printf("Course not found in list\n");
        return 1;
    }

    // remove the course from the list and decrement credits
    else {
        classes.erase(classes.begin()+index); // test this !!!!!!!!!!!!!!!!!
        //float creds = c.getNumCredits();
        //credits -= creds;
        return 0;
    }


    /*// look through classes array to find the index of the course to remove 
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (classes[i].getFaculty() == c.getFaculty() && classes[i].getCourseID() == c.getCourseID()) {
            index = i; 
        }
    }

    // if the course isnt in the array, return 1
    if (index == -1) return 1;

    // create a new size and completed for the smaller array
    int newSize = size - 1;
    Course* newClasses = new Course[newSize];

    // copy everything from the old array to the new array, except the course to remove
    for (int i = 0; i < newSize; i++) {
        if (i < index) {
            newClasses[i] = classes[i];
        }

        else {
            newClasses[i] = classes[i + 1];
        }
    }

    // clear old array & update attributes
    delete[] classes;
    classes = newClasses;

    size = newSize;

    return 0;*/
}

// getter for requirementDashboard
RequirementDashboard* Student::getRequirementDashboard()
{
    return requirementDashboard;
}

// getter for course navigator
CourseNavigator* Student::getCourseNavigator()
{
    return courseNavigator;
}

// getter for progressBar
ProgressBar* Student::getProgressBar()
{
    return progressBar;
}

// destructor
Student::~Student()
{

}