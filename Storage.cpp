#include "Storage.h"

Storage::Storage(){
	server = new Server();
	patrons = new PDeque();
	init();
}

Storage::~Storage(){
	// Delete all patrons
	// patrons->clear();
	// Iterate through the patrons and delete them all.
	while(patrons->count() > 0){
		delete patrons->remove(0);
	}
	delete patrons;

	delete server;
}

void Storage::retBooks(BookArray* bookArr){
	server->retrieve(*bookArr);
}

void Storage::retPatrons(PDeque* patronArr){
	for (int i = 0; i < patrons->count(); ++i){
		patronArr->push(patrons->get(i));
	}
}

void Storage::updPatrons(UpdateType action, Patron* patron){
	switch(action){
		case ADD:
			addPatron(patron);
			break;
		case MODIFY:
			modPatron(patron);
			break;
		case DELETE:
			if(patron->parent != NULL){
				patron->parent->RemoveDependent(patron);
			}

			delete patrons->remove(patron);
			break;
	}
}

void Storage::addPatron(Patron* patron){
	patrons->push(patron);
}

void Storage::modPatron(Patron* patron){
	Patron* oldPatron = patrons->get(patron->name);

	if (oldPatron == NULL) return; // Patron not found. Needs to be added

	oldPatron = patron;

	patrons->update(oldPatron); // Update the patron priority
}

void Storage::init(){
	// INITIALIZE PATRONS
	Patron* parent = new AdultPatron(new Name("Sunmock", "Yang"), 22);
	addPatron(parent);
	Patron* child = new ChildPatron(new Name("Little", "Anne"), 12);
	addPatron(child);
	child->MakeDependent(parent);

	addPatron(new AdultPatron(new Name("Emily", "Deng"), 22));
	addPatron(new AdultPatron(new Name("Priscilla", "Hwang"), 22));
	addPatron(new AdultPatron(new Name("s", "s"), 45));
}
