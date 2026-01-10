#include <QtWidgets/QApplication>

#include "GymJournal.h"
#include "Controller/Controller.h"
#include "View/ExercisesPanel.h"
#include "View/TraningSessionsPanel.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto view = std::make_shared<GymJournal>();
    auto controller = Controller::Create(view);
    std::weak_ptr<Controller> weakController(controller);
    view->GetExercisePanel()->SetObserver(weakController);
    view->GetTraningSessionPanel()->SetObserver(weakController);
    view->show();
    return a.exec();
}
