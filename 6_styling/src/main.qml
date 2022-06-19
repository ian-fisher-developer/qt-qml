import QtQuick.Controls

// Styling exercise implementation notes:
// - Qt6 made significant changes to styling -- be careful to avoid older documentation
// - Replace QtQuick's Window with QtQuick.Controls ApplicationWindow for a better
//   window, and so that styling propagates to children
// - Add the qtquickcontrols2.conf file (and a CMakeLists.txt entry) to quickly apply some
//   global styling (may be overridden by other styling techniques)
// - The TableView does not get the dark-theme foreground color....IN PROGRESS

ApplicationWindow {
    width: 800
    height: 450
    visible: true
    title: qsTr("Styling")

    AdjustableTable{
        width: parent.width
        height: parent.height
    }
}
