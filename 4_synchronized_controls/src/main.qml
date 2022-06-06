import QtQuick

Window {
    width: 850
    height: 350
    visible: true
    title: qsTr("Synchronized Controls")

    AdjustableTable{
        width: parent.width
        height: parent.height
    }
}
