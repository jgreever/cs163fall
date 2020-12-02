/* entry.hpp
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
//#include "bst.hpp"
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;

class entry
{
    public:
        entry();
        ~entry();
        int createEntry(char *name, char *media, char *desc, char *length, char *isNext);
        int copyEntry(const entry &anEntry);
        int compareEntries(entry *anEntry, entry *anotherEntry);
        int displayEntry();
        int removeEntry();
        int retrieveEntry();
    private:
        char *className;
        char *mediaName;
        char *description;
        char *mediaLength;
        char *watchNext;
};