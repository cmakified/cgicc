#include "MStreamable.hh"

// ============================================================
// Class MStreamable
// ============================================================
ostream& 
operator<<(ostream& out, const MStreamable& obj) {
  obj.render(out);
  return out; 
}
