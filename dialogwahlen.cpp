#include "dialogwahlen.h"
#include "ui_dialogwahlen.h"

DialogWahlen::DialogWahlen(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::DialogWahlen)
{
  ui->setupUi(this);
}

DialogWahlen::~DialogWahlen()
{
  delete ui;
}
