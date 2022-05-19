import QtQuick 2.12
import QtQuick.Window 2.12
import AdjustableTableModel 1.0

Window {
    visible: true
    width: 200
    height: 150
    title: qsTr("Adjustable Table")

    TableView {
        anchors.margins: 20
        anchors.fill: parent

        model: AdjustableTableModel{
            nRows: 2
            nCols: 3
        }

        delegate: Rectangle {
            Text {
                text: display
            }
        }
    }
}
