#ifndef STORAGE_H
#define STORAGE_H

#include "Book.h"
#include "Patron.h"
#include "AdultPatron.h"
#include "ChildPatron.h"
#include "BookArray.h"
#include "PDeque.h"

class Storage
{
public:
	enum UpdateType	{ ADD, MODIFY, DELETE };

	Storage();
	~Storage();
	
	void retBooks(BookArray*);
	void retPatrons(PDeque*);
	void updPatrons(UpdateType, Patron*);

private:
	BookArray* books;
	PDeque* patrons;

	unsigned int bookIDOffset;
	void addBook(Book*);

	void addPatron(Patron*);
	void modPatron(Patron*);

	Patron* findPatron(Name*);
	void init();
};

#endif