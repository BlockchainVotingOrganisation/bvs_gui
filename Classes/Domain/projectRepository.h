#ifndef PROJECTREPOSITORY_H
#define PROJECTREPOSITORY_H

#include <QtCore/qglobal.h>
#include <QtCore/QtGlobal>
#include <QStringList>
#include "Classes/Domain/Model/project.h"

class ProjectRepository
{


public:
    explicit ProjectRepository();
    QStringList findAllProjects(QStringList args);
    QStringList findAllItems(QStringList args, QString project);
    Project findByName(QString project);

private:
    QStringList projects;
    QStringList items;
    QStringList keys;
};

#endif // PROJECTREPOSITORY_H
