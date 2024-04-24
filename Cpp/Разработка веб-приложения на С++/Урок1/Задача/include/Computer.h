#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"
#include <string>

class Computer : public Player {

  public:
    Computer(std::string name);
    int pull(int total, int n);
};

#endif // COMPUTER_H