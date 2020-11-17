#include "hash_table.hpp"
using namespace std;

queue::queue()
{
    rear = NULL;
}

queue::~queue()
{
    if (rear)
        queue::dequeue();
}

int queue::enqueue(char *aName)
{
    qNode *temp = new qNode();
    temp->anEntry.create_qEntry(aName);
    temp->next = NULL;

    if (!rear)
    {
        rear = temp;
        rear->next = rear;
        return 1;
    }
    temp = rear->next;
    rear->next = new qNode();
    rear = rear->next;
    rear->next = temp;
    return 1;
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
    else
    {
        qNode *temp = rear->next;
        rear->next = temp->next;
        delete temp;
    }
    return 1;
}

int queue::display()
{
    if (!rear)
        return 0;
    rear->anEntry.display();
    return 1;
}
