#include "gamestatistics.h"
#include <QDebug>

GameStatistics::GameStatistics()
{

}

void GameStatistics::initGameStatictics(int players)
{
    for (; players > 0; players = players-1) {
        playerPoints_.push_back(0);
    }
}

void GameStatistics::addPoints(int playerNumber, float points)
{
    float currentPoints = playerPoints_.at(playerNumber);

    float newPoints = currentPoints + points;
    playerPoints_.at(playerNumber) = newPoints;

}

bool GameStatistics::checkIfWon(int playerNumber)
{
    if ( playerPoints_.at(playerNumber) >= max_points_ ) {
        return true;
    }
    else {
        return false;
    }
}

float GameStatistics::checkPlayerPoints(int playerNumber)
{
    return playerPoints_.at(playerNumber);

}
