/* queue.cpp
 * 
 * Justin Greever
 * CS163 - Program 3
 * 11/9/2020
 * 
 * Program 3 - Scavenger Hunt!
 *
 * The queue class takes information from the hash table via
 * the entry class, if requested, and stores it into the queue
 * that is created. The only input value accepted from the user
 * or main is:
 *  char *name; (the item name)
 * 
 * Our private data is:
 *  qNode *rear; (our rear entry for our Queue)
 * 
 * This class manages our CLL for enqueuing at the rear and
 * adding at the front. The queue only holds the items name
 * that the user adds to the Scavenger hunt list. If information
 * is needed about the item entry (location, hint), the user
 * will pass a name to the hash function class, and if a match
 * is found, will alert the user and retrieve the information
 * about the item. This is either handed to the client for 
 * displaying, or passed into this Queue class to be stored
 * in our list.
 * 
 */
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
    cout << "\nHere is the item you are looking for currently:\n" 
         << rear->anEntry.display(1); //we use a 1 here so the entry
                                      //class is able to display from
                                      //the queue and not the hash table
                                      
    //cout << "\nDEBUG OUTPUT: rear" << rear->anEntry.display(1);
    //cout << "\nDEBUG OUTPUT: rear->next: " << rear->next->anEntry.display(1);
    //cout << "\nDEBUG OUTPUT: rear->next->next: " << rear->next->next->anEntry.display(1);
    return 1;
}
