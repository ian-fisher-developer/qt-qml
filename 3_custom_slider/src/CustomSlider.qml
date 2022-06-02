// A custom slider control that started life as a copy of Qt's BasicSlider.

import QtQuick
import QtQuick.Controls.impl
import QtQuick.Templates as T

T.Slider {
    id: control

    implicitWidth: Math.max(implicitBackgroundWidth + leftInset + rightInset,
                            implicitHandleWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(implicitBackgroundHeight + topInset + bottomInset,
                             implicitHandleHeight + topPadding + bottomPadding)

    padding: 6

    handle: Rectangle {
        x: control.leftPadding + (control.horizontal ? control.visualPosition * (control.availableWidth - width) : (control.availableWidth - width) / 2)
        y: control.topPadding + (control.horizontal ? (control.availableHeight - height) / 2 : control.visualPosition * (control.availableHeight - height))
        implicitWidth: control.horizontal ? 40 : 20
        implicitHeight: control.horizontal ? 20: 40
        radius: 3
        color: control.pressed ? control.palette.light : control.palette.window
        border.width: control.visualFocus ? 2 : 1
        border.color: control.visualFocus ? control.palette.highlight : control.enabled ? control.palette.mid : control.palette.midlight
    }

    background: Rectangle {
        x: control.leftPadding + (control.horizontal ? 0 : (control.availableWidth - width) / 2)
        y: control.topPadding + (control.horizontal ? (control.availableHeight - height) / 2 : 0)
        implicitWidth: control.horizontal ? 200 : 6
        implicitHeight: control.horizontal ? 6 : 200
        width: control.horizontal ? control.availableWidth : implicitWidth
        height: control.horizontal ? implicitHeight : control.availableHeight
        radius: 3
        //color: control.palette.midlight
        color: "#00ffffff"
        scale: control.horizontal && control.mirrored ? -1 : 1

        Rectangle {
            width: control.horizontal ? parent.width : 3
            height: control.horizontal ? 3 : parent.height
            gradient: Gradient {
                orientation: control.orientation
                GradientStop { position: 0.0; color: "blue" }
                GradientStop { position: 0.4; color: "green" }
                GradientStop { position: 0.6; color: "yellow" }
                GradientStop { position: 0.7; color: "orange" }
                GradientStop { position: 1.0; color: "red" }
            }
        }

        Rectangle {
            x: control.horizontal ? x : x + parent.width
            y: control.horizontal ? y + parent.height : y
            width: control.horizontal ? parent.width : 3
            height: control.horizontal ? 3 : parent.height
            gradient: Gradient {
                orientation: control.orientation
                GradientStop { position: 0.0; color: "blue" }
                GradientStop { position: 0.4; color: "green" }
                GradientStop { position: 0.6; color: "yellow" }
                GradientStop { position: 0.7; color: "orange" }
                GradientStop { position: 1.0; color: "red" }
            }
        }
    }
}
