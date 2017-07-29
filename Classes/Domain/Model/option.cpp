#include "option.h"

Option::Option()
{

}


void Option::setName(QString name) {
    this->name = name;
}

void Option::setWalletAddress(QString walletAdress) {
    this->walletAdress = walletAdress;
}

QString Option::getName() {
    return this->name;
}

QString Option::getWalletAddress() {
    return this->walletAdress;
}
