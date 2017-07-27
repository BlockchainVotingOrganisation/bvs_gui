#include <QByteArray>
#include <QJsonDocument>
#include <QDebug>

#include "ballotrepository.h"
#include "projectRepository.h"
#include "Classes/Service/convert.h"

BallotRepository::BallotRepository()
{

}

QStringList BallotRepository::findAllBallots(QStringList args, QString project) {
    ProjectRepository *projectRepository;
    QStringList items = projectRepository->findAllItems(args, project);
    QString ballot;

    for (int i = 0; i < items.length(); i++) {
        QString item = items.at(i);
        if (item.contains("Ballot")) {
            QStringList itemArray = items.at(i).split(":");
            Convert convert;
            ballot = convert.hex2bin(itemArray[1]);
        }
    }

    QByteArray stdOut;
    stdOut = ballot.toLatin1();
    QJsonDocument jsonDocument = QJsonDocument::fromJson(stdOut);
    QStringList ballotList;
    if (!jsonDocument.isNull())
    {
        if (jsonDocument.isObject()) {
            ballotList.append(jsonDocument.toJson());
        }
        else {
            qDebug() << "JSON is not an object!";
        }
    }
    else {
        qDebug() << "JSON is null!";
    }
    return ballotList;
}
