import QtQuick
import QtQuick.Controls

ApplicationWindow {
    width: 800
    height: 300
    visible: true
    title: qsTr("Styling")

    AdjustableTable{
        width: parent.width
        height: parent.height
    }
}
