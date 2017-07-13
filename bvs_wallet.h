#ifndef BVS_WALLET_H
#define BVS_WALLET_H

#if QT_VERSION >= 0x050000
#include <QtWidgets/QMainWindow>
#else
#include <QtGui/QMainWindow>
#endif

namespace Ui {
  class BVS_Wallet;
}

class BVS_Wallet : public QMainWindow
{
  Q_OBJECT

public:
  explicit BVS_Wallet(QWidget *parent = 0);
  ~BVS_Wallet();

private:
  Ui::BVS_Wallet *ui;
};

#endif // BVS_WALLET_H
