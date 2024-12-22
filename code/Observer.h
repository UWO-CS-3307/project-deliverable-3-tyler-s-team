#include <iostream>
using namespace std;

#ifndef OBSERVER_H
#define OBSERVER_H

#pragma once

// this class will remain mostly empty as it will serve as a interface of sorts for its child classes

class Student;


class Observer
{
public:
    Observer();

    void update(Student u);

    ~Observer();

private:

};

#endif