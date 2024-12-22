#include "RequirementDashboard.h"
#include "Student.h"
using namespace std;


// implement later for deliverable 3 !!!


RequirementDashboard::RequirementDashboard()
{
    // im hard coding the requirements for a compsci specialization (just as sample data)
    minCredits = 20.0;
    minAverage = 60;
    minA = 1.0;
    minB = 1.0;
    minC = 1.0;
    minEssay = 1.0;
    minSenior = 13.0;
    minFaculty = 11.0;
    maxFaculty = 14.0;
}

void RequirementDashboard::printRequirements(Student* u)
{
    printf("\n--------------------------------------------------\n");
    printf("\n-------------~REQUIREMENT DASHBOARD~--------------\n");

    Transcript transcript = u->getTranscript();
    vector<Course> courses = transcript.getCompleted();
    vector<int> grades = transcript.getGrades();
    int size = courses.size();

    // CHECK REQUIREMENT FULLFILLMENT

    string result1 = "NO"; // 1) minCredits
    string result2 = "NO"; // 2) minAverage
    string result3 = "NO"; // 3) minA
    string result4 = "NO"; // 4) minB
    string result5 = "NO"; // 5) minC
    string result6 = "NO"; // 6) minEssay
    string result7 = "NO"; // 7) minSenior
    string result8 = "NO"; // 8) minFaculty
    string result9 = "NO"; // 9) maxFaculty
    float totalCreds = 0;
    int gradeAccum = 0;
    float aCreds = 0.0;
    float bCreds = 0.0;
    float cCreds = 0.0;
    float essayCreds = 0.0;
    float seniorCreds = 0.0;
    float sciCreds = 0.0;

    for (int i = 0; i < size; i++) {
        // ignore failed classes
        if (grades[i] < 50) continue;
        Course temp = courses[i];

        totalCreds += temp.getNumCredits();

        gradeAccum += grades[i];

        char breadth = temp.getBreadth();
        if (breadth == 'A') aCreds+= temp.getNumCredits();
        else if (breadth == 'B') bCreds += temp.getNumCredits();
        else if (breadth == 'C') cCreds += temp.getNumCredits();

        if (temp.getType() == 'E' || temp.getType() == 'F' || temp.getType() == 'G') essayCreds += temp.getNumCredits();

        if (temp.getCourseID() >= 1000) seniorCreds += temp.getNumCredits();

        if (temp.getFaculty() == "Science") sciCreds += temp.getNumCredits(); // REALLY hard coded !!!!!!!!!!!!!!
    }

    // minCredits report
    if (totalCreds >= minCredits) result1 = "YES";
    printf("Minimum Credits (%.1f) | %s (%.1f)\n", minCredits, result1, totalCreds);

    // minAverage report
    int avg = 0;
    if (size > 0) avg = gradeAccum/size;
    if (avg >= minAverage) result2 = "YES";
    printf("Minimum Grade Average (%d) | %s (%d)\n", minAverage, result2, avg);

    // minA, minB, and minC report
    if (aCreds >= minA) result3 = "YES";
    if (bCreds >= minB) result4 = "YES";
    if (cCreds >= minC) result5 = "YES";
    printf("Minimum Category A Credits (%.1f) | %s (%.1f)\n", minA, result3, aCreds);
    printf("Minimum Category B Credits (%.1f) | %s (%.1f)\n", minB, result4, bCreds);
    printf("Minimum Category C Credits (%.1f) | %s (%.1f)\n", minC, result5, cCreds);

    // minEssay report
    if (essayCreds >= minEssay) result6 = "YES";
    printf("Minimum Essay Course Credits (%.1f) | %s (%.1f)\n", minEssay, result6, essayCreds);

    // seniorCredits report
    if (seniorCreds >= minSenior) result7 = "YES";
    printf("Minimum Senior Course Credits (%.1f) | %s (%.1f)\n", minSenior, result7, seniorCreds);

    // minFaculty report
    if (sciCreds >= minFaculty) result8 = "YES";
    printf("Minimum Science Credits (%.1f) | %s (%.1f)\n", minFaculty, result8, sciCreds);

    // maxFaculty report
    if (sciCreds <= maxFaculty) result9 = "YES";
    printf("Maximum Science Credits (%.1f) | %s (%.1f)\n", maxFaculty, result9, sciCreds);

    // report for if all module courses have been fulfilled
    // HOW TO DO THIS ???????????????? do i really need this part ?????????????????????


    printf("\n--------------------------------------------------\n");
}

void RequirementDashboard::setRequirements(string doc)
{
    // this method would take info from an API from western (should I grow the app)
}

void RequirementDashboard::update(Student* u)
{
    printRequirements(u); // not sure this is right ????
}

RequirementDashboard::~RequirementDashboard()
{

}