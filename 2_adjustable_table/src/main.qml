import QtQuick
import QtQuick.Controls
import AdjustableTableModel

Window {
    visible: true
    width: 600
    height: 600
    title: qsTr("Adjustable Table")

    Grid {
        columns: 2
        spacing: 20
        width: parent.width
        height: parent.height

        Text {
            text: " "
        }

        Slider {
             id: nColsSlider
             orientation: Qt.Horizontal
             from: 1
             to: 10
             value: 5
         }

        Slider {
            id: nRowsSlider
            orientation: Qt.Vertical
            from: 10
            to: 1
            value: 3
        }

       TableView {
            width: parent.width
            height: parent.height
            model: AdjustableTableModel{
                nRows: nRowsSlider.value
                nCols: nColsSlider.value
            }
            delegate: Rectangle {
                Text {
                    text: display
                }
            }
        }
    }
}
