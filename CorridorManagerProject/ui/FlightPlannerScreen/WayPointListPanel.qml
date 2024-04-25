import QtQuick 2.15
import "../Components"

Rectangle {
    id: wayPointListPanel
    property int maxSpeed: 0
    property int maxTime: 0

    color: "#050505"

    function updateDroneSpecs() {
        var index = droneModel.index(flightPlannerScreen.droneIndex, 0)
        wayPointListPanel.maxSpeed = droneModel.data(index,
                                                     droneModel.maxSpeedRole)
        wayPointListPanel.maxTime = droneModel.data(index,
                                                    droneModel.maxTimeRole)
    }

    Text {
        id: titleText
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: parent.top
            topMargin: -10
        }

        font.pixelSize: 40
        color: "white"
        text: ("New Corridor")
    }

    Text {
        id: backButton

        anchors {
            verticalCenter: titleText.verticalCenter
            left: parent.left
            leftMargin: 10
        }

        color: "#464646"
        font.pixelSize: 40
        text: "<"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                if (flightPathManager.markerModel.rowCount() > 0)
                    flightPlannerScreen.createConfirmationDialog()
                else
                    stackView.pop()
            }
        }
    }

    Text {
        id: flightTimeLabel

        anchors {
            top: dronesComboBox.bottom
            topMargin: 5
            right: dronesComboBox.right
        }

        color: "white"
        font.pixelSize: 16

        //text: "Max Flight Time: " + wayPointListPanel.maxTime + "min"
    }

    ListView {
        id: wayPointListView
        model: flightPathManager.markerModel
        clip: true

        spacing: 15

        width: parent.width * 0.8

        anchors {
            top: flightTimeLabel.bottom
            topMargin: 20
            horizontalCenter: parent.horizontalCenter
            bottom: saveButton.top
            bottomMargin: 15
        }

        delegate: WayPointListViewDelegate {}

        Component.onCompleted: {
            flightPathManager.markerModel.markerModelChanged.connect(
                        scrollToBottom)
        }

        function scrollToBottom() {
            wayPointListView.model = 0
            wayPointListView.model = flightPathManager.markerModel

            wayPointListView.positionViewAtIndex(
                        flightPathManager.markerModel.rowCount() - 1,
                        ListView.End)
        }
    }

    StyledButton {
        id: saveButton

        width: parent.width * 0.25
        height: parent.height * 0.05

        anchors {
            horizontalCenter: parent.horizontalCenter
            bottom: parent.bottom
            bottomMargin: 20
        }

        buttonText: ("Save")

        onClicked: {
            flightPlannerScreen.createRouteNameDialog()
        }
    }
}
