#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>

#include "Patron.h"
#include "Menu.h"
#include "PDeque.h"
#include "Storage.h"

class Library
{
public:
	Library();
	~Library();

	// Patrons
	PDeque* GetAllPatrons();
	PDeque* GetAllPatronsCopy();
	Patron* findPatron(Name*);
	void addPatron(Patron*);
	void updatePatron(Patron*);
	void deletePatron(Patron*);

	// Books
	vector<Book*>* GetAllBooks();
	Book* findBook(unsigned int);
private:
	Storage* storage;
};

#endif