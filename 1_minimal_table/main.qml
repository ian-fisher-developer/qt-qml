import QtQuick 2.12
import QtQuick.Window 2.12
import MinimalTableModel 1.0

Window {
    visible: true
    width: 150
    height: 150
    title: qsTr("Minimal Table")

    TableView {
        anchors.margins: 20
        anchors.fill: parent

        model: MinimalTableModel {}

        delegate: Rectangle {
            Text {
                text: display
            }
        }
    }

}
