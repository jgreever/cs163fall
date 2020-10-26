#include "entry.hpp"

//The data structure is a CLL
struct q_node
{
  journal_entry entry;
  q_node * next;
};

class queue
{
  public:
    queue(void);
    ~queue(void);
    int display_all(void) const;

    int enqueue(const journal_entry & to_add);
    int dequeue ();

  private:
    q_node * rear;

};
