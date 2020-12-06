/* graph.cpp
 *
 * 
 */
#include "graph.hpp"
using namespace std;

graph::graph(int size)
{
    adjacency_list = new vertex[size];
    for (int i = 0; i < size; ++i)
    {
        adjacency_list[i].aPSUclass = NULL;
        adjacency_list[i].head = NULL;
    }
    list_size = size;
};

graph::~graph()
{
    for (int i = 0; i < list_size; ++i)
    {
        delete[] adjacency_list[i].aPSUclass;
        delete adjacency_list[i].head;
    }
    delete[] adjacency_list;
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
        if (adjacency_list[key].aPSUclass == NULL)
        {
            adjacency_list[key].aPSUclass = new char[strlen(aClassNumber) + 1];
            strcpy(adjacency_list[key].aPSUclass, aClassNumber);
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
        if (strcmp(adjacency_list[i].aPSUclass, key_value) == 0)
            return i;
    }
    return 0;
};

node graph::insert_edge(char *mainClass, char *preReq)
{
    int connOne = find_location(mainClass);
    int connTwo = find_location(preReq);
    return *insert_edge(connOne, connTwo);
};

node *graph::insert_edge(int connOne, int connTwo)
{
    node *temp;
    temp = new node;
    temp->adjacent = &adjacency_list[connTwo];
    temp->next = adjacency_list[connOne].head;
    adjacency_list[connOne].head = temp;

    temp = new node;
    temp->adjacent = &adjacency_list[connOne];
    temp->next = adjacency_list[connTwo].head;
    adjacency_list[connTwo].head = temp;
    return adjacency_list[connOne].head;
};

int graph::display_adjacent(char *key_value)
{
    cout << "\n\nClass requirements: ";
    int key = find_location(key_value);
    if (strcmp(adjacency_list[key].aPSUclass, key_value) == 0)
    {
        node *current = adjacency_list[key].head;
        while (current)
        {
            if (current->adjacent)
                cout << current->adjacent->aPSUclass << " \u2b91  ";
            current = current->next;
        }
    }
    return 1;
};
