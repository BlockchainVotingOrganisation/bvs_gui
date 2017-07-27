#include <QByteArray>
#include <QString>
#include "convert.h"
#include <QtDebug>

Convert::Convert()
{

}

QString Convert::hex2bin(QString hexStr) {
    QString binStr = QString::fromLocal8Bit(QByteArray::fromHex(hexStr.toLatin1()));
//    QByteArray binStr = QByteArray::fromHex(hexStr.toLatin1());
    return binStr;
}

