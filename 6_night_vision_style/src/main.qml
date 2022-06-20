import QtQuick.Controls

// Night Vision Style exercise implementation notes:
// - Qt6 made significant changes to styling -- watch out for old documentation
// - Replace QtQuick's Window with QtQuick.Controls ApplicationWindow for a
//   better themed windoww that propagates styling to children
// - Add the qtquickcontrols2.conf file (and a CMakeLists.txt entry) to quickly
//   apply some global styling (this is just one of several styling techniques)
// - Had to hard-code "teal" in the AdjustableTable TableView :(

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
