/* $Id: LinkedList.hh,v 1.1 1998/03/30 00:54:31 sbooth Exp $ */

#ifndef __LINKED_LIST__
#define __LINKED_LIST__ 1

#ifndef __EXCEPTION__
#include "Exception.hh"
#endif

#ifndef __MSTREAMABLE__
#include "MStreamable.hh"
#endif

#ifndef __NODE__
#include "Node.hh"
#endif

#include <iostream.h>
#include <stdlib.h>

// ============================================================
// Class LinkedList
// ============================================================
template <class T>
class LinkedList : public MStreamable {
public:
  
  // ============================================================
  // Class Iterator
  // ============================================================
  class ConstIterator;
  class Iterator : public MStreamable
  {
    
    friend class LinkedList<T>;
    friend class ConstIterator;
    
  public:
    Iterator()
      : fNode(NULL), fValid(false) {}
    
    Iterator(const Iterator& iter)
      : fNode(iter.fNode), fValid(iter.fValid) {}
    
    virtual ~Iterator()
    {}
    
    virtual void render(ostream& out) const
    { out << *this; }
    
    bool isValid() const 
    { return fValid; }
    
    bool operator== (const Iterator& iter) const 
    { return getNode() == iter.getNode(); }
    
    bool operator== (const ConstIterator& iter) const 
    { return getNode() == iter.getNode(); }
    
    bool operator!= (const Iterator& iter) const
    { return ! (*this == iter); }
    
    bool operator!= (const ConstIterator& iter) const
    { return ! (*this == iter); }
    
    Iterator& operator= (const Iterator& rhs)
    { if(this != &rhs) { fNode = rhs.fNode; fValid = rhs.fValid; } return *this; }
    
    T& operator* () const
    { return fNode->getDataReference(); }
    
    Iterator& operator++ ()
    { fNode = (Node<T>*) fNode->getNext(); checkValid(); return *this; }
    
    Iterator operator++ (int)
    { Iterator temp = *this; ++*this; return temp; }
    
    Iterator& operator-- ()
    { fNode = (Node<T>*) fNode->getPrevious(); checkValid(); return *this; }
    
    Iterator operator-- (int)
    { Iterator temp = *this; --*this; return temp; }
    
    Iterator operator+ (int n) const
    { Iterator temp = *this; temp += n; return temp; }
    
    Iterator operator- (int n) const
    { Iterator temp = *this; temp -= n; return temp; }
    
    Iterator operator+= (int n)
    { if(n >= 0) while(n--) ++*this; else while(n++) --*this; return *this; }
    
    Iterator operator-= (int n)
    { if(n >= 0) while(n--) --*this; else while(n++) ++*this; return *this; }
    
  protected:
    Iterator(const Node<T> *node)
      : fNode(NULL), fValid(true) 
    { if(node != NULL) fNode = (Node<T>*) node; else fValid = false; }
    
    void checkValid()
    { if(fNode == NULL) fValid = false; }
    
    inline const Node<T>* getNode() const 
    { return fNode; }
    
    inline void setNode(const Node<T> *node)
    { fNode = (Node<T>*) node; }
    
  private:
    Node<T> *fNode;
    bool fValid;
  };
  
  // ============================================================
  // Class ConstIterator
  // ============================================================
  class ConstIterator : public MStreamable
  {
    
    friend class LinkedList<T>;
    friend class Iterator;
    
  public:
    ConstIterator()
      : fValid(false) {}
    
    ConstIterator(const ConstIterator& iter)
      : fNode(iter.fNode), fValid(iter.fValid) {}
    
    virtual ~ConstIterator()
    {}
    
    virtual void render(ostream& out) const
    { out << *this; }
    
    bool isValid() const 
    { return fValid; }
    
    bool operator== (const ConstIterator& iter) const 
    { return getNode() == iter.getNode(); }
    
    bool operator!= (const ConstIterator& iter) const
    { return ! (*this == iter); }
    
    ConstIterator& operator= (const ConstIterator& rhs)
    { if(this != &rhs) { fNode = rhs.fNode; fValid = rhs.fValid; } return *this; }
    
    const T& operator* () const
    { return **fNode; }
    
    ConstIterator& operator++ ()
    { fNode = (Node<T>*) fNode->getNext(); checkValid(); return *this; }
    
    ConstIterator operator++ (int)
    { ConstIterator temp = *this; ++*this; return temp; }
    
    ConstIterator& operator-- ()
    { fNode = (Node<T>*) fNode->getPrevious(); checkValid(); return *this; }
    
    ConstIterator operator-- (int)
    { ConstIterator temp = *this; --*this; return temp; }
    
    ConstIterator operator+ (int n) const
    { ConstIterator temp = *this; temp += n; return temp; }
    
    ConstIterator operator- (int n) const
    { ConstIterator temp = *this; temp -= n; return temp; }
    
    ConstIterator operator+= (int n)
    { if(n >= 0) while(n--) ++*this; else while(n++) --*this; return *this; }
    
    ConstIterator operator-= (int n)
    { if(n >= 0) while(n--) --*this; else while(n++) ++*this; return *this; }
    
  protected:
    ConstIterator(const Node<T> *node)
      : fNode(NULL), fValid(true) 
    { if(node != NULL) fNode = (Node<T>*) node; else fValid = false; }
    
    void checkValid()
    { if(fNode == NULL) fValid = false; }
    
    inline const Node<T>* getNode() const 
    { return fNode; }
    
    inline void setNode(const Node<T> *node)
    { fNode = (Node<T>*) node; }
    
  private:
    Node<T> *fNode;
    bool fValid;
  };
  
  // ============================================================
  // Class ReverseIterator
  // ============================================================
  class ReverseIterator : public Iterator
  {
    
    friend class LinkedList<T>;
    
  public:
    ReverseIterator()
      : Iterator() {}
    
    ReverseIterator(const Iterator& iter)
      : Iterator(iter) {}
    
    virtual ~ReverseIterator()
    {}
    
    ReverseIterator& operator++ ()
    { setNode(getNode()->getPrevious()); checkValid(); return *this; }
    
    ReverseIterator operator++ (int)
    { ReverseIterator temp = *this; ++*this; return temp; }
    
    ReverseIterator& operator-- ()
    { setNode(getNode()->getNext()); checkValid(); return *this; }
    
    ReverseIterator operator-- (int)
    { ReverseIterator temp = *this; --*this; return temp; }
    
    ReverseIterator operator+ (int n) const
    { ReverseIterator temp = *this; temp += n; return temp; }
    
    ReverseIterator operator- (int n) const
    { ReverseIterator temp = *this; temp -= n; return temp; }
    
    ReverseIterator operator+= (int n)
    { if(n >= 0) while(n--) --*this; else while(n++) ++*this; return *this; }
    
    ReverseIterator operator-= (int n)
    { if(n >= 0) while(n--) ++*this; else while(n++) --*this; return *this; }
    
  protected:
    ReverseIterator(const Node<T> *node)
      : Iterator(node) {}
  };
  
  // ============================================================
  // Class ConstReverseIterator
  // ============================================================
  class ConstReverseIterator : public ConstIterator
  {
    
    friend class LinkedList<T>;
    
  public:
    ConstReverseIterator()
      : ConstIterator() {}
    
    ConstReverseIterator(const ConstReverseIterator& iter)
      : ConstIterator(iter) {}
    
    virtual ~ConstReverseIterator()
    {}
    
    ConstReverseIterator& operator++ ()
    { setNode(getNode()->getPrevious()); checkValid(); return *this; }
    
    ConstReverseIterator operator++ (int)
    { ConstReverseIterator temp = *this; ++*this; return temp; }
    
    ConstReverseIterator& operator-- ()
    { setNode(getNode()->getNext()); checkValid(); return *this; }
    
    ConstReverseIterator operator-- (int)
    { ConstReverseIterator temp = *this; --*this; return temp; }
    
    ConstReverseIterator operator+ (int n) const
    { ConstReverseIterator temp = *this; temp += n; return temp; }
    
    ConstReverseIterator operator- (int n) const
    { ConstReverseIterator temp = *this; temp -= n; return temp; }
    
    ConstReverseIterator operator+= (int n)
    { if(n >= 0) while(n--) --*this; else while(n++) ++*this; return *this; }
    
    ConstReverseIterator operator-= (int n)
    { if(n >= 0) while(n--) ++*this; else while(n++) --*this; return *this; }
    
  protected:
    ConstReverseIterator(const Node<T> *node)
      : ConstIterator(node) {}
  };
  
  LinkedList();
  LinkedList(const T& head) throw(Exception);
  LinkedList(const LinkedList<T>& l);
  
  virtual ~LinkedList();
  
  virtual void render(ostream& out) const;
  
  bool operator== (const LinkedList<T>& rhs) const;
  bool operator!= (const LinkedList<T>& rhs) const;
  LinkedList<T>& operator= (const T& head);
  LinkedList<T>& operator= (const LinkedList<T>& rhs);
  
  Iterator operator[] (int n) throw(Exception);
  ConstIterator operator[] (int n) const throw(Exception);
  
  LinkedList<T>& operator<< (const T& data) throw(Exception);
  LinkedList<T>& operator<< (LinkedList<T> l) throw(Exception);
  
  LinkedList<T>& extract(int start, int limit, LinkedList<T>& l) const throw(Exception);
  
  Iterator at(int n) throw(Exception);
  ConstIterator at(int n) const throw(Exception);
  
  ReverseIterator rAt(int n) throw(Exception);
  ConstReverseIterator rAt(int n) const throw(Exception);
  
  Iterator begin();
  ConstIterator begin() const;
  
  Iterator end();
  ConstIterator end() const;
  
  ReverseIterator rBegin();
  ConstReverseIterator rBegin() const;
  
  ReverseIterator rEnd();
  ConstReverseIterator rEnd() const;
  
  inline long length() const 		{ return fLength; }
  inline bool isEmpty() const 	{ return (fLength == 0); }
  
  inline T& front() 				{ return fHead->getDataReference(); }
  inline const T& front() const 	{ return **fHead; }
  
  inline T& back() 				{ return fTail->getDataReference(); }
  inline const T& back() const 	{ return **fTail; }
  
  LinkedList<T>& prepend(const T& data) throw(Exception);
  LinkedList<T>& prepend(LinkedList<T> l);
  LinkedList<T>& prepend(LinkedList<T> l, int start, int limit) throw(Exception);
  
  LinkedList<T>& append(const T& data) throw(Exception);
  LinkedList<T>& append(LinkedList<T> l);
  LinkedList<T>& append(LinkedList<T> l, int start, int limit) throw(Exception);
  
  LinkedList<T>& insert(int pos, const T& data) throw(Exception);
  LinkedList<T>& insert(int pos, LinkedList<T> l) throw(Exception);
  LinkedList<T>& insert(int pos, LinkedList<T> l, int start, int limit) throw(Exception);
  
  LinkedList<T>& replace(int pos, const T& data) throw(Exception);
  LinkedList<T>& replace(int pos, LinkedList<T> l) throw(Exception);
  LinkedList<T>& replace(int pos, LinkedList<T> l, int start, int limit) throw(Exception);
  LinkedList<T>& replace(int start, int limit, const T& data) throw(Exception);
  LinkedList<T>& replace(int start, int limit, LinkedList<T> l) throw(Exception);
  LinkedList<T>& replace(int start, int limit, LinkedList<T> l, int start2, int limit2) throw(Exception);
  
  const T& pop_front();
  const T& pop_back();
  
  LinkedList<T>& erase(int pos) throw(Exception);
  LinkedList<T>& erase(int first, int last) throw(Exception);
  
  LinkedList<T>& remove(const T& value);
  
  LinkedList<T>& reverse();
  
  LinkedList<T>& deleteAll();
  
  LinkedList<T>& clone(LinkedList<T>& l) const throw(Exception);
  
private:
  Node<T>* findNode(int n) const throw(Exception);
  Node<T>* findStrictNode(int n) const throw(Exception);
  
  Node<T> *fHead;
  Node<T> *fTail;
  long fLength;
};


// ============================================================
// Implementation
// ============================================================

// ============================================================
// Class LinkedList
// ============================================================
template <class T>
LinkedList<T>::LinkedList()
  : fHead(NULL), fTail(NULL), fLength(0)
{}

template <class T>
LinkedList<T>::LinkedList(const T& head) throw(Exception)
  : fHead(NULL), fTail(NULL), fLength(0)
{
  append(head);
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& l)
  : fHead(NULL), fTail(NULL), fLength(0)
{
  ConstIterator iter = l.begin();
  
  while(iter.isValid())
    append(*iter++);
}

template <class T>
LinkedList<T>::~LinkedList() {
  deleteAll();
}

template <class T>
void 
LinkedList<T>::render(ostream& out) const {
  Node<T> *current = (Node<T>*) fHead;
  
  while(current != NULL) {
    Node<T> *next = (Node<T>*) current->getNext();
    current->render(out);
    if(next != NULL)
      out << ' ';
    current = next;
  }
}

template <class T>
bool 
LinkedList<T>::operator== (const LinkedList<T>& rhs) const {
  return ((fHead == rhs.fHead) && (fTail == rhs.fTail));
}

template <class T>
bool 
LinkedList<T>::operator!= (const LinkedList<T>& rhs) const {
  return !(*this == rhs);
}

template <class T>
LinkedList<T>& 
LinkedList<T>::operator= (const T& head) {
  deleteAll();
  return append(head);
}

template <class T>
LinkedList<T>& 
LinkedList<T>::operator= (const LinkedList<T>& rhs) {
  deleteAll();
  return append(rhs);
}

template <class T>
LinkedList<T>::Iterator 
LinkedList<T>::operator[] (int n) throw(Exception) {
  return at(n);
}

template <class T>
LinkedList<T>::ConstIterator 
LinkedList<T>::operator[] (int n) const throw(Exception) {
  return at(n);
}

template <class T>
LinkedList<T>& 
LinkedList<T>::extract(int start, int limit, LinkedList<T>& l) const throw(Exception) {
  ConstIterator iter1 = at(start);
  ConstIterator iter2 = at(limit);
  
  l.deleteAll();
  
  while(iter1 != iter2)
    l.append(*iter1++);
  
  return l;
}

template <class T>
LinkedList<T>::Iterator 
LinkedList<T>::at(int n) throw(Exception) {
  return Iterator(findNode(n));
}

template <class T>
LinkedList<T>::ConstIterator 
LinkedList<T>::at(int n) const throw(Exception) {
  return ConstIterator(findNode(n));
}

template <class T>
LinkedList<T>::ReverseIterator 
LinkedList<T>::rAt(int n) throw(Exception) {
  return ReverseIterator(findNode(n));
}

template <class T>
LinkedList<T>::ConstReverseIterator 
LinkedList<T>::rAt(int n) const throw(Exception) {
  return ConstReverseIterator(findNode(n));
}

template <class T>
LinkedList<T>::Iterator 
LinkedList<T>::begin() {
  return Iterator(fHead);
}

template <class T>
LinkedList<T>::ConstIterator 
LinkedList<T>::begin() const {
  return ConstIterator(fHead);
}

template <class T>
LinkedList<T>::Iterator 
LinkedList<T>::end() {
  return Iterator(fTail);
}

template <class T>
LinkedList<T>::ConstIterator 
LinkedList<T>::end() const {
  return ConstIterator(fTail);
}

template <class T>
LinkedList<T>::ReverseIterator 
LinkedList<T>::rBegin() {
  return ReverseIterator(fHead);
}

template <class T>
LinkedList<T>::ConstReverseIterator 
LinkedList<T>::rBegin() const {
  return ConstReverseIterator(fHead);
}

template <class T>
LinkedList<T>::ReverseIterator 
LinkedList<T>::rEnd() {
  return ReverseIterator(fTail);
}

template <class T>
LinkedList<T>::ConstReverseIterator 
LinkedList<T>::rEnd() const {
  return ConstReverseIterator(fTail);
}

template <class T>
LinkedList<T>& 
LinkedList<T>::operator<< (const T& data) throw(Exception) {
  return append(data);
}

template <class T>
LinkedList<T>& 
LinkedList<T>::operator<< (LinkedList<T> l) throw(Exception) {
  return append(l);
}

template <class T>
LinkedList<T>& 
LinkedList<T>::prepend(const T& data) throw(Exception) {
  if(isEmpty()) {
    fHead = fTail = new Node<T>(&data);
    if(fHead == NULL)
      throw Exception("new failed", ERRINFO);
  }
  else {
    Node<T> *oldHead = (Node<T>*) fHead;
    oldHead->setPrevious(new Node<T>(&data));
    if(oldHead->getPrevious() == NULL)
      throw Exception("new failed", ERRINFO);
    fHead = (Node<T>*) oldHead->getPrevious();
    fHead->setNext(oldHead);
  }
  fLength++;
  return *this;
}

template <class T>
LinkedList<T>& 
LinkedList<T>::prepend(LinkedList<T> l) {
  return prepend(l, 0, l.length());
}

template <class T>
LinkedList<T>& 
LinkedList<T>::prepend(LinkedList<T> l, int start, int limit) throw(Exception) {
  Iterator iter1 = l[start];
  Iterator iter2 = l[limit];
  
  int pos = 0;
  
  prepend(*iter1++);
  while(iter1 != iter2)
    insert(pos++, *iter1++);
  
  return *this;
}

template <class T>
LinkedList<T>& 
LinkedList<T>::append(const T& data) throw(Exception) {
  if(isEmpty()) {
    fHead = fTail = new Node<T>(&data);
    if(fHead == NULL)
      throw Exception("new failed", ERRINFO);
  }
  else {
    Node<T> *oldTail = (Node<T>*) fTail;
    oldTail->setNext(new Node<T>(&data));
    if(oldTail->getNext() == NULL)
      throw Exception("new failed", ERRINFO);
    fTail = (Node<T>*) oldTail->getNext();
    fTail->setPrevious(oldTail);
  }
  fLength++;
  return *this;
}

template <class T>
LinkedList<T>& 
LinkedList<T>::append(LinkedList<T> l) {
  return append(l, 0, l.length());
}

template <class T>
LinkedList<T>& 
LinkedList<T>::append(LinkedList<T> l, int start, int limit) throw(Exception) {
  Iterator iter1 = l[start];
  Iterator iter2 = l[limit];
  
  while(iter1 != iter2)
    append(*iter1++);
  
  return *this;
}

template <class T>
LinkedList<T>& 
LinkedList<T>::insert(int pos, const T& data) throw(Exception) {
  Node<T> *newNode = new Node<T>(&data);
  Node<T> *which = findStrictNode(pos);
  
  newNode->setPrevious(which);
  newNode->setNext(which->getNext());
  which->setNext(newNode);
  
  fLength++;
  
  return *this;
}

template <class T>
LinkedList<T>& 
LinkedList<T>::insert(int pos, LinkedList<T> l) throw(Exception) {
  return insert(pos, l, 0, l.length());
}

template <class T>
LinkedList<T>& 
LinkedList<T>::insert(int pos, LinkedList<T> l, int start, int limit) throw(Exception) {
  Iterator iter1 = l[start];
  Iterator iter2 = l[limit];
  
  while(iter1 != iter2)
    insert(pos++, *iter1++);
  
  return *this;
}

template <class T>
LinkedList<T>& 
LinkedList<T>::replace(int pos, const T& data) throw(Exception) {
  Node<T> *which = findStrictNode(pos);
  which->setData(data);
  
  return *this;
}

template <class T>
LinkedList<T>& 
LinkedList<T>::replace(int start, int limit, const T& data) throw(Exception) {
  insert(limit, data);
  return erase(start, limit);
}

template <class T>
LinkedList<T>& 
LinkedList<T>::replace(int pos, LinkedList<T> l) throw(Exception) {
  insert(pos, l);
  return erase(pos);
}

template <class T>
LinkedList<T>& 
LinkedList<T>::replace(int pos, LinkedList<T> l, int start, int limit) throw(Exception) {
  insert(pos, l, start, limit);
  return erase(pos);
}

template <class T>
LinkedList<T>& 
LinkedList<T>::replace(int start, int limit, LinkedList<T> l) throw(Exception) {
  insert(limit - 1, l);
  return erase(start, limit);
}

template <class T>
LinkedList<T>& 
LinkedList<T>::replace(int start, int limit, LinkedList<T> l, int start2, int limit2) throw(Exception) {
  insert(limit - 1, l, start2, limit2);
  return erase(start, limit);
}
	
template <class T>
const T& 
LinkedList<T>::pop_front() {
  Node<T> *which = fHead;
  fHead = (Node<T>*) fHead->getNext();
  fHead->setPrevious(NULL);
  
  const T& ret = **which;
  
  delete which;
  fLength--;
  
  return ret;
}

template <class T>
const T&
LinkedList<T>::pop_back() {
  Node<T> *which = fTail;
  fTail = (Node<T>*) fTail->getPrevious();
  fTail->setNext(NULL);
  
  const T& ret = **which;
  
  delete which;
  fLength--;
  
  return ret;
}
	
template <class T>
LinkedList<T>& 
LinkedList<T>::erase(int pos) throw(Exception) {
  Node<T> *which = findStrictNode(pos);
  
  if(pos == 0) {
    fHead = (Node<T>*) fHead->getNext();
    fHead->setPrevious(NULL);
  }
  else if(pos == (fLength - 1)) {
    fTail = (Node<T>*) fTail->getPrevious();
    fTail->setNext(NULL);
  }
  else {
    if(which->getPrevious() != NULL)
      ((Node<T>*) which->getPrevious())->setNext(which->getNext());
    if(which->getNext() != NULL)
      ((Node<T>*) which->getNext())->setPrevious(which->getPrevious());
  }
  
  delete which;
  fLength--;
  
  return *this;
}

template <class T>
LinkedList<T>& 
LinkedList<T>::erase(int first, int last) throw(Exception) {
  --last;
  Node<T> *start = findStrictNode(first);
  Node<T> *limit = findStrictNode(last);
  
  int count = (last - first);
  
  if(first == 0 && last == (fLength - 1)) {
    fHead = fTail = NULL;
  }
  else if(first == 0) {
    fHead = (Node<T>*) limit->getNext();
    fHead->setPrevious(NULL);
  }
  else if(last == (fLength - 1)) {
    fTail = (Node<T>*) start->getPrevious();
    fTail->setNext(NULL);
  }
  else {
    if(start->getPrevious() != NULL)
      ((Node<T>*) start->getPrevious())->setNext(limit->getNext());
    if(limit->getNext() != NULL)
      ((Node<T>*) limit->getNext())->setPrevious(start->getPrevious());
  }
  
  Node<T> *current = (Node<T>*) start;
  while(count-- && current != NULL) {
    Node<T> *next = (Node<T>*) current->getNext();
    delete current;
    current = next;
  }
  fLength -= (last - first) + 1;
  
  return *this;
}

template <class T>
LinkedList<T>& 
LinkedList<T>::remove(const T& value) {
  return *this;
}
	
template <class T>
LinkedList<T>& 
LinkedList<T>::reverse() {
  Node<T>* first = fHead;
  if( first == NULL )
    return *this;
  
  fTail = first;
  Node<T> *previous = NULL;
  Node<T> *current = first;
  
  while(current != NULL) {
    Node<T> *next = (Node<T>*) current->getNext();
    current->setNext(previous);
    current->setPrevious(next);
    previous = current;
    current = next;
  }
  fHead = previous;
  return *this;
}

template <class T>
LinkedList<T>& 
LinkedList<T>::deleteAll() {
  Node<T> *current = (Node<T>*) fHead;
  
  while(current != NULL) {
    Node<T> *next = (Node<T>*) current->getNext();
    delete current;
    current = next;
  }
  fLength = 0;
  
  fHead = fTail = NULL;
  return *this;
}

template <class T>
LinkedList<T>&
LinkedList<T>::clone(LinkedList<T>& l) const throw(Exception){
  ConstIterator iter = begin();
  
  while(iter.isValid())
    l.append(*iter++);
  
  return l;
}

template <class T>
Node<T>*
LinkedList<T>::findNode(int n) const throw(Exception) {
  if(n >= 0 && n < fLength) {
    Node<T> *current = fHead;
    while(n--)
      current = (Node<T>*) current->getNext();
    return current;
  }
  else if(n == -1 || n == fLength)
    return NULL;
  else {
    throw Exception("no such element", ERRINFO);
    return NULL;
  }
}

template <class T>
Node<T>*
LinkedList<T>::findStrictNode(int n) const throw(Exception) {
  if(n >= 0 && n < fLength) {
    Node<T> *current = fHead;
    while(n--)
      current = (Node<T>*) current->getNext();
    return current;
  }
  else {
    throw Exception("no such element", ERRINFO);
    return NULL;
  }
}

#endif
