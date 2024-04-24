#include "Computer.h"
#include <cstdlib>

#include <string>

Computer::Computer(std::string name_) : Player(name_) {}

int Computer::pull(int total, int n) {
    int takenMatches = (total - 1) % (n + 1);
    if (takenMatches != 0) {
        return takenMatches;
    }
    return std::rand() % n + 1;
}
