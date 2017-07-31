#include "projekteauswahl.h"
#include "ui_projekteauswahl.h"
#include <qdebug.h>

ProjekteAuswahl::ProjekteAuswahl(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::ProjekteAuswahl)
{
    ui->setupUi(this);
    QString blockchain;
    QStringList args = QCoreApplication::arguments();
    for(int i = 0; i < args.length(); i++) {
        QStringList argBlockchain= args.at(i).split("=");
        if (argBlockchain[0] == "-blockchain") {
            blockchain = argBlockchain[1];
        }
    }

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
    return ui->projectListe->selectedItems().at(0)->text();
}
