#ifndef AUSFUEHRENDIALOG_H
#define AUSFUEHRENDIALOG_H

#include <QDialog>

namespace Ui {
  class AusfuehrenDialog;
}

class AusfuehrenDialog : public QDialog
{
  Q_OBJECT

public:
  explicit AusfuehrenDialog(QStringList args, QWidget *parent = 0);
  ~AusfuehrenDialog();

private slots:
  void on_pushButton_clicked();

private:
  Ui::AusfuehrenDialog *ui;
  QStringList args;

};

#endif // AUSFUEHRENDIALOG_H
