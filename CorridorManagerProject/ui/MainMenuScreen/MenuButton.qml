import QtQuick 2.0

Rectangle {
    id: menuButton
    property string buttonText: "Create"
    property string buttonColor: "#f08256"
    property string buttonPressedColor: "#e68abf"
    property string buttonTextColor: "black"
    property bool pressed: false
    property bool disabled: false
    property int fontSize: 25
    property string imageSource: "qrc:/assets/createIcon.png"

    signal clicked

    color: {
        if (pressed)
            return buttonPressedColor
        else
            return buttonColor
    }

    Text {
        anchors {
            //left: buttonImage.right
            leftMargin: 30
            verticalCenter: parent.verticalCenter
        }


        font.pixelSize: fontSize
        color: buttonTextColor
        text: buttonText
        horizontalAlignment: Text.AlignHCenter
    }

    MouseArea {
        anchors.fill: parent
        onPressed: {
            menuButton.pressed = true
        }
        onReleased: {
            menuButton.pressed = false
        }
        onClicked: {
            menuButton.clicked()
        }
    }
}
