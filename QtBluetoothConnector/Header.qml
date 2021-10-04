import QtQuick 2.0
import QtQuick.Controls 2.15

Item{
    anchors.horizontalCenter: parent.horizontalCenter
    id: item1
    ButtonGroup {
        id: btButtons
    }

    Column {
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 0
        spacing: 4
        Button {
            text: "Look for Xiaomi Smart Band 4"
            ButtonGroup.group: btButtons
            width: 300
            height: 50
            onClicked: btModel.startDeviceDiscovery()

        }

        Button {
            text: "Connect"
            ButtonGroup.group: btButtons
            width: 300
            height: 50
            enabled: btModel.enableConnection
            onClicked: btModel.connectToBand()
        }
        Button {
            text: "Get services"
            ButtonGroup.group: btButtons
            width: 300
            height: 50
            onClicked: btModel.getHeartRate()
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
