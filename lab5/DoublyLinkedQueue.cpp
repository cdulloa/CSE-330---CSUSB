#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

template <typename T>
class Queue {
public:
    // Default constructor
    Queue() 
    {
        front = new NodeType;
        back = new NodeType;
        front->next = back;
        back->prev = front;
    }

    // Desctructor
    ~Queue() 
    {
        clear();
        delete front;
        delete back;
    }

    // makes the queue to empty state
    void clear() 
    {
        delete front;
        delete back;
        front = new NodeType;
        back = new NodeType;
        front-> next = back;
        back-> prev = front;
    }

    // checks if the queue is empty
    bool empty() const 
    {
        return front-> next == back;
    }

    // Insert item at the end of the queue
    void enqueue(const T& item) 
    {
        NodeType* newNode = new NodeType(item);
        newNode-> prev = this-> back->prev;
        newNode-> next = this-> back;
        newNode-> prev->next = newNode;
        this-> back-> prev = newNode;
    }

    // Removes the element at the start of the queue
    void dequeue() 
    {
        if (this-> empty()) 
        {
            return;
        }
        this-> front-> next = this-> front-> next-> next;
        this-> front-> next->prev = this-> front;
    }

    // returns the front element
    const T& front_element() const 
    {
        if (this->empty()) 
        {
            cout << "Queue is Empty!";
        }

        return this->front->next->data;
    }

    // prints the elements of the queue
    void print() const 
    {
        NodeType* ptr = front->next;
        while (ptr != back) 
        {
            cout << ptr->data << ", ";
            ptr = ptr->next;
        }
        cout << endl;
    }

private:
    struct NodeType {
        T data;
        NodeType* next;
        NodeType* prev;

        NodeType(const T& d = T()) : data(d), prev(nullptr), next(nullptr) 
        {}
    };

    NodeType* front; // points to the header node
    NodeType* back; // points to the tail node
};

#endif
