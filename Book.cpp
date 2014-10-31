 #include "Book.h"

Book::Book(string bookTitle, string bookAuthor, int bookYear) :
	title(bookTitle), author(bookAuthor), year(bookYear){
		status = CHECKED_IN;
}

bool Book::checkIn(){
	if (status == CHECKED_OUT){
		status = CHECKED_IN;
		return true;
	}
	return false;
}

bool Book::checkOut(){
	if (status == CHECKED_IN){
		status = CHECKED_OUT;
		return true;
	}
	return false;
}

bool Book::canCheckOut(){
	return (status == CHECKED_IN) ? true : false;
}

Book::~Book(){
	
}