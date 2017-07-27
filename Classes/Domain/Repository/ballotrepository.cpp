#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonValueRef>
#include <QDebug>

#include "ballotrepository.h"
#include "projectRepository.h"
#include "Classes/Service/convert.h"

BallotRepository::BallotRepository()
{

}

QJsonDocument BallotRepository::findBallot(QStringList args, QString project) {
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

    if (jsonDocument.isNull())
    {
        qDebug() << "JSON is null!";
    }

    return jsonDocument;
}

QStringList BallotRepository::findAllOptions(QJsonDocument ballot) {

    QStringList options;

    if (ballot.isObject())
    {
        qDebug() << "JSON is object:" << ballot.toJson();
        QJsonObject ballotObject = ballot.object();
        for (int i = 0; i < ballot.object().keys().count(); i++) {
            QString key = ballotObject.keys().at(i);
            if (key == "name") {
                QString value = ballotObject.value(key).toString().toUtf8();
                options.append(value);
            }
            else if (key == "options") {
                options.append(" ");
                options.append("Options:");
            }
        }
    }
    return options;
}
