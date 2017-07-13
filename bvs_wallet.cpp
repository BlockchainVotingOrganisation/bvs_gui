#include "bvs_wallet.h"
#include "ui_bvs_wallet.h"

BVS_Wallet::BVS_Wallet(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::BVS_Wallet)
{
  ui->setupUi(this);
}

BVS_Wallet::~BVS_Wallet()
{
  delete ui;
}
