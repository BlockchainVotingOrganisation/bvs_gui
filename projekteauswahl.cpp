#include "projekteauswahl.h"
#include "ui_projekteauswahl.h"
#include "QJsonDocument"
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
    out.append(process->readAllStandardOutput();
    qDebug() <<"Raw input:\n" << out << "\n";
    QJsonDocument *itemdoc;
    itemdoc->fromJson(out);
    qDebug() << "Is object?" << itemdoc->isObject();
}

ProjekteAuswahl::~ProjekteAuswahl()
{
  delete ui;
}
