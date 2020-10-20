#include "project.hpp"

int main()
{
    //int MAX = 50;
    int choice = 0;
    char npriorityLevel[MAX];
    char nprojectName[MAX];
    char nestimatedCost[MAX];
    char nlengthOfTime[MAX];
    char nneedToHire[MAX];
    char nwantDoneBy[MAX];
    char nrentSupplies[MAX];

    list lobject;
    project pobject;

    //do
    while (choice != 5)
    {
        std::cout << "\n********************\n";
        std::cout << "Main Menu\n";
        std::cout << "____________________\n";
        std::cout << "1. Add an entry\n";
        std::cout << "2. Delete an entry\n";
        std::cout << "3. Display all project for a priority level\n";
        std::cout << "4. Display all projects\n";
        std::cout << "5. Exit the program\n";
        std::cout << "********************\n";
        std::cin >> choice;
        std::cin.ignore(100, '\n');

        switch (choice)
        {
            case 1:
                std::cout << "Enter the priority level (None, Low, Med, High): ";
                std::cin.get(npriorityLevel, MAX, '\n');
                std::cin.ignore(100, '\n');

                std::cout << "Enter the project name: ";
                std::cin.get(nprojectName, MAX, '\n');
                std::cin.ignore(100, '\n');

                std::cout << "Enter the estimated cost: ";
                std::cin.get(nestimatedCost, MAX, '\n');
                std::cin.ignore(100, '\n');

                std::cout << "Enter the length of time to complete the project: ";
                std::cin.get(nlengthOfTime, MAX, '\n');
                std::cin.ignore(100, '\n');

                std::cout << "If you have to hire someone, enter their name or enter 'none': ";
                std::cin.get(nneedToHire, MAX, '\n');
                std::cin.ignore(100, '\n');

                std::cout << "When do you want it done by: ";
                std::cin.get(nwantDoneBy, MAX, '\n');
                std::cin.ignore(100, '\n');

                std::cout << "If you have to rent supplies, list them here or enter 'none': ";
                std::cin.get(nrentSupplies, MAX, '\n');
                std::cin.ignore(100, '\n');
                
                lobject.add(npriorityLevel, nprojectName, nestimatedCost, nlengthOfTime,
                            nneedToHire, nwantDoneBy, nrentSupplies);

                pobject.add(lobject);
                
                std::cin.clear(); //clears the input buffer of any invalid entries (i.e. pressing enter)
                                  //it also prevents a loop when pressing enter only

                break;

            case 2:
                char toDelete[MAX];
                std::cout << "Enter the name of the project you wish to delete: ";
                std::cin.get(toDelete, MAX, '\n');
                std::cin.ignore(100, '\n');
                pobject.remove(toDelete);
                break;

            case 3:
                char prioritySearch[MAX];
                std::cout << "Enter the priority level you wish to display.\n";
                std::cout << "High, Med, Low, or None: ";
                std::cin.get(prioritySearch, 100, '\n');
                std::cin.ignore(100, '\n');
                pobject.displayPriority(prioritySearch);
                break;
            case 4:
                pobject.display();
                break;

            case 5:
                std::cout << "Exiting Program\n Thank you!\n";
                break;

            case 0:
                std::cout << "Please fill out all fields.\n";
                continue;
            
            default:
                std::cout << "You entered an invalid option, try again.\n";
                continue;
        }
    }//while (choice != 5);

    return 0;
}