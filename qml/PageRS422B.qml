import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

Item{
    id:root
    objectName: "rs422PageB"
    //Recv - Send
    //12 - 12

    //第一行 通道 1~4
    Row{
        id:col1
        spacing: 1
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.right: parent.right
        height: parent.height / 3

        //发送-接收组件
        GroupBox_RS422_Recv_Send{
            height: col1.height
            width: col1.width / 4
            //通道号
            dfNum:1
        }

        //发送-接收组件
        GroupBox_RS422_Manchester{
            height: col1.height
            width: col1.width / 4
            //通道号
            dfNum:2
        }

        //发送-接收组件
        GroupBox_RS422_Recv_Send{
            height: col1.height
            width: col1.width / 4
            //通道号
            dfNum:3
        }

        //发送-接收组件
        GroupBox_RS422_Manchester{
            height: col1.height
            width: col1.width / 4
            //通道号
            dfNum:4
        }

    }

    //第二行 通道 5~8
    Row{
        id:col2
        spacing: 1
        anchors.left: parent.left
        anchors.top: col1.bottom
        anchors.right: parent.right
        height: parent.height / 3

        //发送-接收组件
        GroupBox_RS422_Recv_Send{
            height: col1.height
            width: col1.width / 4
            //通道号
            dfNum:5
        }

        //发送-接收组件
        GroupBox_RS422_Manchester{
            height: col1.height
            width: col1.width / 4
            //通道号
            dfNum:6
        }

        //发送-接收组件
        GroupBox_RS422_Recv_Send{
            height: col1.height
            width: col1.width / 4
            //通道号
            dfNum:7
        }

        //发送-接收组件
        GroupBox_RS422_Manchester{
            height: col1.height
            width: col1.width / 4
            //通道号
            dfNum:8
        }
    }


    //第三行 通道 9~12
    Row{
        id:col3
        spacing: 1
        anchors.left: parent.left
        anchors.top: col2.bottom
        anchors.right: parent.right
        height: parent.height / 3

        Repeater{
            model:4

            //发送-接收组件
            GroupBox_RS422_Recv_Send{
                height: col3.height
                width: col3.width / 4

                //通道号
                dfNum:index + 9
            }
        }
    }



}
