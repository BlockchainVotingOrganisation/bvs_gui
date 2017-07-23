#include "projectController.h"

#include <QStringList>

ProjectController::ProjectController()
{

}

QStringList ProjectController::listAction(QString blockchain) {
    ProjectRepository *repository;
    return repository->findAllProjects(blockchain);
}

//Project ProjectController::showAction(QString project) {
//    ProjectRepository *repository;

////    ballots = repository->GetBallots(project);
//    return myproject;
//}


