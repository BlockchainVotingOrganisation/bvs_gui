#include "sendvotestatus.h"
#include "ui_sendvotestatus.h"
#include "Classes/Service/convert.h"
#include <QDebug>
#include <QApplication>
#include <QProcess>

SendVoteStatus::SendVoteStatus(QString sendAdress, QString voting, QWidget *parent):
    QWidget(parent),
    ui(new Ui::SendVoteStatus)
{
    ui->setupUi(this);
    QString blockchain, path;
    QStringList args = QCoreApplication::arguments();

    for(int i = 0; i < args.length(); i++) {

        QStringList argBlockchain = args[i].split("=");

        if (args[i].contains("blockchain=") == true) {
            blockchain = argBlockchain[1];
        }
        else if (args[i].contains("path=") == true) {
            path = argBlockchain[1];
        }
    }

    QProcess process;
    QStringList arguments;
    Convert convert;

    arguments.append(blockchain);
    arguments.append("sendwithmetadata");
    arguments.append(sendAdress);
    arguments.append("0");
    arguments.append(convert.bin2hex(voting.trimmed()));

    ui->listWidget->addItem("SEND VOTE...");
    ui->listWidget->addItem(voting.trimmed());
    ui->listWidget->addItem("SEND TO:");
    ui->listWidget->addItem(sendAdress);
    ui->progressBar->setValue(30);

    process.start(path + "multichain-cli", arguments);
    process.waitForFinished();

    QByteArray stdOut = process.readAllStandardOutput();
    ui->progressBar->setValue(60);
    qDebug() << stdOut;
    QString out = stdOut;
    ui->listWidget->addItem("RESULT:");
    ui->listWidget->addItem(out.trimmed());
    ui->progressBar->setValue(100);
}

SendVoteStatus::~SendVoteStatus()
{
    delete ui;
}
