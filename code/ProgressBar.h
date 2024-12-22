#include "Observer.h"
#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#pragma once

class ProgressBar : public Observer
{
public:
    ProgressBar();

    void printProgressBar(Student* u);

    void update(Student* u);

    ~ProgressBar();

private:

};

#endif