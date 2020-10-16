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
        int add(const list& new_list);
        int display();

    private:
        node* head;
        node* tail;
};