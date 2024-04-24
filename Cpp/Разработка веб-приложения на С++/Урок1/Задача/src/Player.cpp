#include "Player.h"
#include <iostream>
#include <string>

Player::Player(std::string name_) : name(name_) {}

void Player::say(int k) { std::cout << name << " took " << k << " matches.\n"; }
std::string Player::getName() { return name; }