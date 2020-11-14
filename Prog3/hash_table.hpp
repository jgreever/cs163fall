#include "queue.hpp"

struct node
{
    entry hEntry;
    node *next;
};

class table
{
    public:
        table(int size = 12289);
        ~table(void);
        bool load_from_file();
        int insert(char *key_value, const entry &to_add);
        int retrieve(char *name_to_find, entry &found) const;
        int hash_function(char *key) const;

    private:
        node **hash_table;
        int hash_table_size;
};