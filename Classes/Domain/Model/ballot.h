#ifndef BALLOT_H
#define BALLOT_H

#include <QString>

class Ballot
{
public:
    Ballot();

    void setUid(QString uid);
    QString getUid();

    QString getName();
    void setName(QString name);

    QString getLogo();
    void setLogo(QString logo);

    QString getText();
    void setText(QString text);

private:

    QString uid;
    QString name;
    QString logo;
    QString text;
};

#endif // BALLOT_H
