#include "sendvotestatus.h"
#include "ui_sendvotestatus.h"

SendVoteStatus::SendVoteStatus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SendVoteStatus)
{
    ui->setupUi(this);
}

SendVoteStatus::~SendVoteStatus()
{
    delete ui;
}
