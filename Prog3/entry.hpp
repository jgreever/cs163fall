/* entry.hpp
 * 
 * Justin Greever
 * CS163 - Program 3
 * 11/9/2020
 * 
 * Program 3 - Scavenger Hunt!
 * 
 */
#include <cctype>
#include <cstring>
#include <iostream>
#include <fstream>
#include <stdlib.h>

class entry
{
public:
    entry();
    ~entry();
    int create_entry(const entry &to_add, int choice);
    int create_entry(char *name);
    int create_entry(char *name, char *location, char *hint);
    int display(int userChoice);

private:
    char *name;
    char *location;
    char *hint;
};