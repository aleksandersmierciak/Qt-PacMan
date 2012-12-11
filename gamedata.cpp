#include <QFile>
#include <QTextStream>

#include "gamedata.h"

GameData::GameData(QObject *parent) :
    QObject(parent)
{
    // Open the map file and initialize a QTextStream object.
    QFile mapFile(":/data/original.map");
    if (!mapFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        // TODO: implement notifying the user of missing data.
        qDebug("Error: map file not found.");
        return;
    }

    QTextStream textStream(&mapFile);

    // Read the data until the end of file, omitting ASCII control characters.
    char current;
    while (!textStream.atEnd())
    {
        textStream >> current;
        if (current > 31)
        {
            this->tiles << Tile::ConstructTile(this, current);
        }
    }

    mapFile.close();

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
