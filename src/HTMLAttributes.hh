/* $Id: HTMLAttributes.hh,v 1.1 1998/04/01 20:49:02 sbooth Exp $ */

#ifndef __HTML_ATTRIBUTES__
#define __HTML_ATTRIBUTES__ 1

#ifndef __EXCEPTION__
#include "Exception.hh"
#endif

#ifndef __MSTREAMABLE__
#include "MStreamable.hh"
#endif

#ifndef __LINKED_LIST__
#include "LinkedList.hh"
#endif

#include <iostream.h>

// ============================================================
// Class HTMLAttribute
// ============================================================
/**
 * An HTMLAttribute represents a single name/value pair inside an HTML tag.
 * For example, in the HTML code:
 * <PRE class="html">&lt;A HREF="mailto:sbooth@hmc.edu">Send mail&lt;/A></PRE>
 * The name/value pair <TT>(HREF, mailto:sbooth@hmc.edu)</TT>
 * is an HTMLAttribute.
 */
class HTMLAttribute : public MStreamable {
public:
  /**@name Constructors */
  //@{
  
  /** Create an empty HTMLAttribute. */
  HTMLAttribute();
  
  /**
   * Create an HTMLAttribute with the given name and value.
   * @param name The attribute's name, for example <TT>HREF</TT>.
   * @param value The attributes's alue, for exampe <TT>foo.html</TT>.
   * @exception Exception
   */
  HTMLAttribute(const char *name, 
		const char *value) throw(Exception);

  /**
   * Copy constructor.
   * @param attribute The HTMLAttribute to copy.
   */
  HTMLAttribute(const HTMLAttribute& attribute);
  
  /* Destructor */
  virtual ~HTMLAttribute();
  //@}

  bool operator== (const HTMLAttribute& att) const {
    return (getName() == att.getName());
  }
  
  /**@name Accessor Methods */
  //@{
  
  /**
   * Get the name of this HTMLAttribute.
   * @return The attribute's name.
   */
  inline const char* getName() const 	{ return fName; }
  
  /**
   * Get the value of this HTMLAttribute.
   * @return The attribute's value.
   */
  inline const char* getValue() const 	{ return fValue; }
  //@}
  
  /**@name Mutator Methods */
  //@{
  
  /**
   * Set the name of this HTMLAttribute.
   * @param name The new name of the attribute.
   * @exception Exception
   */
  void setName(const char *name) throw (Exception);
  
  /**
   * Set the value of this HTMLAttribute.
   * @param value The new value of the attribute.
   * @exception Exception
   */
  void setValue(const char *value) throw (Exception);
  //@}
  
  /* Render this attribute */
  virtual void render(ostream& out) const;
  
private:
  char *fName;
  char *fValue;
};

// ============================================================
// Class HTMLAtomicAttribute
// ============================================================
/**
 * An HTMLAtomicAttribute represents a special instance of HTMLAttribute.
 * For example, in the HTML code:
 * <PRE CLASS="html">&lt;IMG SRC="foo.jpg" ISMAP&gt;</PRE>
 * The keyword <EM>ISMAP</EM> is an HTMLAtomicAttribute.
 */
class HTMLAtomicAttribute : public HTMLAttribute {
public:
  /**@name Constructors */
  //@{
  
  /** Create an empty HTMLAtomicAttribute. */
  HTMLAtomicAttribute();
  
  /**
   * Create an HTMLAtomicAttribute with the given name.
   * @param name The name of the attribute.
   * @exception Exception
   */	
  HTMLAtomicAttribute(const char *name) throw(Exception);

  /**
   * Copy constructor.
   * @param attribute The HTMLAtomicAttribute to copy.
   */
  HTMLAtomicAttribute(const HTMLAtomicAttribute& attribute);

  /* Destructor */
  virtual ~HTMLAtomicAttribute();
  //@}
  
  /* Render this attribute */
  virtual void render(ostream& out) const;
};

// ============================================================
// Class HTMLAttributeList
// ============================================================
/**
 * An HTMLAttributeList represents any number of HTMLAttributes inside an 
 * HTMLElement.
 * @see HTMLAttribute
 * @see HTMLAtomicAttribute
 */
class HTMLAttributeList : public LinkedList<HTMLAttribute> {
public:

  /**@name Constructor */
  //@{

  /**
   * Create an empty HTMLAttributeList.
   */
  HTMLAttributeList();

  /**
   * Create a new HTMLAttributeList, specifying the first element.
   * @param head The first element of the list
   */
  HTMLAttributeList(const HTMLAttribute& head);

  /**
   * Copy constructor.
   * @param list The HTMLAttributeList to copy.
   */
  HTMLAttributeList(const HTMLAttributeList& list);

  /* Destructor */
  virtual ~HTMLAttributeList();
  //@}

  /**@name List Addition */
  //@{
  
  /** 
   * Add an HTMLAttribute name/value pair to the list.
   * @param name The name of the HTMLAttribute to add.
   * @param value The value of the HTMLAttribute to add.
   * If NULL, an HTMLAtomicAttribute will be added.
   * @return A reference to the list.
   * @exception Exception
   */
  HTMLAttributeList& add(const char *name, 
			 const char *value = NULL) throw(Exception);
  
  //@}
};

// ============================================================
// List manipulators
// ============================================================
/**
 * Create a new HTMLAttributeList, and add an HTMLAttribute to it.
 * <P>This function is usually called from within the constructor of an
 * \Ref{HTMLElement}:
 * <PRE class="code">
 * out << a("link text", add("href","http://www.foo.com")) << endl;
 * </PRE></P>
 * @param name The name of the HTMLAttribute to add.
 * @param value The value of the HTMLAttribute to add.
 * If NULL, an HTMLAtomicAttribute will be added.
 * @return A reference to the list.
 * @exception Exception
 */
HTMLAttributeList add(const char *name, 
		      const char *value = NULL) throw(Exception);

#endif
