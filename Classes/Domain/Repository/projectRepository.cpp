#include "projectRepository.h"

#include <QJsonDocument>
#include <QProcess>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

/**
 * @brief ProjectRepository::ProjectRepository
 */
ProjectRepository::ProjectRepository()
{

}

/**
 * @brief ProjectRepository::findAllProjects
 * @return
 *
 * Description: gets all streams from multichain blockchain. a stream represents one election project.
 */
QStringList ProjectRepository::findAllProjects(QStringList args) {

    QStringList projectList, arguments;
    QProcess process;
    QByteArray stdOut;
    QString cmd, blockchain, path;

    for(int i = 0; i < args.length(); i++) {
        QStringList argBlockchain= args.at(i).split("=");
        if (argBlockchain[0] == "-blockchain") {
            blockchain = argBlockchain[1];
        }
        else if (argBlockchain[0] == "-path") {
            path = argBlockchain[1];
        }
    }

    arguments.append(blockchain);
    arguments.append("liststreams");

    cmd = path + "multichain-cli";

    process.start(cmd, arguments);
    process.waitForFinished();

    stdOut.append(process.readAllStandardOutput());

    QJsonDocument jsonDocument = QJsonDocument::fromJson(stdOut);

    if (!jsonDocument.isNull())
    {
        if (jsonDocument.isArray()) {
            jsonDocument = QJsonDocument::fromJson(stdOut);
            QJsonArray jsonArray = jsonDocument.array();
            QJsonObject streams[jsonArray.size()];
            for (int i = 0; i < jsonArray.size(); i++) {
              streams[i] = jsonArray[i].toObject();
              projectList.append(streams[i].value("name").toString());
            }

        }
        else {
            qDebug() << "JSON is not an array!";
        }
    }
    else {
        qDebug() << "JSON is null!";
    }
    return projectList;
}

/**
 * @brief ProjectRepository::findAllItems
 * @param project
 * @return
 */
QStringList ProjectRepository::findAllItems(QStringList args, QString project) {

    QStringList itemList, arguments;
    QProcess process;
    QByteArray stdOut;
    QString blockchain, path;


    for(int i = 0; i < args.length(); i++) {
        QString arg = args[i];
        QStringList argBlockchain= args.at(i).split("=");
        if (argBlockchain[0] == "-blockchain") {
            blockchain = argBlockchain[1];
        }
        else if (arg.contains("path=") == true) {
            QStringList argBlockchain = arg.split("=");
            path = argBlockchain[1];
        }
    }
    arguments.append(blockchain);
    arguments.append("subscribe");
    arguments.append("false");

    process.start(path + "multichain-cli", arguments);

    process.waitForFinished();

    arguments.clear();
    arguments.append(blockchain);
    arguments.append("liststreamitems");
    arguments.append(project);
    arguments.append("false");
    arguments.append("999999");

    process.start(path + "multichain-cli", arguments);
    process.waitForFinished();

    stdOut.append(process.readAllStandardOutput());

    QJsonDocument jsonDocument = QJsonDocument::fromJson(stdOut);

    if (!jsonDocument.isNull())
    {
        if (jsonDocument.isArray()) {
            jsonDocument = QJsonDocument::fromJson(stdOut);
            QJsonArray jsonArray = jsonDocument.array();
            QJsonObject streams[jsonArray.size()];
            for (int i = 0; i < jsonArray.size(); i++) {
              streams[i] = jsonArray[i].toObject();
              itemList.append(streams[i].value("key").toString() + ": " + streams[i].value("data").toString());
            }
        }
        else {
            qDebug() << "JSON is not an array!";
        }
    }
    else {
        qDebug() << project << "JSON is null!";
    }
    return itemList;
}
