#include "nodecontroller.h"
#include <QProcess>
#include <QDebug>

NodeController::NodeController()
{

}

int NodeController::stopDaemon(QStringList args) {
    QString blockchain, server, port;

    for(int i = 0; i < args.length(); i++) {

        QStringList argBlockchain= args.at(i).split("=");

        if (argBlockchain[0] == "-blockchain") {
            blockchain = argBlockchain[1];
        }
//        else if (argBlockchain[0] == "-server") {
//            server = argBlockchain[1];
//        }

//        else if (argBlockchain[0] == "-port") {
//            QStringList argBlockchain = args.at(i).split("=");
//            port = argBlockchain[1];
//        }

//         qDebug() << "Node:" << args.at(i);
    }

    QProcess *p = new QProcess;
    qDebug() << "multichain-cli " + blockchain + " stop";
    p->start("multichain-cli " + blockchain + " stop");
    p->waitForFinished();
    return 0;
}
