#include "Queue.hpp";
#include <bits/stdc++.h>
using namespace std;

Queue::Queue(int capacity) : capacity(capacity), front(0), rear(0), count(0)
{
    this->data = new int[capacity];
};

Queue::Queue(const Queue &other)
{
    this->capacity = other.capacity;
    this->front = other.front;
    this->rear = other.rear;
    this->count = other.count;
    for (int i = 0; i < this->count; i++)
    {
        this->data[i] = other.data[i];
    }
}

Queue::~Queue()
{
    delete[] data;
};

Queue &Queue::operator=(const Queue &other)
{
    if (this == &other)
    {
        return *this;
    }
    delete[] data;

    this->capacity = other.capacity;
    this->front = other.front;
    this->rear = other.rear;
    this->count = other.count;
    this->data = new int[this->capacity];
    for (int i = 0; i < count; i++)
    {
        this->data[i] = other.data[i];
    }
    return *this;
}

Queue Queue::operator+(const Queue &other) const
{
    // copy element from this to another queue
    Queue result(this->capacity + other.capacity);

    for (int i = 0, idx = front; i < count; i++, idx = (idx + 1) % capacity)
    {
        result.enqueue(data[idx]);
    }
    for (int j = 0, idx = other.front; j < other.count; j++, idx = (idx + 1) % capacity)
    {
        result.enqueue(other.data[idx]);
    }

    return result;
}

bool Queue::isFull() const
{
    return (count == capacity);
}
void Queue::enqueue(int value)
{
    if (isFull())
    {
        cout << "Queue full!\n";
        return;
    }
    data[rear] = value;
    rear = (rear + 1) % capacity;
    count++;
}

int Queue::dequeue()
{
    if (isEmpty())
    {
        return -1;
    }
    int temp = data[front];
    front = (front + 1) % capacity;
    count--;
    return temp;
}

bool Queue::isEmpty() const
{
    return (count == 0);
}

int Queue::size() const
{
    return count;
}

void Queue::printQueue() const
{
    if (isEmpty())
    {
        cout << "[]\n";
    }
    cout << '[';
    for (int i = 0, idx = front; i < count; i++, idx = (idx + 1) % capacity)
    {
        cout << data[idx];
        if (i != count - 1)
        {
            cout << ", ";
        }
    }
    cout << "]\n";
};