/********************************************************************************
** Form generated from reading UI file 'ballotForm.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BALLOTFORM_H
#define UI_BALLOTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_FormBallot
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *FormBallot)
    {
        if (FormBallot->objectName().isEmpty())
            FormBallot->setObjectName(QStringLiteral("FormBallot"));
        FormBallot->resize(400, 300);
        buttonBox = new QDialogButtonBox(FormBallot);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(50, 260, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(FormBallot);
        QObject::connect(buttonBox, SIGNAL(accepted()), FormBallot, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FormBallot, SLOT(reject()));

        QMetaObject::connectSlotsByName(FormBallot);
    } // setupUi

    void retranslateUi(QDialog *FormBallot)
    {
        FormBallot->setWindowTitle(QApplication::translate("FormBallot", "Ballot", 0));
    } // retranslateUi

};

namespace Ui {
    class FormBallot: public Ui_FormBallot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BALLOTFORM_H
