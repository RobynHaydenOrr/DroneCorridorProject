import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

Window {
    width: 1280
    height: 832
    visible: true
    title: ("Drone Corridor Manager")

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: "qrc:/MainMenuScreen/MainMenuScreen.qml"
    }
}
