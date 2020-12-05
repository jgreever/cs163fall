/* graph.hpp
 * 
 * Justin Greever
 * CS163 - Program 5
 * 12/01/2020
 * 
 * Adjacency List / Graph of PSU Classes and Requirements
 * 
 */
#include "entry.hpp"

// Forward declarations to keep compiler happy
struct node;
class aClass;

struct vertex
{
    aClass *anEntry;
    struct node *head; //”incomplete” declaration
};

struct node 
{
    vertex *adjacent; //could be an index or a key
    node *next; 
};

class table
{
    public:
        table(int size=5);
        ~table(void);
        int insert_vertex(const aClass &to_add);
        int find_location(char *key_value);
        int insert_edge(char *current_vertex, char *to_ttach);
        int display_adjacent(char *key_value);
    private:
        vertex *adjacency_list;
        int list_size;
};