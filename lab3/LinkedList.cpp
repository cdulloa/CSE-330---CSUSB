#ifndef LL_H
#define LL_H
#include<iostream>
using namespace  std;

template <typename T>
class LinkedList
{

public:
    //Default constructor
    LinkedList() :size(0)
    {
        head = new NodeType();
    }
    //Destructor
    ~LinkedList()
    {
        clear();
        delete head;
    }
    bool empty() const
    {
        if (size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // Returns the list to the empty state
    void clear()
    {
        size = 0;
    }
    //Returns the number of items in the list
    int get_size() const
    {
        return size;
    }
    //checks if item in the list
    bool find(const T& item)
    {
        NodeType* ptr = head->next;
        while (ptr != nullptr && ptr-> data != item)
        {
            ptr = ptr->next;
        }
        if (ptr != nullptr)
            return true;
        else
            return false;
    }
    //Inserts item at the front
    void push_front(const T& item)
    {
        if (size == 0)
        {
            size++;
            head->data = item;
            return;
        }
        size++;
        NodeType* n = new NodeType();
        n->data = item;
        n->next = head;
        head = n;
    }
    //Remove the first item
    void pop_front()
    {
        if (size == 0)
        {
            return;
        }
        NodeType* t = head;
        head = head->next;
        size--;
        if (size == 0)
        {
            head = new NodeType();
        }
    }
    void print()
    {
        if (size == 0)
        {
            return;
        }
        NodeType* t = head;
        while (t->next != NULL)
        {
            cout << " " << t->data << ",";
            t = t->next;
        }
        cout << " " << t->data << endl;
        return;
    }
private:
    struct NodeType
    {
        T data;
        NodeType* next;
        NodeType() :data(), next(nullptr)
        {}

        NodeType(const T& d) : data(d), next(nullptr)
        {}
    };

    int size;       //the size of the linked list
    NodeType* head; //points to the header node
};
#endif
