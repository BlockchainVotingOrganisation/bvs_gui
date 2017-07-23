/********************************************************************************
** Form generated from reading UI file 'ausfuehrendialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUSFUEHRENDIALOG_H
#define UI_AUSFUEHRENDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AusfuehrenDialog
{
public:
    QDialogButtonBox *buttonBox;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPlainTextEdit *plainTextEdit;
    QLineEdit *cmdInput;
    QPushButton *pushButton;
    QWidget *tab_2;

    void setupUi(QDialog *AusfuehrenDialog)
    {
        if (AusfuehrenDialog->objectName().isEmpty())
            AusfuehrenDialog->setObjectName(QStringLiteral("AusfuehrenDialog"));
        AusfuehrenDialog->setWindowModality(Qt::ApplicationModal);
        AusfuehrenDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(AusfuehrenDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tabWidget = new QTabWidget(AusfuehrenDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 341, 191));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        plainTextEdit = new QPlainTextEdit(tab);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 50, 321, 141));
        cmdInput = new QLineEdit(tab);
        cmdInput->setObjectName(QStringLiteral("cmdInput"));
        cmdInput->setGeometry(QRect(10, 10, 301, 25));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(310, 10, 25, 25));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        retranslateUi(AusfuehrenDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AusfuehrenDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AusfuehrenDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AusfuehrenDialog);
    } // setupUi

    void retranslateUi(QDialog *AusfuehrenDialog)
    {
        AusfuehrenDialog->setWindowTitle(QApplication::translate("AusfuehrenDialog", "BVS Cliend Cmd", 0));
        cmdInput->setPlaceholderText(QApplication::translate("AusfuehrenDialog", "z.B.: getinfo", 0));
        pushButton->setText(QApplication::translate("AusfuehrenDialog", "->", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("AusfuehrenDialog", "Tab 1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("AusfuehrenDialog", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class AusfuehrenDialog: public Ui_AusfuehrenDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUSFUEHRENDIALOG_H
