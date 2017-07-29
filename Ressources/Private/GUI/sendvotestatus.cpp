#include "sendvotestatus.h"
#include "ui_sendvotestatus.h"
#include <QDebug>
#include <QApplication>

SendVoteStatus::SendVoteStatus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SendVoteStatus)
{
    ui->setupUi(this);

    QStringList args = QCoreApplication::arguments();

    for (int i = 0; i < args.count(); i++) {
//        qDebug() << args.at(i);
    }

}

SendVoteStatus::~SendVoteStatus()
{
    delete ui;
}
