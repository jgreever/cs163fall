/* graph.cpp
 *
 * 
 */
#include "graph.hpp"
using namespace std;

node::node()
{
    next = NULL;
};

node::~node()
{
    delete next;
    next = NULL;
};

graph::graph(int size)
{
    //root = NULL;
    //psuClass = NULL;
    adjacency_list = new vertex[size];
    for (int i = 0; i < size; ++i)
    {
        adjacency_list[i].psuClass = NULL;
        adjacency_list[i].head = NULL;
    }
    list_size = size;
};

graph::~graph()
{
    for (int i = 0; i < list_size; ++i)
    {
        delete[] adjacency_list[i].psuClass;
        delete adjacency_list[i].head;
        //delete root;
    }
    delete[] adjacency_list;
    //delete[] psuClass;
    list_size = 0;
};

int graph::insert_vertex(char *newClassNum)
{
    int passed = 1;
    return insert_vertex(newClassNum, passed);
};

int graph::insert_vertex(char *aClassNumber, int passed)
{
    for (int i = 0; i < list_size; ++i)
    {
        int key = i;
        if (adjacency_list[key].psuClass == NULL)
        {
            adjacency_list[key].psuClass = new char[strlen(aClassNumber) + 1];
            strcpy(adjacency_list[key].psuClass, aClassNumber);
            //adjacency_list[key].aPSUclass->classNumber = this->aPSUclass->classNumber;
            return 1;
        }
    }
    return 0;
};

int graph::find_location(char *key_value)
{
    return get_location(key_value);
}

int graph::get_location(char *key_value)
{
    for (int i = 0; i < list_size; ++i)
    {
        if (strcmp(adjacency_list[i].psuClass, key_value) == 0)
            return i;
    }
    return 9;
};

int graph::insert_edge(char *mainClass, char *preReq)
{
    int connOne = find_location(mainClass);
    int connTwo = find_location(preReq);
    if (insert_edge(connOne, connTwo) == 1)
        return 1;
    else
        return 0;
};

int graph::insert_edge(int connOne, int connTwo)
{
    node *temp = new node;
    temp = createNode(temp, connOne, connTwo);
    //temp = new node;
    //temp = createNode(temp, connOne, connTwo);
    //createNode(temp, connOne, connTwo);
    //temp->adjacent = &adjacency_list[connTwo];
    //temp->next = adjacency_list[connOne].head;
    //adjacency_list[connOne].head = temp;
    temp = new node;
    //temp = new node;
    temp = createNode(temp, connTwo, connOne);
    //createNode(temp, connTwo, connOne);
    //temp->adjacent = &adjacency_list[connOne];
    //temp->next = adjacency_list[connTwo].head;
    //adjacency_list[connTwo].head = temp;
    //delete temp;
    return 1;
};

node *graph::createNode(node *temp, int connOne, int connTwo)
{
    //node *temp = new node;
    temp->adjacent = &adjacency_list[connTwo];
    temp->next = adjacency_list[connOne].head;
    adjacency_list[connOne].head = temp;

    return temp;
};

int graph::display_adjacent(char *key_value)
{
    cout << "\n\nClass requirements: ";
    int key = find_location(key_value);
    //node *current = new node;
    node *current = adjacency_list[key].head;
    //current = adjacency_list[key].head;
    while (current != NULL && key < list_size && key >= 0)
    {
        if (current->adjacent != NULL)
            cout << current->adjacent->psuClass << " \u2b91  ";
        current = current->next;
    }
    //delete current;
    return 1;
};
