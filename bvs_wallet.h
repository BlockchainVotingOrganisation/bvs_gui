#ifndef BVS_WALLET_H
#define BVS_WALLET_H


#include <QtCore/QtGlobal>

#include <QMainWindow>
#include "ausfuehrendialog.h"
#include "Classes/Domain/projectRepository.h"
#include "Classes/Domain/Model/node.h"

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

//public slots:
//  QString getBlockchain();
//  void setBlockchain(QString chain);
//  QString getServer();
//  void setServer(QString myserver);
//  int getPort();
//  void setPort(QString port);

  void on_action_Stimmzettel_triggered();

private:
    Ui::BVS_Wallet *ui;

    QString *blockchain;
    QString *server;
    QString *port;
    QStringList args;
};

#endif // BVS_WALLET_H
