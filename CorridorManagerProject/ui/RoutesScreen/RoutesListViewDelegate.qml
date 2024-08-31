import QtQuick 2.15

Rectangle {
    id: routesListViewDelegate
    property bool currentlySelected: (index === routesScreen.currentlySelectedRouteIndex)
    color: (routesListViewDelegate.currentlySelected ? "#007EC6" : "#464646")
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
        id: approved
        color: "white"
        font.pixelSize: 16
        anchors {
            right: parent.right
            top: parent.top
            margins: 10
        }
        text: ("Approved: ") + model.approved
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

    MouseArea {
        anchors.fill: parent
        onClicked: {
            if (!routesListViewDelegate.currentlySelected) {
                routesScreen.currentlySelectedRouteIndex = index
                fileHandler.loadRoute(model.name)
            } else
                routesScreen.currentlySelectedRouteIndex = -1
        }
    }
}
