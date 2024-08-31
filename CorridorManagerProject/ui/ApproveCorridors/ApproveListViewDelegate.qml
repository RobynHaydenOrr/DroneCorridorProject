import QtQuick 2.15

Rectangle {
    id: approveListViewDelegate
    property bool currentlySelected: (index === approveScreen.currentlySelectedRouteIndex)
    color: (approveListViewDelegate.currentlySelected ? "#007EC6" : "#464646")
    clip: true
    width: parent.width
    height: 121
    radius: 5

    Text {
        id: routeName
        color: "white"
        font.pixelSize: 16
        anchors {
            left: parent.left
            top: parent.top
            margins: 10
        }
        text: model.name
    }

    Text {
        id: distanceLabel
        color: "white"
        font.pixelSize: 16
        anchors {
            left: parent.left
            bottom: parent.bottom
            margins: 10
        }
        text: model.distance.toFixed(1) + (" km")
    }

    Text {
        id: wayPointCountLabel
        color: "white"
        font.pixelSize: 16
        anchors {
            left: parent.left
            leftMargin: 10
            verticalCenter: parent.verticalCenter
        }
        text: model.waypointcount + (" Waypoints")
    }

    Text {
        id: approveLabel
        color: "white"
        font.pixelSize: 16
        anchors {
            right: parent.right
            rightMargin: 10
            verticalCenter: parent.verticalCenter
        }
        text: ("Approved:") + model.approved
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            if (!approveListViewDelegate.currentlySelected) {
                approveScreen.currentlySelectedRouteIndex = index
                fileHandler.loadRoute(model.name)
            } else
                approveScreen.currentlySelectedRouteIndex = -1
        }
    }

    Image {
        id: deleteButton

        visible: approveListViewDelegate.currentlySelected

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
                flightPathManager.reset()
                fileHandler.removeSavedRoute(model.name)
            }
            onPressed: deleteMouseArea.isPressed = true
            onReleased: deleteMouseArea.isPressed = false
        }
        fillMode: Image.PreserveAspectFit
        source: (deleteMouseArea.isPressed ? "qrc:/assets/no.png" : "qrc:/assets/no.png")
    }

    Image {
        id: approveButton

        visible: approveListViewDelegate.currentlySelected

        width: parent.height * 0.2
        height: width

        anchors {
            right: parent.right
            bottom: parent.bottom
            margins: 5
        }

        MouseArea {
            id: approveMouseArea
            property bool isPressed: false
            anchors.fill: parent
            onClicked: {
                flightPathManager.reset()
                fileHandler.updateRouteApproval(model.name, true)
            }
            onPressed: approveMouseArea.isPressed = true
            onReleased: approveMouseArea.isPressed = false
        }
        fillMode: Image.PreserveAspectFit
        source: (approveMouseArea.isPressed ? "qrc:/assets/yes.png" : "qrc:/assets/yes.png")
    }
}
