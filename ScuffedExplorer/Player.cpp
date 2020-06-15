#include "Player.h"

// DEFAULT CONSTRUCTOR
Player::Player() {
	Item* defGun = new Gun("Pisstol");
	inv->append(defGun);
}

// DESTRUCTOR
Player::~Player() {
	delete inv;
}

// RETURN POINTER TO INVENTORY
DLL<Item*>* Player::getInventory() {
	return inv;
}

// FIND ITEM IN INVENTORY
// true = item exist in inventory
// false = item does NOT exist in inventory
bool Player::FindItem(string aItemName) {
	InventoryIterator iter = *inv->getIterator();
	iter++;
	for (iter; iter != iter.end(); iter++) {
		if ((*iter)->getName() == aItemName) {
			return true;
		}
	}
	return false;
}

// ADD ITEM INTO INVENTORY
void Player::AddItem(Item* aItem) {
	inv->append(aItem);
	cout << aItem->getName() << " added to your iventory." << endl;
}

// REMOVE ITEM FROM INVENTORY
Item* Player::RemoveItem(string aItemName) {
	InventoryIterator iter = *inv->getIterator();
	Object* search;
	while ((search = iter.NextNode()) != (Object*)0) { // loops through the node
		if ((*iter)->getName() == aItemName)           // check if specified Item exist
			break;
	}

	// Item does not exist
	if (search == (Object*)0) {
		cout << "Item not found." << endl;
		return nullptr;
	}

	// Item exist
	else {
		Item* item(search->fData);
		if (inv->remove(search)) { // remove item
			cout << aItemName << " dropped." << endl;
			return item;
		}
		else {                     // unable to remove item
			cout << aItemName << " can't be dropped" << endl;
			return nullptr;
		}
	}
}