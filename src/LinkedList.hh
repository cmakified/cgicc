/*
 *  $Id: LinkedList.hh,v 1.7 1998/12/09 00:48:57 sbooth Exp $
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

#ifndef __LINKED_LIST__
#define __LINKED_LIST__ 1

#include "Exception.hh"
#include "MStreamable.hh"
#include "Node.hh"


// ============================================================
// Class LinkedList
// ============================================================
/**
 * A templatized linked list class supporting find, replace, insert, delete,
 * and erase operations.
 *
 * <P>LinkedLists manage their own storage, allocating and deallocating as
 * needed.  Classes contained within a LinkedList <STRONG>MUST</STRONG> define
 * a copy constructor.</P>
 *
 * <P>To create a new LinkedList of Exceptions, and add two items to it:
 * <PRE CLASS="code">
 * LinkedList&lt;Exception&gt; list;
 * list.append(Exception("error one");
 * list &lt;&lt; Exception("error two");
 * </PRE>
 * Note that the items added were created on the stack; LinkedList creates
 * an internal copy, so you can safely add temporaries.
 * </P>
 *
 * <P>To iterate through every item in a LinkedList:
 * <PRE CLASS="code">
 * LinkedList&lt;Exception&gt;::Iterator = list.begin();
 * while(iter.isValid()) {
 *  cout &lt;&lt; (*iter++).getMessage() &lt;&lt; endl;
 * }
 * </PRE>
 * </P>
 *
 * <P>To iterate through every item in a LinkedList backwards:
 * <PRE CLASS="code">
 * LinkedList<Exception>::ReverseIterator = list.rEnd();
 * while(iter.isValid()) {
 *  cout &lt;&lt; (*iter++).getMessage() &lt;&lt; endl;
 * }
 * </PRE>
 * </P>
 *
 * <P>LinkedLists also support insert/delete operations:
 * <PRE CLASS="code">
 * LinkedList&lt;char&gt; list;
 * list &lt;&lt; 'C' &lt;&lt; 'g' &lt;&lt; 'i' &lt;&lt; 'c' &lt;&lt; 'c';
 * list.insert(1, '!'); <SPAN CLASS="green">// list is now Cg!icc</SPAN>
 * list.erase(3); <SPAN CLASS="green">// list is now Cg!cc</SPAN>
 * </PRE>
 * </P>
 */
template <class T>
class LinkedList : public MStreamable {
public:
  
  // ============================================================
  // Class Iterator
  // ============================================================
  class ConstIterator;
  /**
   * A bidirectional iterator over a LinkedList.
   * <P>An Iterator represents one element in a LinkedList.<BR>
   * Iterators are not created directly, but rather are obtained through
   * LinkedLists:</P>
   * <PRE CLASS="code">
   * LinkedList&lt;char&gt; list;
   * list.append('a').append('b').append('c');
   * LinkedList&lt;char&gt;::Iterator iter1 = list.begin();
   * LinkedList&lt;char&gt;::Iterator iter2 = list.at(1);
   * LinkedList&lt;char&gt;::Iterator iter3 = list[2];
   * </PRE>
   * <P>After executing the above code, <TT>iter1</TT> refers to <TT>a</TT>,
   * <TT>iter2</TT> refers to <TT>b</TT>, and <TT>iter3</TT> refers to 
   * <TT>c</TT>.
   * <P>Iterators may be added to, subtracted from, and assigned to:</P>
   * <PRE CLASS="code">
   * LinkedList&lt;int&gt; list;
   * list &lt;&lt; 1 &lt;&lt; 2 &lt;&lt; 3 &lt;&lt; 4 &lt;&lt; 5 &lt;&lt; 6 &lt;&lt; 7;
   * LinkedList&lt;int&gt;::Iterator iter = list.begin();
   * *iter = 0; <SPAN CLASS="green">|| List is now 0234567</SPAN>
   * iter += 2; <SPAN CLASS="green">|| Advance iter by 2</SPAN>
   * iter -= 1; <SPAN CLASS="green">|| Decrement iter by 1</SPAN>
   * --*iter = 1; <SPAN CLASS="green">|| Restore list to original state</SPAN>
   * </PRE>
   */
  class Iterator : public MStreamable
  {
    
    friend class LinkedList<T>;
    friend class ConstIterator;
    
  public:
    /**@name Constructors */
    //@{
    
    /** Constructor */
    Iterator()
      : fNode(NULL), fValid(false) {}

    
    /**
     * Copy constructor.
     * @param iter The Iterator to copy. 
     */
    Iterator(const Iterator& iter)
      : fNode(iter.fNode), fValid(iter.fValid) {}
    
    /** Destructor */
    virtual ~Iterator() {}
    //@}
    
    virtual void render(ostream& out) const
    { out << *this; }

    /**@name Validity */
    //@{

    /**
     * Determine if this Iterator represents a valid list element.
     * @return True if this Iterator represents a valid list element, 
     * false otherwise.
     */
    bool isValid() const 
    { return fValid; }
    //@}

    /**@name Equality Operators */
    //@{

    /**
     * Test two Iterators for equality.
     * @param iter The Iterator for comparison
     * @return True if this Iterator represents the same element as 
     * <TT>iter</TT>, false otherwise.
     */
    bool operator== (const Iterator& iter) const 
    { return getNode() == iter.getNode(); }
    
    /**
     * Test an Iterator and a ConstIterator for equality.
     * @param iter The ConstIterator for comparison.
     * @return True if this Iterator represents the same element as 
     * <TT>iter</TT>, false otherwise.
     */
    bool operator== (const ConstIterator& iter) const 
    { return getNode() == iter.getNode(); }
    
    /**
     * Test two Iterators for inequality.
     * @param iter The Iterator for comparison.
     * @return True if this Iterator represents a different element than
     * <TT>iter</TT>, false otherwise.
     */
    bool operator!= (const Iterator& iter) const
    { return ! (*this == iter); }
    
    /**
     * Test an Iterator and a ConstIterator for inequality.
     * @param iter The ConstIterator for comparison.
     * @return True if this Iterator represents a different element than
     * <TT>iter</TT>, false otherwise.
     */
    bool operator!= (const ConstIterator& iter) const
    { return ! (*this == iter); }
    //@}

    /**@name Assignment */
    //@{

    /**
     * Assign a new value to this Iterator.
     * @param rhs The Iterator representing the new location this Iterator
     * will represent.
     * @return A reference to this Iterator.
     */
    Iterator& operator= (const Iterator& rhs)
    { if(this != &rhs) { 
      fNode = rhs.fNode; fValid = rhs.fValid; } return *this; }
    //@}

    /**@name Element Access */
    //@{

    /**
     * Get a reference to the list element represented by this Iterator.
     * @return A reference to the element represented by this Iterator.
     */
    T& operator* () const
    { return fNode->getDataReference(); }
    //@}

    /**@name List Traversal */
    //@{

    /**
     * Advance this Iterator to the next element in the list.
     * @return A reference to this Iterator.
     */
    Iterator& operator++ ()
    { fNode = (Node<T>*) fNode->getNext(); checkValid(); return *this; }
    
    /**
     * Advance this Iterator to the next element in the list.
     * @return A reference to this Iterator.
     */
    Iterator operator++ (int)
    { Iterator temp = *this; ++*this; return temp; }
    
    /**
     * Advance this Iterator to the previous element in the list.
     * @return A reference to this Iterator.
     */
    Iterator& operator-- ()
    { fNode = (Node<T>*) fNode->getPrevious(); checkValid(); return *this; }
    
    /**
     * Advance this Iterator to the previous element in the list.
     * @return A reference to this Iterator.
     */
    Iterator operator-- (int)
    { Iterator temp = *this; --*this; return temp; }
    
    /**
     * Advance this Iterator an arbitrary number of list elements.
     * @return A reference to this Iterator.
     */
    Iterator operator+= (int n)
    { if(n >= 0) while(n--) ++*this; else while(n++) --*this; return *this; }
    
    /**
     * Advance this Iterator an arbitrary number of list elements.
     * @return A reference to this Iterator.
     */
    Iterator operator-= (int n)
    { if(n >= 0) while(n--) --*this; else while(n++) ++*this; return *this; }
    //@}

    /**@name Addition and Subtraction */
    //@{

    /**
     * Get a new Iterator an arbitrary number of elements ahead of this one.
     * @param n The number of elements to advance.
     * @return A new Iterator an arbitrary number of elements ahead of 
     * this Iterator.
     */
    Iterator operator+ (int n) const
    { Iterator temp = *this; temp += n; return temp; }
    
    /**
     * Get a new Iterator an arbitrary number of elements behind of this one.
     * @param n The number of elements to retreat.
     * @return A new Iterator an arbitrary number of elements behind
     * this Iterator.
     */
    Iterator operator- (int n) const
    { Iterator temp = *this; temp -= n; return temp; }
    //@}
    
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
  /**
   * A bidirectional constant iterator over a LinkedList.
   * <P>A ConstIterator represents one element in a LinkedList.<BR>
   * ConstIterators are not created directly, but rather are obtained through
   * LinkedLists.</P>
   * @see Iterator
   */
  class ConstIterator : public MStreamable
  {
    
    friend class LinkedList<T>;
    friend class Iterator;
    
  public:
    /**@name Constructors */
    //@{

    /** Constructor */
    ConstIterator()
      : fNode(NULL), fValid(false) {}

    /**
     * Copy constructor.
     * @param iter The ConstIterator to copy. 
     */
    ConstIterator(const ConstIterator& iter)
      : fNode(iter.fNode), fValid(iter.fValid) {}
    
    /** Destructor */
    virtual ~ConstIterator() {}
    //@}
    
    virtual void render(ostream& out) const
    { out << *this; }
    
    /**@name Validity */
    //@{
    
    /**
     * Determine if this ConstIterator represents a valid list element.
     * @return True if this ConstIterator represents a valid list element, 
     * false otherwise.
     */
    bool isValid() const 
    { return fValid; }
    //@}
    
    /**@name Equality Operators */
    //@{
    
    /**
     * Test two ConstIterators for equality.
     * @param iter The ConstIterator for comparison
     * @return True if this ConstIterator represents the same element as 
     * <TT>iter</TT>, false otherwise.
     */
    bool operator== (const ConstIterator& iter) const 
    { return getNode() == iter.getNode(); }
    
    /**
     * Test two ConstIterators for inequality.
     * @param iter The ConstIterator for comparison.
     * @return True if this Iterator represents a different element than
     * <TT>iter</TT>, false otherwise.
     */
    bool operator!= (const ConstIterator& iter) const
    { return ! (*this == iter); }
    //@}
    
    /**@name Assignment */
    //@{
    
    /**
     * Assign a new value to this ConstIterator.
     * @param rhs The ConstIterator representing the new location this 
     * ConstIterator will represent.
     * @return A reference to this ConstIterator.
     */
    ConstIterator& operator= (const ConstIterator& rhs)
    { if(this != &rhs) { 
      fNode = rhs.fNode; fValid = rhs.fValid; } return *this; }
    //@}

    /**@name Element Access */
    //@{

    /**
     * Get a constant reference to the list element represented by this 
     * ConstIterator.
     * @return A constant reference to the element represented by this 
     * ConstIterator.
     */
    const T& operator* () const
    { return **fNode; }
    //@}

    /**@name List Traversal */
    //@{

    /**
     * Advance this ConstIterator to the next element in the list.
     * @return A reference to this ConstIterator.
     */
    ConstIterator& operator++ ()
    { fNode = (Node<T>*) fNode->getNext(); checkValid(); return *this; }
    
    /**
     * Advance this ConstIterator to the next element in the list.
     * @return A reference to this ConstIterator.
     */
    ConstIterator operator++ (int)
    { ConstIterator temp = *this; ++*this; return temp; }
    
    /**
     * Advance this ConstIterator to the previous element in the list.
     * @return A reference to this ConstIterator.
     */
    ConstIterator& operator-- ()
    { fNode = (Node<T>*) fNode->getPrevious(); checkValid(); return *this; }
    
    /**
     * Advance this ConstIterator to the previous element in the list.
     * @return A reference to this ConstIterator.
     */
    ConstIterator operator-- (int)
    { ConstIterator temp = *this; --*this; return temp; }
    
    /**
     * Advance this ConstIterator an arbitrary number of list elements.
     * @return A reference to this ConstIterator.
     */
    ConstIterator operator+= (int n)
    { if(n >= 0) while(n--) ++*this; else while(n++) --*this; return *this; }
    
    /**
     * Advance this ConstIterator an arbitrary number of list elements.
     * @return A reference to this ConstIterator.
     */
    ConstIterator operator-= (int n)
    { if(n >= 0) while(n--) --*this; else while(n++) ++*this; return *this; }
    //@}
    
    /**@name Addition and Subtraction */
    //@{
    
    /**
     * Get a new ConstIterator an arbitrary number of elements ahead of 
     * this one.
     * @param n The number of elements to advance.
     * @return A new ConstIterator an arbitrary number of elements ahead of 
     * this ConstIterator.
     */
    ConstIterator operator+ (int n) const
    { ConstIterator temp = *this; temp += n; return temp; }
    
    /**
     * Get a new ConstIterator an arbitrary number of elements behind of 
     * this one.
     * @param n The number of elements to retreat.
     * @return A new ConstIterator an arbitrary number of elements behind
     * this ConstIterator.
     */
    ConstIterator operator- (int n) const
    { ConstIterator temp = *this; temp -= n; return temp; }
    //@}
    
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
  /** 
   * A bidirectional reverse iterator over a LinkedList.
   * <P>ReverseIterators work like regular Iterators, except they
   * traverse the list in the opposite direction</P>
   * @see Iterator
   */
  class ReverseIterator : public Iterator
  {
    
    friend class LinkedList<T>;
    
  public:
    
    /**@name Constructors */
    //@{

    /** Constructor */
    ReverseIterator()
      : Iterator() {}

    /**
     * Copy constructor.
     * @param iter The ReverseIterator to copy. 
     */
    ReverseIterator(const Iterator& iter)
      : Iterator(iter) {}
    
    /** Destructor */
    virtual ~ReverseIterator() {}
    //@}
    
    /**@name List Traversal */
    //@{

    /**
     * Advance this ReverseIterator to the previous element in the list.
     * @return A reference to this ReverseIterator.
     */
    ReverseIterator& operator++ ()
    { setNode(getNode()->getPrevious()); checkValid(); return *this; }
    
    /**
     * Advance this ReverseIterator to the previous element in the list.
     * @return A reference to this ReverseIterator.
     */
    ReverseIterator operator++ (int)
    { ReverseIterator temp = *this; ++*this; return temp; }
    
    /**
     * Advance this ReverseIterator to the next element in the list.
     * @return A reference to this ReverseIterator.
     */
    ReverseIterator& operator-- ()
    { setNode(getNode()->getNext()); checkValid(); return *this; }
    
    /**
     * Advance this ReverseIterator to the next element in the list.
     * @return A reference to this ReverseIterator.
     */
    ReverseIterator operator-- (int)
    { ReverseIterator temp = *this; --*this; return temp; }
        
    /**
     * Advance this ReverseIterator an arbitrary number of list elements.
     * @return A reference to this ReverseIterator.
     */
    ReverseIterator operator+= (int n)
    { if(n >= 0) while(n--) --*this; else while(n++) ++*this; return *this; }
    
    /**
     * Advance this ReverseIterator an arbitrary number of list elements.
     * @return A reference to this ReverseIterator.
     */
    ReverseIterator operator-= (int n)
    { if(n >= 0) while(n--) ++*this; else while(n++) --*this; return *this; }
    //@}
    
    /**@name Addition and Subtraction */
    //@{
    
    /**
     * Get a new ReverseIterator an arbitrary number of elements behind 
     * this one.
     * @param n The number of elements to advance.
     * @return A new ReverseIterator an arbitrary number of elements behind 
     * this ReverseIterator.
     */
    ReverseIterator operator+ (int n) const
    { ReverseIterator temp = *this; temp += n; return temp; }
    
    /**
     * Get a new ReverseIterator an arbitrary number of elements ahead 
     * of this one.
     * @param n The number of elements to advance.
     * @return A new ReverseIterator an arbitrary number of elements ahead of 
     * this ReverseIterator.
     */
    ReverseIterator operator- (int n) const
    { ReverseIterator temp = *this; temp -= n; return temp; }
    //@}
    
  protected:    
    ReverseIterator(const Node<T> *node)
      : Iterator(node) {}
  };
  
  // ============================================================
  // Class ConstReverseIterator
  // ============================================================
  /** 
   * A bidirectional constant reverse iterator over a LinkedList.
   * <P>ConstReverseIterators work like regular ConstIterators, except they
   * traverse the list in the opposite direction</P>
   * @see ConstIterator
   */
  class ConstReverseIterator : public ConstIterator
  {
    
    friend class LinkedList<T>;
    
  public:
    
    /**@name Constructors */
    //@{
    
    /** Constructor */
    ConstReverseIterator()
      : ConstIterator() {}
    
    /**
     * Copy constructor.
     * @param iter The ReverseIterator to copy. 
     */
    ConstReverseIterator(const ConstReverseIterator& iter)
      : ConstIterator(iter) {}
    
    /** Destructor */
    virtual ~ConstReverseIterator() {}
    //@}
    
    /**@name List Traversal */
    //@{

    /**
     * Advance this ConstReverseIterator to the previous element in the list.
     * @return A reference to this ConstReverseIterator.
     */
    ConstReverseIterator& operator++ ()
    { setNode(getNode()->getPrevious()); checkValid(); return *this; }
    
    /**
     * Advance this ConstReverseIterator to the previous element in the list.
     * @return A reference to this ConstReverseIterator.
     */
    ConstReverseIterator operator++ (int)
    { ConstReverseIterator temp = *this; ++*this; return temp; }
    
    /**
     * Advance this ConstReverseIterator to the next element in the list.
     * @return A reference to this ConstReverseIterator.
     */
    ConstReverseIterator& operator-- ()
    { setNode(getNode()->getNext()); checkValid(); return *this; }
    
    /**
     * Advance this ConstReverseIterator to the next element in the list.
     * @return A reference to this ConstReverseIterator.
     */
    ConstReverseIterator operator-- (int)
    { ConstReverseIterator temp = *this; --*this; return temp; }
        
    /**
     * Advance this ConstReverseIterator an arbitrary number of list elements.
     * @return A reference to this ConstReverseIterator.
     */
    ConstReverseIterator operator+= (int n)
    { if(n >= 0) while(n--) --*this; else while(n++) ++*this; return *this; }
    
    /**
     * Advance this ConstReverseIterator an arbitrary number of list elements.
     * @return A reference to this ConstReverseIterator.
     */
    ConstReverseIterator operator-= (int n)
    { if(n >= 0) while(n--) ++*this; else while(n++) --*this; return *this; }
    //@}

    /**@name Addition and Subtraction */
    //@{
    
    /**
     * Get a new ConstReverseIterator an arbitrary number of elements behind 
     * this one.
     * @param n The number of elements to advance.
     * @return A new ConstReverseIterator an arbitrary number of elements 
     * behind this ConstReverseIterator.
     */
    ConstReverseIterator operator+ (int n) const
    { ConstReverseIterator temp = *this; temp += n; return temp; }
    
    /**
     * Get a new ConstReverseIterator an arbitrary number of elements ahead 
     * of this one.
     * @param n The number of elements to advance.
     * @return A new ConstReverseIterator an arbitrary number of elements 
     * ahead of this ConstReverseIterator.
     */
    ConstReverseIterator operator- (int n) const
    { ConstReverseIterator temp = *this; temp -= n; return temp; }
    //@}
    
  protected:
    ConstReverseIterator(const Node<T> *node)
      : ConstIterator(node) {}
  };

  /**@name Constructors */
  //@{
  /** Create an empty list */
  LinkedList();

  /**
   * Create a list with the specified first element.
   * @param head The first element.
   * @exception Exception
   */
  LinkedList(const T& head) throw(Exception);

  /**
   * Create a copy of a given list.
   * @param l The list to copy.
   */
  LinkedList(const LinkedList<T>& l);

  /** Destructor */
  virtual ~LinkedList();
  //@}

  virtual void render(ostream& out) const;

  /**@name Equality Operators */
  //@{
  
  /**
   * Test two LinkedLists for equality.
   * @return True if the two lists contain the same elements, false otherwise.
   */
  bool operator== (const LinkedList<T>& rhs) const;

  /**
   * Test two LinkedLists for inequality.
   * @return False if the two lists contain the same elements, true otherwise.
   */
  bool operator!= (const LinkedList<T>& rhs) const;
  //@}

  /**@name Assignment Operators */
  //@{
  
  /**
   * Replace the contents of this list with a single element.
   * @param head The element.
   * @return A reference to this list.
   */
  LinkedList<T>& operator= (const T& head);

  /**
   * Replace the contents of this list with another.
   * @param rhs The list which will copied.
   * @return A reference to this list.
   */
  LinkedList<T>& operator= (const LinkedList<T>& rhs);
  //@}
  
  /**@name Extraction */
  //@{

  /**
   * Extract the range of elements [start, limit) from this list.
   * This does not alter this list.
   * @param start The start of the range to extract (inclusive).
   * @param limit The limit of the rance to extract (exclusive).
   * @param l The list which will receive the extracted elements.
   * @exception Exception
   */
  void extract(int start, 
	       int limit, 
	       LinkedList<T>& l) const throw(Exception);
  //@}

  /**@name Element Access */
  //@{
  
  /**
   * Get an Iterator referring to an element.
   * @param n The index of the desired element.
   * @return An Iterator referring to element <TT>n</TT>.
   * @exception Exception
   */
  Iterator operator[] (int n) throw(Exception);

  /**
   * Get a ConstIterator referring to an element.
   * @param n The index of the desired element.
   * @return A ConstIterator referring to element <TT>n</TT>.
   * @exception Exception
   */
  ConstIterator operator[] (int n) const throw(Exception);
  
  /**
   * Get an Iterator referring to an element.
   * @param n The index of the desired element.
   * @return An Iterator referring to element <TT>n</TT>.
   * @exception Exception
   */
  Iterator at(int n) throw(Exception);

  /**
   * Get a ConstIterator referring to an element.
   * @param n The index of the desired element.
   * @return A ConstIterator referring to element <TT>n</TT>.
   * @exception Exception
   */
  ConstIterator at(int n) const throw(Exception);
  
  /**
   * Get a ReverseIterator referring to an element.
   * @param n The index of the desired element.
   * @return A ReverseIterator referring to element <TT>n</TT>.
   * @exception Exception
   */
  ReverseIterator rAt(int n) throw(Exception);

  /**
   * Get a ConstReverseIterator referring to an element.
   * @param n The index of the desired element.
   * @return A ConstReverseIterator referring to element <TT>n</TT>.
   * @exception Exception
   */
  ConstReverseIterator rAt(int n) const throw(Exception);

  /**
   * Get an Iterator referring to the first element of the list.
   * @return An Iterator referring to the first element.
   */  
  Iterator begin();

  /**
   * Get a ConstIterator referring to the first element of the list.
   * @return A ConstIterator referring to the first element.
   */  
  ConstIterator begin() const;
  
  /**
   * Get an Iterator referring to the last element of the list.
   * @return An Iterator referring to the last element.
   */  
  Iterator end();

  /**
   * Get a ConstIterator referring to the last element of the list.
   * @return A ConstIterator referring to the last element.
   */  
  ConstIterator end() const;
  
  /**
   * Get a ReverseIterator referring to the first element of the list.
   * @return A ReverseIterator referring to the first element.
   */  
  ReverseIterator rBegin();

  /**
   * Get a ConstReverseIterator referring to the first element of the list.
   * @return A ConstReverseIterator referring to the first element.
   */  
  ConstReverseIterator rBegin() const;
  
  /**
   * Get a ReverseIterator referring to the last element of the list.
   * @return A ReverseIterator referring to the last element.
   */  
  ReverseIterator rEnd();

  /**
   * Get a ConstReverseIterator referring to the last element of the list.
   * @return A ConstReverseIterator referring to the last element.
   */  
  ConstReverseIterator rEnd() const;
  //@}

  /**@name List Information */
  //@{

  /**
   * Get the number of elements in the list.
   * @return The number of elements in the list.
   */
  inline long length() const 		{ return fLength; }

  /**
   * Determine if the list is empty.
   * @return True if the list contains zero elements, false otherwise.
   */
  inline bool isEmpty() const 		{ return (fLength == 0); }
  //@}
  
  /**@name Data Access */
  //@{

  /**
   * Get a reference to the first element.
   * @return A reference to the first element.
   */
  inline T& front() 			{ return fHead->getDataReference(); }

  /**
   * Get a constant reference to the first element.
   * @return A constant reference to the first element.
   */
  inline const T& front() const 	{ return **fHead; }
  
  /**
   * Get a reference to the last element.
   * @return A reference to the last element.
   */
  inline T& back() 			{ return fTail->getDataReference(); }

  /**
   * Get a constant reference to the last element.
   * @return A constant reference to the last element.
   */
  inline const T& back() const 		{ return **fTail; }

  /** Remove the first element from the list. */
  void pop_front();
  
  /** Remove the last element from the list. */
  void pop_back();
  //@}

  /**@name Addition */
  //@{

  /**
   * Prepend an element to this list.
   * @param data The element to prepend.
   * @return A reference to this list.
   * @exception Exception
   */
  LinkedList<T>& prepend(const T& data) throw(Exception);

  /**
   * Prepend another list to this list.
   * @param l The list to prepend.
   * @return A reference to this list.
   * @exception Exception
   */
  LinkedList<T>& prepend(LinkedList<T> l);

  /**
   * Prepend a range of elements in another list to this list.
   * @param l The list containing the elements to prepend.
   * @param start The start of the range to prepend (inclusive).
   * @param limit The limit of the range to prepend (exclusive).
   * @return A reference to this list.
   * @exception Exception
   */
  LinkedList<T>& prepend(LinkedList<T> l, 
			 int start, 
			 int limit) throw(Exception);
  
  /**
   * Append an element to this list.
   * @param data The element to append.
   * @return A reference to this list.
   * @exception Exception
   */
  LinkedList<T>& append(const T& data) throw(Exception);

  /**
   * Append another list to this list.
   * @param l The list to append.
   * @return A reference to this list.
   * @exception Exception
   */
  LinkedList<T>& append(LinkedList<T> l);

  /**
   * Append a range of elements in another list to this list.
   * @param l The list containing the elements to append.
   * @param start The start of the range to append (inclusive).
   * @param limit The limit of the range to append (exclusive).
   * @return A reference to this list.
   * @exception Exception
   */
  LinkedList<T>& append(LinkedList<T> l, 
			int start, 
			int limit) throw(Exception);

  /**
   * Append an element to this list.
   * @param data The element to append.
   * @return A reference to this list.
   * @exception Exception
   */
  LinkedList<T>& operator<< (const T& data) throw(Exception);

  /**
   * Append another list to this list.
   * @param l The list to append.
   * @return A reference to this list.
   * @exception Exception
   */
  LinkedList<T>& operator<< (LinkedList<T> l) throw(Exception);
  //@}  

  /**@name Insertion */
  //@{

  /**
   * Insert an element into the list.
   * @param pos The index of the element preceding the insertion.
   * @param data The element to insert.
   * @return A reference to this list.
   * @exception Exception
   */ 
  LinkedList<T>& insert(int pos, 
			const T& data) throw(Exception);

  /**
   * Insert another list into the list.
   * @param pos The index of the element preceding the insertion.
   * @param l The list to insert
   * @return A reference to this list.
   * @exception Exception
   */ 
  LinkedList<T>& insert(int pos, 
			LinkedList<T> l) throw(Exception);

  /**
   * Insert a range of elements from another list into the list.
   * @param pos The index of the element preceding the insertion.
   * @param l The list to insert
   * @param start The start of the range to insert (inclusive).
   * @param limit The limit of the range to insert (exclusive).
   * @return A reference to this list.
   * @exception Exception
   */ 
  LinkedList<T>& insert(int pos, 
			LinkedList<T> l, 
			int start, 
			int limit) throw(Exception);
  //@}

  /**@name Replacement */
  //@{

  /**
   * Replace an element with another element.
   * @param pos The index of the element to replace.
   * @param data The new elements.
   * @return A reference to this list.
   * @exception Exception
   */
  LinkedList<T>& replace(int pos, 
			 const T& data) throw(Exception);

  /**
   * Replace an element with another list.
   * @param pos The index of the element to replace.
   * @param l The list containing the new elements.
   * @return A reference to this list.
   * @exception Exception
   */
  LinkedList<T>& replace(int pos, 
			 LinkedList<T> l) throw(Exception);

  /**
   * Replace an element with a range of elements from another list.
   * @param pos The index of the element to replace.
   * @param l The list containing the new elements.
   * @param start The start of the range of new elements (inclusive).
   * @param limit The limit of the range of new elements (exclusive).
   * @return A reference to this list.
   * @exception Exception
   */
  LinkedList<T>& replace(int pos, 
			 LinkedList<T> l, 
			 int start, 
			 int limit) throw(Exception);

  /**
   * Replace a range of elements with an element.
   * @param start The start of the range to replace (inclusive).
   * @param limit The limit of the range to replace (exclusive).
   * @param data The new element.
   * @return A reference to this list.
   * @exception Exception
   */
  LinkedList<T>& replace(int start, 
			 int limit, 
			 const T& data) throw(Exception);

  /**
   * Replace a range of elements with another list.
   * @param start The start of the range to replace (inclusive).
   * @param limit The limit of the range to replace (exclusive).
   * @param l The list containing the new elements.
   * @return A reference to this list.
   * @exception Exception
   */
  LinkedList<T>& replace(int start, 
			 int limit, 
			 LinkedList<T> l) throw(Exception);

  /**
   * Replace a range of elements with a range of elements from another list.
   * @param start The start of the range to replace (inclusive).
   * @param limit The limit of the range to replace (exclusive).
   * @param l The list containing the new elements.
   * @param start The start of the range of new elements (inclusive).
   * @param limit The limit of the range of new elements (exclusive).
   * @return A reference to this list.
   * @exception Exception
   */
  LinkedList<T>& replace(int start, 
			 int limit, 
			 LinkedList<T> l, 
			 int start2, 
			 int limit2) throw(Exception);
  //@}

  /**@name Removal */
  //@{
  
  /**
   * Remove an element from the list.
   * @param pos The index of the element to remove.
   * @return A reference to this list.
   * @exception Exception
   */
  LinkedList<T>& erase(int pos) throw(Exception);

  /**
   * Remove a range of elements from the list.
   * @param start The start of the range to remove (inclusive).
   * @param limit The limit of the range to remove (exclusive).
   * @return A reference to this list.
   * @exception Exception
   */
  LinkedList<T>& erase(int start, int limit) throw(Exception);
  //@}


  /**@name Searching */
  //@{

  /**
   * Find all the elements in the list equal to <TT>key</TT>.
   * @param key The comparison key.
   * @param l The list to receive the found elements.
   */
  void findAll(const T& key, 
	       LinkedList<T>& l) const;

  /**
   * Find all the elements in the list satisfying a compare function.
   * @param comparator A pointer to the compare function.
   * @param data The data the pass the compare function.
   * @param l The list to receive the found elements.
   */
  void findAll(bool (*comparator)(const T& element, void *data), 
	       void *data, 
	       LinkedList<T>& l) const;
  
  /**
   * Find the first element in the list equal to <TT>key</TT>.
   * @param key The comparison key.
   * @return An Iterator representing the first matching element.
   * If no matching elements are found, the Iterator will not be valid.
   */
  Iterator find(const T& key);

  /**
   * Find the first element in the list equal to <TT>key</TT>.
   * @param key The comparison key.
   * @return A ConstIterator representing the first matching element.
   * If no matching elements are found, the ConstIterator will not be valid.
   */
  ConstIterator find(const T& key) const;

  /**
   * Find the first element in the list equal to <TT>key</TT>, starting
   * at <TT>start</TT>.
   * @param key The comparison key.
   * @param start An Iterator representing the first element to test.
   * @return An Iterator representing the first matching element.
   * If no matching elements are found, the Iterator will not be valid.
   */
  Iterator find(const T& key, 
		Iterator start);

  /**
   * Find the first element in the list equal to <TT>key</TT>, starting
   * at <TT>start</TT>.
   * @param key The comparison key.
   * @param start A ConstIterator representing the first element to test.
   * @return A ConstIterator representing the first matching element.
   * If no matching elements are found, the ConstIterator will not be valid.
   */
  ConstIterator find(const T& key, 
		     ConstIterator start) const;
  
  /**
   * Find the first element in the list satisfying a compare function.
   * @param comparator A pointer to the compare function.
   * @param data The data to pass to the compare function.
   * @return An Iterator representing the first matching element.
   * If no matching elements are found, the Iterator will not be valid.
   */
  Iterator find(bool (*comparator)(const T& element, void *data), 
		void *data);

  /**
   * Find the first element in the list satisfying a compare function,
   * starting at <TT>start</TT>.
   * @param comparator A pointer to the compare function.
   * @param data The data to pass to the compare function.
   * @param start An Iterator representing the first element to test.
   * @return An Iterator representing the first matching element.
   * If no matching elements are found, the Iterator will not be valid.
   */
  Iterator find(bool (*comparator)(const T& element, void *data), 
		void *data, 
		Iterator start);

  /**
   * Find the first element in the list satisfying a compare function.
   * @param comparator A pointer to the compare function.
   * @param data The data to pass to the compare function.
   * @return A ConstIterator representing the first matching element.
   * If no matching elements are found, the ConstIterator will not be valid.
   */
  ConstIterator find(bool (*comparator)(const T& element, void *data), 
		     void *data) const;

  /**
   * Find the first element in the list satisfying a compare function,
   * starting at <TT>start</TT>.
   * @param comparator A pointer to the compare function.
   * @param data The data to pass to the compare function.
   * @param start A ConstIterator representing the first element to test.
   * @return A ConstIterator representing the first matching element.
   * If no matching elements are found, the ConstIterator will not be valid.
   */
  ConstIterator find(bool (*comparator)(const T& element, void *data), 
		     void *data, 
		     ConstIterator start) const;
  //@}

  /**@name Miscellaneous Operations */
  //@{

  /**
   * Reverse the list in-place.
   * @return A reference to this list.
   */
  LinkedList<T>& reverse();
  
  /**
   * Remove all the elements from the list.
   * @return A reference to this list.
   */
  LinkedList<T>& deleteAll();
  
  /**
   * Create a copy of the list.
   * @param l The list which will receive the data.
   * @return A reference to <TT>l</TT>.
   * @exception Exception
   */
  LinkedList<T>& clone(LinkedList<T>& l) const throw(Exception);
  //@}

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
void
LinkedList<T>::extract(int start, 
		       int limit, 
		       LinkedList<T>& l) const throw(Exception) {
  ConstIterator iter1 = at(start);
  ConstIterator iter2 = at(limit);
  
  l.deleteAll();
  
  while(iter1 != iter2)
    l.append(*iter1++);
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
    fHead = fTail = new Node<T>(data);
    if(fHead == NULL)
      throw Exception("new failed", ERRINFO);
  }
  else {
    Node<T> *oldHead = (Node<T>*) fHead;
    oldHead->setPrevious(new Node<T>(data));
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
    fHead = fTail = new Node<T>(data);
    if(fHead == NULL)
      throw Exception("new failed", ERRINFO);
  }
  else {
    Node<T> *oldTail = (Node<T>*) fTail;
    oldTail->setNext(new Node<T>(data));
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
  Node<T> *newNode = new Node<T>(data);
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
void
LinkedList<T>::pop_front() {
  Node<T> *which = fHead;
  fHead = (Node<T>*) fHead->getNext();
  fHead->setPrevious(NULL);
  
  const T& ret = **which;
  
  delete which;
  fLength--;
}

template <class T>
void
LinkedList<T>::pop_back() {
  Node<T> *which = fTail;
  fTail = (Node<T>*) fTail->getPrevious();
  fTail->setNext(NULL);
  
  const T& ret = **which;
  
  delete which;
  fLength--;
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
void
LinkedList<T>::findAll(const T& key, LinkedList<T>& l) const {
  ConstIterator iter1 = begin();
  ConstIterator iter2 = at(length());
  
  while(iter1 != iter2) {
    if(*iter1 == key)
      l.append(*iter1++);
    else
      iter1++;
  }
}

template <class T>
void
LinkedList<T>::findAll(bool (*comparator)(const T& element, void *data), void *data, LinkedList<T>& l) const {
  ConstIterator iter1 = begin();
  ConstIterator iter2 = at(length());
  
  while(iter1 != iter2) {
    if((*comparator)(*iter1, data))
      l.append(*iter1++);
    else
      iter1++;
  }
}

template <class T>
LinkedList<T>::Iterator 
LinkedList<T>::find(const T& key) {
  return find(key, begin());
}

template <class T>
LinkedList<T>::Iterator 
LinkedList<T>::find(const T& key, Iterator start) {
  Iterator iter1 = start;
  Iterator iter2 = at(length());
  
  while(iter1 != iter2) {
    if(*iter1 == key)
      break;
    else
      iter1++;
  }

  return iter1;
}

template <class T>
LinkedList<T>::ConstIterator 
LinkedList<T>::find(const T& key) const {
  return find(key, begin());
}

template <class T>
LinkedList<T>::ConstIterator 
LinkedList<T>::find(const T& key, ConstIterator start) const {
  ConstIterator iter1 = start;
  ConstIterator iter2 = at(length());
  
  while(iter1 != iter2) {
    if(*iter1 == key)
      break;
    else
      iter1++;
  }

  return iter1;
}

template <class T>
LinkedList<T>::Iterator 
LinkedList<T>::find(bool (*comparator)(const T& element, void *data), 
		    void *data) {
  return find((*comparator), data, begin());
}

template <class T>
LinkedList<T>::Iterator 
LinkedList<T>::find(bool (*comparator)(const T& element, void *data), 
		    void *data, 
		    Iterator start) {
  Iterator iter1 = start;
  Iterator iter2 = at(length());
  
  while(iter1 != iter2) {
    if((*comparator)(*iter1, data))
      break;
    else
      iter1++;
  }

  return iter1;
}

template <class T>
LinkedList<T>::ConstIterator 
LinkedList<T>::find(bool (*comparator)(const T& element, void *data), 
		    void *data) const {
  return find((*comparator), data, begin());
}

template <class T>
LinkedList<T>::ConstIterator 
LinkedList<T>::find(bool (*comparator)(const T& element, void *data), 
		    void *data, 
		    ConstIterator start) const {
  ConstIterator iter1 = start;
  ConstIterator iter2 = at(length());
  
  while(iter1 != iter2) {
    if((*comparator)(*iter1, data))
      break;
    else
      iter1++;
  }

  return iter1;
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
