#ifndef BALLOTFORMWIDGET_H
#define BALLOTFORMWIDGET_H

#include <QDialog>
#include "Classes/Domain/Repository/ballotRepository.h"

namespace Ui {
class BallotFormWidget;
}

class BallotFormWidget : public QDialog
{
    Q_OBJECT

public:
    explicit BallotFormWidget(QStringList args, QWidget *parent = 0);
    ~BallotFormWidget();

private:
    Ui::BallotFormWidget *ui;

    QStringList args;
    QStringList items;

    Ballot ballot;
};

#endif // BALLOTFORMWIDGET_H
