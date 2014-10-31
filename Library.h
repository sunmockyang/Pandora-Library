#ifndef LIBRARY_H
#define LIBRARY_H

#include "Patron.h"
#include "Menu.h"

#include "BookArray.h"
#include "PatronArray.h"
#include "Storage.h"

class Library
{
public:
	Library();
	~Library();

	// Patrons
	PatronArray* GetAllPatrons();
	Patron* findPatron(Name*);
	void addPatron(Patron*);
	void updatePatron(Patron*);
	void deletePatron(Patron*);

	// Books
	BookArray* GetAllBooks();
	Book* findBook(unsigned int);
private:
	Storage* storage;
};

#endif