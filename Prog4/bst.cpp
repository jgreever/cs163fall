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
}

// destructor for trees, helps the ~bst() function do it's job
void bst::deleteTree(node * tree)
{
   if (tree)
   {
      deleteTree(tree->left);
      deleteTree(tree->right);
      delete tree;
   }
}

//destructor that calls deleteTree(root) to delete all nodes and clean up
bst::~bst()
{
   deleteTree(root);
}

// Lets get the minimum value in the BST and use it for removal
node *bst::minValue(node *root)
{
    while (root->left)
        root = root->left;
    return root;
}

// Lets get the maximum value in the BST and use it for removal
node *bst::maxValue(node *root)
{
    while (root->right)
        root = root->right;
    return root;
}
// Grab node (if found) and return from search or to delete
node *bst::getNode(node *root, char *to_get)
{
    if (!root) return NULL;
    else if (root->anEntry.compareEntries(root->anEntry, to_get) == 0)
        return root;
    else if (root->anEntry.compareEntries(root->anEntry, to_get) < 0)
        return getNode(root->right, to_get);
    else if (root->anEntry.compareEntries(root->anEntry, to_get) > 0)
        return getNode(root->left, to_get);
    else
        return NULL;
}

//wrapper funcion this passes in anEntry to be inserted. it returns it with root
bool bst::insert(entry &anEntry)
{
    return bst::insert(root, anEntry);
}

//grabs the value passed by the wrapper function and adds the entry if it doesn't exist
bool bst::insert(node *&root, entry &anEntry)
{
    if (!root)
    {
        root = new node;
        root->anEntry.copyEntry(anEntry);
        root->left = root->right = NULL;
        return true;
    }
    else if (root->anEntry.compareEntries(root->anEntry, anEntry) > 0)
        return bst::insert(root->left, anEntry);
    else if (root->anEntry.compareEntries(root->anEntry, anEntry) < 0)
        return bst::insert(root->right, anEntry);
    else
        return false;
    return true;
}

//this counts how many nodes we have. good for many things
int bst::count(node *root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;
    int count_total = count(root->left) + count(root->right);
    return count_total;
}

//wrapper to get the BST height
int bst::height()
{
    return height(root);
}

//does traversal to determine the height of the BST and returns an int value
int bst::height(node *root)
{
    if (!root)
        return 0;
    int left_height = height(root->left);
    int right_height = height(root->right);
    int total_height = max(left_height, right_height);
    return (total_height + 1);
}

//wrapper to remove all nodes
bool bst::remove_all()
{
    return remove_all(root);
}

//this bad boy will destroy everything you can think of!
//does all traversing needed to delete nodes properly
bool bst::remove_all(node *&root)
{
    if (!root)
        return false;
    remove_all(root->left);
    remove_all(root->right);
    delete root;
    //root = NULL;
    return true;
}

//wrapper, this makes a new node and passes it to the other copy function
bool bst::copy(entry &to_copy)
{
    node *destination = new node;
    node *temp = new node;
    temp->anEntry.copyEntry(to_copy);
    return copy(destination, temp);
}

//this grabs value from wrapper function, and copies data from one node to the next
int bst::copy(node *&destination, node *source)
{
    if (!source)
    {
        destination = NULL;
        return false;
    }
    destination = new node;
    destination->anEntry = source->anEntry;
    destination->left = destination->right = NULL;
    int copy_nodes = copy(destination->left, source->left);
    copy_nodes += copy(destination->right, source->right);
    return (copy_nodes + 1);
}

//wrapper for search function
bool bst::search(char *to_search)
{
    return bst::search(root, to_search);
}

//wrapper to search for all instances of a class
bool bst::searchAllClass(char *classToSearch)
{
    return searchAllClass(root, classToSearch);
}

//grabs value from wrapper and traverses to display all entries for a class
bool bst::searchAllClass(node *root, char *to_search)
{
    if (!root)
        return false;
    if (root->anEntry.compareClass(root->anEntry, to_search) == 0)
    {
        root->anEntry.displayEntry();
    }
    if (root->anEntry.compareClass(root->anEntry, to_search) > 0)
        return searchAllClass(root->left, to_search);
    return searchAllClass(root->right, to_search);
}

//grabs data from wrapper and finds the item to display
bool bst::search(node *root, char *to_search)
{
    if (!root)
        return false;
    if (root->anEntry.compareEntries(root->anEntry, to_search) == 0)
    {
        root->anEntry.displayEntry();
        return true;
    }
    if (root->anEntry.compareEntries(root->anEntry, to_search) > 0)
        return search(root->left, to_search);
    return search(root->right, to_search);
}

//wrapper to remove an entry
bool bst::remove_entry(char *to_remove)
{
    return bst::remove_entry(root, to_remove);
}

//grabs wrapper values and deletes a single node and reconnects any
//child nodes and parent node (if needed)
node *bst::remove_entry(node *&root, char *to_remove)
{
    if (!root)
        return root;
    if (root->anEntry.compareEntries(root->anEntry, to_remove) > 0)
        root->left = remove_entry(root->left, to_remove);
    else if (root->anEntry.compareEntries(root->anEntry, to_remove) < 0)
        root->right = remove_entry(root->right, to_remove);
    else
    {
        if (!root->left && !root->right)
        {
            delete root;
            root = NULL;
        }
        else if (root->left && root->right)
        {
            node *child = minValue(root->right);
            root->anEntry.copyEntry(child->anEntry);
            root->right = remove_entry(root->right, child->anEntry.getMediaName());
        }
        else
        {
            if (!root->left)
            {
                node *temp = root->right;
                delete root;
                root = temp;
            }
            else if (!root->right)
            {
                node *temp = root->left;
                delete root;
                root = temp;
            }
        }
    }
    return root;
}

//wrapper to delete all instances of a class in the BST
bool bst::deleteAllClass(char *to_remove)
{
    return deleteAllClass(root, to_remove);
}

//deletes all entries in the BST that match the className
node *bst::deleteAllClass(node *&root, char *to_remove)
{
    if (!root)
        return root;
    if (root->anEntry.compareClass(root->anEntry, to_remove) > 0)
        root->left = remove_entry(root->left, to_remove);
    else if (root->anEntry.compareClass(root->anEntry, to_remove) < 0)
        root->right = remove_entry(root->right, to_remove);
    else
    {
        if (!root->left && !root->right)
        {
            delete root;
            root = NULL;
        }
        else if (root->left && root->right)
        {
            node *child = minValue(root->right);
            root->anEntry.copyEntry(child->anEntry);
            root->right = remove_entry(root->right, child->anEntry.getClassName());
        }
        else
        {
            if (!root->left)
            {
                node *temp = root->right;
                delete root;
                root = temp;
            }
            else if (!root->right)
            {
                node *temp = root->left;
                delete root;
                root = temp;
            }
        }
    }
    return root;
}

//wrapper to delete an entire class
bool bst::remove_class(char *to_remove)
{
    return remove_class(root, to_remove);
}

//traverses and deletes all instances of a class in the BST recursivly
node *bst::remove_class(node *&root, char *to_remove)
{
    if (!root) return NULL;
    deleteAllClass(root, to_remove);
    root->left = remove_class(root->left, to_remove);
    //deleteAllClass(root, to_remove);
    root->right = deleteAllClass(root->right, to_remove);
    return root;
}

//wrapper to display an entry
bool bst::display()
{
    return display(root);
}

//outputs the value in a node
bool bst::display(node *root)
{
    if (root == NULL) return false;
    if (root != NULL)
    {
        root->anEntry.displayEntry();
        return true;
    }
    return false;
}

//wrapper to display all entries
bool bst::display_all()
{
    return bst::display_all(root);
}

//displays all the entries if they exist
bool bst::display_all(node *root)
{
    if (!root)
        return false;
    else if (root)
    {
        bst::displayRecursive(root);
        bst::display_all(root->left);
        bst::display_all(root->right);
    }
    else
        return false;
    return true;
}

//display the entries, but recursivly
bool bst::displayRecursive(node *root)
{
    root->anEntry.displayEntry();
    return true;
}