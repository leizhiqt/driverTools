import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

Item{
    id:root
    objectName: "rs232Page"
    //10收 - 10发

    //第一行 发送通道 1~5
    Row{
        id:col1
        //spacing: 1
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.right: parent.right
        height: parent.height / 3
        objectName: "rs232row"


        GroupBox_RS232_Recv_Send{
            height: col1.height
            width: col1.width / 5
            objectName: "rs232GroupBox1"
            //通道号
            dfNum:1
        }


        GroupBox_RS232_Recv_Send{
            height: col1.height
            width: col1.width / 5
            objectName: "rs232GroupBox2"
            //通道号
            dfNum:2
        }


        GroupBox_RS232_Recv_Send{
            height: col1.height
            width: col1.width / 5
            objectName: "rs232GroupBox3"
            //通道号
            dfNum:3
        }


        GroupBox_RS232_Recv_Send{
            height: col1.height
            width: col1.width / 5
            objectName: "rs232GroupBox4"
            //通道号
            dfNum:4
        }


        GroupBox_RS232_Recv_Send{
            height: col1.height
            width: col1.width / 5
            objectName: "rs232GroupBox5"
            //通道号
            dfNum:5
        }

    }

    //第二行 发送通道 6~10
    Row{
        id:col2
        //spacing: 1
        anchors.left: parent.left
        anchors.top: col1.bottom
        anchors.right: parent.right
        height: parent.height / 3
        objectName: "rs232row"



        GroupBox_RS232_Recv_Send{
            height: col2.height
            width: col2.width / 5
            //通道号
            dfNum:6
        }


        GroupBox_RS232_Recv_Send{
            height: col2.height
            width: col2.width / 5
            //通道号
            dfNum:7
        }

        GroupBox_RS232_Recv_Send{
            height: col2.height
            width: col2.width / 5
            //通道号
            dfNum:8
        }

        GroupBox_RS232_Recv_Send{
            height: col2.height
            width: col2.width / 5
            //通道号
            dfNum:9
        }

        GroupBox_RS232_Recv_Send{
            height: col2.height
            width: col2.width / 5
            //通道号
            dfNum:10
        }

    }
    //第二行 发送通道 11~14
    Row{
        id:col3
        //spacing: 1
        anchors.left: parent.left
        anchors.top: col2.bottom
        anchors.right: parent.right
        height: parent.height / 3
        objectName: "rs232row"



        GroupBox_RS232_Recv_Send{
            height: col2.height
            width: col2.width / 5
            //通道号
            dfNum:11
        }


        GroupBox_RS232_Recv_Send{
            height: col2.height
            width: col2.width / 5
            //通道号
            dfNum:12
        }

        GroupBox_RS232_Recv_Send{
            height: col2.height
            width: col2.width / 5
            //通道号
            dfNum:13
        }

        GroupBox_RS232_Recv_Send{
            height: col2.height
            width: col2.width / 5
            //通道号
            dfNum:14
        }


    }


    function recvMsg(infd,msg,length)
    {
        if (parent.parent.parent.parent.fd)
        {
            if (infd==parent.parent.parent.parent.fd)
            {
                console.log(grp.title + ",接收数据:" + msg);
                txtAreaRecv.append(msg);

            }
        }
    }

}
