#include "Dog.h"
#include <iostream>
#include <string>

Dog::Dog() : name("Dog"), age(0) {}

Dog::Dog(std::string name_) : name(name_), age(0) {}

Dog::Dog(int age_, std::string name_) : name(name_), age(0) {
    if (age_ > 30 || age_ < 0) {
        std::cout << "Incorrect age" << std::endl;
    } else {
        age = age_;
    }
}

void Dog::setAge(int age_) {
    if (age_ > 30 || age_ < 0) {
        std::cout << "Incorrect age" << std::endl;
    } else {
        age = age_;
    }
}

int Dog::getAge() { return age; }

void Dog::barkAge() {
    for (int i = 0; i < age; ++i) {
        std::cout << "Bark! ";
    }
    std::cout << std::endl;
}

void Dog::show_talents() {
    if (talents.empty()) {
        std::cout << "This is " << name << " and it has no talent."
                  << std::endl;
    } else {
        std::cout << "This is " << name
                  << " and it has some talents:" << std::endl;
        for (auto talent : talents) {
            talent->show_talent();
        }
    }
}

void Dog::addTalent(Talent *talent) { talents.push_back(talent); }