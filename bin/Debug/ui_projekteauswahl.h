/********************************************************************************
** Form generated from reading UI file 'projekteauswahl.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJEKTEAUSWAHL_H
#define UI_PROJEKTEAUSWAHL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjekteAuswahl
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *projectListe;

    void setupUi(QDialog *ProjekteAuswahl)
    {
        if (ProjekteAuswahl->objectName().isEmpty())
            ProjekteAuswahl->setObjectName(QStringLiteral("ProjekteAuswahl"));
        ProjekteAuswahl->setWindowModality(Qt::ApplicationModal);
        ProjekteAuswahl->resize(400, 300);
        buttonBox = new QDialogButtonBox(ProjekteAuswahl);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        projectListe = new QListWidget(ProjekteAuswahl);
        projectListe->setObjectName(QStringLiteral("projectListe"));
        projectListe->setGeometry(QRect(20, 20, 351, 192));

        retranslateUi(ProjekteAuswahl);
        QObject::connect(buttonBox, SIGNAL(accepted()), ProjekteAuswahl, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ProjekteAuswahl, SLOT(reject()));

        QMetaObject::connectSlotsByName(ProjekteAuswahl);
    } // setupUi

    void retranslateUi(QDialog *ProjekteAuswahl)
    {
        ProjekteAuswahl->setWindowTitle(QApplication::translate("ProjekteAuswahl", "Wahl \303\266ffnen", 0));
    } // retranslateUi

};

namespace Ui {
    class ProjekteAuswahl: public Ui_ProjekteAuswahl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJEKTEAUSWAHL_H
