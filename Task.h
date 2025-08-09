#include <string>
#include <iostream>
using namespace std;

class Task{
    friend ostream& operator<<(ostream& o, const Task& task);
    friend istream& operator>>(istream& i, Task& task); 
    public: 
        Task();
        Task(string title, string description, string dueDate, bool isCompleted);
        string getTitle() const;
        string getDescription() const;
        string getDueDate() const;
        bool getIsCompleted() const;
        void setTitle(const string& title);
        void setDescription(const string& description);
        void setDueDate(const string& dueDate);
        void setCompleted(bool isCompleted);
        void print() const;

     
    private:
        string title;
        string description;
        string dueDate;
        bool isCompleted;
};
class Bulletin {
    friend ostream& operator<<(ostream& o, const Bulletin& bulletin);
    public:
        Bulletin();
        ~Bulletin();

        Bulletin(const Bulletin& b);

        Bulletin& operator=(const Bulletin& b);

        void add(const Task& task);
        void update(int index, const Task& task);
        void remove(int index);
        void list() const;

        int getSize() const;
        Task* getTask() const;
    private:
        Task* tasks;
        int capacity, size;
};