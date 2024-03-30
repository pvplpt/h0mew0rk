#ifndef SWIMMING_H
#define SWIMMING_H

#include "Talent.h"

class Swimming : virtual public Talent {
  public:
    Swimming();
    virtual void show_talent();
};

#endif // SWIMMING_H