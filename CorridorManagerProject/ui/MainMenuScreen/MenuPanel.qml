import QtQuick 2.15
import QtQuick.Layouts 1.15
import "../Components"

Rectangle {
    id: menuPanel

    color: "#050505"

    Text {
        id: titleText
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: parent.top
            topMargin: 100
        }

        font.pixelSize: 40
        color: "white"
        text: ("Drone Corridor Manager")
    }

    ColumnLayout {
        id: buttonLayout

        anchors {
            top: titleText.bottom
            bottom: parent.bottom
            horizontalCenter: parent.horizontalCenter
            topMargin: 65
            bottomMargin: 65
        }

        width: parent.width * 0.25

        spacing: 65

        MenuButton {
            id: createButton
            //imageSource: "qrc:/assets/createIcon.png"
            buttonText: "Register New Corridor"
            Layout.fillWidth: true
            Layout.preferredHeight: parent.height / 4 - buttonLayout.spacing
            onClicked: {
                stackView.push(
                            "qrc:/FlightPlannerScreen/FlightPlannerScreen.qml")
            }
        }

        MenuButton {
            id: routesButton
            imageSource: "qrc:/assets/routesIcon.png"
            buttonText: "List/Map Existing Corridors"
            Layout.fillWidth: true
            Layout.preferredHeight: parent.height / 4 - buttonLayout.spacing

            onClicked: {
                stackView.push("qrc:/RoutesScreen/RoutesScreen.qml")
            }
        }

        MenuButton {
            id: dronesButton
            //imageSource: "qrc:/assets/dronesIcon.png"
            buttonText: "Approve/Delete Corridors"
            Layout.fillWidth: true
            Layout.preferredHeight: parent.height / 4 - buttonLayout.spacing

            onClicked: {
                stackView.push("qrc:/ApproveCorridors/ApproveScreen.qml")
            }
        }
    }
}
