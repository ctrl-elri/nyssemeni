#include "gamestatistics.h"
#include <QDebug>

GameStatistics::GameStatistics()
{

}

void GameStatistics::initGameStatics(int players)
{
    for (; players > 0; players = players-1) {
        playerPoints_.push_back(0);
    }
}

void GameStatistics::addPoints()
{

}

void GameStatistics::checkPoints()
{

}

int GameStatistics::checkPlayerPoints(int playerNumber)
{
    qDebug() << playerPoints_.at(playerNumber);
    return playerPoints_.at(playerNumber);

}
