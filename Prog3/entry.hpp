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
    int create_entry(char *name, char *location, char *hint);
    int create_qEntry(char *aName);
    int display();
    int retrieve(char *search_name, entry &found);

private:
    char *aName;
    char *name;
    char *location;
    char *hint;
};