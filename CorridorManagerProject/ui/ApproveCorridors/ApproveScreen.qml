import QtQuick 2.15

Item {
    id: approveScreen

    property int currentlySelectedRouteIndex: -1

    ApproveListPanel {
        id: leftSideBG
        width: parent.width * 0.35
        height: parent.height
        anchors {
            left: parent.left
            top: parent.top
        }
    }

    ApproveMapPanel {
        id: mapPanel

        anchors {
            left: leftSideBG.right
            top: parent.top
            right: parent.right
            bottom: parent.bottom
        }
    }
}
