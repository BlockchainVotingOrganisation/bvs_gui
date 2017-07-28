#ifndef BALLOTCONTROLLER_H
#define BALLOTCONTROLLER_H

#include <QtCore/qglobal.h>
#include <QStringList>
#include <Classes/Domain/Model/ballot.h>


class BallotController
{
public:
    BallotController();

//    QStringList listAction(QString project);
    QStringList ballotItemList(Ballot ballot); // showAction
//    Ballot newAction();
//    int createAction(Ballot ballot);
//    Ballot editAction(QString ballot);

//    int vote();

};

#endif // BALLOTCONTROLLER_H
