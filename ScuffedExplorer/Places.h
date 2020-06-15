#pragma once
#include <fstream>
#include <string>
#include "Place.h"

class Places
{
private:
	Place** fPlaces = new Place * [6]; // Array of available places

public:
	Places();  // default constructor
	~Places(); // destructor

	int Find(string aPlaceName);  // find specified place
	void ShowAll();               // display all available places
	Place& getPlace(int i);       // get Place specified with index number

	Place& operator[](int index); // overloaded index operator
};