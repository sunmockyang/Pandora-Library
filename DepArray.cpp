#include "DepArray.h"

DepArray::DepArray(){
	count = 0;
}

DepArray::~DepArray(){
}

Patron* DepArray::Get(int i){
	if (i < count && i >= 0){ // Make sure index is in bounds
		return arr[i];
	}

	return NULL; // return NULL
}

void DepArray::Set(int i, Patron* patron){
	if(i < count && i >= 0){
		arr[i] = patron;
	}
}

Patron* DepArray::Add(int i, Patron* patron){
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

Patron* DepArray::Add(Patron* patron){
	return Add(count, patron);
}

Patron* DepArray::Remove(int i){
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

Patron* DepArray::Remove(Patron* patron){
	Remove(FindIndex(patron));
}

Patron* DepArray::Pop(){
	return Remove(count-1); // Remove from end
}

bool DepArray::Contains(Patron* patron){
	for (int i = 0; i < count; ++i){
		if (arr[i] == patron){
			return true;
		}
	}
	return false;
}

bool DepArray::CanAdd(){ return (count < MAXARRNUM); }

int DepArray::Count(){ return count; }

int DepArray::FindIndex(Patron* patron){
	for (int i = 0; i < count; ++i){
		if (arr[i] == patron){
			return i;
		}
	}
	return -1;
}

// Find index by Name
int DepArray::FindIndex(Name* name){
	for (int i = 0; i < count; ++i){
		if (arr[i]->isName(name)){
			return i;
		}
	}
	return -1;
}