#include "Storage.h"

Storage::Storage(){
	books = new BookArray();
	patrons = new PDeque();
	
	bookIDOffset = 1000;
	init();
}

Storage::~Storage(){
	// Delete all books
	Book* book = books->Pop();
	while(book != NULL){
		delete book;
		book = books->Pop();
	}
	delete books;

	// Delete all patrons
	// patrons->clear();
	// Iterate through the patrons and delete them all.
	while(patrons->count() > 0){
		delete patrons->remove(0);
	}
	delete patrons;
}

void Storage::retBooks(BookArray* bookArr){
	for (int i = 0; i < books->Count(); ++i){
		*bookArr += books->Get(i);
	}
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

			patrons->remove(patron);
			break;
	}
}

void Storage::addBook(Book* book){
	if(books->CanAdd()){
		*books += book;
		book->id = bookIDOffset + books->Count();
	}
	else{
		delete book;
	}
}

void Storage::addPatron(Patron* patron){
	patrons->push(patron);
}

void Storage::modPatron(Patron* patron){
	Patron* oldPatron = patrons->get(patron->name);

	if (oldPatron == NULL) return; // Patron not found. Needs to be added

	// Compare dependents, modify any changes
	for (int i = 0; i < patron->dependents->count(); ++i){
		if (oldPatron->dependents->get(patron->dependents->get(i)->name) == NULL){
			oldPatron->dependents->push(patron->dependents->get(i));
		}
	}

	// Remove any that's been removed
	for (int i = 0; i < oldPatron->dependents->count(); ++i){
		if (patron->dependents->get(oldPatron->dependents->get(i)->name) == NULL){
			oldPatron->dependents->remove(oldPatron->dependents->get(patron->dependents->get(i)->name));
		}
	}

	// Compare books
	for (int i = 0; i < patron->books->Count(); ++i){
		if (-1 == oldPatron->books->FindIndex(patron->books->Get(i)->id)){
			*oldPatron->books += patron->books->Get(i);
		}
	}
	// Remove any that's been removed
	for (int i = 0; i < oldPatron->books->Count(); ++i){
		if (-1 == patron->books->FindIndex(oldPatron->books->Get(i)->id)){
			oldPatron->books->Remove(oldPatron->books->FindIndex(patron->books->Get(i)->id));
		}
	}

	// Update the attributes
	oldPatron->lifetimeCO = patron->lifetimeCO;
	oldPatron->age = patron->age;
	oldPatron->parent = patron->parent;

	patrons->update(patron); // Update the patron priority
}

void Storage::init(){
	// INITIALIZE BOOKS
	Book* newBook;

	addBook(new Book("Hello", "World", 1994));
	addBook(new Book("Ender's Game", "Orson Scott Card", 1985));
	addBook(new Book("Dune", "Frank Herbert", 1965));
	addBook(new Book("Foundation", "Isaac Asimov", 1951));
	addBook(new Book("Hitch Hiker's Guide to the Galaxy", "Douglas Adams", 1979));
	addBook(new Book("1984", "George Orwell", 1949));
	addBook(new Book("Stranger in a Strange Land", "Robert A. Heinlein", 1961));
	addBook(new Book("Farenheit 451", "Ray Bradbury", 1954));
	addBook(new Book("2001: A Space Odyssey", "Arthur C. Clarke", 1968));
	addBook(new Book("I, Robot", "Isaac Asimov", 1950));
	addBook(new Book("Starship Troopers", "Robert A. Heinlein", 1959));
	addBook(new Book("Do Androids Dream of Electric Sheep?", "Philip K. Dick", 1968));
	addBook(new Book("Neuromancer", "William Gibson", 1984));
	newBook = new Book("Ringworld", "Larry Niven", 1970);
	newBook->status = Book::LOST;
	addBook(newBook);

	newBook = new Book("Rendezvous with Rama", "Arthur C. Clarke", 1973);
	newBook->status = Book::UNDER_REPAIR;
	addBook(newBook);
	addBook(new Book("Hyperion", "Dan Simmons", 1989));


	// INITIALIZE PATRONS
	Patron* parent = new Patron(new Name("Sunmock", "Yang"), 22);
	addPatron(parent);
	Patron* child = new Patron(new Name("Little", "Anne"), 12);
	addPatron(child);
	parent->AddDependent(child);

	addPatron(new Patron(new Name("Emily", "Deng"), 22));
	addPatron(new Patron(new Name("Priscilla", "Hwang"), 22));
	addPatron(new Patron(new Name("s", "s"), 45));
}