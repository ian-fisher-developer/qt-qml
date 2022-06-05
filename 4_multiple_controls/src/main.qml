import QtQuick

Window {
    width: 800
    height: 280
    visible: true
    title: qsTr("Synchronized Controls")

    AdjustableTable{
        width: parent.width
        height: parent.height
    }
}
