#include "hash_table.hpp"
using namespace std;

queue::queue()
{
    rear = NULL;
}

queue::~queue()
{
  if (!rear) return;
  qNode *current = rear->next;
  rear->next = NULL;
  while (current)
  {
    rear = current->next;
    delete current;
    current = rear;
  }
    //while (rear != NULL)
    //    queue::dequeue();

    /*
    qNode *temp = NULL;
    if (rear == NULL)
    {
        delete rear;
        rear = NULL;
    }
    else if (rear->next == rear)
    {
        delete rear;
        rear = NULL;
    }
    else
    {
        temp = rear->next;
        delete rear;
        rear = temp;
    }
    */
}

int queue::enqueue(char *aName)
{
    char *tName = new char[strlen(aName) + 1];
    strcpy(tName, aName);
    qNode *temp = new qNode;
    temp->anEntry.create_entry(tName);
    delete[] tName;

    if (rear == NULL)
    {
        rear = temp;
        rear->next = rear;
        return 1;
    }
    temp->next = rear->next;
    rear->next = new qNode; 
    rear = rear->next;
    rear->next = temp;
    return 1;
}

int queue::dequeue()
{
    if (rear == NULL)
        return 0;
    if (rear->next == rear)
    {
        rear->next = NULL;
        delete rear;
        rear = NULL;
        return 1;
    }
    qNode *temp = rear->next->next;
    delete rear->next;
    rear->next = temp;
    delete temp;
    //temp = NULL;
    return 1;
}

int queue::display()
{
    if (!rear)
        return 0;
    cout << "\nDEBUG OUTPUT: rear" << rear->anEntry.display(1);
    cout << "\nDEBUG OUTPUT: rear->next: " << rear->next->anEntry.display(1);
    cout << "\nDEBUG OUTPUT: rear->next->next: " << rear->next->next->anEntry.display(1);
    return 1;
}
