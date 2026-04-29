#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include "mainwindow.h"
#include "Equipe.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow window;
    window.show();

    Equipe test;
    test.charger("../equipe1.csv");


    return QApplication::exec();
}