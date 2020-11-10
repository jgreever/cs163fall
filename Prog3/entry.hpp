#include <cctype>
#include <cstring>
#include <iostream>

class entry
{
    public:
        entry();
        ~entry();
        int create_entry(char *name, char *location, char *hint);
        int display(void);
        int copy_entry(const entry &anEntry);
        int retrieve(char *search_name, entry &found);

    private:
        char *name;
        char *location;
        char *hint;
};