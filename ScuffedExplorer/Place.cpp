#include "Place.h"

// DEFAULT CONSTRUCTOR
Place::Place() {}

// CONSTRUCTOR
Place::Place(string aName, string aDescription, string aGun, string aKey) {
	fName = aName;
	fDescription = aDescription;
	Item* fGun = new Gun(aGun);
	Item* fKey = new Key(aKey);
	fObjects->append(fGun);
	fObjects->append(fKey);
}

// DESTRUCTOR
Place::~Place() {
	delete fObjects;
}

// RETURN PLACE NAME
string Place::getName() {
	return fName;
}

// RETURN POINTER TO fObjects
DLL<Item*>* Place::getItems() {
	return fObjects;
}

// FIND ITEM IN fObjects
bool Place::FindItem(string aItemName) {
	ObjectListIterator iter = *fObjects->getIterator();
	iter++;
	for (iter; iter != iter.end(); iter++) {    // loop through the list
		if ((*iter)->getName() == aItemName) {  // if item exist
			return true; // item exist
		}
	}
	return false; // item does not exist
}

// ADD DROPPED ITEMS INTO fObjects
void Place::AddDroppedItems(Item* aItem) {
	fObjects->append(aItem);
}

// REMOVE ITEM FORM fObjects
Item* Place::TakeItem(string aItemName) {
	ObjectListIterator iter = *fObjects->getIterator();
	Object* search;
	while ((search = iter.NextNode()) != (Object*)0) {  // loop through the list
		if ((*iter)->getName() == aItemName) // if item exist
			break;
	}

	if (search == (Object*)0) {  // if item does not exist or null
		cout << "Item not found." << endl;
		return nullptr;
	}
	else { // item exist
		Item* item(search->fData);
		if (fObjects->remove(search)) { // check if removing item successful
			return item;
		}
		else { // removing item failed
			return nullptr;
		}
	}
}

// BINARY OVERLOADED OPERATOR
// Check if current place == next destination
bool Place::operator==(const Place& aPlace) {
	return (fName == aPlace.fName);
}

// INSERTION OVERLOADED OPERATOR
// display Place details
ostream& operator<<(ostream& os, const Place& aPlace) {
	os << "You are now in: " << aPlace.fName << endl;
	os << aPlace.fDescription << endl;
	return os;
}