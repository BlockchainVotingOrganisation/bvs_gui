/********************************************************************************
** Form generated from reading UI file 'bvs_wallet.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BVS_WALLET_H
#define UI_BVS_WALLET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BVS_Wallet
{
public:
    QAction *action_Beenden;
    QAction *actionEinstellungen;
    QAction *actionWahl_schlie_en;
    QAction *actionWahl_ffnen;
    QAction *action_Ausf_hren;
    QAction *actionNeu;
    QAction *action_Stimmzettel;
    QAction *actionAuswaehlen;
    QAction *actionErgebnis;
    QAction *actionHilfe;
    QWidget *centralwidget;
    QLabel *label;
    QListWidget *listWidget;
    QMenuBar *menubar;
    QMenu *menuDatei;
    QMenu *menu_Hilfe;
    QMenu *menu_ber_BVS;
    QMenu *menu_Konto;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *BVS_Wallet)
    {
        if (BVS_Wallet->objectName().isEmpty())
            BVS_Wallet->setObjectName(QStringLiteral("BVS_Wallet"));
        BVS_Wallet->resize(800, 600);
        BVS_Wallet->setCursor(QCursor(Qt::ArrowCursor));
        BVS_Wallet->setStyleSheet(QStringLiteral("background: white;"));
        action_Beenden = new QAction(BVS_Wallet);
        action_Beenden->setObjectName(QStringLiteral("action_Beenden"));
        actionEinstellungen = new QAction(BVS_Wallet);
        actionEinstellungen->setObjectName(QStringLiteral("actionEinstellungen"));
        actionWahl_schlie_en = new QAction(BVS_Wallet);
        actionWahl_schlie_en->setObjectName(QStringLiteral("actionWahl_schlie_en"));
        actionWahl_ffnen = new QAction(BVS_Wallet);
        actionWahl_ffnen->setObjectName(QStringLiteral("actionWahl_ffnen"));
        action_Ausf_hren = new QAction(BVS_Wallet);
        action_Ausf_hren->setObjectName(QStringLiteral("action_Ausf_hren"));
        actionNeu = new QAction(BVS_Wallet);
        actionNeu->setObjectName(QStringLiteral("actionNeu"));
        action_Stimmzettel = new QAction(BVS_Wallet);
        action_Stimmzettel->setObjectName(QStringLiteral("action_Stimmzettel"));
        actionAuswaehlen = new QAction(BVS_Wallet);
        actionAuswaehlen->setObjectName(QStringLiteral("actionAuswaehlen"));
        actionErgebnis = new QAction(BVS_Wallet);
        actionErgebnis->setObjectName(QStringLiteral("actionErgebnis"));
        actionHilfe = new QAction(BVS_Wallet);
        actionHilfe->setObjectName(QStringLiteral("actionHilfe"));
        centralwidget = new QWidget(BVS_Wallet);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 551, 31));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(30, 50, 731, 451));
        BVS_Wallet->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BVS_Wallet);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menubar->setStyleSheet(QLatin1String("background: black;\n"
"color: white;"));
        menuDatei = new QMenu(menubar);
        menuDatei->setObjectName(QStringLiteral("menuDatei"));
        menu_Hilfe = new QMenu(menubar);
        menu_Hilfe->setObjectName(QStringLiteral("menu_Hilfe"));
        menu_ber_BVS = new QMenu(menubar);
        menu_ber_BVS->setObjectName(QStringLiteral("menu_ber_BVS"));
        menu_Konto = new QMenu(menubar);
        menu_Konto->setObjectName(QStringLiteral("menu_Konto"));
        BVS_Wallet->setMenuBar(menubar);
        statusbar = new QStatusBar(BVS_Wallet);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        BVS_Wallet->setStatusBar(statusbar);
        toolBar = new QToolBar(BVS_Wallet);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setCursor(QCursor(Qt::CrossCursor));
        BVS_Wallet->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuDatei->menuAction());
        menubar->addAction(menu_Konto->menuAction());
        menubar->addAction(menu_Hilfe->menuAction());
        menubar->addAction(menu_ber_BVS->menuAction());
        menuDatei->addAction(actionNeu);
        menuDatei->addAction(actionWahl_ffnen);
        menuDatei->addSeparator();
        menuDatei->addAction(actionEinstellungen);
        menuDatei->addSeparator();
        menuDatei->addAction(action_Ausf_hren);
        menuDatei->addSeparator();
        menuDatei->addAction(action_Beenden);
        toolBar->addAction(actionAuswaehlen);
        toolBar->addAction(action_Stimmzettel);
        toolBar->addSeparator();
        toolBar->addAction(actionErgebnis);
        toolBar->addAction(actionHilfe);

        retranslateUi(BVS_Wallet);

        QMetaObject::connectSlotsByName(BVS_Wallet);
    } // setupUi

    void retranslateUi(QMainWindow *BVS_Wallet)
    {
        BVS_Wallet->setWindowTitle(QApplication::translate("BVS_Wallet", "BVS Client", 0));
        action_Beenden->setText(QApplication::translate("BVS_Wallet", "&Beenden", 0));
        actionEinstellungen->setText(QApplication::translate("BVS_Wallet", "&Einstellungen", 0));
        actionWahl_schlie_en->setText(QApplication::translate("BVS_Wallet", "&Schlie\303\237en", 0));
        actionWahl_ffnen->setText(QApplication::translate("BVS_Wallet", "&\303\226ffnen", 0));
        action_Ausf_hren->setText(QApplication::translate("BVS_Wallet", "&Ausf\303\274hren", 0));
        actionNeu->setText(QApplication::translate("BVS_Wallet", "Neu", 0));
        action_Stimmzettel->setText(QApplication::translate("BVS_Wallet", "&Stimmzettel", 0));
        actionAuswaehlen->setText(QApplication::translate("BVS_Wallet", "Wahl \303\266ffnen", 0));
#ifndef QT_NO_TOOLTIP
        actionAuswaehlen->setToolTip(QApplication::translate("BVS_Wallet", "Project ausw\303\244hlen", 0));
#endif // QT_NO_TOOLTIP
        actionErgebnis->setText(QApplication::translate("BVS_Wallet", "Ergebnis", 0));
        actionHilfe->setText(QApplication::translate("BVS_Wallet", "Hilfe", 0));
        label->setText(QApplication::translate("BVS_Wallet", "Kein Projekt!", 0));
        menuDatei->setTitle(QApplication::translate("BVS_Wallet", "&Datei", 0));
        menu_Hilfe->setTitle(QApplication::translate("BVS_Wallet", "&Hilfe", 0));
        menu_ber_BVS->setTitle(QApplication::translate("BVS_Wallet", "&\303\234ber BVS", 0));
        menu_Konto->setTitle(QApplication::translate("BVS_Wallet", "&Konto", 0));
        toolBar->setWindowTitle(QApplication::translate("BVS_Wallet", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class BVS_Wallet: public Ui_BVS_Wallet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BVS_WALLET_H
