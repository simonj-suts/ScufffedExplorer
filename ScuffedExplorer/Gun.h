#pragma once
#include "Item.h"

class Gun : public Item
{
private:
	int fBullets; // bullets

public:
	Gun() : fBullets(5) {}                          // default constructor
	Gun(const Gun& aGun) : fBullets(3) {}			// copy constructor
	Gun(string aName) : Item(aName), fBullets(3) {} // constructor

	// Inherited Methods (Overriding function)
	void Use(string fSubject);
	void Examine();
};