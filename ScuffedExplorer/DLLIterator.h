#pragma once
#include "DLNode.h"

template <class T>
class DLIterator {
public:
	typedef DLNode<T> Node;

private:
	Node* fNode; // Node

public:
	DLIterator(Node* aNode = (Node*)0) { fNode = aNode; } // Constructor

	T& operator*() { return fNode->fData; } // dereference operator

	// overloaded binary operator
	bool operator==(const DLIterator& aOther) { return fNode == aOther.fNode; }
	bool operator!=(const DLIterator& aOther) { return !(*this == aOther); }

	Node* NextNode(); // retrieves next node
	Node* PrevNode(); // retrieves previous node

	// increment operator
	DLIterator& operator++();
	DLIterator operator++(int);

	// decrement operator
	DLIterator& operator--();
	DLIterator operator--(int);

	DLIterator end();   // takes last node in iterator
	DLIterator begin(); // takes first node in iterator
};

// RETURNS NEXT NODE
template <class T>
DLNode<T>* DLIterator<T>::NextNode() {
	if (fNode != (Node*)0) { // if current node is not null
		fNode = fNode->fNext;
		return fNode;
	}
	else                      // current node is null
		return (Node*)0;
}

// RETURNS PREVIOUS NODE
template <class T>
DLNode<T>* DLIterator<T>::PrevNode() {
	if (fNode != (Node*)0) { // if current node is not null
		fNode = fNode->fPrev;
		return fNode;
	}
	else                     // current node is null
		return (Node*)0;
}

// INCREMENT OPERATOR (++iter)
template <class T>
DLIterator<T>& DLIterator<T>::operator++() {
	if (fNode != (Node*)0) {
		fNode = fNode->fNext;
	}
	return *this;
}

// INCREMENT OPERATOR (iter++)
template <class T>
DLIterator<T> DLIterator<T>::operator++(int) {
	DLIterator<T> old = *this;
	++(*this);
	return old;
}

// DECREMENT OPERATOR (--iter)
template <class T>
DLIterator<T>& DLIterator<T>::operator--() {
	if (fNode != (Node*)0) {
		fNode = fNode->fPrev;
	}
	return *this;
}

// DECREMENT OPERATOR (iter--)
template <class T>
DLIterator<T> DLIterator<T>::operator--(int) {
	DLIterator<T> old = *this;
	--(*this);
	return old;
}

// TAKES LAST NDOE
template <class T>
DLIterator<T> DLIterator<T>::end() {
	Node* ptr = fNode;
	while (ptr != (Node*)0) { // loops until current node is null
		ptr = ptr->fNext;     // move to next node
	}
	return DLIterator<T>(ptr);
}

// TAKES PREVIOUS NODE
template <class T>
DLIterator<T> DLIterator<T>::begin() {
	Node* ptr = fNode;
	while (ptr != (Node*)0) { // loops until current node is null
		ptr = ptr->fPrev;     // move to previous node
	}
	return DLIterator<T>(ptr);
}