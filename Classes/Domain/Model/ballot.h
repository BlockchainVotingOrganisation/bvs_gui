#ifndef BALLOT_H
#define BALLOT_H

#include <QString>

class Ballot
{
public:
    Ballot();

    void setUid(int uid);
    int getUid();

    QString getName();
    void setName(QString name);

    QString getLogo();
    void setLogo(QString logo);

    QString getText();
    void setText(QString text);

private:

    int uid;
    QString name;
    QString logo;
    QString text;
};

#endif // BALLOT_H
