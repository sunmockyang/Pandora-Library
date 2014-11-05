#include "PDeque.h"

PDeque::PDeque(){
	head = NULL;
}

Patron* PDeque::front(){
	return head;
}

Patron* PDeque::back(){
	PDequeNode* cur = head;

	if(cur == NULL) return NULL;

	while(cur->next != NULL){
		cur = cur->next;
	}

	return cur;
}

void PDeque::push(Patron* patron){
	PDequeNode* node = new PDequeNode();
	node->next = head;
	node->data = patron;
	head = node;
}

void PDeque::popFront(){
	PDequeNode* d = head;
	head = head->next;
	delete d;
}

// Double check this
void PDeque::popBack(){
	PDequeNode* cur = head;
	PDequeNode* prev = NULL;

	if(cur == NULL) return;

	while(cur->next != NULL){
		prev = cur;
		cur = cur->next;
	}

	delete cur;

	if(prev != NULL)
		prev->next = NULL;
}

PDeque::~PDeque(){
	
}

PDequeNode::~PDequeNode(){
	delete data;
}