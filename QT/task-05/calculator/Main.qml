import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material


ApplicationWindow {
    visible: true
    width: 360
    height: 600

    title: "Calculator"

    property string firstNumber: ""
    property string secondNumber: ""
    property string operation: ""
    property bool enteringSecond: false
    property string displayText: "0"
    property bool freshResult: false

    Material.theme: Material.Dark

    function appendDigit(d) {
        if (enteringSecond) {
            secondNumber += d
            displayText = firstNumber + " " + operation + " " + secondNumber
        } else {
            if (freshResult) {
                firstNumber = d
                freshResult = false
            } else {
                firstNumber += d
            }
            displayText = firstNumber
        }
    }

    function setOperation(op) {
        if (firstNumber === "") return
        operation = op
        enteringSecond = true
        secondNumber = ""
        displayText = firstNumber + " " + operation
    }

    function doEquals() {
        if (firstNumber === "" || operation === "" || secondNumber === "")
        {
            return
        }
        var opForBackend = operation === "×" ? "*" : operation
        backend.calculate(parseFloat(firstNumber), parseFloat(secondNumber), opForBackend)
    }

    Connections {
        target: backend
        function onResultChanged() {
            displayText = firstNumber + " " + operation + " " + secondNumber + " = " + backend.result.toString()
            firstNumber = backend.result.toString()
            secondNumber = ""
            operation = ""
            enteringSecond = false
            freshResult = true
        }
    }
    Rectangle {
        anchors.fill: parent
        color: "#202124"
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 15

        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 120

            radius: 15
            color: "#2D2E30"

            Text {
                id: display

                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                anchors.rightMargin: 20

                text: displayText

                color: "white"

                font.pixelSize: 42
            }
        }
        GridLayout {
            id: grid

            Layout.fillWidth: true
            Layout.fillHeight: true

            columns: 4
            rowSpacing: 10
            columnSpacing: 10

            Button {
                text: "7"
                Layout.fillWidth: true
                Layout.fillHeight: true
                font.pixelSize: 24
                onClicked: appendDigit(text)
            }
            Button {
                text: "8"
                Layout.fillWidth: true
                Layout.fillHeight: true
                font.pixelSize: 24
                onClicked: appendDigit(text)

            }
            Button {
                text: "9"
                Layout.fillWidth: true
                Layout.fillHeight: true
                font.pixelSize: 24
                onClicked: appendDigit(text)

            }
            Button {
                text: "/"
                Layout.fillWidth: true
                Layout.fillHeight: true
                font.pixelSize: 24
                onClicked: setOperation(text)
            }

            Button {
                text: "4"
                Layout.fillWidth: true
                Layout.fillHeight: true
                font.pixelSize: 24
                onClicked: appendDigit(text)

            }
            Button {
                text: "5"
                Layout.fillWidth: true
                Layout.fillHeight: true
                font.pixelSize: 24
                onClicked: appendDigit(text)

            }
            Button {
                text: "6"
                Layout.fillWidth: true
                Layout.fillHeight: true
                font.pixelSize: 24
                onClicked: appendDigit(text)

            }
            Button {
                text: "×"
                Layout.fillWidth: true
                Layout.fillHeight: true
                font.pixelSize: 24
                onClicked: setOperation(text)
            }

            Button {
                text: "1"
                Layout.fillWidth: true
                Layout.fillHeight: true
                font.pixelSize: 24
                onClicked: appendDigit(text)

            }
            Button {
                text: "2"
                Layout.fillWidth: true
                Layout.fillHeight: true
                font.pixelSize: 24
                onClicked: appendDigit(text)

            }
            Button {
                text: "3"
                Layout.fillWidth: true
                Layout.fillHeight: true
                font.pixelSize: 24
                onClicked: appendDigit(text)

            }
            Button {
                text: "-"
                Layout.fillWidth: true
                Layout.fillHeight: true
                font.pixelSize: 24
                onClicked: setOperation(text)
            }

            Button {
                text: "0"
                Layout.fillWidth: true
                Layout.fillHeight: true
                font.pixelSize: 24
                onClicked: appendDigit(text)
            }
            Button {
                text: "."
                Layout.fillWidth: true
                Layout.fillHeight: true
                font.pixelSize: 24
                onClicked: appendDigit(text)

            }
            Button {
                text: "="
                Layout.fillWidth: true
                Layout.fillHeight: true
                font.pixelSize: 24
                onClicked: doEquals()
            }
            Button {
                text: "+"
                Layout.fillWidth: true
                Layout.fillHeight: true
                font.pixelSize: 24
                onClicked: setOperation(text)
            }
        }
    }
}