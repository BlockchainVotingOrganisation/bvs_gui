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

    QStringList arguments;
    arguments.append(blockchain);
    arguments.append("stop");

    QString cmd = path + "multichain-cli";
    qDebug() << cmd << blockchain << "stop";
    QProcess process;
    if (process.startDetached(cmd, arguments))
        qDebug()  << "Exit.";
    return 0;
}
