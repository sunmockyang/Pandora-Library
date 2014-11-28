#ifndef PATRON_H
#define PATRON_H

#include <string>
#include <vector>
#include "Name.h"
#include "Book.h"
#include "PDeque.h"
#include "Map.h"

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
	PDeque* dependents;
	Patron* parent;

	void CheckOutBook(Book*);
	void CheckInBook(Book*);
	virtual bool MakeDependent(Patron*);
	Patron* RemoveDependent(Patron*);

	unsigned int    GetAge();
	void            GetBooks(vector<Book*>&);
	unsigned int    GetNumBooks();
	virtual int     GetLifetimeCO();
	bool            canCheckOut();
	bool            canCheckIn(Book*);
	bool            isName(Name*);
	int             compare(Patron*);

	Patron& operator=(Patron*);

private:
	unsigned int age;
	Map<int, Book*> books;

protected:
	int lifetimeCO;
};

#endif