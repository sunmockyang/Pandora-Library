#include "PDeque.h"

PDeque::PDeque(){
	head = NULL;
	n = 0;
}

PDeque::PDeque(PDeque& deque){
	head = deque.head;
	n = deque.n;
}

// GETTERS

int PDeque::count(){
	return n;
}

bool PDeque::contains(Patron* patron){
	return (findNode(patron) != NULL);
}

Patron* PDeque::front(){
	return (head != NULL) ? head->data : NULL;
}

Patron* PDeque::back(){
	PDequeNode* cur = head;

	if(cur == NULL) return NULL;

	while(cur->next != NULL){
		cur = cur->next;
	}

	return cur->data;
}

Patron* PDeque::get(int index){
	PDequeNode* node = findNode(index);
	return (node != NULL) ? node->data : NULL;
}

Patron* PDeque::get(Name* name){
	PDequeNode* node = findNode(name);
	return (node != NULL) ? node->data : NULL;
}

// MODIFIERS

void PDeque::push(Patron* patron){
	PDequeNode* node = new PDequeNode();
	node->data = patron;
	insertNode(node);

	n++;
}

void PDeque::popFront(){
	remove(0);
}

void PDeque::popBack(){
	remove(n - 1);
}

Patron* PDeque::remove(int index){
	PDequeNode* node = findNode(index);
	Patron* p = NULL;

	if(node == NULL) return p;
	if(index == 0){ // If its the head you're removing
		head = node->next;
	}
	else{
		PDequeNode* prev = findPrevNode(node->data);
		prev->next = node->next;
	}
	p = node->data;
	delete node;
	n--;
	return p;
}

Patron* PDeque::remove(Patron* patron){
	PDequeNode* node = findNode(patron);
	Patron* p = NULL;
	
	if(node == NULL) return p;

	if(head->data == patron){
		head = node->next;
	}
	else{
		PDequeNode* prev = findPrevNode(node->data);
		prev->next = node->next;
	}
	
	p = node->data;
	delete node;
	n--;	
	return p;
}

void PDeque::clear(){
	while(n > 0)
		popFront();
}

void PDeque::update(Patron* patron){
	if(n == 0) return; // Lets not even bother.

	// Check to see if its in the correct position.
	PDequeNode* prev = findPrevNode(patron);
	PDequeNode* curr = ((prev == NULL) ? head : prev->next); // set to head if prev not found
	PDequeNode* next = curr->next;

	// If the patron is not found, exit.
	if(curr->data != patron) return;

	// Item is at the start of the list
	if(prev == NULL && (curr->data->compare(next->data) < 0)){
		head = curr->next;
		insertNode(curr);
	}
	// Item is in the middle of the deque
	else if((prev != NULL && next != NULL) && (prev->data->compare(curr->data) < 0 || curr->data->compare(next->data) < 0)){
		prev->next = curr->next;
		insertNode(curr);
	}
	// Item is at the end of the deque
	else if((next == NULL) && (prev->data->compare(curr->data) < 0)){
		prev->next = curr->next;
		insertNode(curr);
	}
}

PDeque* PDeque::copy(){
	PDeque* deque = new PDeque();
	PDequeNode* cur = head;

	while(cur != NULL){
		deque->push(cur->data); // This has functionality to add stuff into the correct order
		cur = cur->next;
	}

	return deque;
}

// Helpers

PDequeNode* PDeque::findNode(int index){
	if(n == 0 || index >= n || index < 0) return NULL;

	PDequeNode* cur = head;
	for (int i = 0; i < index; ++i){
		cur = cur->next;
	}

	return cur;
}

PDequeNode* PDeque::findNode(Name* name){
	PDequeNode* cur = head;

	if(cur == NULL) return NULL;

	while(cur != NULL){
		if(cur->data->name->compare(name))
			return cur;

		cur = cur->next;
	}

	return NULL;
}

PDequeNode* PDeque::findNode(Patron* patron){
	PDequeNode* cur = head;
	if(cur == NULL) return NULL;

	while(cur != NULL){
		if(cur->data == patron)
			return cur;

		cur = cur->next;
	}
	return NULL;
}

PDequeNode* PDeque::findPrevNode(Patron* patron){
	PDequeNode* cur = head;
	if(cur == NULL) return NULL;


	while(cur != NULL && cur->next != NULL){
		if(cur->next->data == patron){
			return cur;
		}

		cur = cur->next;
	}
	return NULL;
}

void PDeque::insertNode(PDequeNode* node){
	if(head == NULL){
		head = node;
		head->next = NULL;
		return;
	}

	PDequeNode* cur = head;
	PDequeNode* prev = NULL;

	while(cur != NULL){
		if(node->data->compare(cur->data) >= 0){
			node->next = cur;

			if(prev != NULL)
				prev->next = node;
			else
				head = node;

			return;
		}

		prev = cur;
		cur = cur->next;
	}

	// Add at the end
	prev->next = node;
	node->next = NULL;
}

PDeque::~PDeque(){
	clear();
}


PDequeNode::PDequeNode(){
	data = NULL;
	next = NULL;
}
PDequeNode::~PDequeNode(){
	// delete data;
}