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
    className = mediaName = description = NULL;
    mediaLength = watchNext = NULL;
}

bst::~bst()
{
    bst::remove_all(root);
}

bool bst::insert(char *name, char *media, char *desc,
                 char *length, char *isNext)
{
    if (this->className)
        delete[] this->className;
    if (this->mediaName)
        delete[] this->mediaName;
    if (this->description)
        delete[] this->description;
    if (this->mediaLength)
        delete[] this->mediaLength;
    if (this->watchNext)
        delete[] this->watchNext;
    this->className = new char[strlen(name) + 1];
    strcpy(this->className, name);
    this->mediaName = new char[strlen(media) + 1];
    strcpy(this->mediaName, media);
    this->description = new char[strlen(desc) + 1];
    strcpy(this->description, desc);
    this->mediaLength = new char[strlen(length) + 1];
    strcpy(this->mediaLength, length);
    this->watchNext = new char[strlen(isNext) + 1];
    strcpy(this->watchNext, isNext);
    return bst::insert(root, this);
}

bool bst::insert(node *&root, bst *anEntry)
{
    if (!root)
    {
        root = new node;
        root->anEntry = anEntry;
        root->left = root->right = NULL;
        return true;
    }
    if (strcmp(root->anEntry->mediaName, anEntry->mediaName) == 1)
        return false;
    if (strcmp(root->anEntry->mediaName, anEntry->mediaName) < 0)
        return bst::insert(root->left, anEntry);
    if (strcmp(root->anEntry->mediaName, anEntry->mediaName) > 1)
        return bst::insert(root->right, anEntry);
    return false;
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
    delete[] className; delete[] mediaName; delete[] description;
    delete[] mediaLength; delete[] watchNext;
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
    destination->anEntry = source->anEntry;
    destination->left = destination->right = NULL;
    int copy_nodes = copy(destination->left, source->left);
    copy_nodes += copy(destination->right, source->right);
    return (copy_nodes + 1);
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
        bst::display(root->left);
        bst::displayRecursive(root);
        bst::display(root->right);
    }
    return true;
}

bool bst::displayRecursive(node *root)
{
    cout << "\nClass Name: " << root->anEntry->className;
    cout << "\nMedia Name: " << root->anEntry->mediaName;
    cout << "\nDescription: " << root->anEntry->description;
    cout << "\nMedia Length: " << root->anEntry->mediaLength;
    cout << "\nWatch Next: " << root->anEntry->watchNext;
    return true;
}