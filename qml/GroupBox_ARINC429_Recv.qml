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

        property var fd:1

        function showTitle()
        {
            switch (grp.fd)
            {
            case 0 : return "";
            case 1 : return "ARINC429通道" + grp.fd +"                XS28(左)_接收";
            case 2 : return "ARINC429通道" + grp.fd +"                XS30(右)_接收";
            case 3 : return "ARINC429通道" + grp.fd +"                APU-J1B (CFDIU发送和控制器接收)";
            case 4 : return "ARINC429通道" + grp.fd +"                APU-J1B (ECS发送)";
            case 5 : return "ARINC429通道" + grp.fd +"";
            case 6 : return "ARINC429通道" + grp.fd +"";
            case 7 : return "ARINC429通道" + grp.fd +"";
            case 8 : return "ARINC429通道" + grp.fd +"";
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

                //接收数据子页
                Item {

                    ScrollView{
                        id: scRevcView
                        anchors.top: parent.top
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.bottom: checkHexRecv.top
                        //文本框
                        TextArea{
                            id:txtAreaRecv
                            text:channelPlay()
                            wrapMode:TextArea.Wrap
                            onTextChanged: {
                                var strlength=txtAreaRecv.length;
                                if(strlength>50)
                                    txtAreaRecv.cursorPosition=strlength-1;
                            }
                            function channelPlay()//当前频道显示的switch函数
                            {
                                switch (grp.fd)
                                {
                                case 0 : return "";

                                default: return "";
                                }
                            }
                        }
                    }

                    //选择十六进制
                    CheckBox{
                        id:checkHexRecv
                        text: "十六进制"
                        checked: channelHex()
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 10
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                        enabled: false
                        height: 40

                        function channelHex()//当前频道显示的switch函数
                        {
                            switch (grp.fd)
                            {
                            case 0 : return false;

                            default: return false;
                            }
                        }
                        //选择状态更改事件
                        onCheckedChanged: {

                            console.log(grp.title + ",接收数据-选择十六进制:" + checked)
                            switch (grp.fd)
                            {
                            case 0 : return false;

                            default: return false;
                            }
                            if (txtAreaRecv.text.length>512)
                            {
                                switch (grp.fd)
                                {
                                case 0 : return "";

                                default: return "";
                                }
                            }
                            else
                            {
                                var varstr="";
                                if (checked)
                                {
                                    var val = "";
                                    for(var i = 0; i < txtAreaRecv.text.length; i++){
                                        if (val == "")
                                            val = txtAreaRecv.text.charCodeAt(i).toString(16);
                                        else
                                            val += " " + txtAreaRecv.text.charCodeAt(i).toString(16);
                                    }
                                    varstr=val;
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
                                switch (grp.fd)
                                {
                                case 0 : return false;

                                default: return false;
                                }
                            }


                        }
                    }

                    Label{
                        id:lbl429RecvBytes
                        text:channelBytes()
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 10
                        anchors.horizontalCenter: parent.horizontalCenter
                        height: 30
                        function channelBytes()//当前频道显示的switch函数
                        {
                            switch (grp.fd)
                            {
                            case 0 : return "";

                            default: return "";
                            }
                        }
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
                            switch (grp.fd)
                            {
                            case 0 : return "";

                            default: return "";
                            }
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
                    /*ComboBox{
                        id: comboxBaud
                        anchors.verticalCenter: txtBaud.verticalCenter
                        anchors.left: txtBaud.right
                        anchors.leftMargin: 10
                        height: 40

                        model: ["150K", "100K","50K","48K","12.5K","10K"]
                        currentIndex: initBaud()
                        //更改选择项事件
                        onCurrentIndexChanged: {
                            console.log(grp.title + ",选择波特率:" + model[currentIndex]);
                            parent.arinc429set();
                        }

                        function initBaud()
                        {
                            switch (grp.fd)
                            {
                            case 0 : return 1;
                            case 1 : return 1;
                            case 2 : return 1;
                            case 3 : return 4;
                            case 4 : return 4;
                            case 5 : return 4;
                            case 6 : return 1;
                            default: return 1;
                            }
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
                            text: initBaud()
                            font.pixelSize: 14
                            selectByMouse: true
                            onFocusChanged:
                            {
                                if(!focus)
                                {
                                    console.log(grp.title + ",选择波特率:" + text.toString());
                                    parent.parent.arinc429set();
                                }
                            }

                            function initBaud()
                            {
                                switch (grp.fd)
                                {
                                case 0 : return 100000;
                                case 1 : return 100000;
                                case 2 : return 100000;
                                case 3 : return 12500;
                                case 4 : return 12500;
                                case 5 : return 12500;
                                case 6 : return 100000;
                                default: return 100000;
                                }
                            }
                        }
                    }


                    Text {
                        id: txtParity
                        text: qsTr("校验位")
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                        anchors.top: txtBaud.bottom
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
                            parent.arinc429set();
                        }
                    }

                    Text {
                        id: txtCode
                        text: qsTr("编码模式")
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                        anchors.top: txtParity.bottom
                        anchors.topMargin: 20
                    }
                    ComboBox{
                        id: comboxCode
                        anchors.verticalCenter: txtCode.verticalCenter
                        anchors.left: txtCode.right
                        anchors.leftMargin: 10
                        height: 40

                        model: ["25", "32"]
                        currentIndex: 1

                        //更改选择项事件
                        onCurrentIndexChanged: {
                            console.log(grp.title + ",编码模式:" + model[currentIndex]);
                            parent.arinc429set();
                        }
                    }

                    function arinc429set()
                    {
                        var comboxBaudValue=parseInt(comboxBaud.text.toString());
                        var comboxParityValue=comboxParity.currentIndex;
                        if(comboxParityValue>0) comboxParityValue=comboxParityValue+3;
                        var comboxCodeValue=comboxCode.currentIndex;
                        console.log(grp.title + ",arinc429set");
                        arinc429.arinc429Config(grp.fd,comboxBaudValue,comboxParityValue,comboxCodeValue);
                    }



                }

            }
        }

    }
}
