#include "queue.hpp"

struct node
{
    entry anEntry;
    node *next;
};

class table
{
public:
    table(int size = 12289);
    ~table();
    bool load_from_file();
    bool clear_table();
    int insert(char *name, char *location, char *hint);
    int retrieve(char *name_to_find);
    int hash_function(char *key) const;

private:
    node **hash_table;
    int hash_table_size;
};
