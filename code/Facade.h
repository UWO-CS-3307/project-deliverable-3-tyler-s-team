#include "Student.h"
#include "Authenticator.h"
#ifndef FACADE_H
#define FACADE_H

#pragma once

class Facade
{
public:
    Facade(Authenticator *a);

    void mainScreen(Student *s);

    void loginScreen();

    void editCoursesScreen(Student *s);

    ~Facade();

private:
    Authenticator *auth;
};

#endif