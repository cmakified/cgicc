/*
 * $Id: MStreamable.cc,v 1.2 1998/10/05 22:25:05 sbooth Exp $
 *
 * (C) Copyright Stephen F. Booth, 1996, 1997, 1998.  All Rights Reserved.
 */

#include "MStreamable.hh"

// ============================================================
// Class MStreamable
// ============================================================
ostream& 
operator<<(ostream& out, const MStreamable& obj) {
  obj.render(out);
  return out; 
}
