#ifndef PROJEKTEAUSWAHL_H
#define PROJEKTEAUSWAHL_H


#include <QDialog>


namespace Ui {
  class ProjekteAuswahl;
}

class ProjekteAuswahl : public QDialog
{
  Q_OBJECT

public:
  explicit ProjekteAuswahl(QWidget *parent = 0);
  ~ProjekteAuswahl();

private:
  Ui::ProjekteAuswahl *ui;
};

#endif // PROJEKTEAUSWAHL_H
