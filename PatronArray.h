#ifndef PATRONARRAY_H
#define PATRONARRAY_H

#include "Name.h"
#include "Patron.h"
#define MAXARRNUM 100

class PatronArray{
	public:
		PatronArray();
		~PatronArray();

		Patron* Get(int);
		void Set(int, Patron*);

		Patron* Add(int, Patron*);
		Patron* Add(Patron*);

		Patron* Remove(int);
		Patron* Remove(Patron*);
		Patron* Pop();	 // Remove one from end and return it

		bool Contains(Patron*);
		bool CanAdd();

		int Count();
		int FindIndex(Patron*);
		int FindIndex(Name*);

	private:
		int count;
		Patron* arr[MAXARRNUM];
};

#endif