import QtQuick 2.15
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.15

ApplicationWindow {

    Material.theme: Material.Dark
    Material.accent: Material.color(Material.Red, Material.ShadeA700) //Material.Amber

    width: 400
    height: 700
    visible: true
    title: qsTr("Hello World")

    ToDoList {}
}
