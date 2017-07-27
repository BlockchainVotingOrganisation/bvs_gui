#ifndef BALLOTREPOSITORY_H
#define BALLOTREPOSITORY_H

#include <QtCore/qglobal.h>
#include <QString>
#include "projectRepository.h"
//#include "Classes/Domain/Model/ballot.h"

class BallotRepository
{
public:
    BallotRepository();

    QStringList findAllBallots(QStringList args, QString project);
    QStringList findAllOptions(QString ballot);
private:
    ProjectRepository *projectRepository;

};

#endif // BALLOTREPOSITORY_H
