#pragma once
#include "Places.h"
#include "Player.h"
#include "Stack.h"


// ABSTRACT COMMAND CLASS
class Command {
public:
	virtual ~Command() {}
	virtual void execute() = 0;
};


// DERIVED: GO COMMAND
class GoCommand : public Command {
private:
	Stack<Place>* fNavigation; // navigation
	Places* fPlaces;           // array of available places
	string fDestination;       // specified destination

public:
	GoCommand(Stack<Place>* aNavigation, Places* aPlaces, string aDestination) {
		fNavigation = aNavigation;
		fPlaces = aPlaces;
		fDestination = aDestination;
	}

	virtual void execute() {
		// to navigate back to previous location
		if (fDestination.find("back") != string::npos) {
			fNavigation->pop();
		}

		// to navigate to next location
		else {
			// identify whether the specified destination exist
			if (fPlaces->Find(fDestination) < 6) {
				if (fPlaces->getPlace(fPlaces->Find(fDestination)) == fNavigation->peek())
					cout << "You're already here." << endl;
				else {
					fNavigation->push(fPlaces->getPlace(fPlaces->Find(fDestination)));
					cout << fNavigation->peek() << endl;
				}
			}
			// destination does not exist
			else {
				fDestination = fDestination.substr(3, fDestination.size());
				cout << fDestination << " does not exist in this realm." << endl;
			}
		}
	}
};


// VIEW ITEMS COMMAND
class ViewItemsCommand : public Command {
private:
	DLL<Item*>* fItems; // list to view

public:
	ViewItemsCommand(DLL<Item*>* aItems) {
		fItems = aItems;
	}

	virtual void execute() {
		int i = 1;
		DLIterator<Item*> iter = *fItems->getIterator(); // get list from the start
		iter++;
		for (iter; iter != iter.end(); iter++) { // loop through the list
			cout << i << ". " << (*iter)->getName() << endl; // display all items in list
			i++;
		}

	}

	~ViewItemsCommand() {
	}
};


// USE ITEM COMMAND
class UseItemCommand : public Command {
private:
	DLL<Item*>* fItems; // list to loop through
	string fItemName;   // specified item name

public:
	UseItemCommand(DLL<Item*>* aItems, string aItemName) {
		fItems = aItems;
		fItemName = aItemName.substr(4, aItemName.size());
	}

	virtual void execute() {

		string subject;
		cout << "You want to use " << fItemName << " on:" << endl;
		getline(cin, subject);

		DLIterator<Item*> iter = *fItems->getIterator();
		DLNode<Item*>* search;
		while ((search = iter.NextNode()) != (DLNode<Item*>*)0) { // loop through the list
			if ((*iter)->getName() == fItemName) // check if specified item exist
				break;
		}

		if (search == (DLNode<Item*>*)0) { // item does not exist
			cout << "Ay, dawg. You don't got " << fItemName << " in your pocket" << endl;
		}
		else { // item does exist
			search->fData->Use(subject);  // *USE ITEM*
		}
	}
};

// ADD ITEM TO LIST
class AddItemCommand : public Command {
private:
	Player* fPlayer; // player
	Place* fPlace;   // current location
	string fItemName;// specified item name

public:
	AddItemCommand(Player* aPlayer, Place* aPlace, string aItemName) {
		fPlayer = aPlayer;
		fPlace = aPlace;
		fItemName = aItemName.substr(5, aItemName.size());
	}

	virtual void execute() {
		Item* item = fPlace->TakeItem(fItemName); // take item from current location
		if (item != nullptr) // item object is not null (exist)
			fPlayer->AddItem(item);               // add item to inventory
		else                 // item object is null (does not exist)
			delete item;
	}
};

// DROP ITEM FROM INVENTORY TO CURRENT LOCATION
class DropItemCommand : public Command {
private:
	Player* fPlayer; // player
	Place* fPlace;   // current location
	string fItemName;// specified item to drop from inventory

public:
	DropItemCommand(Player* aPlayer, Place* aPlace, string aItemName) {
		fPlayer = aPlayer;
		fPlace = aPlace;
		fItemName = aItemName.substr(5, aItemName.size());
	}

	virtual void execute() {
		Item* item = fPlayer->RemoveItem(fItemName); // take item from inventory
		if (item != nullptr) // Item object is not null (exist)
			fPlace->AddDroppedItems(item);           // add item to current location
		else                 // Item object is null (does not exist)
			delete item;
	}
};

// EXAMINE SPECIFIED ITEM EITHER FROM 
// CURRENT LOCATION OR INVENTORY
class ExamineItemCommand : public Command {
private:
	DLL<Item*>* fItems; // list of items
	string fItemName;   // specified item to examine

public:
	ExamineItemCommand(DLL<Item*>* aItems, string aItemName) {
		fItems = aItems;
		fItemName = aItemName;
	}

	virtual void execute() {
		DLIterator<Item*> iter = *fItems->getIterator();
		DLNode<Item*>* search;
		while ((search = iter.NextNode()) != (DLNode<Item*>*)0) { // loop through the list
			if ((*iter)->getName() == fItemName) // check if specified item exist
				break;
		}

		if (search == (DLNode<Item*>*)0) { // item does not exist
			cout << "You tried to examine " << fItemName << endl;
			cout << "You are confused because " << fItemName << " does not exist" << endl;
		}
		else { // *EXAMINE ITEM*
			search->fData->Examine();
		}
	}
};

// HELP COMMAND
class HelpCommand : public Command {
public:
	virtual void execute() {
		cout << "Available commands: " << endl;
		cout << "1. go <LOCATION NAME>\t- Move to new location" << endl;
		cout << "2. go back         \t- Move to previous location" << endl;
		cout << "3. map             \t- Display all available locations" << endl;
		cout << "4. inventory       \t- Show Items in Inventory" << endl;
		cout << "5. items           \t- Show Items in current location" << endl;
		cout << "6. take <ITEM NAME>\t- Take Item from current location and add into Inventory" << endl;
		cout << "7. drop <ITEM NAME>\t- Drop Item from Inventory (Dropped at current location)" << endl;
		cout << "8. use <ITEM NAME> \t- Use Item from Inventory" << endl;
		cout << "9. examine <ITEM NAME>\t- Examine Item from Inventory/Current Location" << endl;
	}
};