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
        padding:1
        topPadding: 22
        bottomPadding: 1
        objectName: "rs422GroupBox"

        property var fd:1

        function showTitle()
        {
            switch (grp.fd)
            {
            case 0 : return "";
            case 1 : return "RS422通道" + grp.fd +"                XS7(左)";
            case 2 : return "RS422通道" + grp.fd +"                XS7(左)_曼码";
            case 3 : return "RS422通道" + grp.fd +"                XS18(左)";
            case 4 : return "RS422通道" + grp.fd +"                XS18(左)_曼码";
            case 5 : return "RS422通道" + grp.fd +"                XS7(右)";
            case 6 : return "RS422通道" + grp.fd +"                XS7(右)_曼码";
            case 7:  return "RS422通道" + grp.fd +"                XS16(右)";
            case 8 : return "RS422通道" + grp.fd +"                XS16(右)_曼码";
            case 9 : return "RS422通道" + grp.fd +"";
            case 10 : return "RS422通道" + grp.fd +"";
            case 11 : return "RS422通道" + grp.fd +"";
            case 12 : return "RS422通道" + grp.fd +"";
            case 13 : return "RS422通道" + grp.fd +"";
            case 13 : return "RS422通道" + grp.fd +"";
            case 14 : return "RS422通道" + grp.fd +"";
            case 15 : return "RS422通道" + grp.fd +"";
            case 16 : return "RS422通道" + grp.fd +"";
            case 17 : return "RS422通道" + grp.fd +"";
            case 18 : return "RS422通道" + grp.fd +"";
            default: return "";
            }

        }

        //顶部tab标签
        TabBar {
            id: bar
            anchors.top: parent.top
            anchors.topMargin: -5
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

                    //操作文本框
                    TextArea{
                        id:txtAreaSend

                        anchors.top: parent.top
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.bottom: checkHexSend.top
                        wrapMode:TextArea.Wrap
                    }

                    //选择十六进制
                    CheckBox{
                        id:checkHexSend
                        text: "十六进制"
                        checked: true
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 10
                        anchors.left: parent.left
                        anchors.leftMargin: 10

                        height: 40

                        //选择状态更改事件
                        onCheckedChanged: {
                            console.log(grp.title + ",发送数据-选择十六进制:" + checked);
                            rs422.setHexRS422(grp.fd,checked);
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
                        id:lbl422SendBytes
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 10
                        anchors.horizontalCenter: parent.horizontalCenter
                        height: 30
                        objectName: "lbl422SendBytes"

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
                            console.log(grp.title + ",点击发送："   + txtAreaSend.text)
                            bus.sendMsg(2,grp.fd, txtAreaSend.text,txtAreaSend.text.length,checkHexSend.checked);
                        }
                    }

                }

                //接收数据子页
                Item {
                    ScrollView{
                        id: scRevcView
                        anchors.top: parent.top
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.bottom: checkHexRecv.top
                        //操作文本框
                        TextArea{
                            id:txtAreaRecv
                            objectName: "rs422RecvItemTextArea"
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
                        checked: true
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 10
                        anchors.left: parent.left
                        anchors.leftMargin: 10

                        height: 40


                        //选择状态更改事件
                        onCheckedChanged: {
                            rs422.setHexRS422(grp.fd,checked);
                            console.log(grp.title + ",接收数据-选择十六进制:" + checked)

                        }
                    }

                    Label{
                        id:lbl422RecvBytes
                        objectName: "lbl422RecvBytes"
                        text:"0"
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
                            rs422.setRecvRS422(grp.fd,"");
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
                        anchors.topMargin: 30
                    }
                    /*ComboBox{
                        id: comboxBaud
                        anchors.verticalCenter: txtBaud.verticalCenter
                        anchors.left: txtBaud.right
                        anchors.leftMargin: 10
                        height: 40

                        model: ["9600", "19200", "38400", "115200","1000000"]
                        currentIndex: 4

                        //更改选择项事件
                        onCurrentIndexChanged: {
                            console.log(grp.title + ",选择波特率:" + model[currentIndex]);
                            parent.rs422set();
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
                            text: qsTr("1000000")
                            font.pixelSize: 14
                            selectByMouse: true
                            onFocusChanged:
                            {
                                if(!focus)
                                {
                                    console.log(grp.title + ",选择波特率:" + text.toString());
                                    parent.parent.rs422set();
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
                            parent.rs422set();
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
                            parent.rs422set();
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
                            parent.rs422set();
                        }
                    }

                    /*Text {
                        id: txtMcst
                        text: qsTr("曼彻斯特编码设置")
                        anchors.top: parent.top
                        anchors.topMargin: 10
                        anchors.horizontalCenter: rectMcst.horizontalCenter
                    }

                    Rectangle{
                        id:rectMcst
                        anchors.left: comboxBaud.right
                        anchors.right: parent.right
                        anchors.top: txtMcst.bottom
                        anchors.bottom: parent.bottom
                        anchors.margins: 10

                        border.color: "black"

                        CheckBox{
                            id:checkMcstParityEnable
                            text: "使能校验"
                            anchors.top: parent.top
                            anchors.topMargin: 1
                            anchors.left: parent.left
                            anchors.leftMargin: 10

                            //选择状态更改事件
                            onCheckedChanged: {

                                console.log(grp.title + ",曼彻斯特校验使能:" + checked);
                                parent.rs422set();
                            }
                        }

                        Text {
                            id: txtMcstParity
                            text: qsTr("校验模式")
                            anchors.left: parent.left
                            anchors.leftMargin: 10
                            anchors.top: checkMcstParityEnable.bottom
                            anchors.topMargin: 1
                        }
                        ComboBox{
                            id: comboxMcstParity
                            anchors.verticalCenter: txtMcstParity.verticalCenter
                            anchors.left: txtMcstParity.right
                            anchors.leftMargin: 10
                            height: 40

                            model: ["偶校验", "奇校验", "固定0", "固定1"]
                            currentIndex: 0

                            //更改选择项事件
                            onCurrentIndexChanged: {
                                console.log(grp.title + ",选择校验模式:" + model[currentIndex]);
                                parent.rs422set();
                            }
                        }

                        CheckBox{
                            id:checkMcstCodeEnable
                            text: "使能曼彻斯特编码"
                            anchors.top: txtMcstParity.bottom
                            anchors.topMargin: 1
                            anchors.left: parent.left
                            anchors.leftMargin: 10

                            //选择状态更改事件
                            onCheckedChanged: {

                                console.log(grp.title + ",曼彻斯特编码使能:" + checked);
                                parent.rs422set();
                            }
                        }

                        Text {
                            id: txtMcstCode
                            text: qsTr("编码模式")
                            anchors.left: parent.left
                            anchors.leftMargin: 10
                            anchors.top: checkMcstCodeEnable.bottom
                            anchors.topMargin: 1
                        }
                        ComboBox{
                            id: comboxMcstCode
                            anchors.verticalCenter: txtMcstCode.verticalCenter
                            anchors.left: txtMcstCode.right
                            anchors.leftMargin: 10
                            height: 40

                            font.family: qsTr("微软雅黑")
                            font.pixelSize: 12

                            model: ["G.E.THomas", "IEEE.802.E"]
                            currentIndex: 0

                            //更改选择项事件
                            onCurrentIndexChanged: {
                                console.log( grp.title + ",选择编码模式:" + currentIndex);
                                parent.rs422set();
                            }
                        }

                    }*/

                    function rs422set()
                    {
                        var comboxBaudValue=parseInt(comboxBaud.text.toString());
                        var comboxBitsValue=parseInt(comboxBits.model[comboxBits.currentIndex]);
                        var comboxParityValue=comboxParity.currentIndex;
                        if(comboxParityValue>0) comboxParityValue=comboxParityValue+3;
                        var comboxStopValue=comboxStop.currentIndex;
                        console.log(grp.title + ",rs422set");
                        rs422.rs422Config(grp.fd,comboxBaudValue,comboxBitsValue,comboxParityValue,comboxStopValue);
                        //rs422. comboxStop.currentIndex
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
                            rs422.saveFileClick(grp.fd,checked);
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
