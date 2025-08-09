#ifndef QUICKQUEUE_H
#define QUICKQUEUE_H

#include <iostream>
using namespace std;

const int MAX = 10;

template< class T >
class QuickQueue
{
public:
   QuickQueue();
   ~QuickQueue();
   bool Enqueue(T item);
   T* Dequeue();
   
   QuickQueue(const QuickQueue<T>& q);
   QuickQueue<T>& operator=(const QuickQueue<T>& q);

private:
	T** array;
	int front;
	int rear;
	int size;

};

#include "QuickQueue.hpp"

#endif
