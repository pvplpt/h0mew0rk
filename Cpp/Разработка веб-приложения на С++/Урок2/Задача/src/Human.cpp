#include "Human.h"
#include <iostream>
#include <string>

Human::Human(std::string name_) : Player(name_) {}

int Human::pull(int total, int n) {
    int takenMatches;
    do {
        std::cout << getName() << ", how many matches will you take (from 1 to "
                  << n << ")? ";
        std::cin >> takenMatches;
    } while (takenMatches <= 0 || takenMatches > n || takenMatches > total);
    return takenMatches;
}