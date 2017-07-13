#ifndef DIALOGWAHLEN_H
#define DIALOGWAHLEN_H

#if QT_VERSION >= 0x050000
#include <QtWidgets/QDialog>
#else
#include <QtGui/QDialog>
#endif

namespace Ui {
  class DialogWahlen;
}

class DialogWahlen : public QDialog
{
  Q_OBJECT

public:
  explicit DialogWahlen(QWidget *parent = 0);
  ~DialogWahlen();

private:
  Ui::DialogWahlen *ui;
};

#endif // DIALOGWAHLEN_H
