/*
 *  $Id: Node.hh,v 1.5 1998/12/09 00:48:57 sbooth Exp $
 *
 *  Copyright (C) 1996, 1997, 1998 Stephen F. Booth
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the Free
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __NODE__
#define __NODE__ 1

#include "Exception.hh"
#include "MStreamable.hh"


// ============================================================
// Class Node
// ============================================================
template <class T>
class LinkedList;
template <class T>
class Node : public MStreamable {
  
  friend class LinkedList<T>;
  
public:
  Node();
  Node(const T& data);
  Node(const Node<T>& x); 
  virtual ~Node();
  
  virtual void render(ostream& out) const;
  
  Node<T>& operator= (const Node<T>& rhs) 
  { if(this != &rhs) fData = rhs.getData(); return *this; }
  
  bool operator== (const Node<T>& x) const     
  { return (*getData() == *x); }

  bool operator!= (const Node<T>& x) const   	{ return ! (*this == x); }
  
  const T& operator* () const 			{ return *getData(); }
  
  inline const Node<T>* getNext() const 	{ return fNext; } 
  inline const Node<T>* getPrevious() const 	{ return fPrevious; } 
  
  inline const T* getData() const 		{ return fData; };
  inline T& getDataReference()			{ return (T&) *fData; }
  
  inline void setData(const T *data) 		{ fData = data; };
  inline void setData(const T& data) 		{ fData = &data; };
  
protected:
  inline void setNext(const Node<T> *next) 	{ fNext = next; }
  inline void setPrevious(const Node<T> *prev) 	{ fPrevious = prev; }
    
private:
  const Node<T> *fNext;
  const Node<T> *fPrevious;
  T *fData;
};

// ============================================================
// Implementation
// ============================================================

template <class T>
Node<T>::Node()
  : fNext(NULL), fPrevious(NULL), fData(NULL)
{}

template <class T>
Node<T>::Node(const T& data)
  : fNext(NULL), fPrevious(NULL), fData(NULL) {
    fData = new T(data);
}

template <class T>
Node<T>::Node(const Node<T>& x)
  : fNext(NULL), fPrevious(NULL), fData() {
    fData = new T(x.getData());
}

template <class T>
Node<T>::~Node() {
  delete fData;
}

template <class T>
void 
Node<T>::render(ostream& out) const {
  out << *getData();
}

#endif
