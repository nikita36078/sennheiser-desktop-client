import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Qt5Compat.GraphicalEffects


Rectangle {
    id: root
    width: 400
    height: 100
    radius: 20
    color: root.palette.window
    border.color: root.palette.mid
    clip: true
    property real maskPosition: 0

    SoundCardHelper {
        id: helper
    }

    Image {
        id: cardIcon
        source: "qrc:/icons/waveform.path.badge.minus.svg"
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.leftMargin: 10
        anchors.rightMargin: 10
        anchors.topMargin: 10
        width: 36
        fillMode: Image.PreserveAspectFit
    }
    Colorize {
        visible: !UiHelper.isDarkTheme
        anchors.fill: cardIcon
        source: cardIcon
        hue: .0
        saturation: 0
        lightness:  -1
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.leftMargin: 10
        anchors.rightMargin: 10
        anchors.topMargin: 10
        spacing: 20

        Label {
            text: "Audio Mode"
            font.bold: true
        }

        RowLayout {
            Layout.minimumWidth: root.width - 20
            Layout.fillHeight: false
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            layoutDirection: Qt.LeftToRight
            uniformCellSizes: true
            spacing: 20
            Layout.fillWidth: true

            Button {
                id: buttonModeFlat
                width: 30
                text: "Flat"
                spacing: 5
                autoExclusive: true
                checked: helper.audioMode === 3
                checkable: true
                onClicked: {
                    helper.audioMode = 3;
                }
            }
            Button {
                id: buttonModeVoice
                width: 30
                text: "Podcast"
                autoExclusive: true
                checked: helper.audioMode === 2
                checkable: true
                onClicked: {
                    helper.audioMode = 2;
                }
            }
            Button {
                id: buttonModeEq
                width: 30
                text: "User EQ"
                autoExclusive: true
                checked: helper.audioMode === 1
                checkable: true
                onClicked: {
                    helper.audioMode = 1;
                }
            }

        }

        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
    }

}
