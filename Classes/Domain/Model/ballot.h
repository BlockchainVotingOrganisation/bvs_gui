#ifndef BALLOT_H
#define BALLOT_H

#include <QtCore/qglobal.h>

class BallotForm
{
public:
    BallotForm();

    QStringList findAllBallots(QString project);
    QStringList findAllOptions(QString ballot);
    Ballot findByReference(QString project);

private:
    QString *ballot;
    QString *project;
};

#endif // BALLOT_H
