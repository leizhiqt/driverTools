#ifndef QTSTRCONVERT_H
#define QTSTRCONVERT_H
#include <QString>
#include <QStringList>

void str_trim(char  *s1);

char convertCharToHex(char ch);

void convertStringToHex(const QString &str, QByteArray &byteData);

QByteArray HexStringToByteArray(QString HexString);

QString ByteArrayToHexString(QByteArray data);

#endif // QTSTRCONVERT_H
