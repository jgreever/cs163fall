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

bst::~bst()
{
   deleteTree(root);
}

/*
bst::~bst()
{
    if (root)
    {
        delete root->left;
        delete root->right;
        root->left = root->right = NULL;
        delete root;
    }
    //bst::remove_all(root);
}
*/

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

/*
// Our Inorder Successor so we can delete and reconnect nodes
node *bst::inorderSuccessor(node *root, char *to_find)
{
    node *current = minValue(root);
    if (!root) return NULL;
    if (current->right)
        return minValue(root->right);
    else
    {
        node *parent = root;
        node *child = NULL;
        while (parent != current)
        {
            if (current->anEntry.compareEntries(current->anEntry, parent->anEntry) > 0)
            {
                child = parent;
                parent = parent->left;
            }
            else
                parent = parent->right;
        }
        return child;
    }
}
*/

bool bst::insert(entry &anEntry)
{
    return bst::insert(root, anEntry);
}

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

/*
int bst::count()
{
    return count(root);
}
*/

int bst::count(node *root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;
    int count_total = count(root->left) + count(root->right);
    return count_total;
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
    //root = NULL;
    return true;
}

bool bst::copy(entry &to_copy)
{
    node *destination = new node;
    node *temp = new node;
    temp->anEntry.copyEntry(to_copy);
    return copy(destination, temp);
}

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

bool bst::search(char *to_search)
{
    return bst::search(root, to_search);
}

bool bst::search(node *root, char *to_search)
{
    if (!root)
        return false;
    if (root->anEntry.compareEntries(root->anEntry, to_search) == 0)
        return true;
    if (root->anEntry.compareEntries(root->anEntry, to_search) > 0)
        return search(root->left, to_search);
    return search(root->right, to_search);
    /*
    else if (root->anEntry.compareEntries(root->anEntry, to_search) == 0)
    {
        bst::display(root);
        return true;
    }
    else if (root->anEntry.compareEntries(root->anEntry, to_search) > 0)
        return bst::search(root->left, to_search);
    else if (root->anEntry.compareEntries(root->anEntry, to_search) < 0)
        return bst::search(root->right, to_search);
    else
        return false;
    */
}

bool bst::remove_entry(char *to_remove)
{
    return bst::remove_entry(root, to_remove);
}

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

bool bst::deleteAllClass(char *to_remove)
{
    return deleteAllClass(root, to_remove);
}

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

bool bst::remove_class(char *to_remove)
{
    return remove_class(root, to_remove);
}

node *bst::remove_class(node *&root, char *to_remove)
{
    if (!root) return NULL;
        root->left = remove_class(root->left, to_remove);
        deleteAllClass(root, to_remove);
        root->right = deleteAllClass(root->right, to_remove);
    return root;
}

bool bst::display()
{
    return display(root);
}

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

bool bst::display_all()
{
    return bst::display_all(root);
}

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

bool bst::displayRecursive(node *root)
{
    root->anEntry.displayEntry();
    return true;
}