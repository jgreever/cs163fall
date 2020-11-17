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
    int create_entry(char *name, char *location, char *hint, int choice);
    int display(int userChoice);

private:
    //char *aName;
    char *name;
    char *location;
    char *hint;
};