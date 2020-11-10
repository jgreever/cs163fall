#include "entry.hpp"

entry::entry()
{
    name = location = hint = NULL;
}

entry::~entry()
{
  if (name)
    delete[] name;
  if (location)
    delete[] location;
  if (hint)
    delete[] hint;
  name = location = hint = NULL;
}

int entry::create_entry(char *name, char *location, char *hint)
{
  if (this->name)
    delete[] this->name;
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);

  if (this->location)
    delete[] this->location;
  this->location = new char[strlen(location) + 1];
  strcpy(this->location, location);

  if (this->hint)
    delete[] this->hint;
  this->hint = new char[strlen(hint) + 1];
  strcpy(this->hint, hint);

  return 1;
}

int entry::copy_entry(const entry &anEntry) 
{
  return entry::create_entry(anEntry.name, anEntry.location, anEntry.hint);
}

int entry::display(void)
{
  std::cout << "\nName: " << name;
  std::cout << "\nLocation: " << location;
  std::cout << "\nHint: " << hint;
  return 1;
}

int entry::retrieve(char *search_name, entry &found)
{
  if (!name || !search_name)
    return 0;

  if (!strcmp(name, search_name)) 
  {
    if (found.name)
      delete[] found.name;
    if (found.location)
      delete[] found.location;
    if (found.hint)
      delete[] found.hint;
    found.name = found.location = found.hint = NULL;

    if (name) {
      found.name = new char[strlen(name) + 1];
      strcpy(found.name, name);
    }

    if (location) {
      found.location = new char[strlen(location) + 1];
      strcpy(found.location, location);
    }

    if (hint) {
      found.hint = new char[strlen(hint) + 1];
      strcpy(found.hint, hint);
    }
    found.display();
    return 1;
  }
  else
    return 0;
}