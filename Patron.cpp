#include "Patron.h"

Patron::Patron(Name* name, unsigned int age){
	this->name = name;
	this->age = age;
	lifetimeCO = 0;
	books = new BookArray();
	dependents = new DepArray();
	parent = 0;
}

Patron::Patron(string first, string last, unsigned int age){
	name = new Name(first, last);
	this->age = age;
	lifetimeCO = 0;
	books = new BookArray();
	dependents = new DepArray();
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
		books->Add(book);
		lifetimeCO++;
	}
}

bool Patron::AddDependent(Patron* patron){
	if(age < 18)
		return false;

	// Add dependent
	dependents->Add(patron);
	patron->parent = this;

	return true;
}

Patron* Patron::RemoveDependent(Patron* patron){
	return dependents->Remove(patron);
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

BookArray* Patron::GetBooks(){
	return books;
}

unsigned int Patron::GetNumBooks(){
	return books->Count();
}

int Patron::GetAllLifetimeCO(){
	int n = lifetimeCO;
	for (int i = 0; i < dependents->Count(); ++i)
	{
		n += dependents->Get(i).GetLifetimeCO();
	}
	return n;
}

int Patron::GetLifetimeCO(){
	return lifetimeCO;
}

Patron::~Patron(){
	delete name;
	delete books;
	delete dependents;
}