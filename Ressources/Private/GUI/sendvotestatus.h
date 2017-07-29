#ifndef SENDVOTESTATUS_H
#define SENDVOTESTATUS_H

#include <QWidget>

namespace Ui {
class SendVoteStatus;
}

class SendVoteStatus : public QWidget
{
    Q_OBJECT

public:
    explicit SendVoteStatus(QString sendAdress, QString voting, QWidget *parent = 0);
    ~SendVoteStatus();

private:
    Ui::SendVoteStatus *ui;
};

#endif // SENDVOTESTATUS_H
