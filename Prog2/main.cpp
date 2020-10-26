#include "stack.hpp"
#include "queue.hpp"

using namespace std;

int main()
{
     stack my_journal;
     journal_entry to_add, an_entry;
     char title[100];
     char notes[300];

  do
  {
  cout <<"Please enter a title: ";
  cin.get(title, 100); cin.ignore(100,'\n');
  cout <<"Please enter the notes: ";
  cin.get(notes, 300); cin.ignore(100,'\n');
  to_add.create_entry(title, notes);

  my_journal.push(to_add);

  } while (again());

  cout <<"\n\nThis is the contents of the stack: ";
  my_journal.display_all();

  do
  {

  if (my_journal.pop())
  {

  cout <<"\n\nAfter removing this is what we have: ";
  my_journal.display_all();
  }
  else  cout <<"\nNothing could be removed, the stack is empty! " <<endl;
  } while (again());

  queue my_journal1;
  journal_entry to_add1, an_entry1;
  char title1[100];
  char notes1[300];

  do
  {
    cout <<"Please enter a title: ";
    cin.get(title1, 100); cin.ignore(100,'\n');
    cout <<"Please enter the notes: ";
    cin.get(notes1, 300); cin.ignore(100,'\n');
    to_add1.create_entry(title1, notes1);

    my_journal1.enqueue(to_add1);

  } while (again());

  cout <<"\n\nThis is the contents of the queue: ";
  my_journal1.display_all();

  do
  {

    if (my_journal1.dequeue())
    {

      cout <<"\n\nAfter removing this is what we have: ";
      my_journal1.display_all();
    }
    else  cout <<"\nNothing could be removed, the queue is empty! " <<endl;
  } while (again());

  return 0;
}
