#ifndef BALLOTREPOSITORY_H
#define BALLOTREPOSITORY_H

#include <QtCore/qglobal.h>
#include <QString>
#include "Classes/Domain/Model/ballot.h"

class BallotRepository
{
public:
    BallotRepository();


    QStringList findAllBallots(QString project);
    QStringList findAllOptions(QString ballot);
    Ballot findByReference(QString project);
};

#endif // BALLOTREPOSITORY_H
