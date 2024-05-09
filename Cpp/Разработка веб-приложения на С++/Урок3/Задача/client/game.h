#ifndef GAME_H
#define GAME_H

//--------------------------------
#include <string>

#include "board.h"

//===============================
class IGame
{
    public:
    virtual ~IGame() = default;
    virtual std::string name() const {return "";}
    virtual bool setup(IBoard* board) = 0;
    virtual bool waitForPlayers(uint64_t timeout) = 0;
    virtual int  exec(/*add parameters*/) = 0;
};

#endif // GAME_H
