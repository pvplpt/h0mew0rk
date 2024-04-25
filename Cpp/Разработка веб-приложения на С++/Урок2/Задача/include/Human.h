#ifndef HUMAN_H
#define HUMAN_H

#include "Player.h"
#include <string>

class Human : public Player {

  public:
    Human(std::string name);
    int pull(int total, int n);
};

#endif // HUMAN_H