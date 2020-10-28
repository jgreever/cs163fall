#include "stack.hpp"

stack::stack()
{
  head = NULL;
  top_index = 0;
}

stack::~stack()
{
  node* temp = NULL;
  while (head)
  {
    temp = head->next;
    delete head;
    head = temp;
  }
  top_index = 0;
}

int stack::push(const alertEntry& to_add)
{
  if (!head)
  {
    head = new node;
    head->entries = new alertEntry[MAX];
    head->next = NULL;
    top_index = 0;
  }

  if (top_index == MAX)
  {
    node* temp = head;
    head = new node;
    head->entries = new alertEntry[MAX];
    head->next = temp;
    top_index = 0;
  }

  if (head->entries[top_index].copy_entry(to_add))
    ++top_index;
  else
    return 0;    
  return 1;
}

int stack::pop (void)
{
  if (!head) return 0; //can't do anything if nothing is there
  node* temp = head->next;
  if (top_index == 0)
  {
    if (head->entries != NULL)
      delete[] head->entries;
    delete head;
    head = temp;
    top_index = MAX;
    if (head != NULL)
      top_index = MAX;
    else
      top_index = 0;
  }
  --top_index;
  return 1;
}

int stack::peek() const
{
  if (!head) return 0;
  if (top_index == 0)
    if (head->next != NULL)
    {
      head->next->entries[top_index + 4].display();
      return 1;
    }
    else
      return 0;
  head->entries[top_index - 1].display();
  return 1;
}

int stack::display_all(void) const
{
  if (!head) return 0;
  return 1;
}
