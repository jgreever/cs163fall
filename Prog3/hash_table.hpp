#include "queue.hpp"

struct node
{
    entry tEntry;
    node *next;
};

class table
{
    public:
        table(int size = 12289);
        ~table(void);
        bool load_from_file(void);
        int insert(char *name, char *location, char *hint);
        int insert(entry &to_add, int tempKey);
        int retrieve(char *name_to_find) const;
        int hash_function(char *key) const;

    private:
        char *name;
        char *location;
        char *hint;
        node **hash_table;
        int hash_table_size;
};
