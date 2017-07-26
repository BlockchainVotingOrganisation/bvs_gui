#include "ballotformwidget.h"
#include "ui_ballotformwidget.h"

BallotFormWidget::BallotFormWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BallotFormWidget)
{
    ui->setupUi(this);
}

BallotFormWidget::~BallotFormWidget()
{
    delete ui;
}
