/* $Id: LinkedList.cc,v 1.1 1998/02/12 05:31:41 sbooth Exp $ */

#include "LinkedList.hh"

// ============================================================
// Class MStreamable
// ============================================================
ostream& 
operator<<(ostream& out, const MStreamable& obj) {
	obj.render(out); 
	return out; 
}

// ============================================================
// Class Node
// ============================================================
Node::Node()
	: fNext(NULL)
{}

Node::~Node()
{}

// ============================================================
// Class LinkedList
// ============================================================
LinkedList::LinkedList()
	: fHead(NULL), fTail(NULL)
{}

LinkedList::LinkedList(const Node *head) {
	fHead = fTail = (Node*) head;
}

LinkedList::~LinkedList() {
	deleteAll();
}

LinkedList& 
LinkedList::operator<<(const Node *node) {
	return add(node);
}

LinkedList& 
LinkedList::add(const Node *node) {
	if(getHead() == NULL)
		fHead = fTail = (Node*) node;
	else {
		Node *oldTail = (Node*) getTail();
		oldTail->fNext = (Node*) node;
		fTail = (Node*) node;
	}
	return *this;
}

LinkedList& 
LinkedList::deleteAll() {
	Node *current = (Node*) getHead();

	while(current != NULL) {
		Node *next = (Node*) current->getNext();
		delete current;
		current = next;
	}
	fHead = fTail = NULL;
	return *this;
}
