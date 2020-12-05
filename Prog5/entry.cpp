/* aClass.cpp
 *
 * 
 */
#include "graph.hpp"
using namespace std;

aClass::aClass()
{
    classNum = NULL;
};

aClass::~aClass()
{
    if (classNum)
        delete[] classNum;
};

int aClass::createEntry(char *class_to_add)
{
    if (classNum)
        delete[] classNum;
    classNum = new char[strlen(class_to_add) + 1];
    strcpy(classNum, class_to_add);
    return 1;
};

int aClass::copyEntry(const aClass &to_copy)
{
    return createEntry(to_copy.classNum);
};

/*
int aClass::retrieve(char *classNum, aClass &found)
{

    return 1;
};

int aClass::retrieve(aClass &found) const
{

    return 1;
};
*/

bool aClass::compare(char *matchThis)
{
    if (!matchThis)
        return 0;
    if (strcmp(classNum, matchThis) == 0)
        return true;
    else
        return false;
};

int aClass::display(void) const
{
    if (!classNum)
        return 0;
    else
    {
        cout << "\n\nClass Number: " << classNum << "\n";
        return 1;
    }
};