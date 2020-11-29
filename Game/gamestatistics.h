#ifndef GAMESTATISTICS_H
#define GAMESTATISTICS_H

#include <vector>

class GameStatistics
{
public:
    GameStatistics();

    void initGameStatics(int players);
    void addPoints();
    void checkPoints();
    int checkPlayerPoints(int playerNumber);

private:
    int point = 1;
    int max_points = 5;
    std::vector<int> playerPoints_;
};

#endif // GAMESTATISTICS_H
