#ifndef PROJECTCONTROLLER_H
#define PROJECTCONTROLLER_H

#include <QtCore/qglobal.h>
#include <QtCore/QtGlobal>
#include <QStringList>

class ProjectController
{


public:
    explicit ProjectController();
    QStringList getProjects();

private:
    QStringList projects;

};

#endif // PROJECTCONTROLLER_H
