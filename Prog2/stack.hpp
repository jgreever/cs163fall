#include "entry.hpp"

struct node
{
  journal_entry * entries;
  node * next;
};

const int MAX = 5;

class stack
{
  public:
    stack(void);
    ~stack(void);
    int display_all(void) const;

    int peek(journal_entry& at_top) const;
    int push(const journal_entry& to_add);
    int pop (void);

  private:
    node * head;
    int top_index;
};
