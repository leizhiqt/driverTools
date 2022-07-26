import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

Item {
    id:cp

    //通道号，调用时指定
    property  alias dfNum: grp.fd

    GroupBox{
        id: grp
        title: "RS232接收通道" + fd
        anchors.fill: parent
        anchors.margins: 1
        objectName: "rs232GroupBox"
        property var fd:1

        //顶部tab标签
        TabBar {
            id: bar
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            height: 40

            HZXTabButton {
                text: qsTr("接收数据")
            }
            HZXTabButton {
                text: qsTr("配置")
            }
        }

        //tab页展示界面
        Rectangle{
            id:rect
            anchors.top: bar.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            border.color: "black"
            color: qsTr("white")

            StackLayout {
                anchors.fill: parent
                anchors.margins: 1

                currentIndex: bar.currentIndex

                //数据子页
                Item {

                    //操作文本框
                    TextArea{
                        id:txtArea

                        anchors.top: parent.top
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.bottom: checkHex.top
                    }

                    //选择十六进制
                    CheckBox{
                        id:checkHex
                        text: "十六进制"

                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 10
                        anchors.left: parent.left
                        anchors.leftMargin: 10

                        height: 40

                        //选择状态更改事件
                        onCheckedChanged: {

                            console.log(grp.title + ",选择十六进制:" + checked)
                        }
                    }

                }

                //配置子页
                Item {

                    Text {
                        id: txtBaud
                        text: qsTr("波特率")
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                        anchors.top: parent.top
                        anchors.topMargin: 50
                    }
                    ComboBox{
                        id: comboxBaud
                        anchors.verticalCenter: txtBaud.verticalCenter
                        anchors.left: txtBaud.right
                        anchors.leftMargin: 10
                        height: 40

                        model: ["9600", "19200", "38400", "115200"]
                        currentIndex: 0

                        //更改选择项事件
                        onCurrentIndexChanged: {
                            console.log(grp.title + ",选择波特率:" + model[currentIndex])
                        }
                    }

                    Text {
                        id: txtBits
                        text: qsTr("数据位")
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                        anchors.top: txtBaud.bottom
                        anchors.topMargin: 20
                    }
                    ComboBox{
                        id: comboxBits
                        anchors.verticalCenter: txtBits.verticalCenter
                        anchors.left: txtBits.right
                        anchors.leftMargin: 10
                        height: 40

                        model: ["5", "6", "7", "8"]
                        currentIndex: 0

                        //更改选择项事件
                        onCurrentIndexChanged: {
                            console.log(grp.title + ",选择数据位:" + model[currentIndex])

                        }
                    }

                    Text {
                        id: txtParity
                        text: qsTr("校验位")
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                        anchors.top: txtBits.bottom
                        anchors.topMargin: 20
                    }
                    ComboBox{
                        id: comboxParity
                        anchors.verticalCenter: txtParity.verticalCenter
                        anchors.left: txtParity.right
                        anchors.leftMargin: 10
                        height: 40

                        model: ["0", "", "", ""]
                        currentIndex: 0

                        //更改选择项事件
                        onCurrentIndexChanged: {
                            console.log(grp.title + ",选择校验位:" + model[currentIndex])

                        }
                    }

                    Text {
                        id: txtStop
                        text: qsTr("停止位")
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                        anchors.top: txtParity.bottom
                        anchors.topMargin: 20
                    }
                    ComboBox{
                        id: comboxStop
                        anchors.verticalCenter: txtStop.verticalCenter
                        anchors.left: txtStop.right
                        anchors.leftMargin: 10
                        height: 40

                        model: ["无", "", "", ""]
                        currentIndex: 0

                        //更改选择项事件
                        onCurrentIndexChanged: {
                            console.log(grp.title + ",选择停止位:" + model[currentIndex])

                        }
                    }


//                    Text {
//                        id: txtMcst
//                        text: qsTr("曼彻斯特编码设置")
//                        anchors.top: parent.top
//                        anchors.topMargin: 10
//                        anchors.horizontalCenter: rectMcst.horizontalCenter
//                    }

//                    Rectangle{
//                        id:rectMcst
//                        anchors.left: comboxBaud.right
//                        anchors.right: parent.right
//                        anchors.top: txtMcst.bottom
//                        anchors.bottom: parent.bottom
//                        anchors.margins: 10

//                        border.color: "black"

//                        CheckBox{
//                            id:checkMcstParityEnable
//                            text: "使能校验"
//                            anchors.top: parent.top
//                            anchors.topMargin: 1
//                            anchors.left: parent.left
//                            anchors.leftMargin: 10

//                            //选择状态更改事件
//                            onCheckedChanged: {

//                                console.log(grp.title + ",曼彻斯特校验使能:" + checked)
//                            }
//                        }

//                        Text {
//                            id: txtMcstParity
//                            text: qsTr("校验模式")
//                            anchors.left: parent.left
//                            anchors.leftMargin: 10
//                            anchors.top: checkMcstParityEnable.bottom
//                            anchors.topMargin: 1
//                        }
//                        ComboBox{
//                            id: comboxMcstParity
//                            anchors.verticalCenter: txtMcstParity.verticalCenter
//                            anchors.left: txtMcstParity.right
//                            anchors.leftMargin: 10
//                            height: 40

//                            model: ["偶校验", "奇校验", "固定0", "固定1"]
//                            currentIndex: 0

//                            //更改选择项事件
//                            onCurrentIndexChanged: {
//                                console.log(grp.title + ",选择校验模式:" + model[currentIndex])

//                            }
//                        }

//                        CheckBox{
//                            id:checkMcstCodeEnable
//                            text: "使能曼彻斯特编码"
//                            anchors.top: txtMcstParity.bottom
//                            anchors.topMargin: 1
//                            anchors.left: parent.left
//                            anchors.leftMargin: 10

//                            //选择状态更改事件
//                            onCheckedChanged: {

//                                console.log(grp.title + ",曼彻斯特编码使能:" + checked)
//                            }
//                        }

//                        Text {
//                            id: txtMcstCode
//                            text: qsTr("编码模式")
//                            anchors.left: parent.left
//                            anchors.leftMargin: 10
//                            anchors.top: checkMcstCodeEnable.bottom
//                            anchors.topMargin: 1
//                        }
//                        ComboBox{
//                            id: comboxMcstCode
//                            anchors.verticalCenter: txtMcstCode.verticalCenter
//                            anchors.left: txtMcstCode.right
//                            anchors.leftMargin: 10
//                            height: 40

//                            font.family: qsTr("微软雅黑")
//                            font.pixelSize: 12

//                            model: ["G.E.THomas", "IEEE.802.E", "", ""]
//                            currentIndex: 0

//                            //更改选择项事件
//                            onCurrentIndexChanged: {
//                                console.log( grp.title + ",选择编码模式:" + currentIndex)
//                            }
//                        }

//                    }

                }

            }
        }

    }
}
