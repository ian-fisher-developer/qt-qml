import QtQuick
import QtQuick.Controls
import AdjustableTableModel

Item {

    id: adjustableTable
    property int nRows: 3
    property int nCols: 5

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
                value: adjustableTable.nCols
                onValueChanged: {
                    adjustableTable.nCols = value
                }
            }
            SpinBox {
                id: nColsSpinBox
                from: 1
                to: adjustableTableModel.nColsMax
                value: adjustableTable.nCols
                onValueChanged: {
                    adjustableTable.nCols = value
                }
            }
            Dial {
                id: nColsDial
                from: 1
                to: adjustableTableModel.nColsMax
                value: adjustableTable.nCols
                onValueChanged: {
                    adjustableTable.nCols = value
                }
            }
        }

        Column {
            Slider {
                id: nRowsSlider
                orientation: Qt.Vertical
                from: adjustableTableModel.nRowsMax
                to: 1
                value: adjustableTable.nRows
                onValueChanged: {
                    adjustableTable.nRows = value
                }
            }
            SpinBox {
                id: nRowsSpinBox
                from: 1
                to: adjustableTableModel.nRowsMax
                value: adjustableTable.nRows
                onValueChanged: {
                    adjustableTable.nRows = value
                }
            }
            Dial {
                id: nRowsDial
                from: 1
                to: adjustableTableModel.nRowsMax
                value: adjustableTable.nRows
                onValueChanged: {
                    adjustableTable.nRows = value
                }
            }
        }

        TableView {
            width: parent.width
            height: parent.height
            rowSpacing: 4
            columnSpacing: 10
            model: AdjustableTableModel {
                id: adjustableTableModel
                nRows: adjustableTable.nRows
                nCols: adjustableTable.nCols
            }
            delegate: Text {
                text: display
            }
        }
    }
}
