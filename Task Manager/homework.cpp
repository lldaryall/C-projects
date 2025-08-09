
/* I this assignment, you will manage a dynamically allocated list of objects based on a class called Task. 
That class should have the following private data members:

Title
Description
DueDate
IsCompleted
All of these data members should be of type string except for IsCompleted, 
which can be a boolean flag. These should also have getters and setters as appropriate.*/


//The main function of the program should establish a dynamic array of Task object initially of size 2. 
//The application should allow users to add, update, delete, and print out Task objects. 

//The application should adhere to the following guidelines:
1.When adding a Task when the array is already full, the application should add 2 additional 
positions in the array such that the growth algorithm is only called every other add after the first growth.

2.When adding a Task, the application should ask the user for all four pieces of information.

3.When updating a Task, the application should allow the user to mark the Task complete or change the DueDate.

4.When deleting a Task, the application does not have to shrink the array

5.Add, Update, and Delete should be implemented as functions in the same file as the main function. 

6.The print functionality should be implemented as an insertion operator override for the Task class

BONUS: For an extra 3 points, implement an extraction operator overload for the Task class that is used in the Add function.

Your video should clearly show off how your application meets these six guidelines.


