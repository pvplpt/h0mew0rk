#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
    char gamerName;

public:
    Player();
    Player(char gamerName_);
    char getGamerName();
    int getMove();
};

#endif // PLAYER_H