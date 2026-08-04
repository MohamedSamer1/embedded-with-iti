import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    id: window

    visible: true
    width: 1000
    height: 600

    title: "Mohamed Shop"

    property bool splash: true

    Rectangle {
        id: splashScreen

        anchors.fill: parent
        visible: splash
        z: 10

        color: "#111111"


        Image {
            source: "qrc:/images/porsche-logo-png_seeklogo-168544.png"

            width: 200
            height: 200

            anchors.centerIn: parent
            fillMode: Image.PreserveAspectFit
        }


        Text {
            text: "Mohamed Shop"

            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 420

            color: "white"

            font.pixelSize: 40
            font.bold: true
        }


        BusyIndicator {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 500

            width: 60
            height: 60

            running: true
        }


        Timer {
            interval: 3000
            running: true
            repeat: false

            onTriggered: {
                splash = false
            }
        }
    }


    Rectangle {
        anchors.fill: parent
        color: "#F2F2F2"
    }

    Rectangle {
        id: card1

        x: 40
        y: 70
        width: 280
        height: 460
        radius: 20

        color: "white"
        border.width: 2
        border.color: "#4CAF50"

        Image {
            anchors.top: parent.top
            anchors.topMargin: -20
            anchors.horizontalCenter: parent.horizontalCenter

            width: 250
            height: 250

            source: "qrc:/images/iris.png"
            fillMode: Image.PreserveAspectFit
        }

        Text {
            text: "718 Cayman GTS 4.0"

            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 40

            font.pixelSize: 24
            font.bold: true
        }

        MouseArea {
            anchors.fill: parent

            onClicked: {
                card2.visible = false;
                card3.visible = false;

                card1.x = 0;
                card1.y = 0;
                card1.width = window.width;
                card1.height = window.height;

                details1.visible = true;
            }
        }
    }

    Rectangle {
        id: card2

        x: 360
        y: 70
        width: 280
        height: 460
        radius: 20
        color: "white"
        border.width: 2
        border.color: "#2196F3"

        Image {
            source: "qrc:/images/cayturboE (Copy).png"
            anchors.top: parent.top
            anchors.topMargin: 30
            anchors.horizontalCenter: parent.horizontalCenter
            width: 180
            height: 180
        }

        Text {
            text: "Cayenne Turbo Electric"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 40
            font.pixelSize: 24
            font.bold: true
        }

        MouseArea {
            anchors.fill: parent

            onClicked: {
                card1.visible = false;
                card3.visible = false;

                card2.x = 0;
                card2.y = 0;
                card2.width = window.width;
                card2.height = window.height;

                details2.visible = true;
            }
        }
    }

    Rectangle {
        id: card3

        x: 680
        y: 70
        width: 280
        height: 460
        radius: 20
        color: "white"
        border.width: 2
        border.color: "#FF9800"

        Image {
            source: "qrc:/images/911.png"
            anchors.top: parent.top
            anchors.topMargin: 30
            anchors.horizontalCenter: parent.horizontalCenter
            width: 180
            height: 180
        }

        Text {
            text: "911 Turbo S Cabriolet"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 40
            font.pixelSize: 24
            font.bold: true
        }

        MouseArea {
            anchors.fill: parent

            onClicked: {
                card1.visible = false;
                card2.visible = false;

                card3.x = 0;
                card3.y = 0;
                card3.width = window.width;
                card3.height = window.height;

                details3.visible = true;
            }
        }
    }
    Column {
        id: details1
        visible: false
        spacing: 20
        anchors.centerIn: card1

        Text {
            text: "CAR 1"
            font.pixelSize: 32
            font.bold: true
        }

        Text {
            text: "Color: RED"
        }

        Text {
            text: "Type: Porsche"
        }
        Text {
            text: "Model: Cayman"
        }

        Button {
            text: "Back"

            onClicked: {
                details1.visible = false;

                card2.visible = true;
                card3.visible = true;

                card1.x = 40;
                card1.y = 70;
                card1.width = 280;
                card1.height = 460;
            }
        }
    }
    Column {
        id: details2
        visible: false
        spacing: 20
        anchors.centerIn: card2

        Text {
            text: "CAR 2"
            font.pixelSize: 32
            font.bold: true
        }

        Text {
            text: "Color: Blue"
        }

        Text {
            text: "Type: Porsche"
        }
        Text {
            text: "Model: Cayenne"
        }

        Button {
            text: "Back"

            onClicked: {
                details2.visible = false;

                card1.visible = true;
                card3.visible = true;

                card2.x = 360;
                card2.y = 70;
                card2.width = 280;
                card2.height = 460;
            }
        }
    }
    Column {
        id: details3
        visible: false
        spacing: 20
        anchors.centerIn: card3

        Text {
            text: "CAR 3"
            font.pixelSize: 32
            font.bold: true
        }

        Text {
            text: "Color: Black"
        }

        Text {
            text: "Type: Porsche"
        }
        Text {
            text: "Model: 911"
        }

        Button {
            text: "Back"

            onClicked: {
                details3.visible = false;

                card1.visible = true;
                card2.visible = true;

                card3.x = 680;
                card3.y = 70;
                card3.width = 280;
                card3.height = 460;
            }
        }
    }
}
