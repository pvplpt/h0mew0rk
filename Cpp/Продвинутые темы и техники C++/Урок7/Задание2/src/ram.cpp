#include "ram.h"

void write(int buffer[8]) {
    for (int i = 0; i < 8; ++i) {
        memory[i] = buffer[i];
    }
}

void read(int buffer[]) {
    for (int i = 0; i < 8; ++i) {
        buffer[i] = memory[i];
    }
}