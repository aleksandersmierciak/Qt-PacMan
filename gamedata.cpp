#include <QFile>
#include <QString>
#include <QStringList>
#include <QTextStream>

#include "gamedata.h"

GameData::GameData(QObject *parent) :
    QObject(parent)
{
    QStringList map = (QStringList()
                       << "WWWWWWWWWWWWWWWWWWWWWWWWWWWW"
                       << "W************WW************W"
                       << "W*WWWW*WWWWW*WW*WWWWW*WWWW*W"
                       << "WOW  W*W   W*WW*W   W*W  WOW"
                       << "W*WWWW*WWWWW*WW*WWWWW*WWWW*W"
                       << "W**************************W"
                       << "W*WWWW*WW*WWWWWWWW*WW*WWWW*W"
                       << "W*WWWW*WW*WWWWWWWW*WW*WWWW*W"
                       << "W******WW****WW****WW******W"
                       << "WWWWWW*WWWWW WW WWWWW*WWWWWW"
                       << "XXXXXW*WWWWW WW WWWWW*WXXXXX"
                       << "XXXXXW*WW    M     WW*WXXXXX"
                       << "XXXXXW*WW WWWGGWWW WW*WXXXXX"
                       << "WWWWWW*WW WXXXXXXW WW*WWWWWW"
                       << "      *   WMXMXMXW   *      "
                       << "WWWWWW*WW WXXXXXXW WW*WWWWWW"
                       << "XXXXXW*WW WWWWWWWW WW*WXXXXX"
                       << "XXXXXW*WW          WW*WXXXXX"
                       << "XXXXXW*WW WWWWWWWW WW*WXXXXX"
                       << "WWWWWW*WW WWWWWWWW WW*WWWWWW"
                       << "W************WW************W"
                       << "W*WWWW*WWWWW*WW*WWWWW*WWWW*W"
                       << "W*WWWW*WWWWW*WW*WWWWW*WWWW*W"
                       << "WO**WW*******P *******WW**OW"
                       << "WWW*WW*WW*WWWWWWWW*WW*WW*WWW"
                       << "WWW*WW*WW*WWWWWWWW*WW*WW*WWW"
                       << "W******WW****WW****WW******W"
                       << "W*WWWWWWWWWW*WW*WWWWWWWWWW*W"
                       << "W*WWWWWWWWWW*WW*WWWWWWWWWW*W"
                       << "W**************************W"
                       << "WWWWWWWWWWWWWWWWWWWWWWWWWWWW");



    // Read the map file and create tiles.
    QFile mapFile(":/data/original.map");
    if (!mapFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug("Error: map file not found.");
        return;
    }

    QTextStream textStream(&mapFile);

    int i = 0;
    while (!textStream.atEnd())
    {
        if (i < GameData::rowsCount)
        {
            map[i++] = textStream.readLine().toLocal8Bit().data();
        }
    }

    mapFile.close();

    QChar current;
    for (int row = 0; row < GameData::rowsCount; ++row)
    {
        for (int column = 0; column < GameData::colsCount; ++column)
        {
            current = map[row][column];
            this->tiles << Tile::ConstructTile(this, current);
        }
    }

    // Initialize the timer to update the game time periodically.
    this->gameTimer = new QTimer(this);
    connect(this->gameTimer, SIGNAL(timeout()), this, SLOT(updateTime()));
    this->gameTimer->setInterval(1000);
}

GameData::~GameData()
{
}

int GameData::getElapsed()
{
    return this->elapsed;
}

void GameData::setElapsed(const int elapsed)
{
    this->elapsed = elapsed;
}

bool GameData::getGameOn()
{
    return this->gameOn;
}

void GameData::setGameOn(bool gameOn)
{
    this->gameOn = gameOn;
}

QDeclarativeListProperty<Tile> GameData::getTiles()
{
    return QDeclarativeListProperty<Tile>(this, tiles);
}

void GameData::resetGame()
{
    this->setElapsed(0);
    this->setGameOn(true);
}

void GameData::pauseGame(bool state)
{
    this->gameOn = state;
}

void GameData::updateTime()
{
    if (this->gameOn)
    {
        ++this->elapsed;
        emit elapsedChanged();
    }
}

void GameData::gameWon()
{

}

void GameData::gameLost()
{

}

const int GameData::getColsCount()
{
    return GameData::colsCount;
}

const int GameData::getRowsCount()
{
    return GameData::rowsCount;
}


