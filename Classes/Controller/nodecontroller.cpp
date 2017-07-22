#include "nodecontroller.h"
#include <QProcess>

NodeController::NodeController()
{

}

int NodeController::stopDaemon() {
    QProcess *p = new QProcess;
    p->start("multichain-cli BVS_R2 stop");
    p->waitForFinished();
    return 0;
}
