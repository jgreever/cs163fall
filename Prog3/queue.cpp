#include "queue.hpp"

queue::queue()
{
    rear = NULL;
}

queue::~queue()
{
    if (!rear)
        queue::dequeue();
}

int queue::enqueue(const entry &to_add)
{
    if (!rear)
    {
        rear = new qNode;
        rear->qEntry.create_entry(to_add);
        rear->next = rear;
    }
    else
    {
        qNode *temp = new qNode;
        rear->qEntry.create_entry(to_add);
        temp = rear->next;
        rear->next = new qNode;
        rear = rear->next;
        rear->next = temp;
    }
    return 1;
}

int queue::dequeue()
{
    if (!rear) return 0;
    if (rear == rear->next)
    {
        delete rear;
        rear = NULL;
    }
    else
    {
        qNode *temp = new qNode;
        temp = rear->next->next;
        delete rear->next;
        rear->next = temp;
    }
    return 1;
}

int queue::display()
{
    if (!rear) return 0;
    rear->qEntry.display();
    return 1;
}

int queue::peek(entry &to_peek)
{

    return 1;
}