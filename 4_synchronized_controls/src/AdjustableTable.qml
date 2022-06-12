import QtQuick
import QtQuick.Controls
import AdjustableTableModel

Item {

    id: adjustableTable

    // Synchronized controls exercise implementation notes:
    // - synchronizing many items suggests common properties
    // - the six controls and the table all depend on the common properties
    //   - when a common property changes all its dependencies update
    // - the dependencies are uni-directional
    //   - to complete the synchronization, each control actively updates
    //     the corresponding common property when its value changes

    property int nRows: 5
    property int nCols: 8

    AdjustableTableModel {
        id: adjustableTableModel
        nRows: adjustableTable.nRows
        nCols: adjustableTable.nCols
    }

    Grid {
        columns: 2
        spacing: 20
        width: parent.width
        height: parent.height

        Text {
            text: " " // empty top-left grid cell -- is there a more explicit item than empty text?
        }

        Row {
            height: 100
            spacing: 30
            SpinBox {
                anchors.verticalCenter: parent.verticalCenter
                from: 1
                to: adjustableTableModel.nColsMax
                value: adjustableTable.nCols
                onValueChanged: {
                    adjustableTable.nCols = value
                }
            }
            Dial {
                height: parent.height
                from: 1
                to: adjustableTableModel.nColsMax
                value: adjustableTable.nCols
                onValueChanged: {
                    adjustableTable.nCols = value
                }
            }
            Slider {
                orientation: Qt.Horizontal
                anchors.verticalCenter: parent.verticalCenter
                from: 1
                to: adjustableTableModel.nColsMax
                value: adjustableTable.nCols
                onValueChanged: {
                    adjustableTable.nCols = value
                }
            }
        }

        Column {
            width: 100
            spacing: 10
            SpinBox {
                width: parent.width // needed to specify this -- shouldn't it happen automatically?
                from: 1
                to: adjustableTableModel.nRowsMax
                value: adjustableTable.nRows
                onValueChanged: {
                    adjustableTable.nRows = value
                }
            }
            Dial {
                width: parent.width // needed to specify this -- shouldn't it happen automatically?
                from: 1
                to: adjustableTableModel.nRowsMax
                value: adjustableTable.nRows
                onValueChanged: {
                    adjustableTable.nRows = value
                }
            }
            Slider {
                orientation: Qt.Vertical
                anchors.horizontalCenter: parent.horizontalCenter
                from: adjustableTableModel.nRowsMax
                to: 1
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
            model: adjustableTableModel
            delegate: Text {
                text: display
            }
        }
    }
}
