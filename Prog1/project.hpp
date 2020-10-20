#include "list.hpp"

struct node
{
    list aList;
    node* next;
};

class project
{
    public:
        project();
        ~project();
        int add(list& new_list);
        int display();
        int displayPriority(char* searchNode);
        int displayPriority(node*& head, char* searchNode);
        int remove(char* searchNode);
        int remove(node*& head, char* searchNode);

    private:
        node* head;
        node* tail;
};