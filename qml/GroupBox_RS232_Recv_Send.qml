import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

Item {
    id:cp

    //通道号，调用时指定
    property  alias dfNum: grp.fd


    GroupBox{
        id: grp
        title: showTitle()
        anchors.fill: parent
        anchors.margins: 1
        objectName: "rs232GroupBox"

        property var fd:1

        function showTitle()
        {
            switch (grp.fd)
            {
            case 0 : return "";
            case 1 : return "RS232通道" + grp.fd +"                X11(左)";
            case 2 : return "RS232通道" + grp.fd +"                X11(左)";
            case 3 : return "RS232通道" + grp.fd +"                X11(左)";
            case 4 : return "RS232通道" + grp.fd +"                X11(左)";
            case 5 : return "RS232通道" + grp.fd +"";
            case 6 : return "RS232通道" + grp.fd +"                X12(右)";
            case 7:  return "RS232通道" + grp.fd +"                X12(右)";
            case 8 : return "RS232通道" + grp.fd +"                X12(右)";
            case 9 : return "RS232通道" + grp.fd +"                X12(右)";
            case 10 : return "RS232通道" + grp.fd +"";
            case 11 : return "RS232通道" + grp.fd +"                ";
            case 12:  return "RS232通道" + grp.fd +"                ";
            case 13 : return "RS232通道" + grp.fd +"                ";
            case 14 : return "RS232通道" + grp.fd +"                ";

            default: return "";
            }

        }

        //顶部tab标签
        TabBar {
            id: bar
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            height: 40

            HZXTabButton {
                text: qsTr("发送")
            }
            HZXTabButton {
                text: qsTr("接收")
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

                //发送数据子页
                Item {

                    ScrollView{
                        id: scSendView
                        anchors.top: parent.top
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.bottom: checkHexSend.top
                        //操作文本框
                        TextArea{
                            id:txtAreaSend
                            wrapMode:TextArea.Wrap
                            selectByKeyboard: true
                            selectByMouse: true
                        }
                    }

                    //选择十六进制
                    CheckBox{
                        id:checkHexSend
                        text: "十六进制"
                        checked: ture
                        enabled: true
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 10
                        anchors.left: parent.left
                        anchors.leftMargin: 10

                        height: 40

                        //选择状态更改事件
                        onCheckedChanged: {
                            console.log(grp.title + ",发送数据-选择十六进制:" + checked);
                            if (checked)
                            {
                                var val = "";
                                var vartemp="";
                                for(var i = 0; i < txtAreaSend.text.length; i++){
                                    vartemp=txtAreaSend.text.charCodeAt(i);
                                    if (val == "")
                                    {
                                        if (vartemp<16) val="0"+vartemp.toString(16)
                                        else val=vartemp.toString(16);
                                    }
                                    else
                                    {
                                        if (vartemp<16) val+=" 0"+vartemp.toString(16)
                                        else val+=" "+vartemp.toString(16);
                                    }
                                }
                                txtAreaSend.text=val;
                            }else
                            {
                                var tempStr=txtAreaSend.text.replace(/ +/g,"");
                                var len = tempStr.length;
                                var curCharCode;
                                var resultStr = [];
                                for(var i = 0; i < len;i = i + 2) {
                                    curCharCode = parseInt(tempStr.substr(i, 2), 16); // ASCII Code Value
                                    resultStr.push(String.fromCharCode(curCharCode));
                                }
                                txtAreaSend.text=resultStr.join("");
                            }
                        }
                    }

                    Label{
                        id:lbl232SendBytes
                        text:"0"
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 10
                        anchors.horizontalCenter: parent.horizontalCenter
                        height: 30
                        objectName: "lbl232SendBytes"
                    }

                    //发送按钮
                    Button{
                        id:btnSend
                        text: "发送"

                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 10
                        anchors.right : parent.right
                        anchors.rightMargin: 10

                        height: 40

                        //点击事件
                        onClicked: {
                            console.log(grp.title + ",点击发送："   + txtAreaSend.text);
                            bus.sendMsg(3,grp.fd, txtAreaSend.text,txtAreaSend.text.length,checkHexSend.checked);
                        }
                    }
                }


                //接收数据子页
                Item {
                    objectName: "rs232RecvItem"
                    ScrollView{
                        id: scRevcView
                        anchors.top: parent.top
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.bottom: checkHexRecv.top
                        //操作文本框
                        TextArea{
                            id:txtAreaRecv
                            objectName: "rs232RecvItemTextArea"
                            text:""
                            wrapMode:TextArea.Wrap
                            onTextChanged: {
                                var strlength=txtAreaRecv.length;
                                if(strlength>50)
                                    txtAreaRecv.cursorPosition=strlength-1;
                            }                            
                        }
                    }



                    //选择十六进制
                    CheckBox{
                        id:checkHexRecv
                        text: "十六进制"
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 10
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                        checked: ture
                        enabled: true
                        height: 40

                        //选择状态更改事件
                        onCheckedChanged: {
                            rs232.setHexRS232(grp.fd,checked);
                            console.log(grp.title + ",接收数据-选择十六进制:" + checked)
                        }
                    }

                    Label{
                        text:"0"
                        objectName: "lbl232RecvBytes"
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 10
                        anchors.horizontalCenter: parent.horizontalCenter
                        height: 30                        
                    }

                    //按钮
                    Button{
                        id:btnClean
                        text: "清除"

                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 10
                        anchors.right : parent.right
                        anchors.rightMargin: 10

                        height: 40

                        //点击事件
                        onClicked: {
                            console.log(grp.title + ",点击清除：");
                            rs232.setRecvRS232(grp.fd,"");
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
                        anchors.topMargin: 20
                    }
                    /*ComboBox{
                        id: comboxBaud
                        anchors.verticalCenter: txtBaud.verticalCenter
                        anchors.left: txtBaud.right
                        anchors.leftMargin: 10
                        height: 40

                        model: ["9600", "19200", "38400", "115200"]
                        currentIndex: 3

                        //更改选择项事件
                        onCurrentIndexChanged: {
                            console.log(grp.title + ",选择波特率:" + model[currentIndex]);
                            parent.rs232set();
                        }
                    }*/
                    Rectangle{
                        anchors.verticalCenter: txtBaud.verticalCenter
                        anchors.left: txtBaud.right
                        anchors.leftMargin: 10
                        height: 30
                        width: 150
                        border.color: 'lightgray'

                        TextInput{
                            id: comboxBaud
                            anchors.fill:parent
                            leftPadding: 15
                            verticalAlignment: TextInput.AlignVCenter
                            //horizontalAlignment:TextInput.AlignHCenter
                            clip: true
                            text: qsTr("115200")
                            font.pixelSize: 14
                            selectByMouse: true
                            onFocusChanged:
                            {
                                if(!focus)
                                {
                                    console.log(grp.title + ",选择波特率:" + text.toString());
                                    parent.parent.rs232set();
                                }
                            }
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
                        currentIndex: 3

                        //更改选择项事件
                        onCurrentIndexChanged: {
                            console.log(grp.title + ",选择数据位:" + model[currentIndex]);
                            parent.rs232set();
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

                        model: ["无校验", "偶校验", "奇校验", "固定0", "固定1"]
                        currentIndex: 0

                        //更改选择项事件
                        onCurrentIndexChanged: {
                            console.log(grp.title + ",选择校验位:" + model[currentIndex]);
                            parent.rs232set();
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

                        model: ["1", "2"]
                        currentIndex: 0

                        //更改选择项事件
                        onCurrentIndexChanged: {
                            console.log(grp.title + ",选择停止位:" + model[currentIndex]);
                            parent.rs232set();
                        }
                    }

                    function rs232set()
                    {
                        var comboxBaudValue=parseInt(comboxBaud.text.toString());
                        var comboxBitsValue=parseInt(comboxBits.model[comboxBits.currentIndex]);
                        var comboxParityValue=comboxParity.currentIndex;
                        if(comboxParityValue>0) comboxParityValue=comboxParityValue+3;
                        var comboxStopValue=comboxStop.currentIndex;
                        console.log(grp.title + ",rs232set");
                        rs232.rs232Config(grp.fd,comboxBaudValue,comboxBitsValue,comboxParityValue,comboxStopValue);
                        //rs232. comboxStop.currentIndex
                    }

                    CheckBox{
                        id:checkSaveFile
                        text: "保存文件"
                        anchors.verticalCenter: comboxBits.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 200
                        height: 40

                        //选择状态更改事件
                        onCheckedChanged: {
                            rs232.saveFileClick(grp.fd,checked);
                        }
                    }

                    CheckBox{
                        id:chkTimerSend
                        text: "定时发送"

                        anchors.verticalCenter: comboxParity.verticalCenter
                        anchors.left: checkSaveFile.left
                        height: 40

                        //选择状态更改事件
                        onCheckedChanged: {
                            console.log(grp.title + ",选择间隔:" + checked.toString());
                        }
                    }
                    Text {
                        id: txtTimerDisp
                        text: qsTr("间隔(ms):")
                        anchors.top: comboxStop.top
                        anchors.topMargin: 10
                        anchors.left: checkSaveFile.left
                        anchors.leftMargin: 5
                        height: 40
                    }
                    Rectangle{
                        anchors.verticalCenter: comboxStop.verticalCenter
                        anchors.left: checkSaveFile.left
                        anchors.leftMargin: 60
                        height: 30
                        width: 50
                        border.color: 'lightgray'

                        TextInput{
                            id: txtTimeSpan
                            anchors.fill:parent
                            leftPadding: 15
                            verticalAlignment: TextInput.AlignVCenter
                            clip: true
                            text: qsTr("500")
                            font.pixelSize: 14
                            selectByMouse: true
                            onFocusChanged:
                            {
                                if(!focus)
                                {
                                    console.log(grp.title + ",选择间隔:" + text.toString());

                                }
                            }
                        }
                    }


                }

            }
        }


    }
}
