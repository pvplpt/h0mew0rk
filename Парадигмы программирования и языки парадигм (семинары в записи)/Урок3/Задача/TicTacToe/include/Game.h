#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Board.h"

class Game
{
private:
    Player players[2];
    Board board;
    bool currentMove = false;
public:
    Game();
    void start();
};

#endif // GAME_H