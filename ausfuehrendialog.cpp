#include "ausfuehrendialog.h"
#include "ui_ausfuehrendialog.h"

AusfuehrenDialog::AusfuehrenDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::AusfuehrenDialog)
{
  ui->setupUi(this);
}

AusfuehrenDialog::~AusfuehrenDialog()
{
  delete ui;
}
