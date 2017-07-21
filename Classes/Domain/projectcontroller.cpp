#include "projectcontroller.h"
#include <QJsonDocument>
#include <QProcess>
#include <QJsonArray>
#include <QJsonObject>

using namespace std;

ProjectController::ProjectController()
{
    list<string> projects;
}

QStringList ProjectController::getProjects() {
    QProcess * process = new QProcess;
    QByteArray stdOut;// = process->readAllStandardOutput();
    process = new QProcess;
    process->start("multichain-cli BVS_R2 liststreams");
    process->waitForFinished();

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
    }
}
