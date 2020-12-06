/* graph.hpp
 * 
 * Justin Greever
 * CS163 - Program 5
 * 12/01/2020
 * 
 * Adjacency List / Graph of PSU Classes and Requirements
 * 
 */
#include <iostream>
#include <cstring>
#include <cctype>
#include <limits>

// Forward declarations to keep compiler happy
struct node;

struct vertex
{
    char *aPSUclass;
    struct node *head;
};

struct node 
{
    vertex *adjacent;
    node *next; 
};

class graph
{
    public:
        graph(int size=5);
        ~graph(void);
        int insert_vertex(char *classNumber);
        int find_location(char *key_value);
        node insert_edge(char *mainClass, char *preReq);
        int display_adjacent(char *key_value);
    private:
        int get_location(char *key_value);
        int insert_vertex(char *aClassNumber, int passed);
        node *insert_edge(int foundOne, int foundTwo);
        int find_location(char *key_value, int key);
        node *head;
        vertex *adjacency_list;
        int list_size;
};