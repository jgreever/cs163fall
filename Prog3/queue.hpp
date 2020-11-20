/* queue.hpp
 * 
 * Justin Greever
 * CS163 - Program 3
 * 11/9/2020
 * 
 * Program 3 - Scavenger Hunt!
 * 
 * This is our Queue class. It holds an item name in a CLL
 * that the user can add to/remove from as they find the items.
 * This class only accepts one input from the user: the name
 * of the item to enqueue, which is passed to it via the hash
 * table retrieve function, if the users wants to enqueue it.
 * We only need to keep track of the rear node, since we are 
 * using a CLL, and can always use rear->next to access the 
 * front of the queue.
 * 
 */
#include "entry.hpp"

struct qNode
{
    entry anEntry;
    qNode *next;
};

class queue
{
public:
    //constructor
    queue();
    //destructor
    ~queue();
    //display information about item in the queue
    int display();
    //this will enqueue, or add, data to the CLL
    int enqueue(char *aName);
    //this removes a single item per function call from the queue
    int dequeue();

private:
    qNode *rear;
};