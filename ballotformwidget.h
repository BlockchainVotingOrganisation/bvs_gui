#ifndef BALLOTFORMWIDGET_H
#define BALLOTFORMWIDGET_H

#include <QDialog>

namespace Ui {
class BallotFormWidget;
}

class BallotFormWidget : public QDialog
{
    Q_OBJECT

public:
    explicit BallotFormWidget(QWidget *parent = 0);
    ~BallotFormWidget();

private:
    Ui::BallotFormWidget *ui;
};

#endif // BALLOTFORMWIDGET_H
