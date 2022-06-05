import QtQuick
import QtQuick.Controls
import AdjustableTableModel

Item {

    // Synchronized controls exercise implementation notes:
    // - synchronizing many items suggests common properties
    // - the six controls and the table all depend on the common properties
    //   - when a common property changes all its dependencies update
    // - the dependencies are uni-directional
    //   - to complete the synchronization, each control actively updates
    //     the corresponding common property when its value changes

    id: adjustableTable
    property int nRows: 5
    property int nCols: 8

    Grid {
        columns: 2
        spacing: 20
        width: parent.width
        height: parent.height

        Text {
            text: " " // empty top-left grid cell -- is there a more explicit item than empty text?
        }

        Row {
            height: 30
            spacing: 30
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
                height: parent.height
                from: 1
                to: adjustableTableModel.nColsMax
                value: adjustableTable.nCols
                onValueChanged: {
                    adjustableTable.nCols = value
                }
            }
        }

        Column {
            width: 30
            spacing: 10
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
                width: parent.width // needed to specify this -- shouldn't it happen automatically?
                from: 1
                to: adjustableTableModel.nRowsMax
                value: adjustableTable.nRows
                onValueChanged: {
                    adjustableTable.nRows = value
                }
            }
            Dial {
                id: nRowsDial
                width: parent.width // needed to specify this -- shouldn't it happen automatically?
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
