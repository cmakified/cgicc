/*
 * $Id: MStreamable.hh,v 1.2 1998/10/05 22:21:05 sbooth Exp $
 *
 * (C) Copyright Stephen F. Booth, 1996, 1997, 1998.  All Rights Reserved.
 */

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
