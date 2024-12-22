#include "ProgressBar.h"
using namespace std;

ProgressBar::ProgressBar()
{

}

void ProgressBar::printProgressBar(Student* u)
{
    printf("\n--------------------------------------------------\n\n");

    Transcript t = u->getTranscript();
    const vector<Course> completed = t.getCompleted();
    const vector<int> grades = t.getGrades();

    float credits = 0;

    for (int i = 0; i < t.getSize(); i++) {

        Course ci = completed[i];

        if (grades[i] > 50) {
            credits += ci.getNumCredits();
        }
    }

    // PRINT PROGRESS BAR
    printf("GRADUATION PROGRESS: %.1f/20\n", credits);
    printf("(");
    for (float i = 0; i < 20.0; i+=0.5) { 
        if (credits >= i) printf("/");
        else printf(" ");
    }
    printf(")\n");
    printf("\n--------------------------------------------------\n");
}

void ProgressBar::update(Student* u)
{
    printProgressBar(u);
}

ProgressBar::~ProgressBar()
{

}