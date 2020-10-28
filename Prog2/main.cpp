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
        cin.get(origin, 101, '\n');
        cin.ignore(100, '\n');
        cout << "Enter the date of the Notification:\n";
        cin.get(date, 51, '\n');
        cin.ignore(100, '\n');
        cout << "Enter the time of the Notification:\n";
        cin.get(time, 11, '\n');
        cin.ignore(100, '\n');
        cout << "Enter the Notification message:\n";
        cin.get(message, 301, '\n');
        cin.ignore(100, '\n');
        cout << "Enter the Notification priority:\n";
        cin.get(priority, 11, '\n');
        cin.ignore(100, '\n');

        to_add.create_entry(origin, date, time, message, priority);
        alerts.push(to_add);
        cin.clear();
        break;
      
      case 2:
        if (alerts.pop())
          cout << "Removed the most recent Notification...\n";
        else
          cout << "No notifications in the list to delete...\n";
        cin.clear();
        break;
      
      case 3:
        if (alerts.peek())
          cout << "Is the most recent Notification.\n";
        else
          cout << "No recent Notifications.\n";
        cin.clear();
        break;
    
      case 4:
        cout << "The stack contains the following Notifications: \n";
        alerts.display_all();
        cin.clear();
        break;

      case 0:
        cout << "\nThank you and goodbye!\n";
        cin.clear();
        break;

      default:
        cout << "Invalid entry, try again.\n";
        cin.clear();
        continue;
    }
  }
  return 0;
}