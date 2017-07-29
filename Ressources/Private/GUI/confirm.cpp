#include "confirm.h"
#include "ui_confirm.h"


Confirm::Confirm(QStringList results, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Confirm)
{
    ui->setupUi(this);
    QString text;
    for (int i = 0; i < results.length(); i++) {
        text = text + "\n" + results.at(i);
    }
    ui->label->setText(text);
}

Confirm::~Confirm()
{
    delete ui;
}

void Confirm::on_buttonBox_accepted()
{

    SendVoteStatus *status = new SendVoteStatus;
    status->show();
}
