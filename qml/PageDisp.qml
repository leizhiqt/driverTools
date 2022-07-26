import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

Item {

    objectName: "recvDispItem"

    ScrollView{
        id: view
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: btnClean.top
        //操作文本框
        TextArea{
            id:txtAreaRecv
            objectName: "recvDispItemTextArea"
            textFormat: "RichText"
            text:bus.recvString
            wrapMode:TextArea.Wrap
            onTextChanged: {
                var strlength=txtAreaRecv.length;
                if(strlength>50)
                    txtAreaRecv.cursorPosition=strlength-1;
            }
        }
    }



    //选择十六进制
    /*CheckBox{
        id:checkHexRecv
        text: "十六进制"
        checked: channelHex()
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10

        height: 40
        function channelHex()//当前频道显示的switch函数
        {
            switch (grp.fd)
            {
            case 0 : return false;
            case 1 : return rs232.hexRS23201;
            case 2 : return rs232.hexRS23202;
            case 3 : return rs232.hexRS23203;
            case 4 : return rs232.hexRS23204;
            case 5 : return rs232.hexRS23205;
            case 6 : return rs232.hexRS23206;
            case 7 : return rs232.hexRS23207;
            case 8 : return rs232.hexRS23208;
            case 9 : return rs232.hexRS23209;
            case 10 : return rs232.hexRS23210;
            default: return false;
            }
        }
        //选择状态更改事件
        onCheckedChanged: {

            console.log(grp.title + ",接收数据-选择十六进制:" + checked)
            switch (grp.fd)
            {
            case 0 : return false;
            case 1 : rs232.hexRS23201=checked;break;
            case 2 : rs232.hexRS23202=checked;break;
            case 3 : rs232.hexRS23203=checked;break;
            case 4 : rs232.hexRS23204=checked;break;
            case 5 : rs232.hexRS23205=checked;break;
            case 6 : rs232.hexRS23206=checked;break;
            case 7 : rs232.hexRS23207=checked;break;
            case 8 : rs232.hexRS23208=checked;break;
            case 9 : rs232.hexRS23209=checked;break;
            case 10 : rs232.hexRS23210=checked;break;
            default: return false;
            }
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
                var len = txtAreaRecv.text.length;
                var curCharCode;
                var resultStr = [];
                for(var i = 0; i < len;i = i + 3) {
                    curCharCode = parseInt(txtAreaRecv.text.substr(i, 2), 16); // ASCII Code Value
                    resultStr.push(String.fromCharCode(curCharCode));
                }
                varstr=resultStr.join("");
            }
            switch (grp.fd)
            {
            case 0 : return false;
            case 1 : rs232.recvRS23201=varstr;break;
            case 2 : rs232.recvRS23202=varstr;break;
            case 3 : rs232.recvRS23203=varstr;break;
            case 4 : rs232.recvRS23204=varstr;break;
            case 5 : rs232.recvRS23205=varstr;break;
            case 6 : rs232.recvRS23206=varstr;break;
            case 7 : rs232.recvRS23207=varstr;break;
            case 8 : rs232.recvRS23208=varstr;break;
            case 9 : rs232.recvRS23209=varstr;break;
            case 10 : rs232.recvRS23210=varstr;break;
            default: return false;
            }
        }
    }*/

    //按钮
    Button{
        id:btnAutoTest
        text: "一键测试"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        height: 40

        //点击事件
        onClicked: {
            btnAutoTest.enabled=false;
            console.log("点击一键测试");
            bus.setRecvString("");
            for(var i=0;i<18;i++)
                rs422.setRecvRS422(i+1,"");
            for(var i=0;i<14;i++)
                rs232.setRecvRS232(i+1,"");
            for(var i=0;i<8;i++)
                arinc429.setRecvArincComm429(i+1,"");
            bus.btnAutoTestClicked();            
            //btnAutoTest.enabled=true;
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
            console.log("点击清除：");
            return bus.setRecvString("");

        }
    }



}
