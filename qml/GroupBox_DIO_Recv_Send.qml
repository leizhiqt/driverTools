import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

Item {
    id:cp

    //通道号，调用时指定
    property alias dfNum: grp.fd

    //设置当前通道是否为高电平
    function setHighLevel(ifHigh)
    {
        //ifHigh: true or false
        btnChannel.highLevel = ifHigh
    }

    GroupBox{
        id: grp
        title: showTitle()
        anchors.fill: parent
        anchors.margins: 1
        objectName: "dioGroupBox"
        property var fd:1

        function showTitle()
        {
            switch (grp.fd)
            {
            case 0 : return "";
            case 1 : return "离散量端口" + grp.fd +"  X11(左)_GSE";
            case 2 : return "离散量端口" + grp.fd +"  X11(左)_STATUS0";
            case 3 : return "离散量端口" + grp.fd +"  X11(左)_STATUS1";
            case 4 : return "离散量端口" + grp.fd +"  X11(左)_DIF RST H";
            case 5 : return "离散量端口" + grp.fd +"  X11(左)_DIF RST L";
            case 6 : return "离散量端口" + grp.fd +"  X11(左)_DIF ATT H";
            case 7:  return "离散量端口" + grp.fd +"  X11(左)_DIF ATT H";
            case 8 : return "离散量端口" + grp.fd +"  X12(右)_GSE";
            case 9 : return "离散量端口" + grp.fd +"  X12(右)_STATUS0";
            case 10 : return "离散量端口" + grp.fd +" X12(右)_STATUS1";
            case 11 : return "离散量端口" + grp.fd +" X12(右)_DIF RST H";
            case 12 : return "离散量端口" + grp.fd +" X12(右)_DIF RST L";
            case 13 : return "离散量端口" + grp.fd +" X12(右)_DIF ATT H";
            case 14 : return "离散量端口" + grp.fd +" X12(右)_DIF ATT H";
            case 15 : return "离散量端口" + grp.fd +"";
            case 16 : return "离散量端口" + grp.fd +"";
            case 17 : return "离散量端口" + grp.fd +"";
            case 18 : return "离散量端口" + grp.fd +"";
            case 19 : return "离散量端口" + grp.fd +"";
            case 20 : return "离散量端口" + grp.fd +"";
            case 21 : return "离散量端口" + grp.fd +"";
            case 22 : return "离散量端口" + grp.fd +"";
            case 23 : return "离散量端口" + grp.fd +"";
            case 24 : return "离散量端口" + grp.fd +"";
            case 25 : return "离散量端口" + grp.fd +"";
            default: return "";
            }

        }

        Text {
            id: txtDirection
            text: qsTr("接口方向")
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 10
        }
        ComboBox{
            id:comBoxDirection
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: txtDirection.bottom
            anchors.topMargin: 1
            currentIndex: directionGet()
            objectName: "comBoxDirection"
            model:["输入", "输出"]


            onCurrentIndexChanged: {
                //console.log(grp.title + ",选择接口方向" + model[currentIndex])
                if(currentIndex==1)
                {
                    checkEnabel.checked = false
                }
                else
                {
                    checkEnabel.checked = true
                }
                switch (grp.fd)
                {
                case 0 : return false;

                default: return false;
                }
            }

            function directionGet()
            {
                switch (grp.fd)
                {
                case 0 : return false;

                default: return false;
                }
            }

        }

        //通道指示灯
        Button{
            id:btnChannel
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: comBoxDirection.bottom
            anchors.topMargin: 30
            height: 100
            width: 90
            objectName: "btnChannel"

            //是否高电平
            property var highLevel: true



            //背景色根据是否收到/发送高电平信号进行变化
            background: Rectangle{
                radius: 20
                color: btnChannel.highLevel ? "grey" : "green"

            }


            checked: channelPlay1();

            //对于发送通道，提供点击选中事件
            //checkable: comBoxDirection.currentIndex==1 ? true : false
            checkable: true
            onCheckedChanged: {

                if(checked)
                {
                    highLevel = true
//                    console.log(grp.title + ",输出高电平")
                }
                else
                {
                    highLevel = false
//                    console.log(grp.title + ",输出低电平")
                }
                switch (grp.fd)
                {
                case 0 : return false;

                default: return true;
                }

            }
            function channelPlay1()//当前频道显示的switch函数
            {
                switch (grp.fd)
                {
                case 0 : return false;

                default: return true;
                }
            }
        }

        CheckBox{
            id:checkEnabel
            text: "内部上拉使能"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: btnChannel.bottom
            anchors.topMargin: 2
            objectName: "checkEnabel"
            checked: true

            enabled: comBoxDirection.currentIndex==0 ? true : false
           // enabled: false

            onCheckedChanged: {
                console.log(grp.fd + ",内部上拉使能:" + checked)
            }
        }

    }

}
