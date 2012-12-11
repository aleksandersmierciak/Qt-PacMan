#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <fstream>
#include <QObject>
#include <QString>
#include <QList>
#include <QStack>
#include <QTime>
#include <QTimer>
#include <QDeclarativeListProperty>
#include "tile.h"

class GameData : public QObject
{
    Q_OBJECT

public:
    explicit GameData(QObject *parent = 0);
    ~GameData();

    Q_PROPERTY(int colsCount READ getColsCount CONSTANT)
    static const int getColsCount();

    /// Number of columns of tiles on the game board.
    static const int colsCount = 28;

    Q_PROPERTY(int rowsCount READ getRowsCount CONSTANT)
    static const int getRowsCount();

    /// Number of rows of tiles on the game board.
    static const int rowsCount = 31;

    Q_PROPERTY(int elapsed READ getElapsed WRITE setElapsed NOTIFY elapsedChanged)
    int getElapsed();
    void setElapsed(const int );

    Q_PROPERTY(bool gameOn READ getGameOn WRITE setGameOn NOTIFY gameOnChanged)
    bool getGameOn();
    void setGameOn(bool );

    Q_PROPERTY(QDeclarativeListProperty<Tile> tiles READ getTiles CONSTANT)
    QDeclarativeListProperty<Tile> getTiles();

signals:
    void elapsedChanged();
    void gameOnChanged();

public slots:
    void resetGame();
    void pauseGame(bool state);
    void updateTime();
    void gameWon();
    void gameLost();

private:

    Tile * tile(int index);
    QList<Tile *> tiles;
    bool gameOn;
    int elapsed;
    QTime gameTime;
    QTimer * gameTimer;
    QString time;
};

#endif // GAMEDATA_H
