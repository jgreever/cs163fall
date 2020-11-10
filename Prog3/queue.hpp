#include "hash_table.hpp"

const int size = 10;

struct qNode
{
    entry qEntry;
    qNode *next;
};

class queue
{
    public:
        queue(void);
        ~queue(void);
        int display(void);
        int enqueue(const entry &to_add);
        int dequeue();

    private:
        qNode *rear;
};