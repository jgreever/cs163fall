#include "entry.hpp"

alertEntry::alertEntry()
{
    origin = date = time = message = priority = NULL;
}

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

int alertEntry::create_entry(char aorigin[], char adate[], char atime[], char amessage[], char apriority[])
{
       if (origin)
        delete[] origin;
    origin = new char[strlen(aorigin) + 1];
    strcpy(origin, aorigin);

    if (date)
        delete[] date;
    date = new char[strlen(adate) + 1];
    strcpy(date, adate);

    if (time)
        delete[] time;
    time = new char[strlen(atime) + 1];
    strcpy(time, atime);

    if (message)
        delete[] message;
    message = new char[strlen(amessage) + 1];
    strcpy(message, amessage);

    if (priority)
        delete[] priority;
    priority = new char[strlen(apriority) + 1];
    strcpy(priority, apriority);

    return 1;
}

int alertEntry::create_entry(const alertEntry& newEntry)
{
    return alertEntry::create_entry(newEntry.origin, newEntry.date, newEntry.time, newEntry.message, newEntry.priority);
}

int alertEntry::display(void) const
{
    std::cout << "Origin: " << origin << std::endl;
    std::cout << "Date: " << date << std::endl;
    std::cout << "Time: " << time << std::endl;
    std::cout << "Message: " << message << std::endl;
    std::cout << "Priority: " << priority << std::endl;
    return 1;
}
