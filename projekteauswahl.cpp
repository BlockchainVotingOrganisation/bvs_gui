#include "projekteauswahl.h"
#include "ui_projekteauswahl.h"
#include "QJsonDocument"
#include <QJsonObject>
#include <QProcess>
#include <qdebug.h>
#include <QJsonArray>
#include "Classes/Domain/projectRepository.h"


ProjekteAuswahl::ProjekteAuswahl(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::ProjekteAuswahl)
{
    ui->setupUi(this);
    ProjectRepository *repository;
    QStringList projects;
    projects = repository->getProjects();
    ui->projectListe->insertItems(0, projects);
}

ProjekteAuswahl::~ProjekteAuswahl()
{
  delete ui;
}

// Getter und Setter für Projektliste

/*
 * get selected project:  * return ui->projectListe->selectedItems().at(0)->text();
 *
 */

QString ProjekteAuswahl::getProject() {
    return ui->projectListe->selectedItems().at(0)->text();
}

QString ProjekteAuswahl::on_projectListe_itemSelectionChanged()
{
    qDebug() << ui->projectListe->selectedItems().at(0)->text();
    return ui->projectListe->selectedItems().at(0)->text();
}



