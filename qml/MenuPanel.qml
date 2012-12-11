import QtQuick 1.1

Item {
    id: menuPanel
    width: parent.width
    height: parent.height
    anchors.centerIn: parent

    Frame {
        id: menuPanelFrame
        width: parent.width - 30
        height: parent.height - 30
        anchors.centerIn: parent

        Image {
            id: gameLogo
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
            // TODO: add a title banner
            // source: "qrc:/images/banner.png"
            height: 40
            Text {
                anchors.centerIn: parent
                font.family: "Helvetica"
                font.pointSize: 28
                smooth: true
                color: "white"
                style: Text.Outline
                styleColor: "black"
                text: "PacMan clone"
            }
        }

        Column {
            width: 50
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.margins: 10
            spacing: 10

            Button {
                id: buttonPlay
                text: "Play"
                onClicked: {
                    gameData.resetGame()
                    menuPanel.state = "hide"
                    gameData.pauseGame(false)
                }
            }

            Button {
                id: buttonContinue
                text: "Continue"
                disabled: !gameData.gameOn
                onClicked: {
                    menuPanel.state = "hide"
                    gameData.pauseGame(false)
                }
            }

            Button {
                id: buttonOptions
                text: "Options"
                onClicked: {
                    menuPanel.state = "hide"
                    optionsPanel.state = "show"
                }
            }

            Button {
                id: buttonHelp
                text: "Help"
                onClicked: {
                    menuPanel.state = "hide"
                    helpPanel.state = "show"
                }
            }
        }
    }

    states: [
    State {
        name: "hide"
        PropertyChanges {
            target: menuPanel
            opacity: 0.0
            y: -menuPanelFrame.height
        }
    }
    ]

    transitions: Transition {
        NumberAnimation {
            properties: "opacity, y"
            duration: 400
        }
    }
}
