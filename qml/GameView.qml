import QtQuick 1.1

Item {
    id: gameView
    anchors.fill: parent

    // *** Board ***
    Item {
        id: gameboard
        anchors.fill: parent
        width: boardGrid.width + controlPanel.width + 40 + 10
        height: boardGrid.height + 40

        Grid {
            id: boardGrid
            columns: gameData.colsCount
            rows: gameData.rowsCount
            spacing: 0
            x: 20
            y: 20

            Repeater {
                model: gameData.tiles
                Tile { }
            }
        }
    }

    // *** Control panel ***
    ControlPanel {
        id: controlPanel
    }
}
