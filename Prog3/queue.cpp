#include "queue.hpp"

queue::queue()
{
    rear = NULL;
}

queue::~queue()
{
    qNode *temp = rear;
    if (!rear)
    {
        delete rear;
        rear = temp->next;
    }
    rear = NULL;
}

int queue::display()
{
    if (!rear) return 0;
    rear->qEntry.display();
    return 1;
}

int queue::enqueue(const entry &to_add)
{
    if (!rear)
    {
        rear = new qNode;
        rear->next = rear;
    }
    rear->qEntry.create_entry(to_add);
    qNode *temp = rear->next;
    rear->next = new qNode;
    rear = rear->next;
    rear->next = temp;
    return 1;
}

int queue::dequeue()
{
    if (!rear) return 0;
    if (rear->next == rear)
    {
        delete rear;
        rear = NULL;
    }
    qNode *temp = rear->next;
    rear->next = temp->next;
    delete temp;
    return 1;
}