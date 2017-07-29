#ifndef BALLOTFORMWIDGET_H
#define BALLOTFORMWIDGET_H

#include <QDialog>
#include <QRadioButton>
#include <QButtonGroup>
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


private slots:
    void on_buttonBox_accepted();

//    void on_radioButton_clicked();

private:
    Ui::BallotFormWidget *ui;

    QStringList args;
    QStringList items;
    bool checked;
//    QList<QRadioButton> *buttonGroup;
    QButtonGroup buttonGroup;
    Ballot ballot;
};

#endif // BALLOTFORMWIDGET_H
