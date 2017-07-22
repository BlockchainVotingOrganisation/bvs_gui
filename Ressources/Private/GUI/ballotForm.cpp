#include "ballotForm.h"
#include "ui_ballot.h"

BallotForm::BallotForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ballot)
{
    ui->setupUi(this);
}

BallotForm::~BallotForm()
{
    delete ui;
}
