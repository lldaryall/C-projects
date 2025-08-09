#ifndef _QUICKQUEUE_HPP
#define _QUICKQUEUE_HPP

template< class T >
QuickQueue< T >::QuickQueue()
{
   front = 0;
   rear = -1;
   size = 0;
   array = new T*[MAX];
}

template< class T >
QuickQueue<T>::~QuickQueue() {
   for(int i = 0; i < size; i++) {
      delete array[i];
   }
   delete [] array;
}

template< class T >
QuickQueue<T>::QuickQueue(const QuickQueue<T>& q) {
   front = q.front;
   rear = q.rear;
   size = q.size;
   
   array = new T*[MAX];
   int current = front;
   for(int i = 0; i < size; i++) {
      array[current] = new T(*q.array[current]);
      current = (current + 1) % MAX;
   }
}

template< class T >
QuickQueue<T>& QuickQueue<T>::operator=(const QuickQueue<T>& q) {
   if(this != &q) {
      for(int i = 0; i < size; i++) {
         delete array[i];
      }
      delete [] array;
      
      front = q.front;
      rear = q.rear;
      size = q.size;
      
      array = new T*[MAX];
      int current = front;
      for(int i = 0; i < size; i++) {
         array[current] = new T(*q.array[current]);
         current = (current + 1) % MAX;
      }
   }
   return *this;
}

template< class T >
bool QuickQueue< T >::Enqueue(T item)
{
   if (size < MAX)
   {
      rear = (rear + 1) % MAX;
      array[rear] = new T;
      *array[rear] = item;
      size++;
      return true;
   }
   else
      return false;
}

template< class T >
T* QuickQueue<T>::Dequeue() {
   T* value = new T(*array[front]);
   delete array[front];
   front = (front + 1) % MAX;
   size--;
   
   return value;
}

#endif
