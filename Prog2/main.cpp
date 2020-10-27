#include "stack.hpp"
using namespace std;

int main()
{
  stack alerts;
  alertEntry to_add;

  char origin[101];
  char date[51];
  char time[11];
  char message[301];
  char priority[11];

  int choice = 1;

  while (choice != 0)
  {
    cout << "\n********************\n";
    cout << " Main Menu\n";
    cout << " --------------------\n";
    cout << "1. Push a notification\n";
    cout << "2. Pop a notification\n";
    cout << "3. Peek at top of stack\n";
    cout << "4. Display entire stack\n";
    cout << "0. Exit the program\n";
    cout << "********************\n";
    cin >> choice;
    cin.ignore(100, '\n');

    switch (choice)
    {
      case 1:
        cout << "Enter the Origin of the Notification:\n";

        cout << "Enter the date of the Notification:\n";

        cout << "Enter the time of the Notification:\n";

        cout << "Enter the Notification message:\n";

        cout << "Enter the Notification priority:\n";
        
        to_add.create_entry(origin, date, time, message, priority);
        alerts.push(to_add);
        break;
      
      case 2:
        if (alerts.pop())
          cout << "\nRemoved the most recent Notification...\n";
        else
          cout << "\nNo notifications in the list to delete...\n";
        break;
      
      case 3:
        cout << "\nHere is the most recent Notification:\n";
        //alerts.peek();
        break;
    
      case 4:
        cout << "\nThe stack contains the following Notifications: \n";
        alerts.display_all();
        break;

      case 0:
        break;

      default:
        cout << "Invalid entry, try again.\n";
        continue;
    }

  }

  if (alerts.pop())
  {

    cout << "\n\nAfter removing this is what we have: ";
    alerts.display_all();
  }
  else
    cout << "\nNothing could be removed, the stack is empty! " << endl;
}