/********************************************************************************
** Form generated from reading UI file 'ballot.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BALLOT_H
#define UI_BALLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Ballot
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Ballot)
    {
        if (Ballot->objectName().isEmpty())
            Ballot->setObjectName(QStringLiteral("Ballot"));
        Ballot->resize(400, 300);
        buttonBox = new QDialogButtonBox(Ballot);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(50, 260, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(Ballot);
        QObject::connect(buttonBox, SIGNAL(accepted()), Ballot, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Ballot, SLOT(reject()));

        QMetaObject::connectSlotsByName(Ballot);
    } // setupUi

    void retranslateUi(QDialog *Ballot)
    {
        Ballot->setWindowTitle(QApplication::translate("Ballot", "Ballot", 0));
    } // retranslateUi

};

namespace Ui {
    class Ballot: public Ui_Ballot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BALLOT_H
