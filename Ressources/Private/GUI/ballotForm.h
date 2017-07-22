#ifndef BALLOT_H
#define BALLOT_H

#include <QtWidgets/QDialog>

namespace Ui {
class Ballot;
}

class BallotForm : public QDialog
{
    Q_OBJECT

public:
    explicit BallotForm(QWidget *parent = 0);
    ~BallotForm();

private:
    Ui::Ballot *ui;
};

#endif // BALLOT_H
