#include "Library.h"

Library::Library(){
	storage = new Storage();
}

vector<Book*>* Library::GetAllBooks(){
	vector<Book*>* books = new vector<Book*>();
	storage->retBooks(books);
	return books;
}

PDeque* Library::GetAllPatrons(){
	PDeque* patrons = new PDeque();
	storage->retPatrons(patrons);
	return patrons;
}

void Library::addPatron(Patron* patron){
	storage->updPatrons(Storage::ADD, patron);
}

void Library::updatePatron(Patron* patron){
	storage->updPatrons(Storage::MODIFY, patron);
}

void Library::deletePatron(Patron* patron){
	storage->updPatrons(Storage::DELETE, patron);
}

Patron* Library::findPatron(Name* name){
	PDeque* patrons = GetAllPatrons();
	Patron* patron = patrons->get(name);
	
	delete patrons;
	return patron;
}

Book* Library::findBook(unsigned int id){
	vector<Book*> books;
	storage->retBooks(&books);

	int numBooks = books.size();
	for (int i = 0; i < numBooks; ++i)
	{
		if(books[i]->getId() == id){
			Book* book = books[i];
			return book;
		}
	}

	return NULL;
}

Library::~Library(){
	delete storage;
}