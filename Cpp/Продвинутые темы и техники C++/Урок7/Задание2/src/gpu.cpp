#include "gpu.h"
#include "ram.h"
#include <iostream>

void display() {
    int buf[8];
    read(buf);
    for (int i = 0; i < 8; ++i) {
        std::cout << buf[i] << " ";
    }
    std::cout << std::endl;
}