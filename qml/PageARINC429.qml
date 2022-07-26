import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

Item{
    id:root
    objectName: "arinc429Page"
    //6收 - 5发

    //第一行 通道 1~3
    Row{
        id:col1
        spacing: 1
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.right: parent.right
        height: parent.height / 2

        GroupBox_ARINC429_Recv_Send{
            height: col1.height
            width: col1.width / 4
            //通道号
            dfNum: 1
        }

        GroupBox_ARINC429_Recv_Send{
            height: col1.height
            width: col1.width / 4
            //通道号
            dfNum:2
        }


        //发送-接收组件
        GroupBox_ARINC429_Recv_Send{
            height: col1.height
            width: col1.width / 4
            //通道号
            dfNum:3
        }

        //发送-接收组件
        GroupBox_ARINC429_Recv_Send{
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
        height: parent.height / 2

        GroupBox_ARINC429_Recv_Send{
            height: col2.height
            width: col2.width / 4

            //通道号
            dfNum:5
        }

        GroupBox_ARINC429_Recv_Send{
            height: col2.height
            width: col2.width / 4

            //通道号
            dfNum:6
        }
        GroupBox_ARINC429_Recv_Send{
            height: col2.height
            width: col2.width / 4

            //通道号
            dfNum:7
        }

        GroupBox_ARINC429_Recv_Send{
            height: col2.height
            width: col2.width / 4

            //通道号
            dfNum:8
        }
        //单接收组件
//        GroupBox_ARINC429_Recv{
//            height: col2.height
//            width: col2.width / 4

//            //通道号
//            dfNum:8
//        }

    }

}
