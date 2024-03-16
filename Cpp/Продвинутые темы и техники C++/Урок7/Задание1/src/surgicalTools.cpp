#include "surgicalTools.h"
#include <iostream>

void scalpel(point &p1, point &p2) {
    std::cout << "\nРазрез между точками: ";
    outputPoint(p1);
    std::cout << " и ";
    outputPoint(p2);
    std::cout << std::endl;
}

void hemostat(point &p1) {
    std::cout << "\nЗажим в точке: ";
    outputPoint(p1);
    std::cout << std::endl;
}

void tweezers(point &p1) {
    std::cout << "\nПинцет в точке: ";
    outputPoint(p1);
    std::cout << std::endl;
}

void suture(point &p1, point &p2) {
    std::cout << "\nШов между точками: ";
    outputPoint(p1);
    std::cout << " и ";
    outputPoint(p2);
    std::cout << std::endl;
}