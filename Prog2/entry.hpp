/** entry.hpp
 * 
 * Justin Greever
 * CS163 - Program 2
 * 10/23/2020
 * 
 * This is our header file for the entry class. This class
 * is responsible for taking input from the client/application
 * and turning it into an alertEntry to be passed to the stack
 * class function to be added to the stack. It shields the data
 * from the user.
 */

#include <cstring>
#include <cctype>
#include <iostream>

/** the alertEntry class, it takes input from the client and sends
 * it to it's copy_entry function that makes it an alertEntry that
 * can be passed to the stack class functions to be added into
 * the stack, as well as display the contents of each stack item in
 * the node.
 */
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
