 #include "Book.h"

int Book::nextId = 1001;

Book::Book(string bookTitle, string bookAuthor, int bookYear, BookStatusType bookStatus) :
	title(bookTitle), author(bookAuthor), year(bookYear){
		id     = nextId++;
		status = bookStatus;
}

void Book::setStatus(BookStatusType s)
{
	status = s;
}

int            Book::getId()     { return id; }
string         Book::getTitle()  { return title; }
string         Book::getAuthor() { return author; }
BookStatusType Book::getStatus() { return status; }

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