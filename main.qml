import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.2
import IC 1.0

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: qsTr("Image Convert")

    menuBar: MenuBar{
        Menu{
            title: "File"
            MenuItem{
                text: "Close"
            }
        }

        Menu{
            title: "Option"
        }
    }

    toolBar: ToolBar{
        id: icToolbar
        RowLayout {
            anchors.fill: parent
            ToolButton {
                text: "New"
            }
            ToolButton {
                text: "Open"
                onClicked: {
                    fileDialog.open()

                }
            }
            ToolButton {
                text: "Convert"
                onClicked: {
                    icController.onConvert()
                }
            }
            Item { Layout.fillWidth: true }
            CheckBox {
                text: "Enabled"
                checked: true
                Layout.alignment: Qt.AlignRight
            }
        }
    }

    statusBar: StatusBar{
        Text{
            anchors.fill: parent
            text: icController.statusText
        }
    }

    FileDialog {
        id: fileDialog
        title: "Open Image"
        folder: shortcuts.home
        onAccepted: {
            icController.onOpenOriginalImage(fileDialog.fileUrl)
        }
        onRejected: {
        }
    }

    SplitView{
        id: mainSplit
        orientation: Qt.Vertical
        anchors.fill: parent
        Rectangle{
            height: parent.height * 0.8
            Layout.fillWidth: true
            border.width: 2
            border.color: "#cfcfcf"

            SplitView{
                id: imgSplit
                orientation: Qt.Horizontal
                anchors.fill: parent
                Rectangle{
                    Layout.fillHeight: true
                    width: parent.width * 0.5
                    anchors.margins: 5
                    border.width: 2
                    border.color: "#cfcfcf"

                    ICImageDisplay{
                        id: oriImageDisplay
                        anchors.fill: parent
                        Component.onCompleted: {
                            icController.setOriginalDisplay(oriImageDisplay);
                        }
                    }

                }

                Rectangle{
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    anchors.margins: 5
                    border.width: 2
                    border.color: "#cfcfcf"
                    ICImageDisplay{
                        id: convertedImageDisplay
                        anchors.fill: parent
                        Component.onCompleted: {
                            icController.setConvertedDisplay(convertedImageDisplay);
                        }
                    }
                }
            }

        }

        Rectangle{
            Layout.fillHeight: true
            Layout.fillWidth: true
            border.width: 2
            border.color: "#cfcfcf"
        }
    }

}
