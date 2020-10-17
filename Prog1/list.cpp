#include "list.hpp"

list::list()
{
    priorityLevel = projectName = estimatedCost = lengthOfTime = needToHire = wantDoneBy = rentSupplies = NULL;
}

list::~list()
{
    std::cout << "List Destructor Called\n"; //TODO: debugging, remove first

    if (priorityLevel)
        delete[] priorityLevel;
    if (projectName)
        delete[] projectName;
    if (estimatedCost)
        delete[] estimatedCost;
    if (lengthOfTime)
        delete[] lengthOfTime;
    if (needToHire)
        delete[] needToHire;
    if (wantDoneBy)
        delete[] wantDoneBy;
    if (rentSupplies)
        delete[] rentSupplies;
    priorityLevel = projectName = estimatedCost = lengthOfTime = needToHire = wantDoneBy = rentSupplies = NULL;
}

int list::add(char apriorityLevel[], char aprojectName[], char aestimatedCost[],
            char alengthOfTime[], char aneedToHire[], char awantDoneBy[],
            char arentSupplies[])
            {
                if (!apriorityLevel || !aprojectName || !aestimatedCost ||
                    !alengthOfTime || !aneedToHire || !awantDoneBy ||
                    !arentSupplies) return 0;

                delete[] priorityLevel; //this is to prevent any issues where the memory didn't get deallocated
                priorityLevel = new char[strlen(apriorityLevel) + 1];
                strcpy(priorityLevel, apriorityLevel);
                delete[]projectName;
                projectName = new char[strlen(aprojectName) + 1];
                strcpy(projectName, aprojectName);
                delete[] estimatedCost;
                estimatedCost = new char[strlen(aestimatedCost) + 1];
                strcpy(estimatedCost, aestimatedCost);
                delete[] lengthOfTime;
                lengthOfTime = new char[strlen(alengthOfTime) + 1];
                strcpy(lengthOfTime, alengthOfTime);
                delete[] needToHire;
                needToHire = new char[strlen(aneedToHire) + 1];
                strcpy(needToHire, aneedToHire);
                delete[] wantDoneBy;
                wantDoneBy = new char[strlen(awantDoneBy) + 1];
                strcpy(wantDoneBy, awantDoneBy);
                delete[] rentSupplies;
                rentSupplies = new char[strlen(arentSupplies) + 1];
                strcpy(rentSupplies, arentSupplies);
                
                return 1;
            }

int list::add(list& new_list)
{
    return list::add(new_list.priorityLevel, new_list.projectName, new_list.estimatedCost,
               new_list.lengthOfTime, new_list.needToHire, new_list.wantDoneBy,
               new_list.rentSupplies);
}

int list::display()
{
    std::cout << "*********************************************************\n";
    std::cout << "Priority Level: " << priorityLevel << std::endl;
    std::cout << "Project Name: " << projectName << std::endl;
    std::cout << "Estimated Cost: " << estimatedCost << std::endl;
    std::cout << "Length of Time to Complete: " << lengthOfTime << std::endl;
    std::cout << "Hire Anyone: " << needToHire << std::endl;
    std::cout << "Want it Done By: " << wantDoneBy << std::endl;
    std::cout << "Rent any Supplies: " << rentSupplies << std::endl;
    std::cout << "*********************************************************\n";
    std::cout << std::endl;

    return 1;
}

int list::search(char* searchNode)
{
    char searchWord[MAX];
    std::strcpy(searchWord, searchNode);
    if (std::strcmp(projectName, searchWord) == 0)
        return 0;
    return 1;
}