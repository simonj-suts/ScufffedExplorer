#pragma once
#include "Item.h"

class Key : public Item
{
private:
	bool used; // has the key been used

public:
	Key() : used(false) {}                               // default constructor
	Key(const Key& aKey) : used(false) {}				 // copy constructor
	Key(string aName) : Item(aName), used(false) { };   // constructor

	// Inherited methods (Overriding function)
	void Use(string fSubject);
	void Examine();
};