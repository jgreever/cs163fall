/** stack.cpp
 * 
 * Justin Greever
 * CS163 - Program 2
 * 10/23/2020
 * 
 * This is our file with the functions that are used
 * to manage our stack. It will set any variables to 
 * NULL/0, and allow us to add/remove new nodes when 
 * a stack fills up.
 * 
 * The functions that will be in this file are:
 * stack(); the constructor
 * ~stack(); the destructor
 * push(); allows us to add an entry
 * pop(); allows us to remove the top entry
 * peek(); lets us *peek* at the top of the stack
 * display_all(); as it says, show all entries in
 *   the stack to the client.
 */

#include "stack.hpp"

/** constructor */
stack::stack()
{
  head = NULL;
  top_index = 0;
}

/** destructor */
stack::~stack()
{
  node *temp = NULL;
  while (head)
  {
    temp = head->next;
    delete head;
    head = temp;
  }
  top_index = 0;
}

/** push function. It takes an entire alertEntry from 
 * the entry class and adds it to the stack in the
 * proper place. If no items, it makes a new stack,
 * if a stack is full, it makes a new stack and links
 * to it.
 */
int stack::push(const alertEntry &to_add)
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
    node *temp = head;
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

/** the pop function doesn't accept any input from the user,
 * instead it simply removes what is on the top of the stack
 * and returns a 0/1 for fail/pass back to the client so it
 * can display the proper message to the user.
 */
int stack::pop(void)
{
  if (!head)
    return 0; //can't do anything if nothing is there
  node *temp = head->next;
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

/** peek doesn't accept any values from the user as well
 * it simply looks at what is on the top of the stack and
 * displays the data to the user. If there is no data, it
 * passes back a 0 so the client can display the error saying
 * nothing is in the stack.
 */
int stack::peek() const
{
  if (!head)
    return 0;
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

/** display_all doesn't accept any input as well
 * as it simply looks to see if there is a stack,
 * and if there is, outputs the data contained via
 * the entry class display function. If there is
 * no data or no stack, it simply returns a 0
 * so the client can display the failure/empty
 * message.
 */
int stack::display_all(void) const
{
  if (!head)
    return 0;
  int top = top_index;
  /*
  while (top >= 0)
  {
    head->entries[top - 1].display();
    --top;
  }
  */
  //if (!head)
  //{
    top = top_index;
    while (top > 0)
    {
      head->entries[top - 1].display();
      --top;
    }
  //}
  return 1;
}
