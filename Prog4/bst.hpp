/* bst.hpp
 *
 * Justin Greever
 * CS163 - Program 4
 * 11/19/2020
 *
 * Media Management (using BSTs)
 *
 * Functions MUST be in the private part of the class
 * with wrapper functions in the public section to access
 * the private functions.
 * 
 * node *root; (private data)
 * 
 * functions:   (public/private)
 *      int sum(); / int sum(node *root);
 *      int count(); / int count(node *root);
 *      int sum(); / int sum(node *root);
 *      int height(); / int height(node *root);
 *      int remove_all(); / int remove_all(node *root);
 *      int copy(const table &to_copy); / int copy(node *&destination, node *source);
 * 
 */
#include "table.hpp"

struct node
{
    int data;
    table bstTable;
    node *left;
    node *right;
};

class bst
{
    public:
        bst();
        ~bst();
        bool insert(int data);
        bool insert(table *&aTable, int data);
        int count();
        int sum();
        int height();
        bool remove_all();
        bool copy(const bst &to_copy);
        void display();

    private:
        node *root;
        int data;
        bool insert(node *&root, int data);
        bool insert(node *&root, table *aTable, int data);
        int count(node *root);
        int sum(node *root);
        int height(node *root);
        bool remove_all(node *&root);
        int copy(node *&destination, node *source);
        void display(node *root);
};
