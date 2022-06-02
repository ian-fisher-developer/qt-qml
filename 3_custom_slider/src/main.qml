import QtQuick
import QtQuick.Controls
import AdjustableTableModel

Window {
    width: 800
    height: 320
    visible: true
    title: qsTr("Adjustable Table")

    Grid {
        columns: 2
        spacing: 20
        width: parent.width
        height: parent.height

        Text {
            text: " " // empty top-left grid cell -- is there a more explicit item than empty text?
        }

        CustomSlider {
            id: nColsControl
            orientation: Qt.Horizontal
            from: 1
            to: adjustableTableModel.nColsMax
            value: adjustableTableModel.nColsDefault
        }

        CustomSlider {
            id: nRowsControl
            orientation: Qt.Vertical
            from: adjustableTableModel.nRowsMax
            to: 1
            value: adjustableTableModel.nRowsDefault
        }

        TableView {
            width: parent.width
            height: parent.height
            rowSpacing: 4
            columnSpacing: 10
            model: AdjustableTableModel {
                id: adjustableTableModel
                nRows: nRowsControl.value
                nCols: nColsControl.value
            }
            delegate: Text {
                text: display
            }
        }
    }
}
