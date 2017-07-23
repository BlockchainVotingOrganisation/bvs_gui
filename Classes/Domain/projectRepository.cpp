#include "projectRepository.h"

#include <QJsonDocument>
#include <QProcess>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>


//using namespace std;

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
QStringList ProjectRepository::findAllProjects(QString blockchain) {

    QStringList projectList;
    QProcess * process = new QProcess;
    QByteArray stdOut;
    QString cmd;

    cmd = "multichain-cli " +blockchain + " liststreams";

    process->start(cmd);
    process->waitForFinished();
    stdOut.append(process->readAllStandardOutput());

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
QStringList ProjectRepository::findAllItems(QString blockchain, QString project) {

    QStringList itemList;
    QProcess * process = new QProcess;
    QByteArray stdOut;

    process->start("multichain-cli " + blockchain + " subscribe " + project + " false"); //project);

    process->waitForFinished();
    process->start("multichain-cli " + blockchain + " liststreamitems " + project); //project);
    process->waitForFinished();
    stdOut.append(process->readAllStandardOutput());

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
