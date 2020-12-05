/* aClass.hpp
 *
 * 
 */
#include <iostream>
#include <cstring>
#include <cctype>

class aClass
{
    public:
        aClass();
        ~aClass();
        int createEntry(char *classNum);
        int copyEntry(const aClass &to_copy);
        int retrieve(char *name, aClass &found);
        int retrieve(aClass &found) const;
        bool compare (char *matchThis);
        int display(void) const;
    private:
        char *classNum;
};