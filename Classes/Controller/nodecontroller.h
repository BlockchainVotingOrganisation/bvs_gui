#ifndef NODECONTROLLER_H
#define NODECONTROLLER_H

#include <QtCore/qglobal.h>
#include <QString>

class NodeController
{
public:
    NodeController();

    int stopDaemon(QStringList args);
};

#endif // NODECONTROLLER_H
