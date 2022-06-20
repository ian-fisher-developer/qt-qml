import QtQuick
import AdjustableTableModel

Item {

    id: adjustableTable

    property int nRows: adjustableTableModel.nRowsMax
    property int nCols: adjustableTableModel.nColsMax
    property real dimmedOpacity: 0.3

    AdjustableTableModel {
        id: adjustableTableModel
        nRows: adjustableTable.nRows
        nCols: adjustableTable.nCols
    }

    TableView {
        id: adjustableTableView
        x: 50
        y: 50
        width: parent.width
        height: parent.height
        rowSpacing: 4
        columnSpacing: 10
        model: adjustableTableModel
        delegate: Text {
            text: display
            color: "teal" // Had to hard-code this, perhaps because TableView is not part of controls2...?
        }
        interactive: false
        Behavior on opacity {
           NumberAnimation { duration: 500; easing.type: Easing.InOutQuad  }
        }
    }

    AdjustableTableNColsControls {
        id: nColsControls
        x: adjustableTableView.x+100
        height: 100
        spacing: 30
        scale: 0
        Behavior on scale {
           NumberAnimation { duration: 500; easing.type: Easing.InOutQuad  }
        }
    }
    MouseArea {
        anchors.fill: nColsControls
        hoverEnabled: true
        acceptedButtons: Qt.NoButton
        onEntered: { adjustableTableView.opacity = dimmedOpacity; nColsControls.scale = 1 }
        onExited: { adjustableTableView.opacity = 1; nColsControls.scale = 0 }
    }

    AdjustableTableNRowsControls {
        id: nRowsControls
        y: adjustableTableView.y+10
        width: 100
        spacing: 10
        scale: 0
        Behavior on scale {
           NumberAnimation { duration: 500; easing.type: Easing.InOutQuad  }
        }
    }
    MouseArea {
        anchors.fill: nRowsControls
        hoverEnabled: true
        acceptedButtons: Qt.NoButton
        onEntered: { adjustableTableView.opacity = dimmedOpacity; nRowsControls.scale = 1 }
        onExited: { adjustableTableView.opacity = 1; nRowsControls.scale = 0 }
    }

}
