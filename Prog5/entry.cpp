/* aClass.cpp
 *
 * 
 */
#include "graph.hpp"
using namespace std;

aClass::aClass()
{

};

aClass::~aClass()
{

};

int aClass::createEntry(char *classNum)
{

    return 1;
};

int aClass::copyEntry(const aClass &to_copy)
{

    return 1;
};

int aClass::retrieve(char *classNum, aClass &found)
{

    return 1;
};

int aClass::retrieve(aClass &found) const
{

    return 1;
};

bool aClass::compare(char *matchThis)
{

    return true;
};

int aClass::display(void) const
{

    return 1;
};