/* $Id: Node.hh,v 1.1 1998/03/30 00:54:36 sbooth Exp $ */

#ifndef __NODE__
#define __NODE__ 1

#ifndef __EXCEPTION__
#include "Exception.hh"
#endif

#ifndef __MSTREAMABLE__
#include "MStreamable.hh"
#endif


// ============================================================
// Class Node
// ============================================================
template <class T>
class Node : public MStreamable {
  
  friend class LinkedList<T>;
  friend class LinkedList<T>::Iterator;
  friend class LinkedList<T>::ConstIterator;
  
public:
  Node();
  Node(const T *data);
  Node(const Node<T>& x); 
  virtual ~Node();
  
  virtual void render(ostream& out) const;
  
  Node<T>& operator= (const Node<T>& rhs) 
  { if(this != &rhs) fData = rhs.getData(); return *this; }
  
  bool operator== (const Node<T>& x) const   
  { return (*getData() == *(x.getData())); }

  bool operator!= (const Node<T>& x) const   	{ return ! (*this == x); }
  
  const T& operator* () const 			{ return *getData(); }
  
  inline const Node<T>* getNext() const 	{ return fNext; } 
  inline const Node<T>* getPrevious() const 	{ return fPrevious; } 
  
  inline const T* getData() const 		{ return fData; };
  
  inline void setData(const T *data) 		{ fData = data; };
  inline void setData(const T& data) 		{ fData = &data; };
  
protected:
  inline void setNext(const Node<T> *next) 	{ fNext = next; }
  inline void setPrevious(const Node<T> *prev) 	{ fPrevious = prev; }
  
  inline T& getDataReference()			{ return (T&) *fData; }
  
private:
  const Node<T> *fNext;
  const Node<T> *fPrevious;
  const T *fData;
};

// ============================================================
// Implementation
// ============================================================

template <class T>
Node<T>::Node()
  : fNext(NULL), fPrevious(NULL), fData(NULL)
{}

template <class T>
Node<T>::Node(const T *data)
  : fNext(NULL), fPrevious(NULL), fData(data)
{}

template <class T>
Node<T>::Node(const Node<T>& x)
  : fNext(NULL), fPrevious(NULL), fData(x.getData())
{}

template <class T>
Node<T>::~Node()
{}

template <class T>
void 
Node<T>::render(ostream& out) const {
  out << *getData();
}

#endif
