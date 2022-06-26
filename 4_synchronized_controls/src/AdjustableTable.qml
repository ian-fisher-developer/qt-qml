import QtQuick
import AdjustableTableModel

Item {

    id: adjustableTable

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
