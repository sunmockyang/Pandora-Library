#include "Menu.h"

Menu::Menu(){
	// clearScreen();
}

int Menu::MainMenu(){
	clearScreen();
	println("\n\n\n\n\n                   WELCOME TO THE PANDORA LIBRARY SYSTEM \n\n\n\n");
	println("        Here are your options:\n\n");
	println("          1. Patron Menu\n\n");
	println("          2. Administrator Menu\n\n");
	println("          3. View Entire Collection\n");
	println("          0. Exit\n\n");

    return enterChoice("1", "2", "3", "0");
}

int Menu::PatronMenu(Name* name){
	clearScreen();
	cout << "\n\n\n\n\n                   PATRON MENU for " << name->First << " " << name->Last << "\n\n" << endl;
    println("        Here are your options:\n\n");
    println("          1. Check in a book\n");
    println("          2. Check out a book\n");
    println("          3. List books checked out\n\n");
    println("          0. Exit\n\n");

    return enterChoice("1", "2", "3", "0");
}

int Menu::AdminMenu(){
	clearScreen();
    println("\n\n\n\n\n                   ADMINISTRATOR MENU \n\n");
    println("        Here are your options:\n\n");
    println("          1. Add a Patron\n");
    println("          2. Delete a Patron\n");
    println("          0. Exit\n\n");

    return enterChoice("1", "2", "0");
}

void Menu::ViewCollectionMenu(BookArray* books){
	clearScreen();
	println("\n                        COLLECTION");
	println("                        ----------");

	listBooks(books);

	print("Press <ENTER> to continue...");
	scan();
}

void Menu::viewPatronBookMenu(Name* name, BookArray* books){
	clearScreen();
	print("\n                        BOOKS CHECKED OUT FOR: ");
	cout << name->First << " " << name->Last << endl;
	println("                        ----------------------");

	listBooks(books);

	print("Press <ENTER> to continue...");
	scan();
}

void Menu::printBook(Book* book){
	cout << "\t" << book->id << "\t" << book->title << string(40 - book->title.length(), ' ');
	cout << book->author << string(20 - book->author.length(), ' ');

	switch(book->status) {
		case Book::CHECKED_IN:
			println("Checked in");
			break;
		case Book::CHECKED_OUT:
			println("Checked out");
			break;
		case Book::UNDER_REPAIR:
			println("Under repair");
			break;
		case Book::LOST:
			println("Lost");
			break;
	}
}

void Menu::listBooks(BookArray* books){
	int numBooks = books->Count();
	for (int i = 0; i < numBooks; ++i){
		printBook(books->Get(i));
	}
}

void Menu::listPatrons(PatronArray* patrons){
	int numPatrons = patrons->Count();

	for (int i = 0; i < numPatrons; ++i){
		Patron* patron = patrons->Get(i);

		cout << string(20 - patron->name->First.length() - patron->name->Last.length(), ' ') << patron->name->First << " " << patron->name->Last;
		cout << ", lifetime #books: " << patron->GetLifetimeCO() << endl;

		listBooks(patron->GetBooks());

		if (patron->dependents->Count() > 0){
			cout << string(20, ' ') << " - dependents:" << endl;
			for (int j = 0; j < patron->dependents->Count(); ++j){
				Patron* dep = patron->dependents->Get(j);
				cout << string(25, ' ') << dep->name->First << " " << dep->name->Last << endl;
			}
		}
	}
}

void Menu::programEnd(BookArray* books, PatronArray* patrons){
	clearScreen();
	
	println("\n                        COLLECTION");
	println("                        ----------");
	listBooks(books);
	
	println("\n                        PATRONS");
	println("                        -------");
	listPatrons(patrons);
}

Name* Menu::inputName(){
	string First, Last;

	do{
		print("\n        Enter patron first name:  ");
		First = scan();
	} while(First.compare("") == 0);

	do{
	  	print("\n        Enter patron last name:  ");
		Last = scan();
	} while(First.compare("") == 0);

  	return new Name(First, Last);
}

Name* Menu::inputParent(){
	print("\nParent needed for new patron. Input parent name.");
	return inputName();
}

unsigned int Menu::inputAge(){
	unsigned int age = 0;

	do{
		print("\n        Enter patron age:  ");
		string val = scan();
		age = atoi(&val);
		if (age <= 0) {
			ErrorMessage("Invalid age");
		}
	} while(age <= 0);

	return age;
}

unsigned int Menu::inputBookID(){
	print("Enter book identifier:  ");
	string val = scan();
	return atoi(&val);
}

void Menu::ErrorMessage(string msg){
	cout << msg << ", press <ENTER> to continue...";
	scan();
}

int Menu::enterChoice(string opt1, string opt2, string opt3){
    string val;

    do{
    	print("        Enter one of the choices above:  ");
		val = scan();
	}while(val.compare(opt1) != 0 && val.compare(opt2) != 0 && val.compare(opt3) != 0);

	return atoi(&val);
}

int Menu::enterChoice(string opt1, string opt2, string opt3, string opt4){
    string val;

    do{
    	print("        Enter one of the choices above:  ");
		val = scan();
	}while(val.compare(opt1) != 0 && val.compare(opt2) != 0 && val.compare(opt3) != 0 && val.compare(opt4) != 0);

	return atoi(&val);
}

string Menu::scan(){
	string val;
	getline(cin, val);
	return val;
}

// Delete?
int Menu::scanInt(){
	string str = scan();
	return atoi(&str);
}

int Menu::atoi(string* str){
	int val;
	stringstream stream(*str);
	stream >> val;
	return val;
}

void Menu::print(string msg){
	cout << msg;
}

void Menu::println(string msg){
	cout << msg << endl;
}

void Menu::clearScreen(){
	// cout << string(50, '\n') << endl;
    std::system("clear");
}

Menu::~Menu(){

}