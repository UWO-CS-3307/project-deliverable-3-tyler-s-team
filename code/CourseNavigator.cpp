#include "CourseNavigator.h"
using namespace std;

CourseNavigator::CourseNavigator()
{

}

void CourseNavigator::printCompletedCourses(Student* u)
{
    Transcript transcript = u->getTranscript();
    vector<Course> completedCourses = transcript.getCompleted();


    if (completedCourses.size() == 0) printf("Completed Courses: none\n");

    else {
        printf("Completed Courses:\n");
        for (int i = 0; i < completedCourses.size(); i++) {
            printf("%s, ", completedCourses[i].getCourseName());
            i++;
            if (i < completedCourses.size()) printf("%s, ", completedCourses[i].getCourseName());
            printf("\n");
        }

        printf("\n");
    }
}

/*void CourseNavigator::printCurrentCourses(Student u)
{
    vector<Course> currentCourses = u.getClasses();

    // display array values to app screen !!!
}*/


// I'm somewhat using Facade Pattern here right?

void CourseNavigator::printUpcomingCourses(Student* u)
{
    vector<Module> modules = u->getModules();
    Transcript transcript = u->getTranscript();
    const vector<Course> completedCourses = transcript.getCompleted();
    vector<Course> currentCourses = u->getClasses();

    // only for the 1st module for now, implement others later !!!!!
    Module m1 = modules[0];
    const vector<Course> m1Courses = m1.getClassList();
    vector<Course> remaining;

    for (int i = 0; i < m1Courses.size(); i++) {
        int flag = 0;
        for (int j = 0; j < completedCourses.size(); j++) {
            if (m1Courses[i].getCourseName() == completedCourses[j].getCourseName()) flag = 1;
        }

        if (flag != 1) remaining.push_back(m1Courses[i]);
    }

    printf("Remaining Courses:\n");
    for (int i = 0; i < remaining.size(); i++) {
        printf("%s, ", remaining[i].getCourseName());
        i++;
        if (i < remaining.size()) printf("%s, ", remaining[i].getCourseName());
        printf("\n");
    }
    printf("\n");
}

void CourseNavigator::update(Student* u)
{
    printf("\n--------------------------------------------------\n");
    printf("                ~COURSE NAVIGATOR~                  \n");

    printCompletedCourses(u);
    printUpcomingCourses(u);

    printf("\n--------------------------------------------------\n");
}

CourseNavigator::~CourseNavigator()
{

}