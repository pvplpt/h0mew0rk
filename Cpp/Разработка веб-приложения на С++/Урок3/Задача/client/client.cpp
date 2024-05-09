//----------------------------------------------
#include <iostream>
#include <optional>
#include <string>
#include <utility>
#include <vector>

#include "board.h"
#include "game.h"
#include "player.h"

#include "gamemanager.h"
#include <memory>

//[5]============================================================================
int main(int argv, char *argc[]) {
    GameManager gameManager;
    while (true) {
        std::unique_ptr<IGame> game;
        std::cout << "Create local game?" << std::endl;
        std::cout << "1. Yes" << std::endl;
        std::cout << "2. No" << std::endl;

        int answer = 0;
        std::cin >> answer;
        switch (answer) {
        case 1: {
            std::cout << "Creating game" << std::endl;
            game.reset(gameManager.createGame("console_game"));
        } break;
        case 2:
            return 0; // exit program
        default:
            break;
        }

        if (game) {
            std::cout << "Game created" << std::endl;
            if (game->waitForPlayers(30000))
                game->exec();
        } else
            std::cout << "Game NOT created" << std::endl;
    }
    return 0;
}

//[6]================================================================
