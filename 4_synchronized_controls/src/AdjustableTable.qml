import QtQuick
//import QtQuick.Controls
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

        AdjustableTableNColsControls {
            height: 100
            spacing: 30
        }

        AdjustableTableNRowsControls {
            width: 100
            spacing: 10
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
