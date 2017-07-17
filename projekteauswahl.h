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


private slots:
    QString on_projectListe_itemSelectionChanged();

public slots:
    QString getProject();

private:
  Ui::ProjekteAuswahl *ui;
};

#endif // PROJEKTEAUSWAHL_H
