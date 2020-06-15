#include "Places.h"

// DEFAULT CONSTRUCTOR
Places::Places() {
    ifstream lPlace;
    string fileName = "Place.txt";
    lPlace.open(fileName, ifstream::in); // open Place.txt
    int i = 0;

    // check if state of stream is good
    if (!lPlace.good()) {
        cerr << "Cannot open text file: " << fileName << endl;
    }
    else {
        string name;
        string desc;
        string gun;
        string key;
        // retrives details for each place from Place.txt
        for (int i = 0; i < 6; i++) {
            getline(lPlace, name);
            getline(lPlace, desc);
            getline(lPlace, gun);
            key = "Key no." + to_string(i + 1);
            fPlaces[i] = new Place(name, desc, gun, key); // instantiate Place objects with data retrieved
        }
    }
    lPlace.close();  // close stream
}

// FIND SPECIFIED PLACE
// returns the correct index if true
int Places::Find(string aPlaceName) {
    string placeName = aPlaceName.substr(3, aPlaceName.size());
    int i = 0;
    for (i; i < 6; i++) { // loop through the array
        if (placeName == fPlaces[i]->getName()) // check if specified place exist
            return i; // specified place exist
    }
    return i++; // returns an index beyond the array size
}

// DESTRUCTOR
Places::~Places() {
    for (int i = 0; i < 6; i++) {
        delete fPlaces[i]; // delete Place object pointer
    }
    delete[] fPlaces; // delete array pointer
}

// DISPLAY ALL PLACES NAME
void Places::ShowAll() {
    cout << "Here are the accessible places:" << endl;
    for (int i = 0; i < 6; i++) // loops through the array
        cout << i + 1 << ". " << fPlaces[i]->getName() << endl; // display each place's name
    cout << endl;
}

// GET PLACE WITH SPECIFIED INDEX
Place& Places::getPlace(int i) {
    return *fPlaces[i];
}

// OVERLOADED INDEX OPERATOR
// return Place specified with index number
Place& Places::operator[](int index) {
    return *fPlaces[index];
}