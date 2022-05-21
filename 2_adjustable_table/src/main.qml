import QtQuick
import QtQuick.Controls
import AdjustableTableModel

Window {
    width: 800
    height: 250
    visible: true
    color: "gray"
    title: qsTr("Adjustable Table")

    Grid {
        columns: 2
        spacing: 20
        width: parent.width
        height: parent.height

        Text {
            text: " "
        }

        Row {
            Slider {
                id: nColsSlider
                orientation: Qt.Horizontal
                from: 1
                to: 26
                value: 5
            }
        }

        Slider {
            id: nRowsSlider
            orientation: Qt.Vertical
            from: 10
            to: 1
            value: 6
        }

        TableView {
            width: parent.width
            height: parent.height
            rowSpacing: 4
            columnSpacing: 10
            model: AdjustableTableModel {
                nRows: nRowsSlider.value
                nCols: nColsSlider.value
            }
            delegate: Text {
                text: display
            }
        }
    }
}
