#include "ballotcontroller.h"


BallotController::BallotController()
{

}
/**
 * @brief BallotController::ballotList - als Ersatz für ShowAction TODO!
 * @param ballot
 * @return
 */
QStringList BallotController::ballotList(Ballot ballot) {
    QStringList items;

    if (ballot.getUid().isEmpty() == false) {
        items.append(ballot.getUid());
    }

    if (ballot.getName() != "") {
        items.append(ballot.getName());
    }

    if (ballot.getText().isEmpty() == false) {
        items.append(ballot.getText());
    }

    if (ballot.getLogo().isEmpty() == false) {
        items.append(ballot.getLogo());
    }
    if (ballot.getOptions().isEmpty() == false) {
        items.append(ballot.getOptions());
    }
    return items;
}
