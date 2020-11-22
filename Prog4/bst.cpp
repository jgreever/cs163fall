/* bst.cpp
 *
 * Justin Greever
 * CS163 - Program 4
 * 11/19/2020
 *
 * Media Management (using BSTs)
 *
 * Information to keep track of:
 *      The root node
 *      The following functions:
 *          int count(node *root);
 *          int sum(node *root);
 *          int height(node *root);
 *          int remove_all(node *root);
 *          int copy(node *&destination, node *source);
 * 
 * Wrapper functions will be:
 *      int count();
 *      int sum();
 *      int height();
 *      int remove_all();
 *      int copy(const table &to_copy);
 * 
 */
#include "bst.hpp"

bst::bst()
{
    root = NULL;
    data = 0;
}

bst::~bst()
{
    bst::remove_all(root);
}

bool bst::insert(int data)
{
    return bst::insert(root, data);
}

bool bst::insert(table *&aTable, int data)
{
    table *newTable = aTable;
    return bst::insert(root, newTable, data);
}

bool bst::insert(node *&root, int data)
{
    if (root == NULL)
    {
        root = new node;
        root->data = data;
        root->left = root->right = NULL;
        return true;
    }
    else if (data < root->data)
        bst::insert(root->left, data);
    else if (data > root->data)
        bst::insert(root->right, data);
    else
        return false;
    return true;
}

bool bst::insert(node *&root, table *aTable, int data)
{
    if (!root)
    {
        root = new node;
        //table *temp = aTable;
        root->data = data;
        root->bstTable.insert(aTable);
        root->left = root->right = NULL;
        return true;
    }
    if (data < root->data)
        bst::insert(root->left, aTable, data);
    else
        bst::insert(root->right, aTable, data);
    return true;
} 

int bst::count()
{
    return count(root);
}

int bst::count(node *root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;
    int count_total = count(root->left) + count(root->right);
    return count_total;
}

int bst::sum()
{
    return sum(root);
}

int bst::sum(node *root)
{
    if (!root)
        return 0;
    int sum_total = sum(root->left) + sum(root->right);
    return sum_total + root->data;
}

int bst::height()
{
    return height(root);
}

int bst::height(node *root)
{
    if (!root)
        return 0;
    int left_height = height(root->left);
    int right_height = height(root->right);
    int total_height = max(left_height, right_height);
    return (total_height + 1);
}

bool bst::remove_all()
{
    return remove_all(root);
}

bool bst::remove_all(node *&root)
{
    if (!root)
        return false;
    remove_all(root->left);
    remove_all(root->right);
    delete root;
    root = NULL;
    return true;
}

bool bst::copy(const bst &to_copy)
{
    node *destination = new node;
    return copy(destination, to_copy.root);
}

int bst::copy(node *&destination, node *source)
{
    if (!source)
    {
        destination = NULL;
        return false;
    }
    destination = new node;
    destination->data = source->data;
    destination->left = destination->right = NULL;
    int copy_nodes = copy(destination->left, source->left);
    copy_nodes += copy(destination->right, source->right);
    return (copy_nodes + 1);
}

void bst::display()
{
    return display(root);
}

void bst::display(node *root)
{
    //cout << root->data << ", ";
    if (root == NULL) return;
    if (root != NULL)
    {
        //cout << root->data << ", ";
        bst::display(root->left);
        cout << root->data << ", ";
        bst::display(root->right);
    }
    return;
}