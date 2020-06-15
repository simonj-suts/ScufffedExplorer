#include "Key.h"

// USE KEY
void Key::Use(string fSubject) {
	if (used) { // if key has been used before
		cout << "You broke this key. Find a new one." << endl;
	}
	else {      // key has not been used before
		cout << "You used key on " << fSubject << endl;
		used = true;
	}
}

// EXAMINE KEY
void Key::Examine() {
	if (used) { // if key has been used before
		cout << "This key is broken." << endl;
	}
	else {      // key has not been used before
		cout << "It's an unused key." << endl;
	}
}