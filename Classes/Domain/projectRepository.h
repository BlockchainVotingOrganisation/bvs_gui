#ifndef PROJECTREPOSITORY_H
#define PROJECTREPOSITORY_H

#include <QtCore/qglobal.h>
#include <QtCore/QtGlobal>
#include <QStringList>

class ProjectRepository
{


public:
    explicit ProjectRepository();
    QStringList getProjects();

private:
    QStringList projects;

};

#endif // PROJECTREPOSITORY_H
