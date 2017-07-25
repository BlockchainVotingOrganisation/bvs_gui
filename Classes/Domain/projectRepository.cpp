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
QStringList ProjectRepository::findAllProjects(QStringList args) {

    QStringList projectList;
    QString cmd;

    QString blockchain, path;
    QStringList arguments;
    QProcess process;

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

    cmd = path + "multichain-cli.exe";

    process.start(cmd, arguments);
    if (process.waitForFinished()) {

        QString out =  process.readAllStandardOutput();
        QByteArray stdOut;
        QJsonParseError jerror;


        /*
         * Work-Around für Windows...
         */
        if (out.contains("method") && out.contains("liststreams")) {
            QStringList outputChars;
            outputChars = out.split("\r\n\r\n");
            qDebug() << "Method?" << outputChars[0];
            stdOut = outputChars[1].toUtf8().replace("\r\n","");
        }
        else
            stdOut = out.toUtf8().replace("\r\n","");


        QJsonDocument jsonDocument = QJsonDocument::fromJson(stdOut, &jerror); // <- funktioniert nicht.

        qDebug() << "jerror:" << jerror.errorString();
        if (!jsonDocument.isNull())
        {
            if (jsonDocument.isArray()) {
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
}

/**
 * @brief ProjectRepository::findAllItems
 * @param project
 * @return
 */
QStringList ProjectRepository::findAllItems(QStringList args, QString project) {

    QStringList itemList, arguments;
    QByteArray stdOut;
    QString blockchain, path, out;
    QProcess process;
    QJsonParseError jerror;

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
    arguments.append(project);
    arguments.append("false");

    process.startDetached(path + "multichain-cli.exe", arguments); //project);
    process.waitForFinished();

    arguments.clear();
    arguments.append(blockchain);
    arguments.append("liststreamitems");
    arguments.append(project);
    arguments.append("false");
    arguments.append("999999");

    process.start(path + "multichain-cli.exe", arguments); //project);
    process.waitForFinished();
    out =  process.readAllStandardOutput();

    /*
     * Work-Around für Windows...
     */
    if (out.contains("method") && out.contains("liststreamitems")) {
        QStringList outputChars;
        outputChars = out.split("\r\n\r\n");
        qDebug() << "Method?" << outputChars[0];
        stdOut = outputChars[1].toUtf8().replace("\r\n","");
    }
    else
        stdOut = out.toUtf8().replace("\r\n","");

//    qDebug() << "\nOutput:" << stdOut;

    QJsonDocument jsonDocument = QJsonDocument::fromJson(stdOut, &jerror);

//    qDebug() << "\nError:" << jerror.errorString();

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
        return itemList;
        }
        else {
            qDebug() << "JSON is not an array!";
        }
    }
    else {
        qDebug() << project << "JSON is null!";
    }
}
