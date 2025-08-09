#include "Task.h"
#include <iomanip>
#include <string>   
#include <iostream>
using namespace std;

Task* grow(Task*& currentList, int currentSize)

int main() {
    int numTasks = 0, maxTasks = 2;
    Task* task = new Task[maxTasks];
    Bulletin b;
    char selection = '\0';

    
    cout << "Task Menu: " << endl;
    cout << "C. Create New Task" << endl;
    cout << "R. List All Tasks" << endl;
    cout << "U. Update Task" << endl;
    cout << "D. Delete Task" << endl;
    cout << "Q. Quit" << endl;
    cin >> selection;

    switch(selection) {
        case 'C':
        case 'c': {
            string title, description, dueDate;
            bool isCompleted;
            cout << "Task: ";
            cin >> title;
            cout << "Description: ";
            cin >> description;
            cout << "Due Date: ";
            cin >> dueDate;
            cout << "Is the task completed?:"
            cin >> isCompleted;

            if (numTasks >= maxTasks) {
                Task* newTasks = new Task[maxTasks + 2];
                for (int i = 0; i < numTasks; i++) {
                    newTasks[i] = task[i];
                }
                delete[] task;
                task = newTasks;
                maxTasks += 2;
            }
            b.add(Task(title, description, dueDate, isCompleted));
            break;
        }
        case 'R':
        case 'r':
            cout << b << endl;
            break;
        case 'U':
        case 'u':
            cout << b << endl;
            cout << "Enter task number to update: " << endl;
            int index;
            cin >> index = -1;
            cout << "Number of tasks: " << b.getSize() << endl;

            b.update(index, task[index]);
            break;
        case 'D':
        case 'd':
            cout << b << endl;
            cout << "Enter task number to delete: " << endl;
            cin >> index;
            b.remove(index);
            break;
        case 'Q':
        case 'q':
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    } while(selection != 'Q' && selection != 'q');

    delete[] task; 
    return 0;
}
