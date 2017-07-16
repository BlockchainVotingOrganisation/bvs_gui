#include "projekteauswahl.h"
#include "ui_projekteauswahl.h"
#include "QJsonDocument"
#include <QJsonObject>
#include <QProcess>
#include <qdebug.h>
#include <QJsonArray>


ProjekteAuswahl::ProjekteAuswahl(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::ProjekteAuswahl)
{
    ui->setupUi(this);

    QProcess * process = new QProcess;
    QByteArray stdOut;// = process->readAllStandardOutput();
    process = new QProcess;
    process->start("multichain-cli BVS_R2 liststreams");
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
              ui->listWidget->addItem(streams[i].value("name").toString());
            }
        }
    }
}

ProjekteAuswahl::~ProjekteAuswahl()
{
  delete ui;
}
