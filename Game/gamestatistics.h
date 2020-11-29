#ifndef GAMESTATISTICS_H
#define GAMESTATISTICS_H


class GameStatistics
{
public:
    GameStatistics();

    void addPoints();
    void checkPoints();

private:
    int point = 1;
    int max_points = 5;
    int player1_points_ = 0;
    int player2_points_ = 0;
    int player3_points_ = 0;
    int player4_points_ = 0;
};

#endif // GAMESTATISTICS_H
