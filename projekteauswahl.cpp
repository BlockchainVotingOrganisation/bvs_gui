#include "projekteauswahl.h"
#include "ui_projekteauswahl.h"
#include "QJsonDocument"
#include <QJsonObject>
#include <QProcess>
#include <qdebug.h>

ProjekteAuswahl::ProjekteAuswahl(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::ProjekteAuswahl)
{
    ui->setupUi(this);

    QProcess * process = new QProcess;
    QByteArray out;// = process->readAllStandardOutput();
    process = new QProcess;
    process->start("multichain-cli BVS_R2 liststreams");
    process->waitForFinished();
    out.append(process->readAllStandardOutput());

    qDebug() <<"Raw input:\n" << out << "\n";

    QJsonDocument mDocument = QJsonDocument::fromJson(out);

    if (!mDocument.isNull())
    {
        qDebug() << "Is array? " << mDocument.isArray();

        qDebug() << "Is object?" << mDocument.isObject();
        if (mDocument.isObject()) {
            QJsonObject jsonObject ;
            jsonObject = mDocument.object();
            qDebug() << "Object empty?:" << jsonObject.isEmpty();
        }

    }
}

ProjekteAuswahl::~ProjekteAuswahl()
{
  delete ui;
}
