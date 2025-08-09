#include "Task.h"
#include <iomanip>
#include <string>   
#include <iostream>
using namespace std;

Task::Task() {
    title = "";
    description = "";
    dueDate = "";
    isCompleted = false;
}
Task::Task(string title, string description, string dueDate, bool isCompleted) {
    this->title = title;
    this->description = description;
    this->dueDate = dueDate;
    this->isCompleted = isCompleted;
}
string Task::getTitle() const {
    return title;
}
string Task::getDescription() const {
    return description;
}
string Task::getDueDate() const {
    return dueDate;
}
bool Task::getIsCompleted() const {
    return isCompleted;
}
void Task::setTitle(const string& title) {
    this->title = title;
}
void Task::setDescription(const string& description) {
    this->description = description;
}
void Task::setDueDate(const string& dueDate) {
    this->dueDate = dueDate;
}
void Task::setCompleted(bool isCompleted) {
    this->isCompleted = isCompleted;
}
void Task::print() const {
    cout << "Title: " << title << endl;
    cout << "Description: " << description << endl;
    cout << "Due Date: " << dueDate << endl;
    cout << "Completed: ";
        if(isCompleted) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }      
}
ostream& operator<<(ostream& o, const Task& task) {
    o << task.title << "\n"
      << task.description << "\n"
      << task.dueDate << "\n"
      << task.isCompleted << "\n";
    return o;
}
istream& operator>>(istream& i, Task& task) {
    getline(i, task.title);
    getline(i, task.description);
    getline(i, task.dueDate);
    i >> task.isCompleted;
    i.ignore(); 
    return i;
}
Bulletin::Bulletin() {
    capacity = 2;
    size = 0;
    tasks = new Task[capacity];
}
Bulletin::~Bulletin() {
    delete[] tasks;
}
Bulletin& Bulletin::operator=(const Bulletin& b) {
    if (this != &b) {
        this->capacity = b.capacity;
        this->size = b.size;
        delete[] tasks;

        this->tasks = new Task[capacity];
        for (int i = 0; i < size; i++) {
            tasks[i] = b.tasks[i];
        }
    }
    return *this;
}
int Bulletin::getSize() const {
    return size;
}
Task* Bulletin::getTask() const {
    return tasks;
}
void Bulletin::add(const Task& t) {
    if (size == capacity) {
        grow();
    }
    tasks[size++] = t;
}
void Bulletin::remove() {
    cout << "Task to delete: " << endl;
    int index = -1;
    cin >> index;
    for (int i = 0; i < numTasks; i++) {
        if(task[i].getTitle() == task[index].getTitle()) {
            index = i;
            break;
        }
    }
    for (int i = index; i < numTasks - 1; i++) {
        task[i] = task[i + 1];
    }
    numTasks--;
}
void Bulletin::update() {
    int index;
    for (int i = 0; i < size; i++) {
        if(tasks[i].getTitle() == title) {
            index = i;
            break;
        }
    }
    cout << tasks[index] << endl;
    cout << "Task:" << tasks[index].getTitle() << endl;
    cout << "Due Date: " << tasks[index].getDueDate() << " -> ";
    string newDueDate = "";
    cin >> newDueDate;
    tasks[index].setDueDate(newDueDate);
    cout << "Completed: " << (tasks[index].getIsCompleted()) << " -> ";
    bool isCompleted;
    cin >> isCompleted;
    tasks[index].setCompleted(isCompleted);
}
void Bulletin::list() const {
    for (int i = 0; i < size; i++) {
        cout << "Task " << i + 1 << ":" << endl;
        tasks[i].print();
        cout << endl;
    }
}