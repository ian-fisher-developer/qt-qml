import QtQuick.Controls


ApplicationWindow {
    width: 800
    height: 450
    visible: true
    title: qsTr("Night Vision Style")

    AdjustableTable{
        width: parent.width
        height: parent.height
    }
}
