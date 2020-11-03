/** entry.cpp
 * 
 * Justin Greever
 * CS163 - Program 2
 * 10/23/2020
 * 
 * This is our class file containing the functions
 * that will be used to create and pass an entry
 * to the stack class functions. It accepts the 
 * following from the client:
 *   origin, date, time, message, priority
 * The functions it contains are:
 *   alertEntry(); our constructor
 *   ~alertEntry(); our destructor
 *   create_entry(); grabs input and gives to
 *     the copy_entry function.
 *   copy_entry(); takes the data from create_entry
 *     and packages it to be sent to the stack class
 *     to be added to a stack/node.
 */

#include "entry.hpp"

/** constructor */
alertEntry::alertEntry()
{
    origin = date = time = message = priority = NULL;
}

/** destructor */
alertEntry::~alertEntry()
{
    if (origin)
        delete[] origin;
    if (date)
        delete[] date;
    if (time)
        delete[] time;
    if (message)
        delete[] message;
    if (priority)
        delete[] priority;
    origin = date = time = message = priority = NULL;
}

/** create_entry grabs values from the client to pass to the copy_entry function.
 * it accepts char array values of origin, date, time, message, priority.
 * we use the 'if (this->something)' statement to ensure that no data is already
 * in use so we do not get memory errors.
 */
int alertEntry::create_entry(char* origin, char* date, char* time, char* message, char* priority)
{
    if (this->origin)
        delete[] this->origin;
    this->origin = new char[strlen(origin) + 1];
    strcpy(this->origin, origin);

    if (this->date)
        delete[] this->date;
    this->date = new char[strlen(date) + 1];
    strcpy(this->date, date);

    if (this->time)
        delete[] this->time;
    this->time = new char[strlen(time) + 1];
    strcpy(this->time, time);

    if (this->message)
        delete[] this->message;
    this->message = new char[strlen(message) + 1];
    strcpy(this->message, message);

    if (this->priority)
        delete[] this->priority;
    this->priority = new char[strlen(priority) + 1];
    strcpy(this->priority, priority);

    return 1;
}

/** copy_entry takes the data from create_entry and packages
 * it up to be sent to the stack function to be added into the 
 * stack/node. It takes no input from the client and is shielded
 * so that the client cannot directly interact with it.
 */
int alertEntry::copy_entry(const alertEntry& newEntry)
{
    /*
    this->origin = new char[strlen(newEntry.origin) + 1];
    strcpy(this->origin, newEntry.origin);
    this->date = new char[strlen(newEntry.date) + 1];
    strcpy(this->date, newEntry.date);
    this->time = new char[strlen(newEntry.time) + 1];
    strcpy(this->time, newEntry.time);
    this->message = new char[strlen(newEntry.message) + 1];
    strcpy(this->message, newEntry.message);
    this->priority = new char[strlen(newEntry.priority) + 1];
    strcpy(this->priority, newEntry.priority);
    return 1;
    */
    return alertEntry::create_entry(newEntry.origin, newEntry.date, newEntry.time, newEntry.message, newEntry.priority);
}

/** display is the lonely function. No values get passed to it,
 * it's just expected to read from the list everytime someone
 * shows interest in the list. Poor guy, all he wanted was to
 * be loved. At least he has a voice to display the contents
 * directly to the client/user without any problems!
 */
int alertEntry::display()
{
    std::cout << "\nOrigin: " << origin << std::endl;
    std::cout << "Date: " << date << std::endl;
    std::cout << "Time: " << time << std::endl;
    std::cout << "Message: " << message << std::endl;
    std::cout << "Priority: " << priority << "\n" << std::endl;
    return 1;
}
