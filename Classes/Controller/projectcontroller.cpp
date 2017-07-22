#include "projectController.h"

#include <QStringList>

ProjectController::ProjectController()
{

}

QStringList ProjectController::listAction() {
    ProjectRepository *repository;
    return repository->findAllProjects();
}

Project ProjectController::showAction(QString project) {

}


