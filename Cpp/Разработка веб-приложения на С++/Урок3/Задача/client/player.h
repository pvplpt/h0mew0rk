#ifndef PLAYER_H
#define PLAYER_H

//===================================
#include <string>
#include <optional>

#include "board.h"

//===================================
class IPlayer
{
    public:
        IPlayer() = default;
        virtual ~IPlayer() = default;
        virtual std::string name() const = 0;
        virtual std::optional<IBoard::PositionType> getMove(uint64_t timeout = -1) const = 0;
};


#endif // PLAYER_H
