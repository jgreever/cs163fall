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
//#include <iostream>
//#include <cstring>
//#include <cctype>
//#include <cstdlib>
#include "entry.hpp"
using namespace std;

class entry;

struct node
{
    entry anEntry;
    node *left;
    node *right;
};

class bst
{
    public:
        bst();
        void deleteTree(node *tree);
        ~bst();
        bool insert(entry &anEntry);
        //int count();
        int height();
        bool remove_all();
        bool copy(entry &to_copy);
        bool search(char *to_search);
        bool remove_class(char *to_remove);
        bool remove_entry(char *to_remove);
        bool deleteAllClass(char *to_remove);
        bool display();
        bool display_all();

    private:
        node *root;
        node *minValue(node *root);
        node *maxValue(node *root);
        node *getNode(node *root, char *to_get);
        //node *inorderSuccessor(node *root, char *to_find);
        bool search(node *root, char *to_search);
        node *remove_entry(node *&root, char *to_remove);
        node *remove_class(node *&root, char *to_remove);
        node *deleteAllClass(node *&root, char *to_remove);
        bool insert(node *&root, entry &anEntry);
        int count(node *root);
        int height(node *root);
        bool remove_all(node *&root);
        int copy(node *&destination, node *source);
        bool display(node *root);
        bool display_all(node *root);
        bool displayRecursive(node *root);
};
