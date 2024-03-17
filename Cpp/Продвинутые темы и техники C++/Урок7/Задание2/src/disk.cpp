#include "disk.h"
#include "ram.h"
#include <fstream>

void save() {
    int buf[8];
    read(buf);
    std::ofstream fileData("data.txt");
    for (int i = 0; i < 8; ++i) {
        fileData << buf[i] << " ";
    }
}

bool load() {
    int buf[8];
    std::ifstream fileData;
    fileData.open("data.txt");
    bool result = false;
    if (fileData) {
        for (int i = 0; i < 8; ++i) {
            fileData >> buf[i];
        }
        write(buf);
        result = true;
    }
    return result;
}