#ifndef PDEQUE_H
#define PDEQUE_H

#define DEBUG true

#if DEBUG
#include <iostream>
#endif

#include "Patron.h"

class PDequeNode;

class PDeque
{

private:

public:
	PDeque();

	int count();
	bool contains(Patron*);
	// bool canAdd();

	Patron* front();
	Patron* back();
	Patron* get(int);
	Patron* get(Name*);
	Patron* set(Patron*);

	void push(Patron*);
	void popFront();
	void popBack();

	void remove(int);
	void remove(Patron*);

	void update(Patron*);
	void print();

	~PDeque();

private:
	int n;
	PDequeNode* head;

	// Helpers
	PDequeNode* findNode(int);
	PDequeNode* findNode(Name*);
	PDequeNode* findNode(Patron*);
	PDequeNode* findPrevNode(Patron*);
	void		insertNode(PDequeNode*);
};

class PDequeNode{
	friend class PDeque;

	public:
		~PDequeNode();

	private:
		Patron* data;
		PDequeNode* next;
};

#endif