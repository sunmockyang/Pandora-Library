#include "Patron.h"

Patron::Patron(Name* name, unsigned int age) : age(age){
	this->name = name;
	lifetimeCO = 0;
	// books = new vector<Book*>();
	dependents = new PDeque();
	parent = 0;
}

Patron::Patron(string first, string last, unsigned int age) : age(age){
	name = new Name(first, last);
	lifetimeCO = 0;
	// books = new vector<Book*>();
	dependents = new PDeque();
	parent = 0;
}

void Patron::CheckInBook(Book* book){
	int i = 0;

	for (int i = 0; i < books.size(); ++i){
		if (books[i] == book){
			break;
		}
	}

	if(i < books.size()){
		books.erase(books.begin() + i);
	}
}

void Patron::CheckOutBook(Book* book){
	if(books.size() < MAXBOOKCHECKOUT){
		books.push_back(book);
		lifetimeCO++;
	}
}

bool Patron::MakeDependent(Patron* parent){
	if(parent->age < 18)
		return false;

	// Add dependent
	parent->dependents->push(this);
	this->parent = parent;

	return true;
}

Patron* Patron::RemoveDependent(Patron* patron){
	return dependents->remove(patron);
}

unsigned int Patron::GetAge(){
	return age;
}

vector<Book*>* Patron::GetBooks(){
	return &books;
}

unsigned int Patron::GetNumBooks(){
	return books.size();
}

int Patron::GetLifetimeCO(){
	return lifetimeCO;
}

bool Patron::canCheckOut(){
	return (books.size() + 1 >= MAXBOOKCHECKOUT) ? false : true;
}

bool Patron::canCheckIn(Book* book){
	int numBooks = books.size();
	for (int i = 0; i < numBooks; ++i)
	{
		if(books[i]->getId() == book->getId()){
			return true;
		}
	}
	return false;
}

bool Patron::isName(Name* checkName){
	return name->First.compare(checkName->First) == 0 && name->Last.compare(checkName->Last) == 0;
}

// < 0: this < arg
//   0: this == arg
// > 0: this > arg
int Patron::compare(Patron* patron){
	// TODO: use age for now, adjust to book num
	return GetLifetimeCO() - patron->GetLifetimeCO();
}

Patron& Patron::operator=(Patron* patron){
	delete name;
	// delete books;
	delete dependents;

	name = new Name(patron->name->First, patron->name->Last);
	age = patron->age;
	dependents = new PDeque(*patron->dependents);
	parent = patron->parent;

	books.clear();
	for (int i = 0; i < patron->books.size(); ++i) {
		books.push_back(patron->books[i]);
	}

	lifetimeCO = patron->lifetimeCO;
}

Patron::~Patron(){
	delete name;
	// delete books;
	delete dependents;
}