#include <cstring>
#include <cctype>
#include <iostream>

class journal_entry
{
  public:
    journal_entry(void);
    ~journal_entry(void);
    int create_entry(char * title, char * notes);
    int copy_entry(const journal_entry & a_new_entry);
    int retrieve(char * title, journal_entry & found) const;
    int retrieve(journal_entry & found) const;
    int display(void) const;

  private:
    char * title;
    char * notes;
};
