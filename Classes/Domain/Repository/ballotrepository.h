#ifndef BALLOTREPOSITORY_H
#define BALLOTREPOSITORY_H

#include <QtCore/qglobal.h>
#include <QString>
#include <QJsonDocument>
#include "Classes/Domain/Model/ballot.h"
#include "projectRepository.h"
//#include "Classes/Domain/Model/ballot.h"

class BallotRepository
{
public:
    BallotRepository();

    Ballot findBallot(QStringList args, QString project);
    QStringList findOptionsByBallotName(QString ballot);
    QStringList findOptionsByBallot(Ballot ballot);

private:
    ProjectRepository *projectRepository;
    Ballot ballot;
};

#endif // BALLOTREPOSITORY_H
