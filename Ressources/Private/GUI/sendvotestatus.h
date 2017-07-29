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
    explicit SendVoteStatus(QWidget *parent = 0);
    ~SendVoteStatus();

private:
    Ui::SendVoteStatus *ui;
};

#endif // SENDVOTESTATUS_H
