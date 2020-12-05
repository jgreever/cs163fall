/* graph.cpp
 *
 * 
 */
#include "graph.hpp"

table::table(int size)
{
    adjacency_list = new vertex[size];
    for (int i = 0; i < size; ++i)
    {
        adjacency_list[i].anEntry = NULL;
        adjacency_list[i].head = NULL;
    }
    list_size = size;
};

table::~table()
{
    //TODO
    //! Make destructor !//
};

int table::insert_vertex(const aClass &to_add)
{
    aClass *temp;
    for (int i = 0; i < list_size; ++i)
    {
        if (adjacency_list[i].anEntry == NULL)
        {
            temp = new aClass;
            temp->copyEntry(to_add);
            adjacency_list[i].anEntry = temp;
            return 1;
        }
    }
    return 0;
};

int table::find_location(char *key_value)
{
    for (int i = 0; i < list_size; ++i)
    {
        if (adjacency_list[i].anEntry->compare(key_value))
        return i;
    }
    return 0;
};

int table::insert_edge(char *current_vertex, char *to_attach)
{
    int connOne = find_location(current_vertex);
    int connTwo = find_location(current_vertex);
    node *temp = new node;
    temp->adjacent = &adjacency_list[connTwo];
    temp->next = adjacency_list[connOne].head;
    adjacency_list[connOne].head = temp;

    temp = new node;
    temp->adjacent = &adjacency_list[connOne];
    temp->next = adjacency_list[connTwo].head;
    adjacency_list[connTwo].head = temp;
    return 1;
};

int table::display_adjacent(char *key_value)
{
    for (int i = 0; i < list_size; ++i)
    {
        if (adjacency_list[i].anEntry->compare(key_value))
        {
            node *current = adjacency_list[i].head;
            while (current)
            {
                if (current->adjacent)
                    current->adjacent->anEntry->display();
                current = current->next;
            }
        }
    }
    return 1;
};