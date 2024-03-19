#include "Track.h"
#include <ctime>
#include <iostream>
#include <string>

Track::Track(std::string inName, std::tm inDateCreation, int inDuration) {
    this->name = inName;
    this->dateCreation = inDateCreation;
    this->duration = inDuration;
}
std::string Track::getName() { return this->name; }
std::tm Track::getDateCreation() { return this->dateCreation; }
int Track::getDuration() { return this->duration; }

void Track::printInfoTrack() {
    std::cout << "Название:" << name << std::endl;
    std::cout << "Дата создания: " << std::asctime(&dateCreation);
    std::cout << "Продолжительность в секундах: " << duration << std::endl;
}
