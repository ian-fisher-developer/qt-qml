import QtQuick
import AdjustableTableModel

Item {

    id: adjustableTable

    property int nRows: adjustableTableModel.nRowsMax
    property int nCols: adjustableTableModel.nColsMax

    AdjustableTableModel {
        id: adjustableTableModel
        nRows: adjustableTable.nRows
        nCols: adjustableTable.nCols
    }

    // Transient controls exercise implementation notes:
    //   - Remove the grid layout from the previous exercise to focus on the table
    //   - Add mouse areas to detect the pointer near the controls
    //     - Set hoverEnabled to detect mouse motion without a click
    //     - Accept no buttons so the underlying controls get them
    //   - Make the TableView interactive:false so it does not steal the control input
    //   - Show/hide the controls with a scale animation
    //   - Dim/brighten the table with an opacity animation

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
        Behavior on opacity {
           NumberAnimation { duration: 500; easing.type: Easing.InOutQuad  }
        }
    }

    AdjustableTableNColsControls {
        id: nColsControls
        x: adjustableTableView.x+100
        height: 100
        spacing: 30
    }
    MouseArea {
        anchors.fill: nColsControls
        hoverEnabled: true
        acceptedButtons: Qt.NoButton
        onEntered: { adjustableTableView.opacity = 0.2; nColsControls.scale = 1 }
        onExited: { adjustableTableView.opacity = 1; nColsControls.scale = 0 }
    }

    AdjustableTableNRowsControls {
        id: nRowsControls
        y: adjustableTableView.y+10
        width: 100
        spacing: 10
    }
    MouseArea {
        anchors.fill: nRowsControls
        hoverEnabled: true
        acceptedButtons: Qt.NoButton
        onEntered: { adjustableTableView.opacity = 0.2; nRowsControls.scale = 1 }
        onExited: { adjustableTableView.opacity = 1; nRowsControls.scale = 0 }
    }

}
