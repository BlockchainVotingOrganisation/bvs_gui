#include "projectRepository.h"
#include <QJsonDocument>
#include <QProcess>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

using namespace std;

ProjectRepository::ProjectRepository()
{
    list<string> projects;
}

QStringList ProjectRepository::getProjects() {
    QProcess * process = new QProcess;
    QByteArray stdOut;// = process->readAllStandardOutput();
//    process = new QProcess;
    process->start("multichain-cli BVS_R2 liststreams");
    process->waitForFinished();
    stdOut.append(process->readAllStandardOutput());

    QJsonDocument jsonDocument = QJsonDocument::fromJson(stdOut);
    QStringList projectList;

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
            return projectList;
        }
        else {
            qDebug() << "JSON is not an array!";
        }
    }
    else {
        qDebug() << "JSON is null!";
    }

}
