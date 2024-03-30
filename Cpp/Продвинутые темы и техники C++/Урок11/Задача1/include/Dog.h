#ifndef DOG_H
#define DOG_H

#include "Talent.h"
#include <string>
#include <vector>

class Dog {
  private:
    std::string name;
    int age;
    std::vector<Talent *> talents;

  public:
    Dog();
    Dog(std::string name);
    Dog(int age_, std::string name);
    void setAge(int age_);
    int getAge();
    void barkAge();
    void addTalent(Talent *talent);
    void show_talents();
};

#endif // DOG_H
