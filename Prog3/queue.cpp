#include "hash_table.hpp"
using namespace std;

queue::queue()
{
    rear = NULL;
}

queue::~queue()
{
    /*
    qNode *temp;
    if (rear == rear->next)
    {
        delete rear;
        rear = NULL;
    }
    else if (rear != NULL)
    {
        temp = rear;
        rear = rear->next;
        delete temp;
    }
    temp = NULL;
    */
    if (rear != NULL)
        queue::dequeue();
}

int queue::enqueue(char *aName)
{
    qNode *temp = new qNode;
    temp->anEntry.create_entry(aName, NULL, NULL, 1);

    if (!rear)
    {
        rear = temp;
        rear->next = rear;
        return 1;
    }
    else
    {    
        temp = rear->next;
        rear->next = new qNode;
        rear = rear->next;
        rear->next = temp;
    }
    return 1;
}

int queue::dequeue()
{
    if (rear == NULL)
        return 0;
    if (rear->next == rear)
    {
        delete rear;
        rear = NULL;
    }
    qNode *temp = rear->next->next;
    delete rear->next;
    rear->next = temp;
    return 1;
}

int queue::display()
{
    if (!rear)
        return 0;
    rear->anEntry.display();
    return 1;
}
