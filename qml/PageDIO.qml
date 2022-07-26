import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

Item{
    id:root
    objectName: "dioPage"
    //16收 - 16发

    //第一行 端口 1~9
    Row{
        id:col1
        spacing: 1
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.right: parent.right
        height: parent.height / 3

        //发送-接收组件
        GroupBox_DIO_Recv_Send{
            height: col1.height
            width: col1.width / 9

            //端口号
            dfNum:1
        }
        GroupBox_DIO_Recv_Send{
            height: col1.height
            width: col1.width / 9

            //端口号
            dfNum:2
        }
        GroupBox_DIO_Recv_Send{
            height: col1.height
            width: col1.width / 9

            //端口号
            dfNum:3
        }
        GroupBox_DIO_Recv_Send{
            height: col1.height
            width: col1.width / 9

            //端口号
            dfNum:4
        }
        GroupBox_DIO_Recv_Send{
            height: col1.height
            width: col1.width / 9

            //端口号
            dfNum:5
        }
        GroupBox_DIO_Recv_Send{
            height: col1.height
            width: col1.width / 9

            //端口号
            dfNum:6
        }
        GroupBox_DIO_Recv_Send{
            height: col1.height
            width: col1.width / 9
            //端口号
            dfNum:7
        }
        GroupBox_DIO_Recv_Send{
            height: col1.height
            width: col1.width / 9

            //端口号
            dfNum:8
        }
        GroupBox_DIO_Recv_Send{
            height: col1.height
            width: col1.width / 9
            //端口号
            dfNum:9
        }

    }

    //第二行 端口 10~18
    Row{
        id:col2
        spacing: 1
        anchors.left: parent.left
        anchors.top: col1.bottom
        anchors.right: parent.right
        height: parent.height / 3

        GroupBox_DIO_Recv_Send{
            height: col2.height
            width: col2.width / 9

            //端口号
            dfNum: 10
        }
        GroupBox_DIO_Recv_Send{
            height: col2.height
            width: col2.width / 9

            //端口号
            dfNum: 11
        }
        GroupBox_DIO_Recv_Send{
            height: col2.height
            width: col2.width / 9

            //端口号
            dfNum: 12
        }

        GroupBox_DIO_Recv_Send{
            height: col2.height
            width: col2.width / 9

            //端口号
            dfNum: 13
        }
        GroupBox_DIO_Recv_Send{
            height: col2.height
            width: col2.width / 9

            //端口号
            dfNum: 14
        }
        GroupBox_DIO_Recv_Send{
            height: col2.height
            width: col2.width / 9

            //端口号
            dfNum: 15
        }
        GroupBox_DIO_Recv_Send{
            height: col2.height
            width: col2.width / 9

            //端口号
            dfNum: 16
        }
        GroupBox_DIO_Recv_Send{
            height: col2.height
            width: col2.width / 9

            //端口号
            dfNum: 17
        }
        GroupBox_DIO_Recv_Send{
            height: col2.height
            width: col2.width / 9

            //端口号
            dfNum: 18
        }

    }

    //第二行 端口 19~25
    Row{
        id:col3
        spacing: 1
        anchors.left: parent.left
        anchors.top: col2.bottom
        anchors.right: parent.right
        height: parent.height / 3

        GroupBox_DIO_Recv_Send{
            height: col2.height
            width: col2.width / 9

            //端口号
            dfNum: 19
        }
        GroupBox_DIO_Recv_Send{
            height: col2.height
            width: col2.width / 9

            //端口号
            dfNum: 20
        }
        GroupBox_DIO_Recv_Send{
            height: col2.height
            width: col2.width / 9

            //端口号
            dfNum: 21
        }

        GroupBox_DIO_Recv_Send{
            height: col2.height
            width: col2.width / 9

            //端口号
            dfNum: 22
        }
        GroupBox_DIO_Recv_Send{
            height: col2.height
            width: col2.width / 9

            //端口号
            dfNum: 23
        }
        GroupBox_DIO_Recv_Send{
            height: col2.height
            width: col2.width / 9

            //端口号
            dfNum: 24
        }
        GroupBox_DIO_Recv_Send{
            height: col2.height
            width: col2.width / 9

            //端口号
            dfNum: 25
        }



    }

}
