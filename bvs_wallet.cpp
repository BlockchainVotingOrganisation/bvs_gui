#include "bvs_wallet.h"
#include "ui_bvs_wallet.h"
#include "ausfuehrendialog.h"
#include "projekteauswahl.h"
#include "settingsdialog.h"
#include <QDebug>
#include <QCloseEvent>


/**
 * @brief BVS_Wallet::BVS_Wallet
 * @param args
 * @param parent
 */
BVS_Wallet::BVS_Wallet(QStringList args, QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::BVS_Wallet),
  node(new Node)
{
    ui->setupUi(this);
    this->args = args;

//    QString  arg[Args.length()];
    QString blockchain;

    for(int i = 0; i < args.length(); i++) {
        QStringList argBlockchain= args.at(i).split("=");

        if (argBlockchain[0] == "-blockchain") {
            blockchain = argBlockchain[1];
        }
//        ui->listWidget->addItem(args.at(i));
    }
}

/**
 * @brief BVS_Wallet::~BVS_Wallet -closes the bvs_gui mainwindow
 *
 */
BVS_Wallet::~BVS_Wallet()
{
//    qDebug() << "Anwendung beenden... (2)";
    closeEvent();
    delete ui;
}

/**
 * @brief BVS_Wallet::on_action_Ausf_hren_triggered
 */
void BVS_Wallet::on_action_Ausf_hren_triggered()
{
  AusfuehrenDialog *a = new AusfuehrenDialog;

  a->show();
}

/**
 * @brief BVS_Wallet::on_actionWahl_ffnen_triggered
 */
void BVS_Wallet::on_actionWahl_ffnen_triggered()
{
    ProjekteAuswahl *p = new ProjekteAuswahl(this->args);
    p->show();

    if (p->exec()==QDialog::Accepted) {
        QString project = p->getProject();
        if (project != "")
        {
            ui->label->setText(project);
        }
    }
}

/**
 * @brief BVS_Wallet::on_action_Beenden_triggered
 */
void BVS_Wallet::on_action_Beenden_triggered()
{
    closeEvent();
    exit(0);
}

/**
 * @brief BVS_Wallet::on_actionAuswaehlen_triggered
 */
void BVS_Wallet::on_actionAuswaehlen_triggered()
{
    ProjekteAuswahl *p = new ProjekteAuswahl(this->args);
    p->show();

    if (p->exec()==QDialog::Accepted) {
        QString project = p->getProject();
        ui->label->setText(project);

        // soll Liste aus controller-showAction abrufen...
        ui->listWidget->addItems(repository->findAllItems(this->args, project));
    }
}

/**
 * @brief BVS_Wallet::on_actionEinstellungen_triggered
 */
void BVS_Wallet::on_actionEinstellungen_triggered()
{
    SettingsDialog *settings = new SettingsDialog;
    settings->show();
}

/**
 * @brief BVS_Wallet::closeEvent
 */
void BVS_Wallet::closeEvent()
{
//    for(int i = 0; i < this->args.length(); i++) {
//         qDebug() << this->args.at(i);
//    }
//    qDebug() << "Anwendung beenden - Blockchain: ";
    NodeController nc;
    int i = nc.stopDaemon(args);
    qDebug() << "Anwendung beenden...";
    qDebug() <<  "Status:" << i;
}

void BVS_Wallet::on_action_Stimmzettel_triggered()
{

}
