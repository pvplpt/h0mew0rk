#ifndef GAMEOFMATCHES_H
#define GAMEOFMATCHES_H

#include "Player.h"

class GameOfMatches {
  private:
    int total = 14;
    int n = 3;
    bool currentMove = false;
    bool gameWithComputer = false;
    Player *players[2];
    void init();
    bool gameEndCheck();

  public:
    GameOfMatches();
    GameOfMatches(int total_, int n_, bool currentMove_,
                  bool gameWithComputer_);
    ~GameOfMatches();
    void start();
};

#endif // GAMEOFMATCHES_H