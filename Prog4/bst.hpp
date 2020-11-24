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
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;

class bst;

struct node
{
    bst *anEntry;
    node *left;
    node *right;
};

class bst
{
    public:
        bst();
        ~bst();
        bool insert(char *name, char *media, char *desc,
                    char *length, char *isNext);
        int count();
        int height();
        bool remove_all();
        bool copy(const bst &to_copy);
        bool display();

    private:
        node *root;
        char *className;
        char *mediaName;
        char *description;
        char *mediaLength;
        char *watchNext;
        bool insert(node *&root, bst *anEntry);
        int count(node *root);
        int height(node *root);
        bool remove_all(node *&root);
        int copy(node *&destination, node *source);
        bool display(node *root);
        bool displayRecursive(node *root);
};
