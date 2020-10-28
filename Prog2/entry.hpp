#include <cstring>
#include <cctype>
#include <iostream>

class alertEntry
{
  public:
    alertEntry(void);
    ~alertEntry(void);
    int create_entry(char* origin, char* date, char* time, char* message, char* priority);
    int copy_entry(const alertEntry& newEntry);
    int display();

  private:
    char* origin;
    char* date;
    char* time;
    char* message;
    char* priority;
};
