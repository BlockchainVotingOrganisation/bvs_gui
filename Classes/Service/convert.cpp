
#include <QString>
#include "convert.h"
#include <QtDebug>

Convert::Convert()
{

}

QString Convert::hex2bin(QString hexStr) {
    qDebug()<<"Input (HEX)       = " << hexStr;
    bool ok;
    int iVal = hexStr.toInt(&ok,16);
    QString binStr = hexStr.setNum(iVal, 2);

    qDebug()<<"Convert to Int    = " << QString::number(iVal);
    qDebug()<<"Convert to Binary = " << binStr;

    return binStr;
}

