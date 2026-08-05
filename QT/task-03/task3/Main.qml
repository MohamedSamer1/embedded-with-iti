import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material

Window {
    width: 750
    height: 500
    visible: true
    title: "Smart Home"
    color: "#121212"

    Rectangle {
        id: login
        anchors.fill: parent
        color: "#121212"
        visible: true

        Column {
            anchors.centerIn: parent
            spacing: 30
            width: 250

            Text {
                text: "Smart Home Login"
                color: "white"
                font.pixelSize: 24
            }

            TextField {
                id: username
                color: "White"
                width: parent.width
                placeholderText: "Username"
            }

            TextField {
                id: password
                color: "White"
                width: parent.width
                placeholderText: "Password"
            }

            Button {
                width: parent.width
                text: "Login"

                onClicked: {
                    if (username.text !== "" && password.text !== "") {
                        login.visible = false;
                        swipe.visible = true;
                    }
                }
            }
        }
    }

    SwipeView {
        id: swipe
        anchors.fill: parent
        visible: false
        interactive: true

        Item {
            ScrollView {
                anchors.fill: parent

                ColumnLayout {
                    width: parent.width
                    Text {
                        text: "Smart Home"
                        color: "white"
                        font.pixelSize: 26
                        font.bold: true
                        Layout.leftMargin: 20
                        Layout.topMargin: 20
                    }
                    RowLayout {
                        width: parent.width

                        Rectangle {
                            Layout.preferredWidth: 220
                            Layout.preferredHeight: 220
                            radius: 15
                            color: "#2962FF"
                            Layout.leftMargin: 20
                            Layout.topMargin: 20

                            ColumnLayout {
                                anchors.fill: parent
                                anchors.margins: 15

                                Text {
                                    text: "Living Room"
                                    color: "white"
                                    font.pixelSize: 14
                                }

                                Text {
                                    text: Math.round(tempSlider.value) + "°C"
                                    color: "white"
                                    font.pixelSize: 28
                                    font.bold: true
                                }

                                Slider {
                                    id: tempSlider
                                    Layout.fillWidth: true
                                    from: 16
                                    to: 30
                                    value: 22
                                }
                            }
                        }
                        Rectangle {
                            Layout.preferredWidth: 220
                            Layout.preferredHeight: 220
                            radius: 15
                            color: "#1E1E1E"
                            Layout.leftMargin: 20
                            Layout.topMargin: 20

                            ColumnLayout {
                                anchors.fill: parent
                                anchors.margins: 15

                                RowLayout {
                                    Layout.fillWidth: true

                                    Text {
                                        text: "Lights Bedroom"
                                        color: "white"
                                        font.pixelSize: 16
                                    }

                                    Item {
                                        Layout.fillWidth: true
                                    }

                                    Switch {
                                        id: lightSwitch
                                        checked: true
                                    }
                                }

                                Slider {
                                    Layout.fillWidth: true
                                    from: 0
                                    to: 100
                                    value: 70
                                    enabled: lightSwitch.checked
                                }
                            }
                        }
                        Rectangle {
                            Layout.preferredWidth: 220
                            Layout.preferredHeight: 220
                            radius: 15
                            color: "#1E1E1E"
                            Layout.leftMargin: 20
                            Layout.topMargin: 20

                            ColumnLayout {
                                anchors.fill: parent
                                anchors.margins: 15
                                spacing: 8

                                Text {
                                    text: "Fan Speed"
                                    color: "white"
                                    font.pixelSize: 16
                                }

                                RowLayout {
                                    ColumnLayout {
                                        Button {
                                            text: "Off"
                                            Layout.preferredWidth: 80
                                        }
                                        Button {
                                            text: "1"
                                            Layout.preferredWidth: 80
                                        }
                                    }
                                    ColumnLayout {
                                        Button {
                                            text: "2"
                                            Layout.preferredWidth: 80
                                        }
                                        Button {
                                            text: "3"
                                            Layout.preferredWidth: 80
                                        }
                                    }
                                }
                            }
                        }
                    }

                    RowLayout {
                        width: parent.width

                        Rectangle {
                            Layout.preferredWidth: 220
                            Layout.preferredHeight: 220
                            radius: 15
                            color: "#1E1E1E"
                            Layout.leftMargin: 20
                            Layout.topMargin: 20

                            ColumnLayout {
                                anchors.fill: parent
                                anchors.margins: 15

                                Text {
                                    text: "Bedroom"
                                    color: "white"
                                    font.pixelSize: 14
                                }

                                Text {
                                    text: Math.round(tempSlider2.value) + "°C"
                                    color: "white"
                                    font.pixelSize: 28
                                    font.bold: true
                                }

                                Slider {
                                    id: tempSlider2
                                    Layout.fillWidth: true
                                    from: 16
                                    to: 30
                                    value: 22
                                }
                            }
                        }
                        Rectangle {
                            Layout.preferredWidth: 220
                            Layout.preferredHeight: 220
                            radius: 15
                            color: "#1E1E1E"
                            Layout.leftMargin: 20
                            Layout.topMargin: 20

                            ColumnLayout {
                                anchors.fill: parent
                                anchors.margins: 15

                                RowLayout {
                                    Layout.fillWidth: true

                                    Text {
                                        text: "Lights Bedroom"
                                        color: "white"
                                        font.pixelSize: 16
                                    }

                                    Item {}

                                    Switch {
                                        id: lightSwitch2
                                        checked: true
                                    }
                                }

                                Slider {
                                    from: 0
                                    to: 100
                                    value: 70
                                    enabled: lightSwitch2.checked
                                }
                            }
                        }
                        Rectangle {
                            Layout.preferredWidth: 220
                            Layout.preferredHeight: 220
                            radius: 15
                            color: "#1E1E1E"
                            Layout.leftMargin: 20
                            Layout.topMargin: 20

                            ColumnLayout {
                                anchors.fill: parent
                                anchors.margins: 15
                                spacing: 8

                                Text {
                                    text: "TV"
                                    color: "white"
                                    font.pixelSize: 16
                                }

                                RowLayout {
                                    ColumnLayout {
                                        Button {
                                            text: "Off"
                                            Layout.preferredWidth: 80
                                        }
                                        Button {
                                            text: "1"
                                            Layout.preferredWidth: 80
                                        }
                                        Button {
                                            text: "2"
                                            Layout.preferredWidth: 80
                                        }
                                    }
                                    ColumnLayout {

                                        Button {
                                            text: "3"
                                            Layout.preferredWidth: 80
                                        }
                                        Button {
                                            text: "4"
                                            Layout.preferredWidth: 80
                                        }
                                        Button {
                                            text: "5"
                                            Layout.preferredWidth: 80
                                        }
                                    }
                                }
                            }
                        }
                    }

                    RowLayout {
                        width: parent.width

                        Rectangle {
                            Layout.preferredWidth: 220
                            Layout.preferredHeight: 220
                            radius: 15
                            color: "#1E1E1E"
                            Layout.leftMargin: 20
                            Layout.topMargin: 20

                            ColumnLayout {
                                anchors.fill: parent
                                anchors.margins: 15
                                spacing: 10

                                Text {
                                    text: "Sound System"
                                    color: "white"
                                    font.pixelSize: 16
                                }

                                Dial {
                                    id: volumeDial
                                    from: 0
                                    to: 100
                                    value: 60

                                    Layout.alignment: Qt.AlignHCenter
                                }

                                Text {
                                    text: "Volume: " + Math.round(volumeDial.value) + "%"
                                    color: "white"
                                    font.pixelSize: 18
                                    Layout.alignment: Qt.AlignHCenter
                                }

                                Switch {
                                    text: "Power"
                                    checked: true
                                    Layout.alignment: Qt.AlignHCenter
                                }
                            }
                        }
                        Rectangle {
                            Layout.preferredWidth: 220
                            Layout.preferredHeight: 220
                            radius: 15
                            color: "#1E1E1E"
                            Layout.leftMargin: 20
                            Layout.topMargin: 20

                            ColumnLayout {
                                anchors.fill: parent
                                anchors.margins: 15

                                RowLayout {
                                    Layout.fillWidth: true

                                    Text {
                                        text: "Dimmer"
                                        color: "white"
                                        font.pixelSize: 16
                                    }

                                    Item {}

                                    Switch {
                                        id: dimmer
                                        checked: true
                                    }
                                }

                                Slider {
                                    from: 0
                                    to: 100
                                    value: 70
                                    enabled: dimmer.checked
                                }
                            }
                        }
                        Rectangle {
                            Layout.preferredWidth: 220
                            Layout.preferredHeight: 220
                            radius: 15
                            color: "#1E1E1E"
                            Layout.leftMargin: 20
                            Layout.topMargin: 20

                            ColumnLayout {
                                anchors.fill: parent
                                anchors.margins: 15

                                Text {
                                    text: "Security Camera"
                                    color: "white"
                                    font.pixelSize: 16
                                }

                                Rectangle {
                                    Layout.fillWidth: true
                                    Layout.fillHeight: true
                                    radius: 8
                                    color: "#2A2A2A"
                                    border.color: "#555555"
                                    border.width: 1

                                    Text {
                                        anchors.centerIn: parent
                                        color: "#AAAAAA"
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        Item {
            Rectangle {
                anchors.fill: parent
                color: "#121212"

                ScrollView {
                    anchors.fill: parent

                    ColumnLayout {
                        width: parent.width
                        x: 20
                        y: 20
                        spacing: 15

                        Text {
                            text: "Settings"
                            color: "white"
                            font.pixelSize: 26
                            font.bold: true
                        }

                        Text {
                            text: "Screen Brightness"
                            color: "white"
                        }

                        Slider {
                            id: brightnessSlider
                            Layout.preferredWidth: 300
                            from: 0
                            to: 100
                            value: 75
                        }
                        Text {
                            text: Math.round(brightnessSlider.value)
                            color: "white"
                            font.bold: true
                            Layout.preferredWidth: 40
                            horizontalAlignment: Text.AlignHCenter
                        }

                        Text {
                            text: "Notification Volume"
                            color: "white"
                        }

                        Slider {
                            id: volumeSlider
                            Layout.preferredWidth: 300
                            from: 0
                            to: 100
                            value: 50
                        }
                        Text {
                            text: Math.round(volumeSlider.value)
                            color: "white"
                            font.bold: true
                            Layout.preferredWidth: 40
                            horizontalAlignment: Text.AlignHCenter
                        }

                        Text {
                            text: "Theme"
                            color: "white"
                        }

                        ComboBox {
                            Layout.preferredWidth: 220
                            model: ["Dark", "Light", "System"]
                        }

                        Text {
                            text: "Language"
                            color: "white"
                        }

                        ComboBox {
                            Layout.preferredWidth: 220
                            model: ["English", "Arabic", "German"]
                        }

                        Text {
                            text: "Temperature Unit"
                            color: "white"
                        }

                        ComboBox {
                            Layout.preferredWidth: 220
                            model: ["°C", "°F"]
                        }
                    }
                }
            }
        }
    }
}
