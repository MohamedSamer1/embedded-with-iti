import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello world")

    Rectangle {
            width: 400
            height: 300
            anchors.centerIn: parent
            color: "lightblue"
            radius: 15
            border.color: "darkblue"
            border.width: 2

            Column {
                anchors.centerIn: parent
                spacing: 10

                Text {
                    text: "Hello World"
                    font.pixelSize: 28
                    font.bold: true
                    color: "darkblue"
                }

                Text {
                    text: "Name: Mohamed"
                    font.pixelSize: 18
                }

                Text {
                    text: "University: MSA"
                    font.pixelSize: 18
                }

                Text {
                    text: "City: Cairo"
                    font.pixelSize: 18
                }

                Text {
                    text: "Course: Embedded Systems"
                    font.pixelSize: 18
                }

                Text {
                    text: "I am an Engineering Student"
                    font.pixelSize: 18
                    color: "green"
                }
            }
        }
}
