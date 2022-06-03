// A custom slider control that started life as a copy of Qt's BasicSlider.
// Switched the handle rectangle for images; put color annotation alongside.

import QtQuick
import QtQuick.Controls.impl
import QtQuick.Templates as T

T.Slider {
    id: control

    implicitWidth: Math.max(implicitBackgroundWidth + leftInset + rightInset,
                            implicitHandleWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(implicitBackgroundHeight + topInset + bottomInset,
                             implicitHandleHeight + topPadding + bottomPadding)

    padding: 10
    leftInset: 5
    rightInset: 5
    topInset: 5
    bottomInset: 5

    handle: Image {
        source: control.horizontal ? "HorizontalSliderHandle" : "VerticalSliderHandle"
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
        color: "#00ffffff"
        scale: control.horizontal && control.mirrored ? -1 : 1

        Rectangle {
            // The left/upper color annotation
            x: control.horizontal ? leftInset+control.handle.width/2 : 0
            y: control.horizontal ? 0 : topInset+control.handle.height/2
            width: control.horizontal ? parent.width-leftInset-rightInset-control.handle.width : leftInset
            height: control.horizontal ? topInset : parent.height-topInset-bottomInset-control.handle.height
            gradient: ColdHotGradient {
                orientation: control.orientation
            }
            Repeater {
                // Mask the color annotation at intervals, for a pseudo-gradation effect
                model: 9
                Rectangle {
                    x: control.horizontal ? (index+1)*parent.width/10 : 0
                    y: control.horizontal ? 0 : (index+1)*parent.height/10
                    width: control.horizontal ? parent.width/100 : leftInset
                    height: control.horizontal ? topInset : parent.height/100
                    color: control.palette.window
                }
            }
            Rectangle {
                // Mask the color annotation beyond the control position
                x: control.horizontal ? control.handle.x : 0
                y: control.horizontal ? 0 : control.handle.y
                width: control.horizontal ? parent.width-control.handle.x : leftInset
                height: control.horizontal ? topInset : parent.height-control.handle.y
                color: control.palette.window
            }
        }

        Rectangle {
            // The lower/right color annotation
            x: control.horizontal ? leftInset+control.handle.width/2 : parent.width-rightInset
            y: control.horizontal ? parent.height-bottomInset : topInset+control.handle.height/2
            width: control.horizontal ? parent.width-leftInset-rightInset-control.handle.width : rightInset
            height: control.horizontal ? bottomInset : parent.height-topInset-bottomInset-control.handle.height
            gradient: ColdHotGradient {
                orientation: control.orientation
            }
            Repeater {
                // Mask the color annotation at intervals, for a pseudo-gradation effect
                model: 9
                Rectangle {
                    x: control.horizontal ? (index+1)*parent.width/10 : parent.width-rightInset
                    y: control.horizontal ? parent.height-bottomInset : (index+1)*parent.height/10
                    width: control.horizontal ? parent.width/100 : rightInset
                    height: control.horizontal ? bottomInset : parent.height/100
                    color: control.palette.window
                }
            }
            Rectangle {
                // Mask the color annotation beyond the control position
                x: control.horizontal ? control.handle.x : parent.width-rightInset
                y: control.horizontal ? parent.height-bottomInset : control.handle.y
                width: control.horizontal ? parent.width-control.handle.x : rightInset
                height: control.horizontal ? bottomInset : parent.height-control.handle.y
                color: control.palette.window
            }
        }
    }
}
