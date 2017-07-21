#ifndef PROJECTREPOSITORY_H
#define PROJECTREPOSITORY_H

#include <QtCore/qglobal.h>
#include <QtCore/QtGlobal>
#include <QStringList>

class ProjectRepository
{


public:
    explicit ProjectRepository();
    QStringList findAllProjects();
    QStringList findAllItems(QString project);

private:
    QStringList projects;
    QStringList items;

};

#endif // PROJECTREPOSITORY_H
