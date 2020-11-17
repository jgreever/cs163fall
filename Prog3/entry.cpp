#include "hash_table.hpp"
using namespace std;

entry::entry()
{
    aName = name = location = hint = NULL;
}

entry::~entry()
{
    if (aName)
        delete[] aName;
    if (name)
        delete[] name;
    if (location)
        delete[] location;
    if (hint)
        delete[] hint;
    aName = name = location = hint = NULL;
}

int entry::create_entry(char *aname, char *alocation, char *ahint, int choice)
{
    if (aName)
        delete[] aName;
    if (name)
        delete[] name;
    if (location)
        delete[] location;
    if (hint)
        delete[] hint;
    
    if (aname && choice == 1)
    {
        aName = new char[strlen(aname) + 1];
        strcpy(aName, aname);
        return 1;
    }
    else if (aname && choice == 2)
    {
        name = new char[strlen(aname) + 1];
        strcpy(name, aname);
        location = new char[strlen(alocation) + 1];
        strcpy(location, alocation);
        hint = new char[strlen(ahint) + 1];
        strcpy(hint, ahint);
        return 1;
    }
    return 0;
}

int entry::display()
{
    if (this->aName)
    {
        cout << "\nItem name: " << this->aName;
        return 1;
    }
    else if (this->name)
    {
        cout << "\nItem name: " << this->name;
        cout << "\nItem location: " << this->location;
        cout << "\nItem hint: " << this->hint;
        return 1;
    }
    return 0;
}