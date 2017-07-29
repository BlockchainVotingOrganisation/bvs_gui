#include <QDebug>
#include <QString>
#include <QStringList>
#include <QJsonDocument>
#include <QProcess>
#include <QJsonArray>
#include <QJsonObject>
#include <QRadioButton>
#include <QList>
#include <QPushButton>
#include <QVBoxLayout>

#include "Ressources/Private/GUI/confirm.h"
#include "ballotformwidget.h"
#include "ui_ballotformwidget.h"

#include "Classes/Controller/projectController.h"
#include "Classes/Domain/Repository/projectRepository.h"
#include "Classes/Domain/Repository/ballotRepository.h"
#include "Classes/Service/convert.h"
#include "Classes/Domain/Model/ballot.h"
#include "Classes/Controller/ballotcontroller.h"

BallotFormWidget::BallotFormWidget(QStringList args, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BallotFormWidget)
{
    ui->setupUi(this);
    this->args = args;

//    QString  arg[Args.length()];
    QString project;

    for(int i = 0; i < args.length(); i++) {
        QStringList argBlockchain = args.at(i).split("=");

        if (argBlockchain[0] == "-project") {
            project = argBlockchain[1];
        }
        if (args.at(i) == "-debug") {
            qDebug() << "\nArgs:" << args.length() << "";
            for(int j = 0; j < args.length(); j++) {
                qDebug() << "args[" << j << "] = " << args.at(j) << "";
            }
        }
    }
    this->setWindowTitle(project);
    BallotRepository *ballotRepository; //  soll  BallotController *controller;
    Ballot ballot;
    ballot = ballotRepository->findBallot(args, project); // soll  BallotController *controller showAction

    ui->labelBallonName->setText(ballot.getName());
    ui->textBrowser->setText(ballot.getText());

//    /*buttongroup*/ = new QButtonGroup(this);

    for (int i = 0; i < ballot.getOptions().length(); i++) {
        QRadioButton *button = new QRadioButton(ballot.getOptions().at(i), this);
        button->setLayoutDirection(Qt::RightToLeft);
        button->setStyleSheet("font-size: 20px;");
        button->setProperty("name", ballot.getOptions().at(i));


        this->buttonGroup.addButton(button);
        ui->gridLayout->addWidget(button);
    }



    // Konsolenausgabe!
//    ui->listWidget->addItems(controller->ballotItemList(ballot));
}

BallotFormWidget::~BallotFormWidget()
{
    delete ui;
}


void BallotFormWidget::on_buttonBox_accepted()
{
//    qDebug() << "Buttons müssen in buttonGroup, damit sie beim Beenden abgefragt werden können.";




//    connect(ok, SIGNAL(clicked()), confirm, SLOT(show()));
    QStringList myresults;

    for (int i = 0; i < this->buttonGroup.buttons().count(); i++) {
        qDebug() << i << " " << this->buttonGroup.buttons().at(i)->isChecked() << " " << this->buttonGroup.buttons().at(i)->text().trimmed();
        myresults.append(this->buttonGroup.buttons().at(i)->text().trimmed() + " " + QString::number(this->buttonGroup.buttons().at(i)->isChecked()));

//        bool ok = this->buttonGroup.buttons().at(i)->isChecked();
//        textlist.append(this->buttonGroup.buttons().at(i)->text().trimmed());
//        textlist.append(text + QString::number(ok));
    }
    Confirm *confirm = new Confirm(myresults);
    confirm->show();


}


