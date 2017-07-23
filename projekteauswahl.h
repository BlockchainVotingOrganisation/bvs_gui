#ifndef PROJEKTEAUSWAHL_H
#define PROJEKTEAUSWAHL_H


#include <QDialog>
#include "Classes/Controller/projectController.h"

namespace Ui {
  class ProjekteAuswahl;
}

class ProjekteAuswahl : public QDialog
{
  Q_OBJECT

public:
  explicit ProjekteAuswahl(QStringList args, QWidget *parent = 0);
  ~ProjekteAuswahl();


private slots:
    QString on_projectListe_itemSelectionChanged();

public slots:
    QString getProject();

private:
  Ui::ProjekteAuswahl *ui;
  ProjectController *controller;
};

#endif // PROJEKTEAUSWAHL_H
