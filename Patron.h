#ifndef PATRON_H
#define PATRON_H

#include <string>
#include "Name.h"
#include "Book.h"
#include "BookArray.h"
#include "PDeque.h"

#define MAXBOOKCHECKOUT 20

class PDeque;
class Patron
{
	friend class Storage;
public:
	Patron(Name*, unsigned int);
	Patron(string, string, unsigned int);
	~Patron();

	Name* name;
	unsigned int age;
	PDeque* dependents;
	Patron* parent;

	void CheckOutBook(Book*);
	void CheckInBook(Book*);
	bool AddDependent(Patron*);
	Patron* RemoveDependent(Patron*);

	BookArray* 			GetBooks();
	unsigned int 	GetNumBooks();
	int				GetAllLifetimeCO();
	int				GetLifetimeCO();
	bool 			canCheckOut();
	bool			canCheckIn(Book*);
	bool			isName(Name*);
	int			compare(Patron*);

	Patron& operator=(Patron*);

private:
	BookArray* books;
	int lifetimeCO;
};

#endif