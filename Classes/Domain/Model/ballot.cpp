#include "ballot.h"
#include "Classes/Domain/Repository/ballotrepository.h"
#include <QObject>

Ballot::Ballot()
{

}

QString Ballot::getUid() {
    return this->uid;
}
void Ballot::setUid(QString uid) {
    this->uid = uid;
}

QString Ballot::getName() {
    return this->name;
}

void Ballot::setName(QString name) {
    this->name = name;
}

QString Ballot::getLogo() {
    return this->logo;
}

void Ballot::setLogo(QString logo) {
    this->logo = logo;
}

QString Ballot::getText() {
    return this->text;
}

void Ballot::setText(QString text) {
    this->text = text;
}

QStringList Ballot::getOptions() {
    return this->options;
}

void Ballot::setOptionsStrList(QStringList options) {
    this->options = options;
}


