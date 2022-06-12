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

    // Transient controls exercise implementation notes: WORK IN PROGRESS
    // Remove the grid layout from the previous exercise, filling the window
    // with the table. Have the controls overlay when called for, then disappear.
    // Make the TableView interactive:false so it does not steal the control input
    // Add overlaying mouse areas to show/hide the controls -- accept no buttons so the underlying controls get them

    TableView {
        id: adjustableTableView
        x: 50
        y: 50
        interactive: false
        width: parent.width
        height: parent.height
        rowSpacing: 4
        columnSpacing: 10
        model: adjustableTableModel
        delegate: Text {
            text: display
        }
    }

    AdjustableTableNColsControls {
        id: nColsControls
        x: adjustableTableView.x+30
        height: 100
        spacing: 30
        visible: false
    }
    MouseArea {
        anchors.fill: nColsControls
        hoverEnabled: true
        onEntered: { adjustableTableView.opacity = 0.1; nColsControls.visible = true }
        onExited: { adjustableTableView.opacity = 1; nColsControls.visible = false }
        acceptedButtons: Qt.NoButton
    }

    AdjustableTableNRowsControls {
        id: nRowsControls
        y: adjustableTableView.y+10
        width: 100
        spacing: 10
        visible: false
    }
    MouseArea {
        anchors.fill: nRowsControls
        hoverEnabled: true
        onEntered: { adjustableTableView.opacity = 0.1; nRowsControls.visible = true }
        onExited: { adjustableTableView.opacity = 1; nRowsControls.visible = false }
        acceptedButtons: Qt.NoButton
    }

}
