/* table.hpp
 *
 * Justin Greever
 * CS163 - Program 4
 * 11/19/2020
 *
 * Media Management (using BSTs)
 *
 */
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <time.h>

class table
{
    public:
        table();
        ~table();
        bool insert(char *aClass, char *aName,
                    char *desc, char *length, char *isNext);
        bool insert(table *&anEntry);
        bool display(void) const;

    private:
        char *aClass;
        char *aName;
        char *desc;
        char *length;
        char *isNext;
};