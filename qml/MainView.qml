import QtQuick 1.1

Item {
    id: screen
    width: 448
    height: 576

    Image {
        id: backgroundImage
        anchors.fill: parent
        source: "qrc:\images/background-space.jpg"
        fillMode: Image.PreserveAspectCrop
    }

    // *** Game View ***
    GameView {
        id: gameView
        // Gameview is disabled when gameViewHider is shown
        enabled: gameViewHider.state == "hide"
    }

    // *** Game View Hider ***
    Rectangle {
        id: gameViewHider
        anchors.fill: parent
        color: "black"
        opacity: 0.7

        states: [
        State {
            name: "hide"
            when: menuPanel.state == "hide"
                  && optionsPanel.state == "hide"
                  && helpPanel.state == "hide"
            PropertyChanges {
                target: gameViewHider
                opacity: 0.0
            }
        }
        ]

        transitions: Transition {
            NumberAnimation {
                properties: "opacity"
                duration: 400
            }
        }
    }

    // *** Main Menu panel ***
    MenuPanel {
        id: menuPanel
    }

    OptionsPanel {
        id: optionsPanel
        state: "hide"
    }

    HelpPanel {
        id: helpPanel
        state: "hide"
    }
}
