#pragma once
#include <iostream>

using namespace std;

class Item
{
protected:
	string fName;

public:
	Item();						// default constructor
	Item(const Item& aItem);	// copy constructor
	Item(string aName);			// constructor

	string getName(); // return fName

	// Abstract methods
	virtual void Use(string fSubject) = 0;
	virtual void Examine() = 0;

	// Overloaded insertion operator
	friend ostream& operator<<(ostream& os, const Item& aItem);
};