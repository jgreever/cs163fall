#include "project.hpp"

project::project()
{
    head = tail = NULL;
}

project::~project()
{
    std::cout << "Project Destructor Called\n"; //TODO: debugging, remove first

    node *temp = NULL;
    while (head)
    {
        temp = head->next;
        delete head;
        head = temp;
    }
    tail = NULL;
}

int project::add(list &new_list)
{
    node *temp = new node;
    if (!temp)
        return 0;
    temp->aList.add(new_list);
    temp->next = NULL;

    if (!head)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = tail->next;
    }
    return 1;
}

int project::display()
{
    if (!head)
        return 0;

    node *temp = head;
    while (temp)
    {
        temp->aList.display();
        temp = temp->next;
    }
    return 1;
}

int project::displayPriority(char* searchNode)
{
    return project::displayPriority(head, searchNode);
}

int project::displayPriority(node *&head, char *searchNode)
{
    node* temp = head;
    while (temp != NULL)
    {
        if (temp->aList.searchPriority(searchNode) == 0)
        {
            temp->aList.display();
            temp = temp->next;
        }else
            temp = temp->next;
    }
    return 1;
}

int project::remove(char* searchNode)
{
    return project::remove(head, searchNode);
}

int project::remove(node*& head, char* searchNode)
{
    //if (!head) return 0; //no list to delete
    while (head != NULL)
    {
        if (head->aList.search(searchNode) != 0)
        {
            return project::remove(head->next, searchNode);
        }
        else if (head->aList.search(searchNode) == 0)
        {
            node *temp = head->next;
            delete head;
            head = temp;
            return project::remove(head, searchNode);
        }
    }
    return 1;
}