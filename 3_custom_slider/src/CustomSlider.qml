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


    handle: Image {
        source: "VerticalSliderHandle"
        sourceSize.width: 50
        sourceSize.height: 50
        x: control.leftPadding + (control.horizontal ? control.visualPosition * (control.availableWidth - width) : (control.availableWidth - width) / 2)
        y: control.topPadding + (control.horizontal ? (control.availableHeight - height) / 2 : control.visualPosition * (control.availableHeight - height))
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
            // The left/upper colorbar
            width: control.horizontal ? parent.width : 3
            height: control.horizontal ? 3 : parent.height
            gradient: ColdHotGradient {
                orientation: control.orientation
            }
        }

        Rectangle {
            // The lower/right color bar
            // Note that X/Y positions are relative to the parent.
            x: control.horizontal ? 0 : parent.width
            y: control.horizontal ? parent.height: 0
            width: control.horizontal ? parent.width : 3
            height: control.horizontal ? 3 : parent.height
            gradient: ColdHotGradient {
                orientation: control.orientation
            }
        }
    }
}
