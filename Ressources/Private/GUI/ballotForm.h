#ifndef BALLOT_H
#define BALLOT_H

#include <QtWidgets/QDialog>

namespace Ui {
class Ballot;
}

class Ballot : public QDialog
{
    Q_OBJECT

public:
    explicit Ballot(QWidget *parent = 0);
    ~Ballot();

private:
    Ui::Ballot *ui;
};

#endif // BALLOT_H
