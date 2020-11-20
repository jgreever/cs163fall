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
#include <time.h>

struct node
{
    int data;
    node *left;
    node *right;
};

class bst
{
public:
    bst();
    ~bst();
    int insert(int data);
    int count();
    int sum();
    int height();
    int remove_all();
    int copy(const bst &to_copy);
    int display();

private:
    node *root;
    int insert(node *&root, int data);
    int count(node *root);
    int sum(node *root);
    int height(node *root);
    int remove_all(node *&root);
    int copy(node *&destination, node *source);
    int display(node *root, int level);
};
