import QtQuick 2.15
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.15

import ToDo 1.0


// FIXME: column layout need to be full screen
ColumnLayout{
    Frame {
        ListView{
            implicitHeight: 400
            implicitWidth: 500
            clip: true // Forces items outside the frame to hide

            model: ToDoModel {
                list: toDoList
            }

            delegate: RowLayout {
                width: parent.width

                CheckBox {
                    checked: model.done
                    onClicked: model.done = checked
                }
                TextField {
                    text: model.description
                    onEditingFinished: model.description = text
                    Layout.fillWidth: true
                }
            }
        }
    }

    RowLayout {
        Button {
            text: qsTr("Add new item")
            onClicked: toDoList.appendItem()
        }
        Button {
            text: qsTr("Remove completed")
            onClicked: toDoList.removeCompletedItems()
        }
    }
}
