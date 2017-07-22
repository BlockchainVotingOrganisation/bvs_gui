#ifndef BALLOT_H
#define BALLOT_H

#if QT_VERSION >= 0x050000
#include <QtWidgets/QDialog>
#else
#include <QtGui/QDialog>
#endif

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
