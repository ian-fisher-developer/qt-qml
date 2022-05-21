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

        Slider {
            id: nColsSlider
            orientation: Qt.Horizontal
            from: 1
            to: adjustableTableModel.maxNCols
            value: adjustableTableModel.defaultNCols
        }

        Slider {
            id: nRowsSlider
            orientation: Qt.Vertical
            from: adjustableTableModel.maxNRows
            to: 1
            value: adjustableTableModel.defaultNRows
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
