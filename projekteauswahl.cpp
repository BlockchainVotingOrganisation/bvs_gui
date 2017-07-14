#include "projekteauswahl.h"
#include "ui_projekteauswahl.h"

ProjekteAuswahl::ProjekteAuswahl(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::ProjekteAuswahl)
{
  ui->setupUi(this);
}

ProjekteAuswahl::~ProjekteAuswahl()
{
  delete ui;
}
