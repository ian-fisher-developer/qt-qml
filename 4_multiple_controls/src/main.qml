import QtQuick

Window {
    width: 800
    height: 250
    visible: true
    title: qsTr("Multiple Controls")

    AdjustableTable{
        width: parent.width
        height: parent.height
    }
}
