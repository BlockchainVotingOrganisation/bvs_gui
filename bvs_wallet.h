#ifndef BVS_WALLET_H
#define BVS_WALLET_H


#include <QtCore/QtGlobal>

#include <QMainWindow>
#include "ausfuehrendialog.h"

#include "Classes/Domain/Model/node.h"
#include "Classes/Controller/nodecontroller.h"
#include "Classes/Controller/projectController.h"
#include "Classes/Domain/projectRepository.h"

namespace Ui {
  class BVS_Wallet;
}

class AusfuehrenDialog;


class BVS_Wallet : public QMainWindow
{
  Q_OBJECT

public:
  explicit BVS_Wallet(QStringList args, QWidget *parent = 0);
  ~BVS_Wallet();

  Node *node;


private slots:
  void on_action_Ausf_hren_triggered();
  void on_actionWahl_ffnen_triggered();
  void on_action_Beenden_triggered();
  void on_actionAuswaehlen_triggered();
  void on_actionEinstellungen_triggered();
  void closeEvent();
  void on_action_Stimmzettel_triggered();
  void projectOpen();

private:
    Ui::BVS_Wallet *ui;
    ProjectController *controller;
    ProjectRepository *repository;
    QString *blockchain;
    QString *server;
    QString *port;
    QStringList args;
};

#endif // BVS_WALLET_H
