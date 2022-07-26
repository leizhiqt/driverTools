import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

Item{
    id:root
    objectName: "rs422Page"
    //Recv - Send
    //12 - 12

    //第一行 通道 1-6
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
            width: col1.width / 6
            //通道号
            dfNum:1
        }

        //发送-接收组件
        GroupBox_RS422_Manchester{
            height: col1.height
            width: col1.width / 6
            //通道号
            dfNum:2
        }

        //发送-接收组件
        GroupBox_RS422_Recv_Send{
            height: col1.height
            width: col1.width / 6
            //通道号
            dfNum:3
        }

        //发送-接收组件
        GroupBox_RS422_Manchester{
            height: col1.height
            width: col1.width / 6
            //通道号
            dfNum:4
        }

        //发送-接收组件
        GroupBox_RS422_Recv_Send{
            height: col1.height
            width: col1.width / 6
            //通道号
            dfNum:5
        }

        //发送-接收组件
        GroupBox_RS422_Manchester{
            height: col1.height
            width: col1.width / 6
            //通道号
            dfNum:6
        }

    }

    //第二行 通道 7-12
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
            width: col1.width / 6
            //通道号
            dfNum:7
        }

        //发送-接收组件
        GroupBox_RS422_Manchester{
            height: col1.height
            width: col1.width / 6
            //通道号
            dfNum:8
        }

        //发送-接收组件
        GroupBox_RS422_Recv_Send{
            height: col1.height
            width: col1.width / 6
            //通道号
            dfNum:9
        }

        //发送-接收组件
        GroupBox_RS422_Manchester{
            height: col1.height
            width: col1.width / 6
            //通道号
            dfNum:10
        }


        //发送-接收组件
        GroupBox_RS422_Recv_Send{
            height: col1.height
            width: col1.width / 6
            //通道号
            dfNum:11
        }

        //发送-接收组件
        GroupBox_RS422_Manchester{
            height: col1.height
            width: col1.width / 6
            //通道号
            dfNum:12
        }

    }


    //第三行 通道 13-18
    Row{
        id:col3
        spacing: 1
        anchors.left: parent.left
        anchors.top: col2.bottom
        anchors.right: parent.right
        height: parent.height / 3

//        Repeater{
//            model:6

//            //发送-接收组件
//            GroupBox_RS422_Recv_Send{
//                height: col3.height
//                width: col3.width / 6
//                //通道号
//                dfNum:index+13
//            }



            //发送-接收组件
            GroupBox_RS422_Recv_Send{
                height: col1.height
                width: col1.width / 6
                //通道号
                dfNum:13
            }

            //发送-接收组件
            GroupBox_RS422_Manchester{
                height: col1.height
                width: col1.width / 6
                //通道号
                dfNum:14
            }

            //发送-接收组件
            GroupBox_RS422_Recv_Send{
                height: col1.height
                width: col1.width / 6
                //通道号
                dfNum:14
            }

            //发送-接收组件
            GroupBox_RS422_Manchester{
                height: col1.height
                width: col1.width / 6
                //通道号
                dfNum:16
            }


            //发送-接收组件
            GroupBox_RS422_Recv_Send{
                height: col1.height
                width: col1.width / 6
                //通道号
                dfNum:17
            }

            //发送-接收组件
            GroupBox_RS422_Manchester{
                height: col1.height
                width: col1.width / 6
                //通道号
                dfNum:18
            }

        }


    }
