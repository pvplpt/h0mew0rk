#ifndef DANCING_H
#define DANCING_H

#include "Talent.h"

class Dancing : virtual public Talent {
  public:
    Dancing();
    virtual void show_talent();
};

#endif // DANCING_H