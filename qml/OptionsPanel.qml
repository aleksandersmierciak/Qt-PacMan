import QtQuick 1.1

Item {
    id: optionsPanel
    width: parent.width
    height: parent.height
    anchors.centerIn: parent

    Frame {
        id: optionsPanelFrame
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
            anchors.margins: 10
            spacing: 10

            Switch {
                id: switchMusic
                textOff: "Sounds off"
                textOn: "Sounds on"
            }

            Button {
                id: buttonBack
                text: "Back"
                onClicked: {
                    optionsPanel.state = "hide"
                    menuPanel.state = "show"
                }
            }
        }
    }

    states: [
    State {
        name: "hide"
        PropertyChanges {
            target: optionsPanel
            opacity: 0.0
            y: -optionsPanelFrame.height
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
