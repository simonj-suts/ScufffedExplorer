#pragma once

template <class T>
class SNode {
public:
	T fData;         // data
	SNode<T>* fNext; // pointer to next node
};