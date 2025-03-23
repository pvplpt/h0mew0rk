#include "Player.h"
#include <iostream>
#include <cctype>

Player::Player() {}

Player::Player(char gamerName_) : gamerName(gamerName_) {}

char Player::getGamerName() { return gamerName; }

int Player::getMove() {
    std::cout << "Куда поставить " << gamerName << "\n";
    bool badDigit = true;
    char digit;
    do {
        std::cout << "Введите число от 1 до 9: ";
        std::string number;
        std::cin >> number;
        digit = number[0];
        if (std::isdigit(digit)) {
            badDigit = false;
        }else{
            std::cout << "\nОшибка ввода числа от 1 до 9.\n";
        }
    } while (badDigit);
    return digit - '0';
}