#include "nodecontroller.h"
#include <QProcess>
#include <QDebug>

NodeController::NodeController()
{

}

int NodeController::stopDaemon(QStringList args) {
    QString blockchain, path;

    for(int i = 0; i < args.length(); i++) {

        QStringList argBlockchain= args.at(i).split("=");

        if (argBlockchain[0] == "-blockchain") {
            blockchain = argBlockchain[1];
        }
        else if (argBlockchain[0] == "-path") {
            path = argBlockchain[1];
        }
    }

    QProcess p;
    QStringList arguments;
    arguments.append(blockchain);
    arguments.append("stop");

    QString cmd = path + "multichain-cli.exe";
    qDebug() << cmd << blockchain << "stop";

    if (QProcess::startDetached(cmd, arguments))
        qDebug() << "Exit.";
    return 0;
}
