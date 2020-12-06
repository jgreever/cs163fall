/* main.cpp
 * 
 * Justin Greever
 * CS163 - Program 5
 * 11/29/2020
 * 
 * We will be implementing only the following algorithms (e.g., member functions); 
 * a) Construct an adjacency list (An array of vertices, 
 *    where each has a head pointer to a LLL of edge nodes. 
 *    The nodes indicate which vertices are adjacent.
 * b) Insert a connection between two course vertices 
 *    (i.e.,inserting a node into the edge list)
 * c) Traverse the adjacency list, displaying all of the courses that can be taken
 *    after I complete this vertices’ course. Do this recursively!
 * d) EXTRA CREDIT for an implementation of a depth first algorithm
 * e) Destroy, deallocating all dynamic memory (e.g., destructor)
 * f) *** THERE IS NO REQUIREMENT FOR INDIVIDUAL DELETE FUNCTION!
 * 
 */
#include "graph.hpp"
using namespace std;

int main()
{
    graph *mainGraph = new graph;
    char classNum[10];
    char classOne[10];
    char classTwo[10];
    int choice = -1;

    do
    {
        cout << "\n\n********************\n";
        cout << "PSU Class Requrement Listing\n";
        cout << "********************\n";
        cout << "\nMain Menu\n";
        cout << "--------------------\n";
        cout << "1. Insert a class number \u2192\n";
        cout << "2. Connect two classes\n";
        cout << "3. Search for media to view requirements \u2193\n";
        cout << "9. Exit the program :( \n";
        cout << "********************\n\n";
        cin >> choice;
        cin.ignore(100, '\n');
        cin.clear();

        switch (choice)
        {
            case 1:
                cout << "\n\nPlease enter the class name/number: ";
                cin.get(classNum, 10, '\n');
                cin.ignore(100, '\n');
                cin.clear();
                mainGraph->insert_vertex(classNum);
                break;

            case 2:
                cout << "\n\nEnter the class to add requirements to: ";
                cin.get(classOne, 10, '\n');
                cin.ignore(100, '\n');
                cin.clear();
                cout << "\n\nEnter the next requirement in the series: ";
                cin.get(classTwo, 10, '\n');
                cin.ignore(100, '\n');
                cin.clear();
                mainGraph->insert_edge(classOne, classTwo);
                break;

            case 3:
                cout << "\n\nEnter the class to view all requirements: ";
                cin.get(classNum, 10, '\n');
                cin.ignore(100, '\n');
                cin.clear();
                mainGraph->display_adjacent(classNum);
                break;

            case 9:
                cout << "\n\nExiting program. Thank you!\n";
                break;

            default:
                cout << "\n\nInvalid entry. Please try again.\n";
                continue;
        }
    } while (choice != 9);

    if (mainGraph)
        delete mainGraph;

    return 1;
}