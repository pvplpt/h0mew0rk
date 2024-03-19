#include "AudioPlayer.h"
#include "Track.h"
#include <iostream>
#include <vector>

AudioPlayer::AudioPlayer(std::vector<Track> pl) {
    for (int i = 0; i < pl.size(); ++i) {
        playList.push_back(pl[i]);
    }
    numberOfTrack = playList.size();
}

bool AudioPlayer::getIsPlay() { return isPlay; }

bool AudioPlayer::getIsPause() { return isPause; }

bool AudioPlayer::selectTrack(std::string name) {
    for (int i = 0; i < numberOfTrack; ++i) {
        if (playList[i].getName() == name) {
            numberTrack = i;
            return true;
        }
    }
    return false;
}

void AudioPlayer::play() {
    if (!isPlay) {
        isPlay = true;
        isPause = false;
        std::cout << "\nВоспроизводится запись:\n";
        playList[numberTrack].printInfoTrack();
    }
}

void AudioPlayer::nextTrack() {
    stopPlay();
    numberTrack = std::rand() % numberOfTrack;
    play();
}

void AudioPlayer::stopPlay() {
    if (isPlay || isPause) {
        isPlay = false;
        isPause = false;
        std::cout << "\nОстановлена запись:\n";
        playList[numberTrack].printInfoTrack();
    }
}

void AudioPlayer::pausePlay() {
    if ((!isPause) && isPlay) {
        isPause = true;
        isPlay = false;
        std::cout << "\nНа паузе запись:\n";
        playList[numberTrack].printInfoTrack();
    }
}
