import QtQuick

Window {
    width: 800
    height: 300
    visible: true
    title: qsTr("Transient Controls")

    AdjustableTable{
        width: parent.width
        height: parent.height
    }
}
