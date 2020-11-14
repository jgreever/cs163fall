#include "entry.hpp"

struct qNode
{
    entry qEntry;
    qNode *next;
};

class queue
{
    public:
        queue();
        ~queue();
        int display();
        int peek(entry &to_peek);
        int enqueue(const entry &to_add);
        int dequeue();

    private:
        qNode *rear;

};