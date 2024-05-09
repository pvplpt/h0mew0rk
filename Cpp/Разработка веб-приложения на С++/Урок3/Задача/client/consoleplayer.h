#ifndef CONSOLEPLAYER_H
#define CONSOLEPLAYER_H

//----------------------------------
#include <string>
#include <optional>

#include "board.h"
#include "player.h"

//==================================
class ConsolePlayer : public IPlayer
{
    public:
        ConsolePlayer() = default;
        ConsolePlayer(const std::string& name) : m_name(name) {}
        ~ConsolePlayer() = default;

        virtual std::string name() const override;
        virtual std::optional<IBoard::PositionType> getMove(uint64_t /*timeout = -1*/) const override;

    private:
        std::string m_name;
};

#endif // CONSOLEPLAYER_H
