#include "hash_table.hpp"
using namespace std;

entry::entry()
{
    name = location = hint = NULL;
}

entry::~entry()
{
    //if (aName)
    //    delete[] aName;
    if (name)
        delete[] name;
    if (location)
        delete[] location;
    if (hint)
        delete[] hint;
    name = location = hint = NULL;
}

int entry::create_entry(char *aname, char *alocation, char *ahint, int choice)
{
    //if (this->aName)
    //    delete[] this->aName;
    if (this->name)
        delete[] this->name;
    if (this->location)
        delete[] this->location;
    if (this->hint)
        delete[] this->hint;
    
    if (aname && choice == 1)
    {
        this->name = new char[strlen(aname) + 1];
        strcpy(this->name, aname);
        this->location = this->hint = NULL;
        return 1;
    }
    else if (aname && choice == 2)
    {
        this->name = new char[strlen(aname) + 1];
        strcpy(this->name, aname);
        this->location = new char[strlen(alocation) + 1];
        strcpy(this->location, alocation);
        this->hint = new char[strlen(ahint) + 1];
        strcpy(this->hint, ahint);
        return 1;
    }
    return 0;
}

int entry::display(int userChoice)
{
    if (this->name && userChoice == 1)
    {
        cout << "\nItem name: " << this->name;
        return 1;
    }
    else if (this->name && userChoice == 2)
    {
        cout << "\nItem name: " << this->name;
        cout << "\nItem location: " << this->location;
        cout << "\nItem hint: " << this->hint;
        return 1;
    }
    return 0;
}