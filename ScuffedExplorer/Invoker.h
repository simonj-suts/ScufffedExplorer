#pragma once
#include "Command.h"

class Invoker {
private:
	Command* command; // pointer to command 
	Player* fPlayer;  // player
	Places* fPlaces;  // array of places
	Stack<Place>* fNav; // navigation

public:
	// constructor
	Invoker(Player* player, Places* places, Stack<Place>* nav) {
		command = nullptr;
		fPlayer = player;
		fPlaces = places;
		fNav = nav;
	}

	// destructor
	~Invoker() {
		delete command;
	}

	// execute commands based on user's input
	void executeCommand(string input) {
		bool executed = true;

		if (input.find("go") != string::npos) { // go to different place
			command = new GoCommand(fNav, fPlaces, input);
		}
		else if (input.find("items") != string::npos) { // display all items in current location
			cout << "Items you found at " << fNav->peek().getName() << ":" << endl;
			command = new ViewItemsCommand(fNav->peek().getItems());
		}
		else if (input.find("inventory") != string::npos) { // display all items in inventory
			cout << "Items in your inventory:" << endl;
			command = new ViewItemsCommand(fPlayer->getInventory());
		}
		else if (input.find("use") != string::npos) { // use specified item
			command = new UseItemCommand(fPlayer->getInventory(), input);
		}
		else if (input.find("take") != string::npos) { // take specified item
			command = new AddItemCommand(fPlayer, &fNav->peek(), input);
		}
		else if (input.find("drop") != string::npos) { // drop specified item
			command = new DropItemCommand(fPlayer, &fNav->peek(), input);
		}
		else if (input.find("examine") != string::npos) { // examine specified item..
			input = input.substr(8, input.size());
			if (fPlayer->FindItem(input)) { // ..from inventory
				cout << "An item from your inventory" << endl;
				command = new ExamineItemCommand(fPlayer->getInventory(), input);
			}
			else if (fNav->peek().FindItem(input)) { // .. from current location
				cout << "An item you found at " << fNav->peek().getName() << endl;
				command = new ExamineItemCommand(fNav->peek().getItems(), input);
			}
		}
		else if (input.find("help") != string::npos) { // help
			command = new HelpCommand;
		}
		else { // command not found
			cout << "Invalid command" << endl;
			cout << "Seek \"help\"" << endl;
			executed = false;
		}

		if (executed) { // *execute command*
			command->execute();
		}
	}
};