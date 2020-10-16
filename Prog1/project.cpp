#include "project.hpp"

project::project() 
{
    head = tail = NULL; 
}

project::~project()
{
    std::cout << "Project Destructor Called\n"; //TODO: debugging, remove first

    node* temp = NULL;
    while (head)
    {
        temp = head->next;
        delete head;
        head = temp;
    }
    tail = NULL;
}

int project::add(const list& new_list)
{ 
  node* temp = new node;
  if (!temp) return 0;
  temp->aList.add(new_list);
  temp->next = NULL;

  if (!head)
  { 
     head = tail = temp;
  } 
  else
  {
    tail->next = temp;
    tail = tail->next;
  }
  return 1;
}

int project::display()
{
    if (!head) return 0; 

    node* temp = head;
    while (temp)
    {
        temp->aList.display();
        temp = temp->next;
    }
    return 1;
}
