#ifndef STORAGE_H
#define STORAGE_H

#include <vector>

#include "Book.h"
#include "Patron.h"
#include "AdultPatron.h"
#include "ChildPatron.h"
#include "PDeque.h"
#include "Server.h"

class Storage
{
public:
	enum UpdateType	{ ADD, MODIFY, DELETE };

	Storage();
	~Storage();
	
	void retBooks(vector<Book*>*);
	void retPatrons(PDeque*);
	void updPatrons(UpdateType, Patron*);

private:
	Server* server;
	PDeque* patrons;

	void addPatron(Patron*);
	void modPatron(Patron*);

	Patron* findPatron(Name*);
	void init();
};

#endif