#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
  private:
    std::string name;

  public:
    Player(std::string name);
    virtual int pull(int total, int n) = 0;
    void say(int k);
    std::string getName();
};

#endif // PLAYER_H
