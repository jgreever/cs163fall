/** stack.hpp
 * 
 * Justin Greever
 * CS163 - Program 2
 * 10/23/2020
 * 
 * This is our header file for our stack class. It allows
 * us to automagically work with initializing variables, 
 * hiding/shielding data from the client, and keeping
 * track of where in the stack our data is able to be
 * inserted or removed.
 */

#include "entry.hpp"

/** This is our basic node structure to hold the alert entry and
 * point to the next node.
 */
struct node
{
  alertEntry* entries;
  node* next;
};

const int MAX = 5; //!This is to set the stack size to 5 max

/** Here is our class stack. It will manage creation, deletion,
 * adding, viewing, and removing of stack entries. Our private
 * data here is our node* head and int top_index.
 */
class stack
{
  public:
    stack();
    ~stack();
    int display_all(void) const;
    int peek() const;
    int push(const alertEntry& to_add);
    int pop (void);

  private:
    node* head;
    int top_index;
};
