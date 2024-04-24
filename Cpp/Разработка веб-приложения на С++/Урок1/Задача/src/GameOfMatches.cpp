#include "GameOfMatches.h"
#include "Computer.h"
#include "Human.h"
#include <iostream>
#include <string>

GameOfMatches::GameOfMatches() {}
GameOfMatches::GameOfMatches(int total_, int n_, bool currentMove_,
                             bool gameWithComputer_)
    : total(total_), n(n_), currentMove(currentMove_),
      gameWithComputer(gameWithComputer_) {}

void GameOfMatches::init() {
    std::string yourName;
    std::cout << "Enter your name: ";
    std::cin >> yourName;
    players[0] = new Human(yourName);
    if (gameWithComputer) {
        players[1] = new Computer("Compik");
    } else {
        std::cout << "Enter the name of the second player:";
        std::cin >> yourName;
        players[1] = new Human(yourName);
    }
}

bool GameOfMatches::gameEndCheck() {
    bool gameOver = total < 2;
    if (gameOver) {
        std::string winnerName = total == 1 ? players[currentMove]->getName()
                                            : players[!currentMove]->getName();
        std::cout << "\nWon: " << winnerName << std::endl;
    }
    return gameOver;
}

void GameOfMatches::start() {
    init();
    std::cout
        << "There are " << total
        << " matches in total. The one who drew the last match will lose.\n";
    int matches;
    while (true) {
        matches = players[currentMove]->pull(total, n);
        players[currentMove]->say(matches);
        total -= matches;
        std::cout << std::endl << total << " matches left\n";
        if (gameEndCheck()) {
            break;
        }
        currentMove = !currentMove;
    }
}

GameOfMatches::~GameOfMatches() {
    delete players[0];
    delete players[1];
}
