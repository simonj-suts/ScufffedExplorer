#include "Item.h"

// DEFAULT CONSTRUCTOR
Item::Item() {}

// COPY CONSTRUCTOR
Item::Item(const Item& aItem) {
	fName = aItem.fName;
}

// CONSTRUCTOR
Item::Item(string aName) {
	fName = aName;
}

// GETTER FOR fName
string Item::getName() {
	return fName;
}

// OVERLOADED INSERTION OPERATOR
ostream& operator<<(ostream& os, const Item& aItem) {
	os << aItem.fName << endl;
	return os;
}