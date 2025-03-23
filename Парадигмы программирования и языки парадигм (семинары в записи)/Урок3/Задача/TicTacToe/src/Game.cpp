
#include <iostream>
#include "Player.h"
#include "Board.h"
#include "Game.h"

Game::Game() {
    players[0] = Player('X');
    players[1] = Player('0');
}

void Game::start() {
    board.helpCells();
    bool battleContinues = true;
    while (battleContinues)
    {
        char gamerName = players[currentMove].getGamerName();
        bool badMove = true;
        do
        {
            int move = players[currentMove].getMove();

            if (board.setCell(move, gamerName)) {
                badMove = false;
            }else{
                std::cout << "\nКлетка занята!\n";
                board.printCells();
                board.helpCells();
            }
        } while (badMove);

        board.printCells();

        if (board.checkWin(gamerName)){
            if (gamerName == 'X'){
                std::cout << "Крестики выиграли!\n";
            }else{
                std::cout << "Нолики выиграли!\n";
            }
            battleContinues = false;
        }else{
            if (board.isFull()){
                std::cout << "Поздравляю с ничьей!\n";
                battleContinues = false;
            }
        }

        currentMove = !currentMove;
    }
}
