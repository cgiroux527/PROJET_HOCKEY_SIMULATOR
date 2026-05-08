#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include "mainwindow.h"
#include "Equipe.h"
#include "Simulation.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow window;
    window.show();

    /*Simulation exemple;
    while (!exemple.getCalendrier().empty()) {
        ResultatMatch resultat = exemple.simulerMatch(EquipeCanadiens);
        //S'ASSURER DE PASSER EQUIPE CANADIENS LE ROSTER CHOISI ET NON L'EQUIPE AU COMPLET
        std::cout << resultat.getScoreAdverse();
        ...
    }*/

    return QApplication::exec();
}