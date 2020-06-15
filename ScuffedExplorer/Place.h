#pragma once
#include <iostream>
#include "DLL.h"
#include "Gun.h"
#include "Key.h"

using namespace std;

class Place
{
public:
	typedef DLNode<Item*> Object;
	typedef DLL<Item*> ObjectList;
	typedef DLIterator<Item*> ObjectListIterator;

private:
	string fName;                           // name of place
	string fDescription;                    // description of place
	ObjectList* fObjects = new ObjectList(); // List of items available in that place

public:
	Place();															// default constructor
	Place(string aName, string aDescription, string aGun, string aKey); // constructor
	~Place();															// destrcutor

	string getName();       // getter for fName
	ObjectList* getItems(); // getter for fObjects

	bool FindItem(string aItemName);   // Find Item in fObjects
	void AddDroppedItems(Item* aItem); // Add Item dropped by player into fObjects
	Item* TakeItem(string aItemName);  // Remove Item from fObjects

	// overloaded operators
	bool operator==(const Place& aPlace);                         // binary operator
	friend ostream& operator<<(ostream& os, const Place& aPlace); // insertion operator
};