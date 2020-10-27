#include "entry.hpp"

struct node
{
  alertEntry* entries;
  node* next;
};

const int MAX = 5;

class stack
{
  public:
    stack();
    ~stack();
    int display_all(void) const;
    int peek(alertEntry& at_top) const;
    int push(const alertEntry& to_add);
    int pop (void);

  private:
    node* head;
    int top_index;
};
