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
    className = mediaName = description = NULL;
    mediaLength = watchNext = NULL;
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
    className = mediaName = NULL;
    description = mediaLength = NULL;
    watchNext = NULL;
}

int entry::createEntry(char *aClass, char *aMedia, char *aDescription, char *aLength, char *aNext)
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

int entry::copyEntry(entry &anEntry)
{
    return entry::createEntry(anEntry.className, anEntry.mediaName, anEntry.description, anEntry.mediaLength, anEntry.watchNext);
}

int entry::compareEntries(entry *anEntry, entry *anotherEntry)
{
    int strCompare = strcmp(anEntry->className, anotherEntry->className);
    return strCompare;
}

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