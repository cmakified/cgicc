/* $Id: MStreamable.hh,v 1.1 1998/04/01 20:46:54 sbooth Exp $ */

#ifndef __MSTREAMABLE__
#define __MSTREAMABLE__ 1

#include <iostream.h>

// ============================================================
// Class MStreamable
// ============================================================
/** 
 * Abstract mix-in class which makes classes streamable via
 * the << operator.
 * Written in the spirit of a Java interface.
 */
class MStreamable {
  
  friend ostream& operator<<(ostream& out, 
			     const MStreamable& obj);
  
public:
  /**
   * Write this object to a stream.  Subclasses must implement this function.
   * @param out The ostream to which to write.
   */
  virtual void render(ostream& out) const = 0;
};

#endif
