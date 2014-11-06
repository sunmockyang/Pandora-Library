#include "Library.h"

Library::Library(){
	storage = new Storage();
}

BookArray* Library::GetAllBooks(){
	BookArray* books = new BookArray();
	storage->retBooks(books);
	return books;
}

PatronArray* Library::GetAllPatrons(){
	PatronArray* patrons = new PatronArray();
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
	PatronArray* patrons = new PatronArray();
	storage->retPatrons(patrons);
	
	Patron* patron = patrons->Get(patrons->FindIndex(name));
	
	delete patrons;
	return patron;
}

Book* Library::findBook(unsigned int id){
	BookArray* books = new BookArray();
	storage->retBooks(books);

	int numBooks = books->Count();
	for (int i = 0; i < numBooks; ++i)
	{
		if(books->Get(i)->id == id){
			Book* book = books->Get(i);
			delete books;
			return book;
		}
	}

	delete books;
	return NULL;
}

Library::~Library(){
	delete storage;
}