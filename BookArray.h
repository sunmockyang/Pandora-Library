#ifndef BOOKARRAY_H
#define BOOKARRAY_H

#include "Book.h"
#define MAXARRNUM 100

class BookArray{
	friend class Storage;
	public:
		BookArray();
		~BookArray();

		Book* Get(int);
		void Set(int, Book*);

		Book* Add(int, Book*);
		Book* Add(Book*);

		Book* Remove(int);
		Book* Remove(Book*);
		Book* Pop();	 // Remove one from end and return it

		bool Contains(Book*);
		bool CanAdd();

		int Count();
		int FindIndex(Book*);
		int FindIndex(unsigned int);

	private:
		int count;
		Book* arr[MAXARRNUM];
};

#endif