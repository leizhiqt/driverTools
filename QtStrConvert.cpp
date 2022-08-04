#include "QtStrConvert.h"

void str_trim(char  *s1)
{
    char *s2;
    s2 = s1; //让我们的S2指向数组，以便更改数组里面的东西
    while (*s1) {
        if (*s1 == ' ') {
            s1++;
        } else {
            *s2 = *s1;
            s1++;
            s2++; //指向数组的指针往后移动
        }
    }
    *s2 = '\0';
}

char convertCharToHex(char ch)
{
    if((ch >= '0') && (ch <= '9'))
         return ch-0x30;
     else if((ch >= 'A') && (ch <= 'F'))
         return ch-'A'+10;
     else if((ch >= 'a') && (ch <= 'f'))
         return ch-'a'+10;
    else return (-1);
}

//QString 转换为 Hex ByteArray
void convertStringToHex(const QString &str, QByteArray &byteData)
{
    int hexdata,lowhexdata;
    int hexdatalen = 0;
    int len = str.length();
    byteData.resize(len/2);
    char lstr,hstr;
    for(int i=0; i<len; )
    {
        //char lstr,
        hstr=str[i].toLatin1();
        if(hstr == ' ')
        {
            i++;
            continue;
        }
        i++;
        if(i >= len)
            break;
        lstr = str[i].toLatin1();
        hexdata = convertCharToHex(hstr);
        lowhexdata = convertCharToHex(lstr);
        if((hexdata == 16) || (lowhexdata == 16))
            break;
        else
            hexdata = hexdata*16+lowhexdata;
        i++;
        byteData[hexdatalen] = (char)hexdata;
        hexdatalen++;
    }
    byteData.resize(hexdatalen);
}

//16进制字符串转换ByteArray
/*
 * @breif 将16进制字符串转换为对应的字节序列
 */
QByteArray HexStringToByteArray(QString HexString)
{
    bool ok;
    QByteArray ret;
    HexString = HexString.trimmed();
    HexString = HexString.simplified();
    QStringList sl = HexString.split(" ");

    foreach (QString s, sl) {
        if(!s.isEmpty())
        {
            char c = s.toInt(&ok,16)&0xFF;
            if(ok){
                ret.append(c);
            }else{
                printf("非法的16进制字符：%s\n",s.toLatin1().data());
            }
        }
    }
//    qDebug()<<ret;
    return ret;
}


//ByteArray 转换为 16进制字符串
QString ByteArrayToHexString(QByteArray data)
{
    QString ret(data.toHex().toUpper());
    int len = ret.length()/2;
//    qDebug()<<len;
    for(int i=1;i<len;i++)
    {
//        qDebug()<<i;
        ret.insert(2*i+i-1," ");
    }
    return ret;
}


int example_convert()
{
    QString str="12abcd";

    QString str1=str.toLatin1().toHex(' ');

    printf("%s\n",str1.toLatin1().data());

    str1.replace(" ","");

    printf("%s\n",str1.toLatin1().data());

    QByteArray ba;
    char *p = ba.begin();
    convertStringToHex(str1,ba);

    printf("%d\n",ba.length());
    int len=ba.length();
    for(int i=0;i<len;i++){
        printf("%02x\n",(unsigned char)*(p+i));
    }

    QString hexs=ByteArrayToHexString(ba);
    printf("%s\n",hexs.toLatin1().data());
}
