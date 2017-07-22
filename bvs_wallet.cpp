#include "bvs_wallet.h"
#include "ui_bvs_wallet.h"
#include "ausfuehrendialog.h"
#include "projekteauswahl.h"
#include "settingsdialog.h"


BVS_Wallet::BVS_Wallet(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::BVS_Wallet)
{
  ui->setupUi(this);
  QString *blockchain;
  QString *server;
  int *port;
//  setCentralWidget(ui->listWidget);

}

BVS_Wallet::~BVS_Wallet()
{
  delete ui;
}


void BVS_Wallet::on_action_Ausf_hren_triggered()
{
  AusfuehrenDialog *a = new AusfuehrenDialog;
  a->show();
}

void BVS_Wallet::on_actionWahl_ffnen_triggered()
{
    ProjekteAuswahl *p = new ProjekteAuswahl;
    p->show();

    if (p->exec()==QDialog::Accepted) {
        QString project = p->getProject();
        if (project != "")
        {
            ui->label->setText(project);
        }
    }
}

void BVS_Wallet::on_action_Beenden_triggered()
{
    exit(0);
}

void BVS_Wallet::on_actionAuswaehlen_triggered()
{
    ProjekteAuswahl *p = new ProjekteAuswahl;
    p->show();

    ProjectRepository *repository;

    if (p->exec()==QDialog::Accepted) {
        QString project = p->getProject();
        ui->label->setText(project);
        ui->listWidget->addItems(repository->findAllItems(project));    }
}

void BVS_Wallet::on_actionEinstellungen_triggered()
{
    SettingsDialog *settings = new SettingsDialog;
    settings->show();
}

void BVS_Wallet::setBlockchain(QString chain) {
//    *blockchain = chain;
}

void BVS_Wallet::setServer(QString myserver) {
//    *server = myserver;
}

void BVS_Wallet::setPort(int port) {
//    this->port = port;
}

QString BVS_Wallet::getBlockchain() {
//    return this->blockchain;
}

QString BVS_Wallet::getServer() {
//    return this->server;
}

int BVS_Wallet::getPort() {
//    return this->port;
}
