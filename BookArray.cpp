#include "BookArray.h"

BookArray::BookArray(){
	count = 0;
}

BookArray::~BookArray(){
}

Book* BookArray::Get(int i){
	if (i < count && i >= 0){ // Make sure index is in bounds
		return arr[i];
	}

	return NULL; // return NULL
}

void BookArray::Set(int i, Book* book){
	if(i < count && i >= 0){
		arr[i] = book;
	}
}

Book* BookArray::Add(int i, Book* book){
	if(count < MAXARRNUM && i <= count && i >=0){
		for (int j=count; j > i; --j){ // Copy the array over 1
			arr[j] = arr[j-1];
		}

		arr[i] = book; // Set the value to the new spot

		count++;

		return book;
	}

	return NULL;
}

Book* BookArray::Add(Book* book){
	return Add(count, book);
}

Book* BookArray::Remove(int i){
	if(count > 0 && i < count && i >= 0){
		Book* book = arr[i]; // Get the pointer to the to-be-delete element
		for (int j = i; j <= count-1; ++j){ // Shift back the array
			arr[j] = arr[j+1];
		}
		count--;
		return book;
	}
	return 0;
}

Book* BookArray::Remove(Book* book){
	Remove(FindIndex(book));
}

Book* BookArray::Pop(){
	return Remove(count-1); // Remove from end
}

bool BookArray::Contains(Book* book){
	for (int i = 0; i < count; ++i){
		if (arr[i] == book){
			return true;
		}
	}
	return false;
}

bool BookArray::CanAdd(){ return (count < MAXARRNUM); }

int BookArray::Count(){	return count; }

int BookArray::FindIndex(Book* book){
	for (int i = 0; i < count; ++i){
		if (arr[i] == book){
			return i;
		}
	}
	return -1;
}

// Find index by bookID
int BookArray::FindIndex(unsigned int id){
	int numBooks = Count();
	for (int i = 0; i < numBooks; ++i){
		if(arr[i]->getId() == id){
			return i;
		}
	}
	return -1;
}

BookArray& BookArray::operator+=(Book* book){
	Add(book);
}