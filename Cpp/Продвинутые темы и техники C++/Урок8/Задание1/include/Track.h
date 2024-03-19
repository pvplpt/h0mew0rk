#ifndef TRACK_H
#define TRACK_H

#include <ctime>
#include <string>

class Track {
    std::string name;
    std::tm dateCreation;
    int duration;

  public:
    Track(std::string inName, std::tm inDateCreation, int inDuration);
    std::string getName();
    std::tm getDateCreation();
    int getDuration();
    void printInfoTrack(); // вывод в консоль информации о треке
};

#endif // TRACK_H
