#include "cpu.h"
#include "ram.h"
#include <iostream>

void compute() {
    int buf[8];
    read(buf);
    int total;
    for (int i = 0; i < 8; ++i) {
        total += buf[i];
    }
    std::cout << "\nСумма чисел в оперативной памяти: " << total << std::endl;
}