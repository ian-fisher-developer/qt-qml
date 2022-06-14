import QtQuick
import QtQuick.Controls

Row {

    Behavior on scale {
       NumberAnimation { duration: 500; easing.type: Easing.InOutQuad  }
    }

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

