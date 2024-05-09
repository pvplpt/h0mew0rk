//-----------------------------------------
#include "gamemanager.h"

#include <string>
#include <iostream>

#include "game.h"

#include "simpleboard.h"
#include "consoleplayer.h"
#include "consolegame.h"

//============================================
IGame* GameManager::createGame(const std::string& name) const
{
    IGame* game = nullptr;
    if(name == "console_game")
    {
        IBoard* board = new SimpleBoard<3>();
        game = static_cast<IGame*>(new ConsoleGame("console_game", board));
    }

    return game;
}
