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

  if (head->entries[top_index].create_entry(to_add))
    ++top_index;
  else
    return 0;
  return 1;
}

int stack::pop (void)
{
  if (!head) return 0; //can't do anything if nothing is there
  node* hold = head->next;
  if (!top_index)
  {
    if (head->entries)
      delete[] head->entries;
    delete head;
    head = hold;
    top_index = MAX;
  }
  --top_index;
  return 1;
}

int stack::peek(alertEntry& at_top) const
{
  if (!head) return 0; //nothing to do here boys, pack it up!
  if (top_index == 0)
    if (head->next == NULL)
      return 0;
      //TODO: create display function here.
  return 1;
}

int stack::display_all(void) const
{
  if (!head) return 0;
  return 1;
}