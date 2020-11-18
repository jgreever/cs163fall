#include "hash_table.hpp"
using namespace std;

entry::entry()
{
    this->name = this->location = this->hint = NULL;
}

entry::~entry()
{
    if (this->name)
        delete[] this->name;
    if (this->location)
        delete[] this->location;
    if (this->hint)
        delete[] this->hint;
    this->name = this->location = this->hint = NULL;
}
int entry::create_entry(const entry &to_add, int choice)
{
    return entry::create_entry(to_add.name, to_add.location, to_add.hint);
}

int entry::create_entry(char *aName)
{
    if (this->name)
        delete[] this->name;
    this->name = new char[strlen(aName) + 1];
    location = hint = NULL;
    strcpy(this->name, aName);
    return 1;
}
int entry::create_entry(char *aname, char *alocation, char *ahint)
{
    if (this->name)
        delete[] this->name;
    if (this->location)
        delete[] this->location;
    if (this->hint)
    delete[] this->hint;
    this->name = new char[strlen(aname) + 1];
    strcpy(this->name, aname);
    this->location = new char[strlen(alocation) + 1];
    strcpy(this->location, alocation);
    this->hint = new char[strlen(ahint) + 1];
    strcpy(this->hint, ahint);
    return 1;
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