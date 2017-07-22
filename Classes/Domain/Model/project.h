#ifndef PROJECT_H
#define PROJECT_H

#include <QtCore/qglobal.h>
#include <QString>

class Project
{
public:
    Project();

private:
    QString *name;
    QString *txid;
    QStringList *ballots;
};

#endif // PROJECT_H
