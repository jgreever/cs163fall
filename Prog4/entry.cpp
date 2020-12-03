/* entry.cpp
 *
 * Justin Greever
 * CS163 - Program 4
 * 11/19/2020
 *
 * Media Management (using BSTs)
 *
 * Functions MUST be in the private part of the class
 * with wrapper functions in the public section to access
 * the private functions.
 * 
 * 
 * functions:
 *      int createEntry();
 *      int copyEntry();
 *      int displayEntry();
 *      int removeEntry();
 *      int retrieveEntry();
 * 
 */

#include "bst.hpp"
using namespace std;

entry::entry()
{
    className = NULL;
    mediaName = NULL;
    description = NULL;
    mediaLength = NULL;
    watchNext = NULL;
}

entry::~entry()
{
    if (className)
        delete[] className;
    if (mediaName)
        delete[] mediaName;
    if (description)
        delete[] description;
    if (mediaLength)
        delete[] mediaLength;
    if (watchNext)
        delete[] watchNext;
    className = NULL;
    mediaName = NULL;
    description = NULL;
    mediaLength = NULL;
    watchNext = NULL;
}

// used to create a new entry in a node for the BST
int entry::createEntry(char *aClass, char *aMedia, char *aDescription, char *aLength, char *aNext)
{
    if (className) delete[] className;
    if (mediaName) delete[] mediaName;
    if (description) delete[] description;
    if (mediaLength) delete[] mediaLength;
    if (watchNext) delete[] watchNext;
    
    className = new char[strlen(aClass) + 1];
    strcpy(className, aClass);
    mediaName = new char[strlen(aMedia) + 1];
    strcpy(mediaName, aMedia);
    description = new char[strlen(aDescription) + 1];
    strcpy(description, aDescription);
    mediaLength = new char[strlen(aLength) + 1];
    strcpy(mediaLength, aLength);
    watchNext = new char[strlen(aNext) + 1];
    strcpy(watchNext, aNext);

    return 1;
}

//wrapper function to copy anEntry to a new entry
int entry::copyEntry(const entry &anEntry)
{
    return entry::createEntry(anEntry.className, anEntry.mediaName, anEntry.description, anEntry.mediaLength, anEntry.watchNext);
}

//wrapper function to compare entries by media name
int entry::compareEntries(entry &anEntry, char *to_compare)
{
    return (strcmp(anEntry.mediaName, to_compare));
}

//wrapper to compare entries by class name
int entry::compareClass(entry &anEntry, char *to_compare)
{
    return (strcmp(anEntry.className, to_compare));
}

//compare media name in entries and return strcmp value
int entry::compareEntries(entry &anEntry, entry &anotherEntry)
{
    return (strcmp(anEntry.mediaName, anotherEntry.mediaName));
}

//grabs the media name and returns it for sorting/compare/etc
char *entry::getMediaName()
{
    char *reMediaName = new char[strlen(mediaName) + 1];
    return reMediaName;
}

//gets the class name and returns it for search/compare/etc
char *entry::getClassName()
{
    char *reClassName = new char[strlen(className)+ 1];
    return reClassName;
}

//displays the entry located at this->
int entry::displayEntry()
{
    cout << "\nClass Name: " << className;
    cout << "\nMedia Name: " << mediaName;
    cout << "\nDescription: " << description;
    cout << "\nMedia Length: " << mediaLength;
    cout << "\nWatch Next: " << watchNext;
    cout << "\n";
    return 1;
}