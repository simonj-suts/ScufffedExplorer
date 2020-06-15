#pragma once
#include "DLL.h"
#include "Gun.h"
using namespace std;

class Player
{
public:
	typedef DLNode<Item*> Object;
	typedef DLL<Item*> Inventory;
	typedef DLIterator<Item*> InventoryIterator;

private:
	Inventory* inv = new Inventory(); // Inventory (Doubly Linked List storing Item*)

public:
	Player();  // default constructor
	~Player(); // destructor

	// METHODS
	Inventory* getInventory();            // Get Inventory
	bool FindItem(string aItemName);      // Find Item in Inventory
	void AddItem(Item* aItem);            // Add Item into Inventory
	Item* RemoveItem(string aItemName);   // Remove Item from Inventory
};