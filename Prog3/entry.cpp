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

int entry::create_entry(char *aname, char *alocation, char *ahint)
{
  if (name)
    delete[] name;
  if (location)
    delete[] location;
  if (hint)
    delete[] hint;
  //name = location = hint = NULL;
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
  std::cout << "\n\n";
  return 1;
}

int entry::retrieve(char *search_name, entry &found)
{
  if (!strcmp(name, search_name)) 
  {
    display();
    found.create_entry(name, location, hint);
    return 1;
  }
  else
    return 0;
}