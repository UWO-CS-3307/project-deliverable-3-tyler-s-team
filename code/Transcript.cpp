#include "Transcript.h"
#include "Student.h"
#include "RequirementDashboard.h"
#include "ProgressBar.h"
#include "CourseNavigator.h"
#include "Authenticator.h"
using namespace std;

Transcript::Transcript() : size(0) {}

// getter for completed list
const vector<Course> Transcript::getCompleted() const
{
    return completed;
}

// adder for completed
int Transcript::addCompleted(Course c, int g)
{
    // check if the course is already in the list
    for (int i = 0; i < completed.size(); i++) {
        if (completed[i].getCourseName() == c.getCourseName()) {
            return 1;
        }
    }

    // add course to list and incrament credits
    completed.push_back(c);
    grades.push_back(g);
    notifyObservers(); // is this where/how im supposed to do this??????????????
    return 0;

    /*// create a new size & completed 1 bigger than the origional
    int newSize = size + 1;
    Course* newCompleted = new Course[newSize];

    // copy old completed array to new array
    if (completed) { 
        memcpy(newCompleted, completed, size * sizeof(Course));
    }

    newCompleted[size] = c;

    // create new grades array
    int* newGrades = new int[newSize];

    // copy old grades to new array
    if (grades) { 
        memcpy(newGrades, grades, size * sizeof(int));
    }

    newGrades[size] = g;

    // clear old array data & replace it with the new arrays
    delete[] completed;
    completed = newCompleted;

    delete[] grades;
    grades = newGrades;

    size = newSize;

    notifyObservers();*/
}

// remove completed, returns 0 for success & 1 for error (IF THERE ARE MULTIPLE OF THE SAME COURSE, ONLY ONE WILL BE ERASED)
int Transcript::removeCompleted(Course c)
{
    // look for course in list
    int index = -1;
    for (int i = 0; i < completed.size(); i++) {
        if (completed[i].getCourseName() == c.getCourseName()) index = i;
    }

    // if the course is not in the list, return 1
    if (index == -1) {
        printf("Course not found in list\n");
        return 1;
    }

    // remove the course from the list and decrement credits
    completed.erase(completed.begin()+index); // test this !!!!!!!!!!!!!!!!!
    grades.erase(grades.begin() + index);
    notifyObservers(); // is this where/how im supposed to do this??????????????
    return 0;
    

    /*// look through completed array to find the index of the course to remove 
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (completed[i].getFaculty() == c.getFaculty() && completed[i].getCourseID() == c.getCourseID()) {
            index = i;
            break;
        }
    }

    // if the course isnt in the array, return 1
    if (index == -1) return 1;

    // create a new size and completed for the smaller array
    int newSize = size - 1;
    Course* newCompleted = new Course[newSize];

    // copy everything from the old array to the new array, except the course to remove
    for (int i = 0; i < newSize; i++) {
        if (i < index) {
            newCompleted[i] = completed[i];
        }

        else {
            newCompleted[i] = completed[i + 1];
        }
    }

    // create new grades array for smaller size
    int* newGrades = new int[newSize];

    // copy everything from the old array to the new array, except the grade to remove
    for (int i = 0; i < newSize; i++) {
        if (i < index) {
            newGrades[i] = grades[i];
        }

        else {
            newGrades[i] = grades[i + 1];
        }
    }

    // clear old arrays & update attributes
    delete[] completed;
    completed = newCompleted;

    delete[] grades;
    grades = newGrades;

    size = newSize;

    notifyObservers();

    return 0;*/
}

// change grade for a completed course
int Transcript::changeGrade(Course c, int g) 
{
    // ensure the course is in the list
    int index = -1;
    for (int i = 0; i < completed.size(); i++) {
        if (completed[i].getCourseName() == c.getCourseName()) index = i;
    }
    if (index == -1) {
        printf("Course not found in list\n");
        return 1;
    }

    grades[index] = g;
    printf("grade for %s chanded to %d\n", c.getCourseName(), g);
    notifyObservers(); // is this where/how im supposed to do this??????????????
    return 0;

    /*// look through array to find the index of the course 
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (completed[i].getFaculty() == c.getFaculty() && completed[i].getCourseID() == c.getCourseID()) {
            index = i;
            break;
        }
    }

    // if the course isnt in the array, return 1
    if (index == -1) return 1;

    // change the corresponding grade
    grades[index] = g;

    notifyObservers();

    return 0;*/
}

// getter for grades
const vector<int> Transcript::getGrades() const
{
    return grades;
}

// getter for size
int Transcript::getSize()
{
    return size;
}

// 
void Transcript::notifyObservers()
{
    //Authenticator* a = Authenticator.getInstance();
    Authenticator* a = Authenticator::getInstance();
    Student *s = a->getUser();

    CourseNavigator *cn = s->getCourseNavigator();
    ProgressBar *pb = s->getProgressBar();
    RequirementDashboard *rd = s->getRequirementDashboard();

    cn->update(s);
    pb->update(s);
    rd->update(s);
}

// destrutor 
Transcript::~Transcript()
{

}