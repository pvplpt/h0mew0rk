#pragma once
#include <string>

struct point {
    double x;
    double y;
};

void inputPoint(std::string msg, point &p);

void outputPoint(point &p);

bool equalityPoint(point &p1, point &p2);
