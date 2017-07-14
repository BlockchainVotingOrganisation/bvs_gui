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
  explicit AusfuehrenDialog(QWidget *parent = 0);
  ~AusfuehrenDialog();

private:
  Ui::AusfuehrenDialog *ui;
};

#endif // AUSFUEHRENDIALOG_H
