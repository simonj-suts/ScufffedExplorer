#pragma once

template <class T>
class DLNode {
public:
	T fData;       // data
	DLNode* fNext; // pointer to next node
	DLNode* fPrev; // pointer to previous node

	// CONSTRUCTOR
	DLNode(const T& aData = T(), DLNode* next = (DLNode*)0, DLNode* prev = (DLNode*)0)
		: fData(aData), fNext(next), fPrev(prev) {}
};