import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

Window {
    visible: true
    width: 1280
    height: 720
    title: qsTr("ElectroShop")

    Rectangle {
        id: head_id
        anchors.top: parent.top
        width: parent.width
        height: 75
        z: 2

        color: "white"
        border.color: "#f1f1f1"
        border.width: 1

        RowLayout {
            anchors.fill: parent
            anchors.leftMargin: 35
            anchors.rightMargin: 35
            spacing: 20

            Text {
                text: qsTr("Electronics Shop")
                font.pixelSize: 28
                font.bold: true
                color: "#222222"
            }

            Item {
                Layout.fillWidth: true
            }

            Rectangle {
                width: 320
                height: 38
                radius: 8
                color: "white"
                border.color: "#D8D8D8"

                RowLayout {
                    anchors.fill: parent
                    anchors.leftMargin: 12
                    anchors.rightMargin: 12

                    TextField {
                        Layout.fillWidth: true
                        placeholderText: qsTr("Search Products...")
                        background: null
                    }

                    Text {
                        text: qsTr("🔍")
                        font.pixelSize: 18
                        color: "#666666"
                    }
                }
            }

            Rectangle {
                width: 1
                height: 35
                color: "#DDDDDD"
            }

            Row {
                spacing: 8

                Text {
                    text: qsTr("🛒")
                    font.pixelSize: 22
                    anchors.verticalCenter: parent.verticalCenter
                }

                Column {
                    spacing: 2

                    Text {
                        text: qsTr("Cart")
                        font.pixelSize: 12
                        color: "#777777"
                    }

                    Text {
                        text: qsTr("$150.00")
                        font.pixelSize: 16
                        font.bold: true
                        color: "#222222"
                    }
                }
            }

            Rectangle {
                width: 1
                height: 35
                color: "#DDDDDD"
            }

            RowLayout {
                spacing: 8
                Layout.alignment: Qt.AlignVCenter

                Text {
                    text: qsTr("🌐")
                    font.pixelSize: 20
                    Layout.alignment: Qt.AlignVCenter
                }

                Text {
                    text: qsTr("Language")
                    font.pixelSize: 14
                    color: "#555555"
                    Layout.alignment: Qt.AlignVCenter
                }

                ComboBox {
                    model: ["English", "Arabic"]

                    onCurrentTextChanged: {
                        if (currentText === "Arabic")
                            languageManager.changeLanguage("ar");
                        else
                            languageManager.changeLanguage("en");
                    }
                }
            }
        }
    }

    ListModel {
        id: featuredModel

        ListElement {
            name: "Laptop"
            price: "$1299"
            image: "qrc:/images/laptop.jpeg"
        }
        ListElement {
            name: "iPhone 16"
            price: "$999"
            image: "qrc:/images/iphone.png"
        }
        ListElement {
            name: "Keyboard"
            price: "$89"
            image: "qrc:/images/keyboard.png"
        }
        ListElement {
            name: "Mouse"
            price: "$49"
            image: "qrc:/images/mouse.png"
        }
        ListElement {
            name: "Monitor"
            price: "$299"
            image: "qrc:/images/monitor.png"
        }
        ListElement {
            name: "Headphones"
            price: "$149"
            image: "qrc:/images/headphones.png"
        }
        ListElement {
            name: "Speaker"
            price: "$79"
            image: "qrc:/images/speaker.png"
        }
        ListElement {
            name: "Watch"
            price: "$199"
            image: "qrc:/images/watch.png"
        }
        ListElement {
            name: "PlayStation 5"
            price: "$499"
            image: "qrc:/images/ps5.png"
        }
        ListElement {
            name: "Xbox Controller"
            price: "$69"
            image: "qrc:/images/controller.png"
        }
        ListElement {
            name: "External SSD"
            price: "$159"
            image: "qrc:/images/ssd.jpg"
        }
        ListElement {
            name: "USB C Hub"
            price: "$39"
            image: "qrc:/images/hub.png"
        }
        ListElement {
            name: "Webcam"
            price: "$59"
            image: "qrc:/images/webcam.png"
        }

    }

    GridView {
        id: productsGrid

        anchors.top: head_id.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        leftMargin: 60
        rightMargin: 60
        topMargin: 20
        bottomMargin: 30

        clip: true

        cellWidth: 230
        cellHeight: 300

        model: featuredModel

        header: Column {
            width: productsGrid.width - 120
            spacing: 30
            bottomPadding: 20

            Image {
                width: parent.width
                height: 250
                fillMode: Image.PreserveAspectCrop

                source: "qrc:/images/pic1.jpg"

                layer.enabled: true
            }

            Text {
                text: qsTr("Featured Items")
                font.pixelSize: 28
                font.bold: true
            }
        }

        delegate: Rectangle {
            width: 200
            height: 260
            radius: 10
            color: "#F5F5F5"
            border.color: "#DDDDDD"

            Column {
                anchors.fill: parent
                anchors.margins: 10
                spacing: 10

                Image {
                    width: parent.width
                    height: 120
                    source: image
                    fillMode: Image.PreserveAspectFit
                }

                Text {
                    text: name
                    font.pixelSize: 18
                    font.bold: true
                }

                Text {
                    text: price
                    color: "#008000"
                    font.pixelSize: 16
                }

                Button {
                    width: parent.width
                    text: qsTr("Add to Cart")

                    contentItem: Text {
                        text: parent.text
                        color: "white"
                        font.pixelSize: 14
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                    background: Rectangle {
                        radius: 6
                        color: "#222222"
                    }

                    onClicked: {
                        popupText_id.text = name + " " + qsTr("added to cart");
                        notificationPopup_id.open();
                    }
                }
            }
        }
    }

    Popup {
        id: notificationPopup_id
        x: (parent.width - width) / 2
        y: 90
        width: 320
        height: 60
        modal: false
        focus: false

        background: Rectangle {
            color: "#333333"
            radius: 12
            border.color: "#5DADE2"
            border.width: 2
        }

        Label {
            id: popupText_id
            anchors.centerIn: parent
            color: "white"
            font.pixelSize: 16
            font.bold: true
        }

        Timer {
            id: popupTimer_id
            interval: 1500
            repeat: false
            onTriggered: notificationPopup_id.close()
        }

        onOpened: popupTimer_id.start()
    }
}
