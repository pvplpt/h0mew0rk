
#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include "Track.h"
#include <vector>

class AudioPlayer {
    bool isPlay = false;         // трек воспроизводится
    bool isPause = false;        // трек на паузе
    std::vector<Track> playList; // список треков
    int numberOfTrack = 0; // количество треков в плеере
    int numberTrack = 0; // номер трека на воспроизведение

  public:
    AudioPlayer(std::vector<Track> pl);
    bool getIsPlay();
    bool getIsPause();
    bool selectTrack(std::string name); // поиск и выбор трека по имени
    void play();
    void nextTrack();
    void stopPlay();
    void pausePlay();
};

#endif // AUDIOPLAYER_H
