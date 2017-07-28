#ifndef OPTION_H
#define OPTION_H

#include <QString>
#include "ballot.h"

class Option
{
public:
    Option();

    QString getName();
    void setName(QString name);

    Ballot getballot();
    void setBallot(Ballot ballot);

    QString getWalletAddress();
    void setWalletAddress();

private:

    QString name;
    Ballot ballot;
    QString walletAdress;
};

#endif // OPTION_H
