/* table.cpp
 *
 * Justin Greever
 * CS163 - Program 4
 * 11/19/2020
 *
 * Media Management (using BSTs)
 *
 * Information to keep track of:
 *      Name of the class for the media
 *      Name of the media
 *      Description of the material on the media
 *      Length of the video
 *      Next video in playlist (within the same class)
 * 
 * Our table will need to do the following:
 *      Hash the data to get a value to pass to the BST
 *      Add the required information to the BST
 *      Display the information from the BST
 *      Remove the information from the BST
 * 
 */
#include "table.hpp"

table::table()
{
    aClass = aName = desc =
    length = isNext = NULL;
}

table::~table()
{
    if (this->aClass)
        delete[] this->aClass;
    if (this->aName)
        delete[] this->aName;
    if (this->desc)
        delete[] this->desc;
    if (this->length)
        delete[] this->length;
    if (this->isNext)
        delete[] this->isNext;
    this->aClass = this->aName = this->desc = 
    this->length = this->isNext = NULL;
}

int table::get_value()
{
    return table::get_value(aName);
}

int table::get_value(char *aName)
{
    //TODO! Fix the line below
    int value = *aName;
    //TODO: remove the line below
    cout << "\nValue for " << aName << " is: " << value << endl;
    return value;
}

bool table::insert(char *aClass, char *aName,
                   char *desc, char *length, char *isNext)
{
    if (this->aClass)
        delete[] this->aClass;
    if (this->aName)
        delete[] this->aName;
    if (this->desc)
        delete[] this->desc;
    if (this->length)
        delete[] this->length;
    if (this->isNext)
        delete[] this->isNext;
    this->aClass = new char[strlen(aClass) + 1];
    strcpy(this->aClass, aClass);
    this->aName = new char[strlen(aName) + 1];
    strcpy(this->aName, aName);    
    this->desc = new char[strlen(desc) + 1];
    strcpy(this->desc, desc);    
    this->length = new char[strlen(length) + 1];
    strcpy(this->length, length);    
    this->isNext = new char[strlen(isNext) + 1];
    strcpy(this->isNext, isNext);
    return true;
}

bool table::display(void) const
{
    if (this->aClass)
        cout << "\nClass Name: " << this->aClass;
    if (this->aName)
        cout << "\nMedia Name: " << this->aName;
    if (this->desc)
        cout << "\nDescription: " << this->desc;
    if (this->length)
        cout << "\nLength: " << this->length;
    if (this->isNext)
        cout << "\nNext to Watch: " << this->isNext << "\n";
    return true;
}

bool table::insert(table *anEntry)
{
    return table::insert(anEntry->aClass, anEntry->aName, 
                         anEntry->desc, anEntry->length,
                         anEntry->isNext);
}
