import QtQuick.Controls

// Styling exercise implementation notes:
// - Qt6 made significant changes to styling -- be careful to avoid older documentation
// - Replace QtQuick's Window with QtQuick.Controls ApplicationWindow for a better native experience
// - Qt6.3 properly supports dark mode only on MSWindows, so consider a full styling solution... in progress

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
