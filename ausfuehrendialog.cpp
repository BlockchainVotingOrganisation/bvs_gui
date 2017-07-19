#include "ausfuehrendialog.h"
#include "ui_ausfuehrendialog.h"
#include "QJsonDocument"
#include <QJsonObject>
#include <QJsonArray>
#include <QProcess>
#include <qdebug.h>
#include <QProcess>



AusfuehrenDialog::AusfuehrenDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::AusfuehrenDialog)
{
  ui->setupUi(this);//    QRegularExpression regex("\\[|\\]");


}

AusfuehrenDialog::~AusfuehrenDialog()
{
  delete ui;
}

void AusfuehrenDialog::on_pushButton_clicked()
{
    QProcess * process = new QProcess;

    process->start("multichain-cli BVS_R2 " + ui->cmdInput->text());
    process->waitForFinished();
    QString out = process->readAllStandardOutput();
    ui->plainTextEdit->appendPlainText(out);
}
