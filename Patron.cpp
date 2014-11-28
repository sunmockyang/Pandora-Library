#include "Patron.h"

Patron::Patron(Name* name, unsigned int age) : age(age){
	this->name = name;
	lifetimeCO = 0;
	parent = 0;
}

Patron::Patron(string first, string last, unsigned int age) : age(age){
	name = new Name(first, last);
	lifetimeCO = 0;
	parent = 0;
}

void Patron::CheckInBook(Book* book){
	books.remove(book->getId());
}

void Patron::CheckOutBook(Book* book){
	if(books.size() < MAXBOOKCHECKOUT){
		books.add(book->getId(), book);
		lifetimeCO++;
	}
}

bool Patron::MakeDependent(Patron* parent){
	if(parent->age < 18)
		return false;

	// Add dependent
	parent->dependents.add(0,this);
	this->parent = parent;

	return true;
}

Patron* Patron::RemoveDependent(Patron* patron){
	return dependents.remove(patron);
}

unsigned int Patron::GetAge(){
	return age;
}

void Patron::GetBooks(vector<Book*>& vec){
	Book* bookArr[books.size()];
	books.toArray(bookArr);

	for (int i = 0; i < books.size(); ++i)
	{
		vec.push_back(bookArr[i]);
	}
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
	return books.containsKey(book->getId());
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

	name = new Name(patron->name->First, patron->name->Last);
	age = patron->age;
	dependents = patron->dependents;
	parent = patron->parent;

	books = Map<int, Book*>(books);

	lifetimeCO = patron->lifetimeCO;
}

Patron::~Patron(){
	delete name;
}