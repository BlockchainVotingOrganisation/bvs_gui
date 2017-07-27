#include "bvs_wallet.h"
#include "ui_bvs_wallet.h"
#include "ausfuehrendialog.h"
#include "projekteauswahl.h"
#include "settingsdialog.h"
#include "ballotformwidget.h"
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

        if (args.at(i) == "-debug") {
            qDebug() << "\nArgs:" << args.length() << "";
            for(int j = 0; j < args.length(); j++) {
                qDebug() << "args[" << j << "] = " << args.at(j) << "";
            }
        }

        if (argBlockchain[0] == "-project") {
//            qDebug() << "args[" << i << "] = " << args.at(i) << "";
            this->setWindowTitle(argBlockchain[1]);
            ui->label->setText(argBlockchain[1]);

            QStringList items;
            items = repository->findAllItems(args, argBlockchain[1]);
            if (items.length() > 0) {
                ui->listWidget->addItems(items);
            }

        }
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
  AusfuehrenDialog *a = new AusfuehrenDialog(args);

  a->show();
}

/**
 * @brief BVS_Wallet::on_actionWahl_ffnen_triggered
 */
void BVS_Wallet::on_actionWahl_ffnen_triggered()
{
    this->projectOpen();
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
void BVS_Wallet::on_actionAuswaehlen_triggered()//    ProjekteAuswahl *p = new ProjekteAuswahl(this->args);
{
    this->projectOpen();
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
////    qDebug() << "Anwendung beenden - Blockchain: ";
//    NodeController nc;
//    int i = nc.stopDaemon(args);
//    qDebug() << "Anwendung beenden Status:" << i;
}

/**
 * @brief BVS_Wallet::on_action_Stimmzettel_triggered
 */
void BVS_Wallet::on_action_Stimmzettel_triggered()
{
    BallotFormWidget *ballotform = new BallotFormWidget(this->args);
    ballotform->show();
}

/**
 * @brief BVS_Wallet::projectOpen
 */
void BVS_Wallet::projectOpen() {
    ProjekteAuswahl *p = new ProjekteAuswahl(this->args);
    p->show();

    QString blockchain;

    for(int i = 0; i < args.length(); i++) {
        QStringList argBlockchain= args.at(i).split("=");
        if (argBlockchain[0] == "-blockchain") {
            blockchain = argBlockchain[1];
        }
    }

    if (p->exec()==QDialog::Accepted) {
        QString project = p->getProject();
        if (args.contains("project") == false) {
            args.append("-project=" + project);
        }

        ui->label->setText(project);
        ui->listWidget->clear();
        ui->listWidget->addItems(repository->findAllItems(this->args, project));
    }
}
