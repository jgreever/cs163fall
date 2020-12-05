/* main.cpp
 *
 * 
 */
#include "graph.hpp"
using namespace std;

int main()
{
    graph mainGraph;    
    aClass mainEntry;
    char classNumber[10];

    cout << "\n\nEnter the class number (ex. CS163): ";
    cin.get(classNumber, 10, '\n');
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    mainEntry.createEntry(classNumber);
    mainGraph.insert_vertex(mainEntry);
    cout << "\n\nEnter another class number (ex. CS202): ";
    cin.get(classNumber, 10, '\n');
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    mainEntry.createEntry(classNumber);
    mainGraph.insert_vertex(mainEntry);
    cout << "\n\nType the name of the item to link: ";
    char classOne[10];
    char classTwo[10];
    cin.get(classOne, 10, '\n');
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nNow enter the name to link it with: ";
    cin.get(classTwo, 10, '\n');
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    mainGraph.insert_edge(classOne, classTwo);
    cout << "\n\nDisplaying edges: ";
    mainGraph.display_adjacent(classOne);

    return 1;
}