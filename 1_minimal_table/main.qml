import QtQuick 2.12
import QtQuick.Window 2.12
import MinimalTableModel 1.0

Window {
    visible: true
    width: 900
    height: 900
    title: qsTr("Minimal Table")

    TableView {
        anchors.fill: parent

        model: MinimalTableModel {}

        delegate: Rectangle {
            Text {
                text: display
            }
        }
    }

}
