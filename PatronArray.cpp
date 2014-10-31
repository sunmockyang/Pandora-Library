#include "PatronArray.h"

PatronArray::PatronArray(){
	count = 0;
}

PatronArray::~PatronArray(){
}

Patron* PatronArray::Get(int i){
	if (i < count && i >= 0){ // Make sure index is in bounds
		return arr[i];
	}

	return NULL; // return NULL
}

void PatronArray::Set(int i, Patron* patron){
	if(i < count && i >= 0){
		arr[i] = patron;
	}

	return;
}

Patron* PatronArray::Add(int i, Patron* patron){
	if(count < MAXARRNUM && i <= count && i >=0){
		for (int j=count; j > i; --j){ // Copy the array over 1
			arr[j] = arr[j-1];
		}

		arr[i] = patron; // Set the value to the new spot

		count++;

		return patron;
	}

	return NULL;
}

Patron* PatronArray::Add(Patron* patron){
	return Add(count, patron);
}

Patron* PatronArray::Remove(int i){
	if(count > 0 && i < count && i >= 0){
		Patron* patron = arr[i]; // Get the pointer to the to-be-delete element
		for (int j = i; j <= count-1; ++j){ // Shift back the array
			arr[j] = arr[j+1];
		}
		count--;
		return patron;
	}
	return 0;
}

Patron* PatronArray::Remove(Patron* patron){
	Remove(FindIndex(patron));
}

Patron* PatronArray::Pop(){
	return Remove(count-1);
}

bool PatronArray::Contains(Patron* patron){
	for (int i = 0; i < count; ++i){
		if (arr[i] == patron){
			return true;
		}
	}
	return false;
}

bool PatronArray::CanAdd(){ return (count < MAXARRNUM); }

int PatronArray::Count(){ return count; }

int PatronArray::FindIndex(Patron* patron){
	for (int i = 0; i < count; ++i){
		if (arr[i] == patron){
			return i;
		}
	}
	return -1;
}

// Find index by Name
int PatronArray::FindIndex(Name* name){
	for (int i = 0; i < count; ++i){
		if (arr[i]->isName(name)){
			return i;
		}
	}
	return -1;
}