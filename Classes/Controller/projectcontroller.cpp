#include "projectController.h"

#include <QStringList>

ProjectController::ProjectController()
{

}

QStringList ProjectController::listAction(QStringList args) {
    ProjectRepository *repository;
    return repository->findAllProjects(args);
}

Project ProjectController::showAction(QStringList args, QString projectName) {
    ProjectRepository *repository;
    QStringList items;
    items = repository->findAllItems(args,projectName);
}


