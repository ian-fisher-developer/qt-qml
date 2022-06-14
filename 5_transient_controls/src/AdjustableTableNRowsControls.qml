import QtQuick
import QtQuick.Controls

Column {

    Behavior on scale {
       NumberAnimation { duration: 500; easing.type: Easing.InOutQuad  }
    }

    SpinBox {
        width: parent.width // needed to specify this for webassembly build -- shouldn't it happen automatically?
        from: 1
        to: adjustableTableModel.nRowsMax
        value: adjustableTable.nRows
        onValueChanged: {
            adjustableTable.nRows = value
        }
    }

    Dial {
        width: parent.width // needed to specify this for webassembly build -- shouldn't it happen automatically?
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
