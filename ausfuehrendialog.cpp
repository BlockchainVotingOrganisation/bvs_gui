#include "ausfuehrendialog.h"
#include "ui_ausfuehrendialog.h"

#include <QProcess>


AusfuehrenDialog::AusfuehrenDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::AusfuehrenDialog)
{
  ui->setupUi(this);


}

AusfuehrenDialog::~AusfuehrenDialog()
{
  delete ui;
}

void AusfuehrenDialog::on_pushButton_clicked()
{
    QProcess * process = new QProcess;
    process->start("multichaind BVS_R2@blockchain-voting.org:6733");
    process->waitForFinished();
    QByteArray out = process->readAllStandardOutput();
    process->start("multichain-cli BVS_R2 " + ui->cmdInput->text());
    process->waitForFinished();
    out.append(process->readAllStandardOutput());
    ui->plainTextEdit->appendPlainText(out);
//    QJsonDocument *itemdoc ;
//    itemdoc->fromJson(out);
//    qDebug() << itemdoc;
}
