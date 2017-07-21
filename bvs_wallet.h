#ifndef BVS_WALLET_H
#define BVS_WALLET_H


#include <QtCore/QtGlobal>

#include <QMainWindow>
#include "ausfuehrendialog.h"
#include "Classes/Domain/projectRepository.h"

namespace Ui {
  class BVS_Wallet;
}

class AusfuehrenDialog;


class BVS_Wallet : public QMainWindow
{
  Q_OBJECT

public:
  explicit BVS_Wallet(QWidget *parent = 0);
  ~BVS_Wallet();

    int getPort();
    void setPort();

    QString getBlockchain();
    void setBlockchain();

    QString getServer();
    void setServer();

private slots:
  void on_action_Ausf_hren_triggered();

  void on_actionWahl_ffnen_triggered();

  void on_action_Beenden_triggered();

  void on_actionAuswaehlen_triggered();

  void on_actionEinstellungen_triggered();

private:
    Ui::BVS_Wallet *ui;
    QString *blockchain;
    QString *server;
    int *port;
};

#endif // BVS_WALLET_H
