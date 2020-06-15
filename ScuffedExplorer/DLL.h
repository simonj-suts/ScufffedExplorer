#pragma once
#include <iostream>
#include "DLLIterator.h"

using namespace std;

template <class T>
class DLL {
public:
	typedef DLNode<T> Node;

private:
	Node* head; // start of list
	Node* tail; // end of list

public:
	DLL() {  // default constructor
		head = new Node();
		tail = new Node();
	}

	~DLL() { // destructor
		clear();
		delete head;
		delete tail;
	}

	bool isEmpty();              // check if list is empty
	void append(const T& aData); // add new data
	bool remove(Node* aNode);    // remove specified node
	void clear();                // remove everything in list

	DLIterator<T>* getIterator();// get Iterator from the head of the list
};

// CHECK IF LIST IS EMPTY
template <class T>
bool DLL<T>::isEmpty() {
	// return if next node of head and previous node of tail is null
	return (head->fNext == (Node*)0 && tail->fPrev == (Node*)0);
}

// ADD NEW DATA
template <class T>
void DLL<T>::append(const T& aItem) {
	if (isEmpty()) {  // if list is empty
		Node* newNode = new Node(aItem); // create new node
		head->fNext = newNode;
		tail->fPrev = newNode;
	}
	else {             // list is not empty
		// point to last node
		Node* last = tail->fPrev;
		// create new node with its previous node pointing to last node
		Node* newNode = new Node(aItem, (Node*)0, last);
		last->fNext = newNode;
		tail->fPrev = newNode;
	}
}

// REMOVE SPECIFIED NODE
template <class T>
bool DLL<T>::remove(Node* aNode) {
	if (isEmpty()) { // check if list is empty
		return false;
	}

	// loop through the list to find if specified node exist
	Node* ptr = head->fNext;
	while (ptr != (Node*)0) {
		if (ptr == aNode)
			break;
		ptr = ptr->fNext;
	}


	if (ptr == (Node*)0) return false; // specified node does not exist
	else {							   // specified node exist
		Node* afterPtr = ptr->fNext;
		Node* beforePtr = ptr->fPrev;

		if (afterPtr == (Node*)0) tail->fPrev = beforePtr;
		else afterPtr->fPrev = beforePtr;

		if (beforePtr == (Node*)0) head->fNext = afterPtr;
		else beforePtr->fNext = afterPtr;

		delete ptr;
		return true;
	}
}

// REMOVE ALL NODES (EXCEPT HEAD & TAIL)
template <class T>
void DLL<T>::clear() {
	while (tail->fPrev != (Node*)0) { // loop through while deleting one by one
		Node* del = tail->fPrev;
		tail->fPrev = del->fPrev;
		delete del;
	}
}

// GET ITERATOR FROM THE HEAD OR START OF THE LIST
template <class T>
DLIterator<T>* DLL<T>::getIterator() {
	DLIterator<T>* iter = new DLIterator<T>(head);
	return iter;
}