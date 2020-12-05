/* graph.cpp
 *
 * 
 */
#include "graph.hpp"

graph::graph(int size)
{
    adjacency_list = new vertex[size];
    for (int i = 0; i < size; ++i)
    {
        adjacency_list[i].anEntry = NULL;
        adjacency_list[i].head = NULL;
    }
    list_size = size;
};

graph::~graph()
{
    for (int i = 0; i < list_size; ++i)
    {
        delete adjacency_list[i].anEntry;
        delete adjacency_list[i].head;
    }
    delete[] adjacency_list;
    list_size = 0;
 };

int graph::insert_vertex(const aClass &to_add)
{
    aClass *temp = new aClass();
    for (int i = 0; i < list_size; ++i)
    {
        if (adjacency_list[i].anEntry == NULL)
        {
            //temp = new aClass;
            temp->copyEntry(to_add);
            adjacency_list[i].anEntry = temp;
            return 1;
        }
    }
    return 0;
};

int graph::find_location(char *key_value)
{
    int key = 0;
    return find_location(key_value, key);
}

int graph::find_location(char *key_value, int key)
{
        if (adjacency_list[key].anEntry->compare(key_value) == true && key < list_size)
            return key;
        ++key;
        return find_location(key_value, key);
};

int graph::insert_edge(char *current_vertex, char *to_attach)
{
    int connOne = find_location(current_vertex);
    int connTwo = find_location(to_attach);
    node *temp;
    temp = new node;
    temp->adjacent = &adjacency_list[connTwo];
    temp->next = adjacency_list[connOne].head;
    adjacency_list[connOne].head = temp;

    temp = new node;
    temp->adjacent = &adjacency_list[connOne];
    temp->next = adjacency_list[connTwo].head;
    adjacency_list[connTwo].head = temp;
    return 1;
};

int graph::display_adjacent(char *key_value)
{
        int key = find_location(key_value);
        if (adjacency_list[key].anEntry->compare(key_value) == true)
        {
            node *current = adjacency_list[key].head;
            while (current)
            {
                if (current->adjacent)
                    current->adjacent->anEntry->display();
                current = current->next;
            }
        }
    return 1;
};