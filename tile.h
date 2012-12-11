#ifndef TILE_H
#define TILE_H

#include <QObject>
#include <QString>

/// The Tile class provides a game board tile.
class Tile : public QObject
{
    Q_OBJECT

public:
    /// This enum type is used to specify the line type
    /// of the tile.
    enum TileLine
    {
        /// The tile has no line type (for empty tiles).
        NONE,
        /// The tile has a single line.
        SINGLE,
        /// The tile has a double line.
        DOUBLE,
        /// The tile has a squared line
        /// (double with sharp corners).
        SQUARE
    };

    /// This enum type is used to specify the type
    /// of the tile.
    enum TileType
    {
        EMPTY,
        WALL,
        CORNER,
        TURNOUT,
        GATE
    };

    /// This enum type is used to specify the item that
    /// the tile holds.
    enum TileItem
    {
        NOTHING,
        PELLET,
        POWERUP,
        FRUIT
    };

    /// Initializes a new instance of the Tile class.
    explicit Tile(QObject * = 0,
                  int = 0,
                  bool = false,
                  TileLine = NONE,
                  TileType = EMPTY,
                  TileItem = NOTHING);

    Q_PROPERTY(QString tileImage READ getTileImage CONSTANT)
    /// Gets the tile's image.
    const QString getTileImage();

    Q_PROPERTY(int rotation READ getRotation CONSTANT)
    /// Gets the tile's rotation.
    const int getRotation();

    Q_PROPERTY(bool traversible READ isTraversible CONSTANT)
    /// Gets a value indicating whether the tile is traversible.
    const bool isTraversible();

    Q_PROPERTY(TileLine tileLine READ getTileLine CONSTANT)
    /// Gets the tile's line type.
    const TileLine getTileLine();

    Q_PROPERTY(TileType tileType READ getTileType CONSTANT)
    /// Gets the tile's type.
    const TileType getTileType();

    Q_PROPERTY(TileItem tileItem READ getTileItem CONSTANT)
    /// Gets the tile's item.
    const TileItem getTileItem();

    Q_PROPERTY(QString getTileString READ getTileString CONSTANT)
    const QString getTileString();

    Q_PROPERTY(QString getTileItemString READ getTileItemString CONSTANT)
    const QString getTileItemString();

    /// Returns a tile according to the letter supplied.
    static Tile * ConstructTile(QObject * , char );

private:
    /// Filename for the texture for this tile.
    const QString tileImage;

    /// Tile's texture rotation in degrees clockwise from 12:00.
    const int rotation;

    /// Value indicating whether the tile is traversible or not.
    const bool traversible;

    /// Tile's line type: single, double or squared.
    const TileLine tileLine;

    /// Tile's type: space, wall, wall corner or special corner.
    const TileType tileType;

    /// Enumerated for the item that is located on this tile.
    TileItem tileItem;
};

#endif // TILE_H
