#include <cstring>
#include <cctype>
#include <iostream>

class alertEntry
{
  public:
    alertEntry(void);
    ~alertEntry(void);
    int create_entry(char origin[], char date[], char time[], char message[], char priority[]);
    int create_entry(const alertEntry& newEntry);
    int display(void) const;

  private:
    char* origin;
    char* date;
    char* time;
    char* message;
    char* priority;
};
