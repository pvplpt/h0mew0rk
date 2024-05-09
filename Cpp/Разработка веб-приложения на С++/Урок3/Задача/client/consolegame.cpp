//--------------------------------
#include "consoleplayer.h"
#include "simpleboard.h"
#include <iostream>
#include <string>

#include "consolegame.h"

//================================
ConsoleGame::ConsoleGame(const std::string &name,
                         IBoard *board /*other parameters*/)
    : m_name(name) {
    setup(board);
}

bool ConsoleGame::setup(IBoard *board) {
    if (m_players.empty())
        m_board.reset(board);
    return true;
}

bool ConsoleGame::waitForPlayers(uint64_t /*timeout*/) {
    while (m_players.size() < 2) {
        std::cout << "Enter name of players "
                  << std::to_string(m_players.size() + 1) << std::endl;

        std::string name;
        std::cin >> name;
        if (name.empty())
            continue;

        m_players.emplace_back(new ConsolePlayer(name));
    }

    return true;
}

void ConsoleGame::renderBoard() const {
    auto dimension = m_board->dimention();
    const auto &xmin = dimension.first.x;
    const auto &ymin = dimension.first.y;
    const auto &xmax = dimension.second.x;
    const auto &ymax = dimension.second.y;

    IBoard::PositionType pos;
    for (auto y = ymin; y < ymax; y++) {
        pos.y = y;
        for (auto x = xmin; x < xmax; x++) {
            pos.x = x;
            auto mark = m_board->mark(pos);
            std::string outSymbol = "_";
            switch (mark) {
            case IBoard::MARK_O:
                outSymbol = "O";
                break;
            case IBoard::MARK_X:
                outSymbol = "X";
                break;
            default:
                break;
            }
            std::cout << "|" << outSymbol << "|";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int ConsoleGame::calculateVictory() {
    auto dimension = m_board->dimention();
    const auto &xmin = dimension.first.x;
    const auto &ymin = dimension.first.y;
    const auto &xmax = dimension.second.x;
    const auto &ymax = dimension.second.y;
    std::string line_win[xmax + ymax + 2];
    std::string xline;
    std::string oline;
    IBoard::PositionType pos;
    for (auto y = ymin; y < ymax; y++) {
        pos.y = y;
        char outSymbol = '_';
        for (auto x = xmin; x < xmax; x++) {
            pos.x = x;
            auto mark = m_board->mark(pos);
            outSymbol = '_';
            switch (mark) {
            case IBoard::MARK_O:
                outSymbol = 'O';
                break;
            case IBoard::MARK_X:
                outSymbol = 'X';
                break;
            default:
                break;
            }
            line_win[y] += outSymbol;
            if (y == x) {
                line_win[xmax + ymax] += outSymbol;
            }
            if (y == xmax - 1 - x) {
                line_win[xmax + ymax + 1] = outSymbol;
            }
        }
        xline += "X";
        oline += "O";
    }
    for (auto x = xmin; x < xmax; ++x) {
        pos.x = x;
        char outSymbol = '_';
        for (auto y = ymin; y < ymax; ++y) {
            pos.y = y;
            auto mark = m_board->mark(pos);
            outSymbol = '_';
            switch (mark) {
            case IBoard::MARK_O:
                outSymbol = 'O';
                break;
            case IBoard::MARK_X:
                outSymbol = 'X';
                break;
            default:
                break;
            }
            line_win[xmax + x] += outSymbol;
        }
    }

    bool isWinner = false;
    for (auto i = 0; i < xmax + ymax + 2; ++i) {
        if (line_win[i] == xline || line_win[i] == oline) {
            isWinner = true;
            break;
        }
    }
    return isWinner; // rand()%2;
}

int ConsoleGame::exec(/*add parameters*/) {
    int iplayer = 0;
    while (true) {
        renderBoard();
        auto &player = m_players[iplayer];
        bool moveAssepted = false;
        while (!moveAssepted) {
            auto move = player->getMove();
            if (!move)
                return -1;

            auto currentMark = m_board->mark(move.value());
            if (currentMark == IBoard::MARK_EMPTY)
                moveAssepted = m_board->setMark(move.value(),
                                                iplayer == 0 ? IBoard::MARK_X
                                                             : IBoard::MARK_O);
        }
        // calculate wictory function
        if (calculateVictory() > 0) {
            std::cout << "player " << std::to_string(iplayer + 1)
                      << " win! Congratulations!" << std::endl;
            return iplayer;
        }

        iplayer = (iplayer + 1) % 2;
    }
    return -1;
}

//[7]
