#ifndef GAMESTATISTICS_H
#define GAMESTATISTICS_H

#include <vector>

class GameStatistics
{
public:
    GameStatistics();

    void initGameStatics(int players);
    void addPoints(int playerNumber, float points);
    bool checkIfWon(int playerNumber);
    float checkPlayerPoints(int playerNumber);

private:
    float max_points_ = 20;
    std::vector<float> playerPoints_;
};

#endif // GAMESTATISTICS_H
