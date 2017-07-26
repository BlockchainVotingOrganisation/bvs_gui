#ifndef CONVERT_H
#define CONVERT_H

#include <QString>

class Convert
{
public:
    Convert();

    QString hex2bin(QString hexStr);
    QString bin2hex(QString binStr);
};

#endif // CONVERT_H
