#include <cctype>
#include <cstring>
#include <iostream>
#include <fstream>

class entry
{
    public:
        entry();
        ~entry();
        int create_entry(char *name, char *location, char *hint);
        int display(void);
        int create_entry(const entry &anEntry);
        int retrieve(char *search_name, entry &found);

    private:
        char *name;
        char *location;
        char *hint;
};