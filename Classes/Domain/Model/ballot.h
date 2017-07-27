#ifndef BALLOT_H
#define BALLOT_H

#include <QString>

class Ballot
{
public:
    Ballot();

    QString getName();
    void setName(QString name);

private:
    QString *name;
};

#endif // BALLOT_H
