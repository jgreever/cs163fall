/* main.cpp
 *
 * Justin Greever
 * CS163 - Program 4
 * 11/19/2020
 *
 * Media Management (using BSTs)
 *
 */
#include "table.hpp"
using namespace std;

int main()
{
    bst *mainBST = new bst;
    srand(time(0));
    cout << "\n\nAdding data to the tree...\n";
    for (int i = 0; i < 10; ++i)
    {
        int rng = rand() % 100;
        cout << "\nDEBUG: " << rng << "\n";
        mainBST->insert(rng);
    }
    mainBST->display();
    cout << "\n\nBST Height: " << mainBST->height() << "\n\n";

    if (mainBST)
        delete mainBST;

    return 1;
}