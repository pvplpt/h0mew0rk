#include "point.h"
#include <iostream>
#include <string>

void inputPoint(std::string msg, point &p) {
    std::cout << msg;
    std::cin >> p.x >> p.y;
}

void outputPoint(point &p) { std::cout << "(" << p.x << ", " << p.y << ")"; }

bool equalityPoint(point &p1, point &p2) {
    return ((p1.x == p2.x) && (p1.y == p2.y));
}
