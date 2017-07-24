#include "projectController.h"

#include <QStringList>

ProjectController::ProjectController()
{

}

QStringList ProjectController::listAction(QStringList args) {
    ProjectRepository *repository;
    return repository->findAllProjects(args);
}

//Project ProjectController::showAction(QString project) {
//    ProjectRepository *repository;

////    ballots = repository->GetBallots(project);
//    return myproject;
//}


