#include "Board.h"
#include <iostream>

Board::Board() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cells[i][j] = ' ';
            places[i][j] = false;
        }
    }
}

void Board::printCells(){
    std::cout << std::endl;
    std::cout << " " << cells[0][0] << " | " << cells[0][1] << " | " << cells[0][2] << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << " " << cells[1][0] << " | " << cells[1][1] << " | " << cells[1][2] << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << " " << cells[2][0] << " | " << cells[2][1] << " | " << cells[2][2] << std::endl;
}

void Board::helpCells() {
    std::cout << "Позсказка по игровому полю:\n";
    std::cout << " 1 | 2 | 3 \n"
              << "-----------\n"
              << " 4 | 5 | 6 \n"
              << "-----------\n"
              << " 7 | 8 | 9 \n";
}

bool Board::setCell(int move, char gamerName) {
    if (move >= 1 && move <= 9) {
        int x = (move - 1) / 3;
        int y = (move - 1) % 3;
        if (places[x][y]) {
            return false;
        }else{
            places[x][y] = true;
            cells[x][y] = gamerName;
            --freeCells;
        }
    }else{
        return false;
    }
    return true;
}

bool Board::isFull() {
    return (freeCells == 0);
}

bool Board::checkWin(char gamerName) {
    for (int i = 0; i < 3; ++i) {
        int countRow = 0;
        int countCol = 0;
        for (int j = 0; j < 3; ++j) {
            countRow += (cells[i][j] == gamerName);
            countCol += (cells[j][i] == gamerName);
        }
        if (countRow == 3 || countCol == 3) {
            return true;
        }
    }
    // Проверим диагонали
    if ((cells[0][0] == gamerName) && (cells[1][1] == gamerName) && (cells[2][2] == gamerName)) {
        return true;
    }
    if ((cells[0][2] == gamerName) && (cells[1][1] == gamerName) && (cells[2][0] == gamerName)) {
        return true;
    }
    return false;
}
