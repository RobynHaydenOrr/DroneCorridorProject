import QtQuick 2.15
import "../Components"

Rectangle {
    id: approveListPanel

    color: "#050505"

    Text {
        id: titleText
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: parent.top
            topMargin: 25
        }

        font.pixelSize: 40
        color: "white"
        text: ("Corridors To Manage")
    }

    Text {
        id: backButton

        anchors {
            verticalCenter: titleText.verticalCenter
            left: parent.left
            leftMargin: 0
        }

        color: "#464646"
        font.pixelSize: 40
        text: "<"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                flightPathManager.reset()
                stackView.pop()
            }
        }
    }

    ListView {
        id: routesListView
        model: fileHandler.savedRoutesModel
        clip: true

        spacing: 15

        width: parent.width * 0.8

        anchors {
            top: titleText.bottom
            topMargin: 20
            horizontalCenter: parent.horizontalCenter
            bottom: parent.bottom
            bottomMargin: 15
        }

        delegate: ApproveListViewDelegate {}
    }
}
