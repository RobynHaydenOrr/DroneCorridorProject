import QtQuick 2.15
import QtQuick.Controls 2.15
import "../Components"

Rectangle {
    id: wayPointListViewDelegate

    property bool currentlySelected: (index === flightPlannerScreen.currentSelectedWayPoint)

    clip: false
    width: parent.width
    height: 121

    radius: 5

    color: {
        (wayPointListViewDelegate.currentlySelected ? "#007EC6" : "#464646")
    }

    Text {
        id: waypointLabelText
        anchors {
            top: parent.top
            left: parent.left
            margins: 5
        }

        color: "white"
        font.pixelSize: 16

        text: ("Waypoint ") + index
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            if (!wayPointListViewDelegate.currentlySelected)
                flightPlannerScreen.currentSelectedWayPoint = index
            else
                flightPlannerScreen.currentSelectedWayPoint = -1
        }
    }

    Image {
        id: deleteButton

        visible: wayPointListViewDelegate.currentlySelected

        width: parent.height * 0.2
        height: width

        anchors {
            right: parent.right
            top: parent.top
            margins: 5
        }

        MouseArea {
            id: deleteMouseArea
            property bool isPressed: false
            anchors.fill: parent
            onClicked: {
                flightPathManager.removeMarker(index)
            }
            onPressed: deleteMouseArea.isPressed = true
            onReleased: deleteMouseArea.isPressed = false
        }
        fillMode: Image.PreserveAspectFit
        source: (deleteMouseArea.isPressed ? "qrc:/assets/no.png" : "qrc:/assets/no.png")
    }

    Text {
        id: coordsLabel
        anchors {
            horizontalCenter: parent.horizontalCenter
            bottom: distanceTraveledLabel.top
            margins: 5
        }

        color: "white"
        font.pixelSize: 16

        text: model.latitude + "," + model.longitude
    }

    Text {
        id: distanceTraveledLabel
        anchors {
            right: parent.right
            bottom: remainingTimeLabel.top
            margins: 0
        }

        color: "white"
        font.pixelSize: 16

        text: ("Distance: ") + model.totaldistance.toFixed(1) + "km"
    }

    Text {
        id: remainingTimeLabel
        anchors {
            right: parent.right
            bottom: parent.bottom
            margins: 0
        }

        color: "white"
        font.pixelSize: 16

        //text: ("Remaining: ") + (wayPointListPanel.maxTime - model.totaltime).toFixed(
        //          1) + "min"
    }
}
