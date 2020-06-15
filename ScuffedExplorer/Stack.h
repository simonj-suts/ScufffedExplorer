#pragma once
#include <iostream>
#include "SLL.h"

using namespace std;

template <class T>
class Stack {
private:
	SNode<T>* top; // top node

public:
	// DEFAULT CONSTRUCTOR
	Stack() : top((SNode<T>*)0) {}

	// DESTRUCTOR
	~Stack() {
		SNode<T>* delStack = top;
		while (top) {
			top = top->fNext;
			free(delStack);
			delStack = top;
		}
	}

	// CHECK IF STACK IS EMPTY
	bool isEmpty() {
		return top == (SNode<T>*)0;
	}

	// RETURNS THE LAST/TOP NODE
	T& peek() {
		return top->fData;
	}

	// PUSH DATA TO THE TOP OF THE STACK
	void push(const T& aData) {
		if (top == (SNode<T>*)0) { // if stack is empty
			top = new SNode<T>;
			top->fNext = (SNode<T>*)0;
			top->fData = aData;
		}
		else {                     // if stack is not empty
			SNode<T>* newStack = new SNode<T>;
			newStack->fData = aData;
			newStack->fNext = top;
			top = newStack;
		}
	}

	// REMOVE TOP/LAST NODE
	void pop() {
		// check if next node is null
		if (top->fNext != (SNode<T>*)0) {
			SNode<T>* delStack = top;
			top = top->fNext;
			free(delStack);
			cout << top->fData << endl;
		}
	}
};