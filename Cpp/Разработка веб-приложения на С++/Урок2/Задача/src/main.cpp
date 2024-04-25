/* Задача:
Реализуйте игру в спички в нескольких заголовочных файлах (каждый класс или
логически связанный набор функций в отдельном файле). Напишите CMake который в
результате отработки генерирует исполняемый файл.

Игра в спички: определенное количество спичек задается в начале игры. После
этого каждый из игроков тянет от 1 до N спичек — проигрывает тот кто вытянул
последнюю спичку.
*/

#include "GameOfMatches.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

int main() {
    std::srand(std::time(nullptr));
    std::cout << "Enter the total number of matches for the game: ";
    int totalNumberOfMatches;
    std::cin >> totalNumberOfMatches;
    std::cout << "Enter the number of matches for one move: ";
    int forOneMove;
    std::cin >> forOneMove;
    std::cout << "Do you want to go first? [Y/n]: ";
    std::string answer;
    std::cin >> answer;
    bool firstMove = answer == "n"; // false -ходит первый игрок
    std::cout << "Do you want to play with me? [Y/n]: ";
    std::cin >> answer;
    bool withCompik = answer != "n"; // true - игра с компьютером

    GameOfMatches game(totalNumberOfMatches, forOneMove, firstMove, withCompik);
    game.start();
    return 0;
}
