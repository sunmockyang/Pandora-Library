#ifndef PATRON_H
#define PATRON_H

#include <string>
#include "Name.h"
#include "Book.h"
#include "BookArray.h"
#include "PDeque.h"

#define MAXBOOKCHECKOUT 20

using namespace std;
class PDeque;
class Patron
{
	friend class Storage;
public:
	Patron(Name*, unsigned int);
	Patron(string, string, unsigned int);
	~Patron();

	void CheckOutBook(Book*);
	void CheckInBook(Book*);
	bool AddDependent(Patron*);
	void RemoveDependent(Patron*);

	BookArray* 			GetBooks();
	unsigned int 	GetNumBooks();
	int				GetAllLifetimeCO();
	int				GetLifetimeCO();
	bool 			canCheckOut();
	bool			canCheckIn(Book*);
	bool			isName(Name*);
	int			compare(Patron*);
	
	Name* name;
	unsigned int age;
	PDeque* dependents;
	Patron* parent;

private:
	BookArray* books;
	int lifetimeCO;
};

#endif