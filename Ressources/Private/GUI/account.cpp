#include "account.h"
#include "ui_account.h"

Account::Account(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Account)
{
  ui->setupUi(this);
}

Account::~Account()
{
  delete ui;
}
