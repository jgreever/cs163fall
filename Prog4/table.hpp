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
using namespace std;

class table
{
    public:
        table();
        ~table();
        int get_value();
        bool insert(char *aClass, char *aName,
                    char *desc, char *length, char *isNext);
        bool insert(table *anEntry);
        bool display(void) const;

    private:
        int get_value(char *aName);
        //bool insert(table *anEntry);
        char *aClass;
        char *aName;
        char *desc;
        char *length;
        char *isNext;
};