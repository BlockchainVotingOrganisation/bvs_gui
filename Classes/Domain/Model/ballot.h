#ifndef BALLOT_H
#define BALLOT_H

#include <QtCore/qglobal.h>
#include <QString>

class Ballot
{
public:
    Ballot();


private:
    QString *ballot;
    QString *project;
};

#endif // BALLOT_H
