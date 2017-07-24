#include "projekteauswahl.h"
#include "ui_projekteauswahl.h"
#include "QJsonDocument"
#include <QJsonObject>
#include <QProcess>
#include <qdebug.h>
#include <QJsonArray>

ProjekteAuswahl::ProjekteAuswahl(QStringList args, QWidget *parent) :
  QDialog(parent),
  ui(new Ui::ProjekteAuswahl)
{
    ui->setupUi(this);
    QStringList projects;

    projects = this->controller->listAction(args);
    if (projects.length() > 0) {
        ui->projectListe->insertItems(0, projects);
    }
}

ProjekteAuswahl::~ProjekteAuswahl()
{
  delete ui;
}


QString ProjekteAuswahl::getProject() {
    if (ui->projectListe->selectedItems().length() > 0) {
        return ui->projectListe->selectedItems().at(0)->text();
    }
    else return "";
}

QString ProjekteAuswahl::on_projectListe_itemSelectionChanged()
{
    qDebug() << "Lade Stream" << ui->projectListe->selectedItems().at(0)->text() + ".";
    return ui->projectListe->selectedItems().at(0)->text();
}
