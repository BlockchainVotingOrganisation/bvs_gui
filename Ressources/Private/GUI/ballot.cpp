#include "ballot.h"
#include "ui_ballot.h"

Ballot::Ballot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ballot)
{
    ui->setupUi(this);
}

Ballot::~Ballot()
{
    delete ui;
}
