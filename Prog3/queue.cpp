#include "queue.hpp"

queue::queue(void)
{
    rear = NULL;
}

queue::~queue(void)
{
    qNode *temp = rear;
    if (!rear)
    {
        delete rear;
        rear = temp->next;
    }
    rear = NULL;
}

int queue::display(void)
{
    if (!rear)
        return 0;
    int success = rear->qEntry.display();
    return 1;
}

int queue::enqueue(const entry &to_add)
{
    if (!rear)
        return 0;
    rear = new qNode;
    rear->next = rear;
    qNode *temp = rear->next;
    rear->next = new qNode;
    rear = rear->next;
    rear->next = temp;
    int success = rear->qEntry.copy_entry(to_add);
    return success;
}

int queue::dequeue()
{
    if (!rear)
        return 0;
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