#include "Patron.h"

Patron::Patron(Name* name, unsigned int age){
	this->name = name;
	this->age = age;
	lifetimeCO = 0;
	books = new BookArray();
	dependents = new PDeque();
	parent = 0;
}

Patron::Patron(string first, string last, unsigned int age){
	name = new Name(first, last);
	this->age = age;
	lifetimeCO = 0;
	books = new BookArray();
	dependents = new PDeque();
	parent = 0;
}

void Patron::CheckInBook(Book* book){
	int i = books->FindIndex(book);

	if(i != -1){
		books->Remove(i);
	}
}

void Patron::CheckOutBook(Book* book){
	if(books->Count() < MAXBOOKCHECKOUT){
		*books += book;
		lifetimeCO++;
	}
}

bool Patron::AddDependent(Patron* patron){
	if(age < 18)
		return false;

	// Add dependent
	dependents->push(patron);
	patron->parent = this;

	return true;
}

Patron* Patron::RemoveDependent(Patron* patron){
	return dependents->remove(patron);
}

BookArray* Patron::GetBooks(){
	return books;
}

unsigned int Patron::GetNumBooks(){
	return books->Count();
}

int Patron::GetLifetimeCO(){
	return lifetimeCO;
}

bool Patron::canCheckOut(){
	return (books->Count() + 1 >= MAXBOOKCHECKOUT) ? false : true;
}

bool Patron::canCheckIn(Book* book){
	int numBooks = books->Count();
	for (int i = 0; i < numBooks; ++i)
	{
		if(books->Get(i)->id == book->id){
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
	delete books;
	delete dependents;

	name = new Name(patron->name->First, patron->name->Last);
	age = patron->age;
	dependents = new PDeque(*patron->dependents);
	parent = patron->parent;

	books = new BookArray();
	for (int i = 0; i < patron->books->Count(); ++i) {
		*books += patron->books->Get(i);
	}

	lifetimeCO = patron->lifetimeCO;
}

Patron::~Patron(){
	delete name;
	delete books;
	delete dependents;
}