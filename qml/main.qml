import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

ApplicationWindow {
    visible: true

    width: 1920
    height: 1000
    title: qsTr("便携式综合检测设备自检测软件 V1.0.2")

    minimumWidth: 1600
    minimumHeight: 900

    id:root
    objectName: "rootObject"

    onClosing: bus.close()

    //顶部快捷操作区
    Rectangle{
        id:rectTop
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.left: parent.left
        anchors.right: parent.right
        border.color: "black"
        height: 40

        /*Button{
            id:btnTestAll
            text: "便携式综合检测设备自检测软件"
            height: 40
            anchors.centerIn: parent


            onClicked: {
                console.log("clicked:便携式综合检测设备自检测软件")
            }
        }*/

    }

    //tab切换标签
    TabBar {
        id: bar
        anchors.top: rectTop.bottom
        anchors.topMargin: 1
        anchors.left: parent.left
        anchors.right: parent.right

        HZXTabButton {
            text: qsTr("RS422")
        }
        HZXTabButton {
            text: qsTr("RS232")
        }
        HZXTabButton {
            text: qsTr("ARINC429")
        }
        HZXTabButton {
            text: qsTr("离散量")
        }
        HZXTabButton {
            text: qsTr("一键测试")
        }
    }

    //tab页展示区
    Rectangle{
        id:rect
        anchors.top: bar.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 1
        border.color: "black"
        color: qsTr("white")

        StackLayout {
            anchors.fill: parent
            anchors.margins: 1

            currentIndex: bar.currentIndex

            //RS422
            Item {
                id: rs422Item

                PageRS422{
                    anchors.fill: parent
                }
            }




            //RS232
            Item {
                id:rs232Item

                PageRS232{
                    anchors.fill: parent
                }
            }

            //ARINC429
            Item {
                id: arinc429Item

                PageARINC429{
                    anchors.fill: parent
                }
            }

            //离散量
            Item {
                id: disItem

                PageDIO{
                    anchors.fill: parent
                }
            }

            //一键测试显示
            Item {
                id: dispItem

                PageDisp{
                    anchors.fill: parent
                }
            }

        }

    }


}
