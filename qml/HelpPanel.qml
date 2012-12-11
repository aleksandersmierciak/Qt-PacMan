import QtQuick 1.1

Item {
    id: helpPanel
    width: parent.width
    height: parent.height
    anchors.centerIn: parent

    Frame {
        id: helpPanelFrame
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
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.top: gameLogo.bottom
            anchors.margins: 10
            spacing: 10

            Frame {
                id: aboutArea
                width: parent.width
                height: parent.height - buttonBack.height - 10
                gradient: Gradient {
                    GradientStop { position: 0.0; color: "#ffffff" }
                    GradientStop { position: 1.0; color: "#eeeeee" }
                }

                Flickable {
                    id: aboutAreaFlickable
                    anchors.fill: parent
                    contentWidth: aboutArea.width
                    contentHeight: aboutAreaText.height
                    flickableDirection: Flickable.VerticalFlick
                    clip: true
                    Text {
                        id: aboutAreaText
                        width: parent.width - 20
                        anchors.horizontalCenter: parent.horizontalCenter
                        wrapMode: Text.WordWrap
                        font.family: "Helvetica"
                        font.pointSize: 15
                        text: "<p>(Surely you need not an introduction to the concept " +
                              "of PacMan, do you?\n...oh well...)</p>" +
                              "As a small and ever-hungering ball, your aim " +
                              "is to eat all the pellets in the level while " +
                              "not losing the chase to deadly ghosts. " +
                              "You can also get bonus points for collecting " +
                              "fruits which pop up on the board from time " +
                              "to time.</p>" +
                              "<p>Enjoy the game :-)</p>" +
                              "<p>Useful resources:</p>" +
                              "<ul><li>In-depth PacMan mechanics study: <a href=\"http://home.comcast.net/~jpittman2/pacman/pacmandossier.html\">PacMan Dossier</a></li>" +
                              "<li>What the game was written in: <a href=\"http://doc.qt.digia.com/qt/qtquick.html\">Qt Quick</a></li></ul>"
                    }
                }
            }

            Button {
                id: buttonBack
                text: "Back"
                onClicked: {
                    helpPanel.state = "hide"
                    menuPanel.state = "show"
                }
            }
        }
    }

    states: [
    State {
        name: "hide"
        PropertyChanges {
            target: helpPanel
            opacity: 0.0
            y: -helpPanelFrame.height
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
