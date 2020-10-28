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

int alertEntry::display()
{
    std::cout << "Origin: " << origin << std::endl;
    std::cout << "Date: " << date << std::endl;
    std::cout << "Time: " << time << std::endl;
    std::cout << "Message: " << message << std::endl;
    std::cout << "Priority: " << priority << std::endl;
    return 1;
}
