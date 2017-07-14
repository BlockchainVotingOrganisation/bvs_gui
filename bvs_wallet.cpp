#include "bvs_wallet.h"
#include "ui_bvs_wallet.h"
#include "ausfuehrendialog.h"

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



void BVS_Wallet::on_action_Ausf_hren_triggered()
{
  AusfuehrenDialog *a = new AusfuehrenDialog;
  a->show();
//  a.setVisible(true);
//  connect (Form.pushButton, SIGNAL(clicked()),ausfuehrendialog,SLOT(close()));
}
