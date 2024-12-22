/*#include "ModuleList.h"
using namespace std;

// constructor (default), does nothing
ModuleList::ModuleList() {}

// getter
const vector<Module> ModuleList::getModuleList() const
{
    return list;
}

// adder for module list, returns 1 for error
int ModuleList::addModule(Module m)
{
    // check if the module is already in the list
    for (int i = 0; i < list.size(); i++) {
        if (list[i].getName() == m.getName() && list[i].getType() == m.getType()) {
            printf("module is already in list\n");
            return 1;
        }
    }

    // add module to list
    list.push_back(m);
    return 0;
}

// remover for module list, returns 1 for error
int ModuleList::removeModule(Module m)
{
    // look for module in list
    int index = -1;
    for (int i = 0; i < list.size(); i++) {
        if (list[i].getName() == m.getName() && list[i].getType() == m.getType()) index = i;
    }

    // if the course is not in the list, return 1
    if (index == -1) {
        printf("module not found in list\n");
        return 1;
    }

    // remove the course from the list and decrement credits
    else {
        list.erase(list.begin()+index); // test this !!!!!!!!!!!!!!!!!
        return 0;
    }
}

// destructor, does nothing
ModuleList::~ModuleList()
{

}*/