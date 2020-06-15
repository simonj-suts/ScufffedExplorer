#include <iostream>
#include "Invoker.h"

using namespace std;

int main() {
    // INSTANTIATE OBJECTS
    Player me = Player();     // Player
    Places places = Places(); // Places
    Stack<Place> nav;         // Navigation
    nav.push(places[0]);      // Initialise first place


    // PROGRAM STARTS HERE
    cout << nav.peek() << endl;
    while (true) {
        // INSTANTIATE INVOKER: Command Design Pattern
        Invoker* invoker = new Invoker(&me, &places, &nav);

        // GET USER INPUT
        string command;
        getline(cin, command);

        // EXECUTION BASED ON USER'S INPUT 
        // find if specified items exist in inventory or current place
        if (command.find("examine") != string::npos) {
            string ItemName = command.substr(8, command.size());
            if (me.FindItem(ItemName) || nav.peek().FindItem(ItemName)) {
                invoker->executeCommand(command);
            }
            else {
                cout << "You tried to examine " << command << endl;
                cout << "You are confused because " << command << " does not exist" << endl;
            }
        }

        // Display all available locations
        else if (command.find("map") != string::npos) {
            places.ShowAll();
        }

        // Quit
        else if (command.find("quit") != string::npos) {
            cout << "GoodBye" << endl;
            break;
        }

        // Command execution
        else {
            invoker->executeCommand(command);
        }

        delete invoker;
    }
}