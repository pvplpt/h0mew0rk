#ifndef COUNTING_H
#define COUNTING_H

#include "Talent.h"

class Counting : virtual public Talent {
  public:
    Counting();
    virtual void show_talent();
};

#endif // COUNTING_H