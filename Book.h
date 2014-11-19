#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "types.h"
using namespace std;

class Book{
	public:
		Book(string="", string="", int=0, BookStatusType=CHECKED_IN);
		~Book();

		void setStatus(BookStatusType);
		BookStatusType getStatus();

		int	   getId();
		string getTitle();
		string getAuthor();

		bool checkIn();
		bool checkOut();
		bool canCheckOut();
		
	private:
		static int nextId;
		unsigned int id;
		const string title;
		const string author;
		const int year;
		BookStatusType status;
};

#endif