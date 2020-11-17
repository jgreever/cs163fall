#include "entry.hpp"

struct qNode
{
    entry anEntry;
    qNode *next;
};

class queue
{
public:
    queue();
    ~queue();
    int display();
    int enqueue(char *aName);
    int dequeue();

private:
    qNode *rear;
};