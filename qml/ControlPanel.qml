import QtQuick 1.1

Item {
    Item {
        id: upperPanel
        width: parent.width
        height: 40
        anchors.top: parent.top

        Frame {
            id: upperPanelBox

            Text {
                x: 25
                y: 5
                font.family: "Helvetica"
                font.pointSize: 12
                smooth: true
                color: "black"
                text: "Time"
            }

            Text {
                anchors.right: parent.right
                anchors.rightMargin: 15
                y: 5
                font.family: "Helvetica"
                font.pointSize: 12
                smooth: true
                color: "black"
                text: "Points"
            }
            Text {
                x: 10
                y: 25
                font.family: "Helvetica"
                font.pointSize: 26
                smooth: true
                color: "gray"
                style: Text.Outline
                styleColor: "black"
                text: gameData.elapsed
            }
            Text {
                anchors.right: parent.right
                anchors.rightMargin: 20
                y: 25
                font.family: "Helvetica"
                font.pointSize: 26
                smooth: true
                color: "gray"
                style: Text.Outline
                styleColor: "black"
                text: gameData.points
            }
        }
    }

    Item {
        id: lowerPanel
        width: parent.width
        height: 40
        anchors.bottom: parent.bottom

        Frame {
            id: lowerPanelBox

            Row {
                anchors.left: parent.left

                Repeater {
                    model: gameData.lives
                    Image {
                        source: "qrc:/images/pacman_live.png"
                    }
                }
            }

            Row {
                opacity: 1
                anchors.right: parent.right

                Repeater {
                    model: gameData.fruits
                    Image {
                        source: "qrc:/images/fruit.png"
                    }
                }
            }
        }
    }
}
