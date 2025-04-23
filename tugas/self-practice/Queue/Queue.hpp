#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
using namespace std;

class Queue
{
private:
    int *data;
    int capacity;
    int front;
    int rear;
    int count;

public:
    // Constructor
    Queue(int capacity = 10);

    // Copy constructor
    Queue(const Queue &other);

    // Destructor
    ~Queue();

    // Copy assignment
    Queue &operator=(const Queue &other);

    // Operator+ to concatenate two queues
    Queue operator+(const Queue &other) const;

    // Enqueue: add element to rear
    void enqueue(int value);

    // Dequeue: remove element from front
    int dequeue();

    // Print the queue
    void printQueue() const;

    // Utility methods (optional but helpful)
    bool isEmpty() const;
    bool isFull() const;
    int size() const;
};

#endif
