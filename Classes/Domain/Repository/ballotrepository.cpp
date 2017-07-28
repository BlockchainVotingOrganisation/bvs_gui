#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonValueRef>
#include <QDebug>

#include "ballotrepository.h"
#include "projectRepository.h"
#include "Classes/Domain/Model/ballot.h"
#include "Classes/Service/convert.h"

BallotRepository::BallotRepository()
{

}

Ballot BallotRepository::findBallot(QStringList args, QString project) {
    ProjectRepository *projectRepository;
    QStringList projectItems = projectRepository->findAllItems(args, project);
    QString ballotStr;
    Ballot ballot;

    for (int i = 0; i < projectItems.length(); i++) {
        QString item = projectItems.at(i);
        if (item.contains("Ballot")) {
            QStringList itemArray = projectItems.at(i).split(":");
            Convert convert;
            ballotStr = convert.hex2bin(itemArray[1]);
        }
    }

    QByteArray stdOut;
    stdOut = ballotStr.toLatin1();
    QJsonDocument jsonDocument = QJsonDocument::fromJson(stdOut);

    if (jsonDocument.isNull())
    {
        qDebug() << "JSON is null!";
    }

    if (jsonDocument.isObject())
    {
        qDebug() << "JSON is object:" << jsonDocument.toJson();
        QJsonObject ballotObject = jsonDocument.object();

        for (int i = 0; i < ballotObject.keys().count(); i++) {
            QString key = ballotObject.keys().at(i);
            QString value = ballotObject.value(key).toString();


            if (key == "uid") {
                QString valueStr = value.setNum(value.toInt());
                ballot.setUid(valueStr);
                qDebug() << "uid" << value.toInt();
            }
            if (key == "name") {
                ballot.setName(value);
                qDebug() << "name" << value;
            }
            if (key == "logo") {
                ballot.setLogo(value);
                qDebug() << "logo" << value;
            }
            if (key == "text") {
                qDebug() << "text" << value;
                ballot.setText(value);
            }
            if (key == "options") {
                QStringList options;
                QJsonObject myOptions = ballotObject.value(key).toObject();
                for (int j = 0; j < myOptions.keys().count(); j++) {
//                    qDebug() << "option" << j << myOptions.keys().at(j) << ":" <<  myOptions.value(myOptions.keys().at(j));
                    QByteArray myvalue;
                    myvalue = myOptions.value(myOptions.keys().at(j)).toString().replace("\\\\\\","\\\\").toLatin1();
                    QJsonObject option = QJsonDocument::fromJson(myvalue).object();
                    qDebug() << "\n\noption" << j << " " << myvalue;
                    for (int k = 0; k < option.keys().count(); k++) {
                        qDebug()  << "data:" << option.keys().at(k) << ":" <<  option.value(option.keys().at(k));
                    }
                    options.append(myOptions.value(myOptions.keys().at(j)).toString().replace("\\\\\\","\\\\"));
                }
                ballot.setOptions(options);
            }
        }
    }
    return ballot;
}



