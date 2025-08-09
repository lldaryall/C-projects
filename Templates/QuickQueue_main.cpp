#include <iostream>
#include "QuickQueue.h"

using namespace std;

int main()
{
   QuickQueue< int > intQueue;
   cout << "\nTesting integer queue:\n";
   
   for (int i = 1; i <= 5; i++) {
      intQueue.Enqueue(i * 10);
      cout << "Enqueued: " << i * 10 << '\n';
   }
   
   cout << "Dequeueing integers:\n";
   for (int i = 0; i < 5; i++) {
      int* value = intQueue.Dequeue();
      cout << "Dequeued: " << *value << '\n';
      delete value;
   }

   QuickQueue< double > doubleQueue;
   cout << "\nTesting double queue:\n";
   
   for (int i = 1; i <= 5; i++) {
      doubleQueue.Enqueue(i * 1.5);
      cout << "Enqueued: " << i * 1.5 << '\n';
   }
   
   cout << "\nDequeueing doubles:\n";
   for (int i = 0; i < 5; i++) {
      double* value = doubleQueue.Dequeue();
      cout << "Dequeued: " << *value << '\n';
      delete value;
   }

   return 0;
} 