#ifndef STORAGE_H
#define STORAGE_H

#include "Book.h"
#include "Patron.h"
#include "BookArray.h"
#include "DepArray.h"
#include "PatronArray.h"

class Storage
{
public:
	enum UpdateType	{ ADD, MODIFY, DELETE };

	Storage();
	~Storage();
	
	void retBooks(BookArray*);
	void retPatrons(PatronArray*);
	void updPatrons(UpdateType, Patron*);

private:
	BookArray* books;
	PatronArray* patrons;

	unsigned int bookIDOffset;
	void addBook(Book*);

	void addPatron(Patron*);
	void modPatron(Patron*);

	Patron* findPatron(Name*);
	void init();
};

#endif