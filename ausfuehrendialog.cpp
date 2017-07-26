#include "ausfuehrendialog.h"
#include "ui_ausfuehrendialog.h"
#include "QJsonDocument"
#include <QJsonObject>
#include <QJsonArray>
#include <QProcess>
#include <qdebug.h>
#include <QProcess>



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

    for(int i = 0; i < args.size(); i++) {



        QStringList argBlockchain = args[i].split("=");


        if (args[i].contains("blockchain=") == true) {

            blockchain = argBlockchain[1];
        }


        else if (args[i].contains("path=") == true) {

            path = argBlockchain[1];
        }
}

    arguments.append(blockchain);
    arguments.append(ui->cmdInput->text());

    process.start(path + "multichain-cli!", arguments);
    process.waitForFinished();
    QString out = process.readAllStandardOutput();
    ui->plainTextEdit->appendPlainText(out);
}
