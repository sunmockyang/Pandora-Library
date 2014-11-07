#include "PLSControl.h"	

PLSControl::PLSControl(){
	library = new Library();
	menu = new Menu();
}

void PLSControl::Start(){
	bool running = true;
	BookArray* books;

	// Main control loop
	while(running){
		int choice = menu->MainMenu();

		switch(choice){
			case 1:
				// Patron menu
				PatronMode();
				break;
			case 2:
				// Admin menu
				AdminMode();
				break;
			case 3:
				// View Collection menu
				books = library->GetAllBooks();
				menu->ViewCollectionMenu(books);
				delete books;
				break;

			default:
				running = false;
				break;
		}
	}

	// End program dump
	PatronArray* patrons = library->GetAllPatrons();
	books = library->GetAllBooks();
	menu->programEnd(books, patrons);
	delete patrons;
}

void PLSControl::PatronMode(){
	// Sign in
	Name* name = menu->inputName();
	Patron* user = library->findPatron(name);
	delete name;

	if(user == NULL){
		menu->ErrorMessage("Could not find patron");
		return;
	}

	// Patron mode loop
	bool patronModeRunning = true;
	while(patronModeRunning){
		int choice = menu->PatronMenu(user->name);

		switch(choice){
			case 1: // Check in a book
				CheckInBook(user);
				break;

			case 2: // Check out a book
				CheckOutBook(user);
				break;

			case 3: // List books checked out
				menu->viewPatronBookMenu(user->name, user->GetBooks());
				break;

			case 0:
				patronModeRunning = false;
				break;
		}
	}
}

void PLSControl::CheckInBook(Patron* user){
	unsigned int bookID = menu->inputBookID();
	Book* book = library->findBook(bookID);

	if(book == NULL){
		menu->ErrorMessage("Could not find book");
		menu->ErrorMessage("Could not check in book");
		return;
	}

	if(user->canCheckIn(book)){ // Check to see if the book can be checked in
		user->CheckInBook(book);
		book->checkIn();
		library->updatePatron(user);
	} else {
		menu->ErrorMessage("Book not checked out to this patron");
		menu->ErrorMessage("Could not check in book");
		return;
	}
}

void PLSControl::CheckOutBook(Patron* user){
	if(!user->canCheckOut()){ // Check if patron can check out any more books
		menu->ErrorMessage("Patron cannot check out any more books");
		menu->ErrorMessage("Could not check out book");
		return;
	}

	unsigned int bookID = menu->inputBookID();
	Book* book = library->findBook(bookID);

	if(book == NULL){ // Check if the book exists
		menu->ErrorMessage("Could not find book");
		menu->ErrorMessage("Could not check out book");
		return;
	}

	if(book->canCheckOut()){ // Check if the book can be checked out
		user->CheckOutBook(book);
		book->checkOut();
		library->updatePatron(user);
	} else {
		menu->ErrorMessage("Could not check out book");
		return;
	}
}

void PLSControl::AdminMode(){
	bool adminModeRunning = true;

	while(adminModeRunning){
		int choice = menu->AdminMenu();

		switch(choice){
			case 1:
				// Add a patron
				AddPatron();
				break;
			case 2:
				// Delete a patron
				DeletePatron();
				break;
			case 0:
				// exit
				adminModeRunning = false;
				break;
		}
	}
}

void PLSControl::AddPatron(){
	// library->addPatron(menu->inputName(), menu->inputAge());
	Name* name = menu->inputName();
	Patron* patron = new Patron(name, menu->inputAge());
	PatronArray* patrons = library->GetAllPatrons();
	
	if(!patrons->CanAdd()){ // Check to see if there's space
		menu->ErrorMessage("Could not add patron (Limit reached)");
		delete patrons;
		delete patron;
		delete name;
		return;
	}
	
	delete patrons;

	library->addPatron(patron);

	// Check to see if the patron is of age.
	if (patron->age < 18) {
		Patron* parent = NULL;
		bool canParent = false;

		// Get a valid parent
		do{
			Name* parentName = menu->inputParent();
			parent = library->findPatron(parentName);

			delete parentName;
			
			if(parent == NULL){
				menu->ErrorMessage("Could not find parent patron");
				continue;
			}

			canParent = parent->AddDependent(patron);

			if (canParent == false){
				menu->ErrorMessage("Parent not old enough");
				continue;
			}
			else{
				library->updatePatron(parent);
			}
		} while(parent == NULL || canParent == false);

	}
}

void PLSControl::DeletePatron(){
	Name* name = menu->inputName();

	Patron* patron = library->findPatron(name);
	delete name;

	if(patron == NULL){
		menu->ErrorMessage("Could not find patron");
	}
	else if(patron->GetNumBooks() > 0){
		menu->ErrorMessage("Patron has books checked out");
	}
	else if(patron->dependents->count() > 0){
		menu->ErrorMessage("Patron has dependents. Cannot delete");
	}
	else{
		library->deletePatron(patron);
	}
}

PLSControl::~PLSControl(){
	delete library;
	delete menu;
}