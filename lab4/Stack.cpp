#ifndef STACK_H
#define STACK_H

#include<iostream>

using namespace std;

template<typename T>
class Stack
{
public:
	// Constructor
	Stack();

	// Destructor
	~Stack();

	// Makes the stack to the empty state
	void make_empty();

	//Checks if stack is empty or not
	bool empty() const;

	//Insert item in stack
	void push(const T& item);

	//Return the top element
	const T& top() const;

	//Removes the top element
	void pop();

	static const int CAPACITY = 50;

private:

	int topOfStack; // -1 for empty stack 
	T* items;
};

//Constructor
template<typename T>
Stack<T>::Stack()
{
	topOfStack = -1;
	items = new T[CAPACITY];
}

//Destructor
template<typename T>
Stack<T>::~Stack()
{
	topOfStack = -1;
	delete items;
}

//Function to check if stack is empty or not
template<typename T>
bool Stack<T>::empty() const
{
	if (topOfStack == -1)
		return true;
	return false;
}

//Push 
template<typename T>
void Stack<T>::push(const T& item)
{
	if (topOfStack == CAPACITY - 1)
		return;
	items[++topOfStack] = item;
}


// Return element at top of the stack
template<typename T>
const T& Stack<T>::top() const
{
	return items[topOfStack];
}

//Pop 
template<typename T>
void Stack<T>::pop()
{
	if (empty())
		return;
	topOfStack--;
}

#endif
