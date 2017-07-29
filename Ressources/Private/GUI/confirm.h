#ifndef CONFIRM_H
#define CONFIRM_H

#include <QDialog>
#include "Ressources/Private/GUI/sendvotestatus.h"

namespace Ui {
class Confirm;
}

class Confirm : public QDialog
{
    Q_OBJECT

public:
    explicit Confirm(QString sendAddress, QStringList results, QWidget *parent = 0);
    ~Confirm();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Confirm *ui;
    SendVoteStatus *status;
    QString sendAddress;

};

#endif // CONFIRM_H
