import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    width: 300
    height: 600
    visible: true
    title: qsTr("Tabs")

    Header{}

    Text{
        anchors.bottom: parent.bottom
        font.pointSize: 15
        color: "white"
        text: btModel.update
    }
}
