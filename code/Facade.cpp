#include "Facade.h"
#include "Student.h"
#include "Authenticator.h"
#include "RequirementDashboard.h"
#include "ProgressBar.h"
#include "RequirementDashboard.h"
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>
using namespace std;

Facade::Facade(Authenticator *a) 
{
    auth = a;
}

void Facade::mainScreen(Student *s)
{
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n------------------------Welcome %s-----------------------\n");
    printf("\n");

    ProgressBar *pb = s->getProgressBar();
    RequirementDashboard *rd = s->getRequirementDashboard();
    CourseNavigator *cn = s->getCourseNavigator();

    pb->update(s);
    rd->update(s);
    cn->update(s);


    int flag = 0;

    while (flag == 0)
    {
        string userInput;

        printf("Navigation options (type the character then press enter): Logout - 'L', Add Class Grade - 'A', Exit - 'E'\n");
        std::cin >> userInput;

        // Convert to uppercase to handle lowercase input
        userInput = std::toupper(userInput);

        // Process input
        if (userInput == 'L') {
            auth->logout();
        } 
        else if (userInput == 'A') {
            editCoursesScreen(s); 
        } 
        else if (userInput == 'E') {
            exit(0);
        } 
        else {
            std::cout << "Invalid input! Please try again." << std::endl;
        }
    }
}

void Facade::loginScreen()
{
    Student *s = auth->printLogin();
    mainScreen(s);
}

void Facade::editCoursesScreen(Student *s)
{
    vector<Module> mods = s->getModules();
    Module mod = mods[0];
    vector<Course> modCourses = mod.getClassList();
    Transcript *tr = s->getTranscript();

    printf("\n");
    int flag = 0;

    while (flag == 0)
    {
        string userInput;
        int number;

        printf("What is the class you would like to add? please use the format of 'compsci 1026', 'economics 1021', or 'calculus 1000'. or enter 'M' to return to the main screen.\n");
        std::cin >> userInput;

        // Convert to uppercase to handle lowercase input
        string userUpper = std::toupper(userInput);
        if (userUpper == 'M') {
            flag = 1;
            break;
        }

        // Convert to uppercase to handle lowercase input
        userInput = std::tolower(userInput);

        int found = -1;
        for (int i = 0; i < modCourses.sizez(); i++) {
            if (userInput == modCourses[i].getClassName()) found = i;
        }

        if (found == -1) {
            printf("That course was not found, please try again.\n");
            continue;
        }
        
        else {
            printf("Please enter the grade you scored in this class as an integer between 0 and 100, or type anything else to return to the main screen.\n");
            std::cin >> userInput;

            stringstream ss(userInput);
            if (!(ss >> number) || !(ss.eof())) {
                break;
            }

            // Check if the number is within the valid range
            if (number >= 0 && number <= 100) {
                
                if (tr->addCompleted(modCourses[found], number) == 1) {
                    tr->removeCompleted(modCourses[found], number);
                    tr->addCompleted(modCourses[found], number);
                    flag = 1;
                    break;
                }

            } 
            else {
                flag = 1
                break;
            }
        }
    }

    mainScreen(s);
}

Facade::~Facade()
{

}