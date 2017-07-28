#include <QDebug>
#include <QString>
#include <QJsonDocument>
#include <QProcess>
#include <QJsonArray>
#include <QJsonObject>
#include "ballotformwidget.h"
#include "ui_ballotformwidget.h"
#include "Classes/Controller/projectController.h"
#include "Classes/Domain/Repository/projectRepository.h"
#include "Classes/Domain/Repository/ballotRepository.h"
#include "Classes/Service/convert.h"

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
//        ui->listWidget->addItem(args.at(i));
        if (args.at(i) == "-debug") {
            qDebug() << "\nArgs:" << args.length() << "";
            for(int j = 0; j < args.length(); j++) {
                qDebug() << "args[" << j << "] = " << args.at(j) << "";
            }
        }
    }

    this->setWindowTitle(project);
    BallotRepository *ballotRepository;
    Ballot ballot;
    ballot = ballotRepository->findBallot(args, project);

    if (ballot.getUid().isEmpty() == false) {
        ui->listWidget->addItem(ballot.getUid());
    }

    if (ballot.getName() != "") {
        ui->listWidget->addItem(ballot.getName());
    }

    if (ballot.getText().isEmpty() == false) {
        ui->listWidget->addItem(ballot.getText());
    }

    if (ballot.getLogo().isEmpty() == false) {
        ui->listWidget->addItem(ballot.getLogo());
    }

    /**
      * addItems soll auf Ballot zugreifen
      *
      */
    ui->listWidget->addItems(ballotRepository->findOptionsByProjectName(project));
}

BallotFormWidget::~BallotFormWidget()
{
    delete ui;
}
