#include "entry.hpp"

entry::entry()
{
    name = location = hint = NULL;
}

entry::~entry()
{
  if (name) delete[] name;
  if (location) delete[] location;
  if (hint) delete[] hint;
  name = location = hint = NULL;
}

int entry::create_entry(char *aname, char *alocation, char *ahint)
{
  if (name) delete[] name;
  if (location) delete[] location;
  if (hint) delete[] hint;
  name = location = hint = NULL;
  name = new char[strlen(aname) + 1];
  strcpy(name, aname);
  location = new char[strlen(alocation) + 1];
  strcpy(location, alocation);
  hint = new char[strlen(ahint) + 1];
  strcpy(hint, ahint);

  return 1;
}

int entry::create_entry(const entry &anEntry) 
{
  return entry::create_entry(anEntry.name, anEntry.location, anEntry.hint);
}

int entry::display()
{
  std::cout << "\nThe item to find is:";
  std::cout << "\nName: " << name;
  std::cout << "\nLocation: " << location;
  std::cout << "\nHint: " << hint;
  std::cout << "\n";
  return 1;
}

int entry::retrieve(char *search_name, entry &found)
{
  if (!name || !search_name) return 0;

  if (!strcmp(name, search_name)) 
  {
    if (found.name) delete[] found.name;
    if (found.location) delete[] found.location;
    if (found.hint) delete[] found.hint;
    found.name = found.location = found.hint = NULL;

    if (name) 
    {
      found.name = new char[strlen(name) + 1];
      strcpy(found.name, name);
    }

    if (location) 
    {
      found.location = new char[strlen(location) + 1];
      strcpy(found.location, location);
    }

    if (hint) 
    {
      found.hint = new char[strlen(hint) + 1];
      strcpy(found.hint, hint);
    }
    //found.display();
    return 1;
  }
  else
    return 0;
}