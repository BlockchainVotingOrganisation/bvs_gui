#include "ausfuehrendialog.h"
#include "ui_ausfuehrendialog.h"
#include "QJsonDocument"
#include <QJsonObject>
#include <QJsonArray>
#include <QProcess>
#include <qdebug.h>

AusfuehrenDialog::AusfuehrenDialog(QStringList args, QWidget *parent) :
  QDialog(parent),
  ui(new Ui::AusfuehrenDialog)
{
  ui->setupUi(this);//    QRegularExpression regex("\\[|\\]");
    this->args = args;
}

AusfuehrenDialog::~AusfuehrenDialog()
{
  delete ui;
}

void AusfuehrenDialog::on_pushButton_clicked()
{
    QProcess process;
    QStringList arguments;
    QString blockchain, path;

    for(int i = 0; i < args.length(); i++) {

        QStringList argBlockchain = this->args[i].split("=");

        if (this->args[i].contains("blockchain=") == true) {
            blockchain = argBlockchain[1];
//            qDebug() << "BC:" << blockchain;
        }
        else if (this->args[i].contains("path=") == true) {
            path = argBlockchain[1];
//            qDebug() << "path" << path;
        }
    }

    arguments.append(blockchain);
    arguments.append(ui->cmdInput->text());

    process.start(path + "multichain-cli", arguments);
    process.waitForFinished();

    QByteArray stdOut = process.readAllStandardOutput();

    qDebug() << stdOut;
    QString out = stdOut;

    ui->plainTextEdit->appendPlainText(out);
}
