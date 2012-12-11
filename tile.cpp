#include "tile.h"

Tile::Tile(QObject *parent, int rotation, bool traversible, TileLine tileLine, TileType tileType, TileItem tileItem) :
    QObject(parent),
    rotation(rotation),
    traversible(traversible),
    tileLine(tileLine),
    tileType(tileType),
    tileItem(tileItem)
{
}

const QString Tile::getTileImage()
{
    return this->tileImage;
}

const int Tile::getRotation()
{
    return this->rotation;
}

const bool Tile::isTraversible()
{
    return this->traversible;
}

const Tile::TileLine Tile::getTileLine()
{
    return this->tileLine;
}

const Tile::TileType Tile::getTileType()
{
    return this->tileType;
}

const QString Tile::getTileString()
{
    QString tileName;
    switch (this->tileLine)
    {
    case NONE:
    case SINGLE:
    default:
        tileName = "";
        break;
    case DOUBLE:
        tileName = "_double";
        break;
    case SQUARE:
        tileName = "_square";
        break;
    }

    switch (this->tileType)
    {
    case EMPTY:
    default:
        tileName = "";
        break;
    case WALL:
        tileName = "line" + tileName;
        break;
    case CORNER:
        tileName = "corner" + tileName;
        break;
    case TURNOUT:
        tileName = "turnout";
        break;
    case GATE:
        tileName = "gate";
        break;
    }

    return "qrc:/images/board/" + tileName + ".png";
}

const Tile::TileItem Tile::getTileItem()
{
    return this->tileItem;
}

const QString Tile::getTileItemString()
{
    switch (this->tileItem)
    {
    case PELLET:
        return "qrc:/images/board/pellet.png";
        break;
    case POWERUP:
        return "qrc:/images/board/powerup.png";
        break;
    case FRUIT:
        return "qrc:/images/board/fruit.png";
        break;
    case NOTHING:
    default:
        return "";
        break;
    }
}

Tile * Tile::ConstructTile(QObject *tileParent, char tileChar)
{
    switch(tileChar)
    {
    case 'W':
        // It is a wall, we need to determine the sprite.
        // TODO: implement sprite determination.
        return new Tile(tileParent, 0, false, DOUBLE, WALL, NOTHING);
        break;
    case 'X':
        // It is a blank non-traversible space (outside of maze walls).
        return new Tile(tileParent, 0, false, NONE, EMPTY, NOTHING);
        break;
    case ' ':
        // It is a blank traversible space.
        return new Tile(tileParent, 0, true, NONE, EMPTY, NOTHING);
        break;
    case '*':
        // It is a traversible space with a pellet.
        return new Tile(tileParent, 0, true, NONE, EMPTY, PELLET);
        break;
    case 'O':
        // It is a traversible space with a power-up.
        return new Tile(tileParent, 0, true, NONE, EMPTY, POWERUP);
        break;
    case 'P':
        // It is a PacMan spawn point.
        return new Tile(tileParent, 0, true, NONE, EMPTY, NOTHING);
        break;
    case 'G':
        // It is a Ghost pen gate.
        return new Tile(tileParent, 0, true, NONE, GATE, NOTHING);
        break;
    case 'M':
        // It is a Ghost spawn point.
        return new Tile(tileParent, 0, true, NONE, EMPTY, NOTHING);
        break;
    default:
        qDebug("Error: tile character not recognized: " + tileChar);
        return 0;
        break;
    }
}
