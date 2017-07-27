#ifndef BALLOTREPOSITORY_H
#define BALLOTREPOSITORY_H

#include <QtCore/qglobal.h>
#include <QString>
#include <QJsonDocument>

#include "projectRepository.h"
//#include "Classes/Domain/Model/ballot.h"

class BallotRepository
{
public:
    BallotRepository();

    QJsonDocument findBallot(QStringList args, QString project);
    QStringList findAllOptions(QJsonDocument ballot);
private:
    ProjectRepository *projectRepository;

};

#endif // BALLOTREPOSITORY_H
