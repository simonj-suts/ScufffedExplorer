#include "Gun.h"

// EXAMINE GUN (with its own implementation)
void Gun::Examine() {
	cout << "It's a " << fName << " with " << fBullets << " bullets left." << endl;
}

// USE GUN
void Gun::Use(string fSubject) {
	if (fBullets != 0) { // if there is bullet(s)
		if (fSubject == "me" || fSubject == "myself") {                       // shoot "me" or "myself"
			cout << "Somehow the game developer does not allow that" << endl;
		}
		else if (fSubject.find("eveloper") != string::npos) {                 // shoot developer
			cout << "Yea, I do not allow that as well." << endl;
			cout << "But you can mess around with the source code tho." << endl;
		}
		else {                                                                // shoot other subjects
			fBullets -= 1;
			cout << "You shot " << fSubject << " epicly. " << fBullets << " bullets left." << endl;
		}

	}
	else { // no bullets
		cout << "You ran out of bullets, but you used the handle of " << fName << " on " << fSubject << " instead." << endl;
		cout << "It's 0% effective" << endl;
	}
}