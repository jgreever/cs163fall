#include <iostream>
#include <cctype>
#include <cstring>

const int MAX = 50;

//TODO: The entries below are so I can diagnose memory leaks in valgrind easier.
//#include "valgrind/valgrind.h"
//#include "valgrind/memcheck.h"

class list
{
public:
    list();
    ~list();
    int add(char priorityLevel[], char projectName[], char estimatedCost[],
            char lengthOfTime[], char needToHire[], char wantDoneBy[],
            char rentSupplies[]);
    int add(const list& new_list);
    int display();
    int search(const char* searchNode);

private:
    char* priorityLevel;
    char* projectName;
    char* estimatedCost;
    char* lengthOfTime;
    char* needToHire;
    char* wantDoneBy;
    char* rentSupplies;
};