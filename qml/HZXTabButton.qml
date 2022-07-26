import QtQuick 2.0
import QtQuick.Controls 2.5

TabButton {
    text: qsTr("tabButton")

    font.family: qsTr("微软雅黑")
    font.pixelSize: 14
    font.weight: checked ? Font.Black : Font.Normal
    height: 35
    background: Rectangle {
        color: parent.checked ? "#cccccc" : "white"
        border.color: "black"
    }
    contentItem: Text {
        text: parent.text
        font: parent.font
        color: "black"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
}
