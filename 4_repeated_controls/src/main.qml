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
            text: " " // empty top-left grid cell -- is there a more explicit item than empty text?
        }

        Row {
            Slider {
                id: nColsSlider
                orientation: Qt.Horizontal
                from: 1
                to: adjustableTableModel.nColsMax
                value: adjustableTableModel.nCols
            }
            Dial {
                from: nColsSlider.from
                to: nColsSlider.to
                value: nColsSlider.value
            }
        }

        Column {
            Slider {
                id: nRowsSlider
                orientation: Qt.Vertical
                from: adjustableTableModel.nRowsMax
                to: 1
                value: adjustableTableModel.nRows
            }
            Dial {
                from: nRowsSlider.to
                to: nRowsSlider.from
                value: nRowsSlider.value
            }
        }

        TableView {
            width: parent.width
            height: parent.height
            rowSpacing: 4
            columnSpacing: 10
            model: AdjustableTableModel {
                id: adjustableTableModel
                nRows: nRowsSlider.value
                nCols: nColsSlider.value
            }
            delegate: Text {
                text: display
            }
        }
    }
}
