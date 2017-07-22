#ifndef PROJECTCONTROLLER_H
#define PROJECTCONTROLLER_H

#include "Classes/Domain/Model/project.h"
#include "Classes/Domain/projectRepository.h"

#include <QtCore/qglobal.h>

class ProjectController
{
public:
    ProjectController();
    QStringList listAction();

    Project showAction(QString project);
    Project newAction();
    Project createAction();
    Project editAction(QString project);
    Project deleteAction(QString project);

private:
    ProjectRepository *repository;
    QStringList listBallotsAction(QString project);
};

#endif // PROJECTCONTROLLER_H
