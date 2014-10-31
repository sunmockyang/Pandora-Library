#include "PDeque.h"

PDeque::PDeque(){
	head = NULL;
}

void PDeque::push(Patron* patron){
	PDequeNode* node = new PDequeNode();
	node->next = head;
	node->data = patron;
	head = node;
}

PDeque::~PDeque(){
	
}