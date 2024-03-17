#include "kbd.h"
#include "ram.h"
#include <iostream>

void input() {
    int buf[8];
    for (int i = 0; i < 8; ++i) {
        std::cout << "Введите " << i + 1 << "-е число: ";
        std::cin >> buf[i];
    }
    write(buf);
}