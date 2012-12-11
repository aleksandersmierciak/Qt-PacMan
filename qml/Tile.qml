import QtQuick 1.1

Item {
    id: tile
    width: 16
    height: 16

    Image {
        id: tileBackground
        anchors.centerIn: parent
        source: modelData.getTileString
        rotation: modelData.rotation
        opacity: 0.7
    }

    Image {
        id: tileItem
        anchors.centerIn: parent
        source: modelData.getTileItemString
    }
}
