#include "hash_table.hpp"
using namespace std;

entry::entry()
{
    name = location = hint = NULL;
}

entry::~entry()
{
    if (name)
        delete[] name;
    if (location)
        delete[] location;
    if (hint)
        delete[] hint;
    name = location = hint = NULL;
}

int entry::create_entry(char *aname, char *alocation, char *ahint)
{
    if (name)
        delete[] name;
    if (location)
        delete[] location;
    if (hint)
        delete[] hint;
    name = new char[strlen(aname) + 1];
    strcpy(name, aname);
    location = new char[strlen(alocation) + 1];
    strcpy(location, alocation);
    hint = new char[strlen(ahint) + 1];
    strcpy(hint, ahint);

    return 1;
}

int entry::create_qEntry(char *tName)
{
    if (aName)
        delete[] aName;
    aName = new char[strlen(tName) + 1];
    strcpy(aName, tName);

    return 1;
}

int entry::retrieve(char *search_name, entry &found)
{
    if (!strcmp(name, search_name))
    {
    }
    return 0;
}

int entry::display()
{
    if (this->aName)
        cout << "\nItem name: " << this->aName;
    else
    {
        cout << "\nItem name: " << this->name;
        cout << "\nItem location: " << this->location;
        cout << "\nItem hint: " << this->hint;
        cout << "\n\n";
    }
    return 1;
}