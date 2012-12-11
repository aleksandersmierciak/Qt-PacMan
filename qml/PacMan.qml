import QtQuick 1.1

Item {
    id: pacMan
    objectName: "pacMan"
    focus: true
    width: 128
    height: 128
    x: 0
    y: 0

    property string direction: "None"

    Keys.onPressed: {
             if (event.key === Qt.Key_Right) {
                 console.log('Right arrow was pressed');
                 pacMan.direction = "Right"
                 graphic.playing = true;
                 event.accepted = true;
             }
             else if (event.key === Qt.Key_Down) {
                 console.log('Down arrow was pressed');
                 pacMan.direction = "Down"
                 graphic.playing = true;
                 event.accepted = true;
             }
             else if (event.key === Qt.Key_Left) {
                 console.log('Left arrow was pressed');
                 pacMan.direction = "Left"
                 graphic.playing = true;
                 event.accepted = true;
             }
             else if (event.key === Qt.Key_Up) {
                 console.log('Up arrow was pressed');
                 pacMan.direction = "Up"
                 graphic.playing = true;
                 event.accepted = true;
             }
             else if (event.key === Qt.Key_Space) {
                 console.log('Space bar was pressed');
                 pacMan.direction = "None"
                 event.accepted = true;
             }
         }

    AnimatedImage {
        id: graphic
        opacity: 1.0
        source: parent.direction == "None"
                ? "qrc:/images/pacman_static.png"
                : "qrc:/images/pacman_movement.gif"
        width: parent.width
        height: parent.height
        x: 0
        y: 0

        transitions: Transition {
            RotationAnimation { duration: 1000; direction: RotationAnimation.Counterclockwise }
        }
    }

    transitions: Transition {
        PropertyAnimation { properties: "x, y" }
    }

    states: [
        State {
            name: "None"
            when: pacMan.direction == "None"
            PropertyChanges { target: graphic; rotation: 0 }
        },
        State {
            name: "Right"
            when: pacMan.direction == "Right"
            PropertyChanges { target: graphic; rotation: 0 }
        },
        State {
            name: "Down"
            when: pacMan.direction == "Down"
            PropertyChanges { target: graphic; rotation: 90 }
        },
        State {
            name: "Left"
            when: pacMan.direction == "Left"
            PropertyChanges { target: graphic; rotation: 180 }
        },
        State {
            name: "Up"
            when: pacMan.direction == "Up"
            PropertyChanges { target: graphic; rotation: 270 }
        }
    ]
}
