#ifndef BOARD_H
#define BOARD_H

class Board
{
private:
    char cells[3][3];
    bool places[3][3];
    int freeCells = 9;

public:
    Board();
    void printCells();
    void helpCells();
    bool setCell(int move, char gamerName);
    bool isFull();
    bool checkWin(char gamerName);
};

#endif // BOARD_H